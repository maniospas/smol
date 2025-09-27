// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

@include std.core.num
@include std.core.str
@include std.core.err
@include std.mem
@unsafe
@about "Standard library implementation of file management that uses the C filesystem."
@about ReadFile   "An opened file that is meant to be read only."
@about WriteFile  "An opened file that is meant to be read or written."
@about File       "A union between file types that allows common reading and positioning operations."
@about open       "Opens a File given a String path. There might be service failure due to external factors. Opening a WriteFile, "
                  "may also cause failure if it already exists - in that case remove it first and it will be created. "
                  "On the other hand, a ReadFile must already exist to be opened. "
                  "Files must be set as mutables to allow reads and writes. Otherwise, only a few operations become available."
                  "\n\nExample for overwriting a file:"
                  "<pre>if is_file(\"hi.txt\")"
                  "\n    remove_file(\"hi.txt\")"
                  "\n    end"
                  "\n@mut file = WriteFile.open(\"tmp.txt\")"
                  "\nfile:print(\"Hello world!\")"
                  "\n@release file // early release closes the file"
                  "\n</pre>"
@about to_start   "Go to the beginning of a File. You can continue reading or writing from there. This may cause service failure "
                  "due to external factors."
@about to_end     "Go to the end of a WriteFile. This is not implemented for ReadFile, as it makes more sense to just close the latter. "
                  "Returns a boolean indicating a successful operation."
@about len        "Computes the size of a File in bytes. This tries to leverage operating system metadata first, but if it fails it explicitly reads through the file once."
@about print      "Writes a string on a WriteFile."
@about temp       "Creates a WriteFile of a given size that is constrained to fixed memory provided by a Memory allocator. "
                  "\n\nDue to safety mechanisms provided by operating systems, operations on this file may be slower than simple memory read and writes. "
                  "If the operating system does not properly support memory mapped files, this may even end up consuming disk storage space of "
                  "up to the given size by being stored as a temporary file. In general, reads and writes (with print) will be at most as slow as a normal "
                  "file, with the contract that data cannot be recovered after termination. Some operating systems require manual deletion of "
                  "temporary file folders if systems are abruptly powered off. This type of file should be mostly used to store temporary data or for "
                  "testing purposes.\n\nExample usage:"
                  "<pre>on Heap:dynamic // allocator for the file"
                  "\n    @mut f = WrteFile.temp(1024)"
                  "\n    end"
                  "\nf.print(\"hello from withing a temp file!\")"
                  "\nf.to_start()"
                  "\nf.next_line(@mut u64 line)"
                  "\nprint(line)"
                  "\n</pre>"
@about next_chunk "Reads the next chunk of a file while using it as an iterator. It accomodates Arena and Volatile memories. "
                  "Here is an example where volatile memory is used to avoid repeated or large allocations:"
                  "<pre>on Heap:volatile(1024)"
                  "\n    ReadFile"
                  "\n    .open(\"README.md\")"
                  "\n    .while next_chunk(@mut str chunk)"
                  "\n        print(chunk)"
                  "\n    end end</pre>"
@about next_line  "Reads the next line of a file while using it as an iterator. It accomodates Arena and Volatile memories. "
                  "Here is an example where volatile memory is used to avoid repeated or large allocations:"
                  "<pre>endl=\"n\".str().first // optimized to just setting the new line character"
                  "\non Heap:volatile(1024)"
                  "\n    ReadFile(\"README.md\")"
                  "\n    .open(\"README.md\")"
                  "\n    .while next_line(@mut str line)"
                  "\n        if line[line:len-1]==endl"
                  "\n             line = line[0 to line:len-1]"
                  "\n             end"
                  "\n        print(line)"
                  "\n    end end</pre>"
@about ended      "Checks if the ending of the file has been reached. This is normal to be true for WriteFile."
@about is_file    "Checks if a String path is a file system file."
@about is_dir     "Checks if a String path is a file system directory."
@about create_dir "Creates a directory given a String path. May cause service failure due to external factors, or if the directory already exists."
@about remove_file "Deletes a file from the system. May cause service failure due to external factors, or if the file is already open."

def ReadFile(nominal, ptr contents)
    @noborrow
    return @args

def WriteFile(nominal, ptr contents)
    @noborrow
    return @args

union File
    ReadFile
    WriteFile
    end

def open(@access @mut ReadFile, String _path) 
    path = _path.str()
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{ptr contents = fopen((char*)path__contents, "r");}
    @finally contents {
        if(contents)
            fclose((FILE*)contents);
        contents=0;
    }
    if contents.exists().not()
        @fail{printf("Failed to open file: %.*s\n", (int)path__length, (char*)path__contents);} 
        end
    return nominal.ReadFile(contents)

def to_start(@access @mut File f) 
    if f.contents.exists().not()
        @fail{printf("Failed to move to start of closed file");} 
        end
    @body{fseek((FILE*)f__contents, 0, SEEK_SET);}
    end

def to_end(@access @mut WriteFile f) 
    // only useful for moving to the end of write files. For read files, @release them instead.
    @body{
        if(f__contents) 
            fseek((FILE*)f__contents, 0, SEEK_END);
    }
    return f.contents.exists()

def len(@access @mut File f)
    @head{#include "std/oscommon.h"}
    @head{#include <stdio.h>}
    @body{
        u64 size = 0;
        if(f__contents)
            size = __smo_file_size((FILE*)f__contents);
        if(f__contents && !size) {
            u64 pos = ftell((FILE*)f__contents);
            if(pos != -1L && fseek((FILE*)f__contents, 0, SEEK_END) == 0) {
                size = ftell((FILE*)f__contents);
                fseek((FILE*)f__contents, pos, SEEK_SET);
            }
        }
    }
    return size

def print(@access @mut WriteFile f, String _s)
    s = _s.str()
    if f.contents.exists().not()
        @fail{printf("Failed to write to closed file: %.*s\n", (int)s__length, (char*)s__contents);}
        end
    @head{#include <stdio.h>}
    @body{
        u64 bytes_written = fwrite((char*)s__contents, 1, s__length, (FILE*)f__contents);
        bool success = (bytes_written == s__length);
    }
    if success.not()
        @fail{printf("Failed to write to file: %.*s\n", (int)s__length, (char*)s__contents);}
    end end

def temp(@mut Memory memory, @access @mut WriteFile, u64 size)
    // using temporary files can be exceptionall 
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @head{#include "std/oscommon.h"}
    mem = memory.allocate(size)
    @body{ptr contents = fmemopen(mem__mem, size, "w+");}
    @finally contents {
        if(contents)
            fclose((FILE*)contents);
        contents=0;
    }
    return nominal.WriteFile(contents)
    
def next_chunk (
        @mut Volatile reader, 
        @access @mut File f,
        @mut nstr value
    )
    contents = reader.contents.mem
    size = reader.contents.size
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = f__contents?fread((char*)contents, 1, size, (FILE*)f__contents):0;
        if(!bytes_read) 
            ((char*)contents)[bytes_read] = 0; // Null-terminate for cstr compatibility of `first`
        ptr ret = bytes_read ? (ptr)contents : 0;
        char first = ((char*)contents)[0];
        reader__length = reader__length + bytes_read;
    }
    value = nominal.nstr(ret, bytes_read, first, reader.contents.underlying)
    return ret.bool()

def next_line (
        @mut Volatile reader, 
        @access @mut File f, 
        @mut nstr value
    )
    contents = reader.contents.mem
    size = reader.contents.size
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr ret = f__contents?(ptr)fgets((char*)contents, size, (FILE*)f__contents):f__contents;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)contents)[0];
        if(bytes_read && ((char*)reader__contents__mem)[bytes_read-1] == 10) {
            bytes_read--;
            if(bytes_read && ((char*)reader__contents__mem)[bytes_read-1] == 13) 
                bytes_read--;
            ((char*)reader__contents__mem)[bytes_read] = 0;
        }
        reader__length = reader__length + bytes_read;
    }
    value = nominal.nstr(ret, bytes_read, first, reader.contents.underlying)
    return ret.bool()

def next_chunk (
        @mut Arena reader, 
        @access @mut File f,
        @mut nstr value
    )
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        u64 bytes_read = f__contents?fread((char*)reader__contents__mem, 1, reader__contents__size, (FILE*)f__contents):0;
        if(!bytes_read) ((char*)reader__contents__mem)[bytes_read] = 0; // Null-terminate for cstr compatibility of `first`
        ptr ret = bytes_read ? (ptr)reader__contents__mem : 0;
        char first = ((char*)reader__contents__mem)[0];
        reader__length = reader__length + bytes_read;
    }
    value = nominal.nstr(ret, bytes_read, first, reader.contents.mem.ptr())
    return ret.bool()

def next_line(
        @mut Arena reader,
        @access @mut File f,
        @mut nstr value
    )
    @head{#include <stdio.h>}
    @head{#include <string.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr ret = f__contents?(ptr)fgets((char*)reader__contents__mem, reader__contents__size, (FILE*)f__contents):f__contents;
        u64 bytes_read = ret ? strlen((char*)ret) : 0;
        char first = ((char*)reader__contents__mem)[0];
        if(bytes_read && ((char*)reader__contents__mem)[bytes_read-1] == 10) {
            bytes_read--;
            if(bytes_read && ((char*)reader__contents__mem)[bytes_read-1] == 13) bytes_read--;
            ((char*)reader__contents__mem)[bytes_read] = 0;
        }
        reader__length = reader__length + bytes_read;
    }
    value = nominal.nstr(ret, bytes_read, first, reader.contents.mem.ptr())
    return ret.bool()

def next_line (
        @mut BoundedMemory reader,
        @access @mut File f, 
        @mut str value
    )
    ret = next_line(reader, f, @mut nstr retvalue)
    value = retvalue.str()
    return ret

def next_chunk (
        @mut BoundedMemory reader, 
        @access @mut File f, 
        @mut str value
    )
    ret = next_chunk(reader, f, @mut nstr retvalue)
    value = retvalue.str()
    return ret

def ended(@access @mut File f)
    @head{#include <stdio.h>}
    @body{
        char c = fgetc((FILE*)f__contents);
        bool has_ended = (c == EOF);
        if(!has_ended) ungetc(c, (FILE*)f__contents); 
    }
    return has_ended

def is_file(CString _path)
    path = _path.nstr()
    @head{#include <stdio.h>}
    @body{
        ptr f = fopen((char*)path__contents, "r");
        bool exists = (f != 0);
        if(f) fclose((FILE*)f);
    }
    return exists

def is_dir(CString _path)
    path = _path.nstr()
    @head{#include <sys/stat.h> #ifdef _WIN32 #define stat _stat #endif}
    @body{
        ptr info = (ptr)malloc(sizeof(struct stat));
        i64 status = stat((char*)path__contents, (struct stat*)info);
        bool result = (status == 0 && (((struct stat*)info)->st_mode & S_IFMT) == S_IFDIR);
        free(info);
    }
    return result

def remove_file(String _path)
    path = _path.str()
    @head{#include <stdio.h>}
    @body{u64 status = remove((char*)path__contents);}
    if status.bool() 
        @fail{printf("Failed to remove file - make sure that it's not open: %.*s\n", (int)path__length, (char*)path__contents);}
    end end

def open(@access @mut WriteFile, String _path)
    path = _path.str()
    @head{#include <stdio.h>}
    @head{
        #if defined(_WIN32) || defined(_WIN64)
            #include <direct.h>
            #define __SMOLANG_CREATE_FILE(path_cstr, out_file) fopen_s((FILE**)&(out_file), (char*)(path_cstr), "wx+")
        #else
            #define __SMOLANG_CREATE_FILE(path_cstr, out_file) (out_file) = fopen((char*)(path_cstr), "wx+")
        #endif
    }
    @body{
        ptr contents = 0;
        __SMOLANG_CREATE_FILE(path__contents, contents);
    }
    if contents.exists().not()
        @fail{printf("Failed to create file - make sure that it does not exist: %.*s\n", (int)path__length, (char*)path__contents);}
        end
    return nominal.WriteFile(contents)

def create_dir(String _path)
    path = _path.str()
    @head{#if defined(_WIN32) || defined(_WIN64)
    #include <direct.h>
    #define __SMOLANG_CREATE_DIR(path_cstr, status) (status) = _mkdir((char*)(path_cstr))
    #else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define __SMOLANG_CREATE_DIR(path_cstr, status) (status) = mkdir((char*)(path_cstr), 0777)
    #endif}
    @body{
        int status = -1;
        __SMOLANG_CREATE_DIR(path__contents, status);
        bool created = (status == 0);
    }
    if created.not()
        @fail{printf("Failed to create directory. It may already exist (add an is_dir check) or operation unsupported.\n");}
    end end
    
def console(@access @mut WriteFile)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @head{#include <unistd.h>}
    @head{
        #if defined(_WIN32) || defined(_WIN64)
            #include <windows.h>
            #include <io.h>
            #define SMOLAMBDA_CONSOLE(f) AllocConsole(); {HANDLE hIn = CreateFileA("CONIN$", GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL); HANDLE hOut = CreateFileA("CONOUT$", GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL); if(hIn != INVALID_HANDLE_VALUE && hOut != INVALID_HANDLE_VALUE) {int fd = _open_osfhandle((intptr_t)hIn, 0); if(fd != -1) {(f) = (ptr)_fdopen(fd, "r+"); if((f)) {setvbuf((FILE*)(f), NULL, _IONBF, 0); DWORD mode; GetConsoleMode(hIn, &mode); mode &= ~ENABLE_ECHO_INPUT; SetConsoleMode(hIn, mode);}} int fdOut = _open_osfhandle((intptr_t)hOut, 0); if(fdOut != -1) dup2(fdOut, _fileno((FILE*)(f)));}}
            #define SMOLAMBDA_CONSOLE_CLOSE(f) if(f)fclose((FILE*)(f)); FreeConsole();
        #else
            #include <stdlib.h>
            #include <unistd.h>
            #include <fcntl.h>
            #include <termios.h>
            #include <string.h>
            #define SMOLAMBDA_CONSOLE(f) {int pty_fd = posix_openpt(O_RDWR | O_NOCTTY); if(pty_fd >= 0 && grantpt(pty_fd) == 0 && unlockpt(pty_fd) == 0) {char pts_name[128]; if(ptsname_r(pty_fd, pts_name, sizeof(pts_name)) == 0) {struct termios tio; tcgetattr(pty_fd, &tio); tio.c_lflag &= ~(ECHO | ICANON); tcsetattr(pty_fd, TCSANOW, &tio); const char* terms[] = {"xterm", "konsole"}; const char* found = NULL; for(int i = 0; i < 2 && !found; i++) {char cmd[64]; snprintf(cmd, sizeof(cmd), "command -v %s >/dev/null 2>&1", terms[i]); if(system(cmd) == 0) found = terms[i];} if(found) {pid_t pid = fork(); if(pid == 0) {close(pty_fd); if(strcmp(found, "xterm") == 0) execlp("xterm", "xterm", "-e", pts_name, NULL); else if(strcmp(found, "konsole") == 0) execlp("konsole", "konsole", "-e", "socat", "-", pts_name, NULL); _exit(1);} else {(f) = (ptr)fdopen(pty_fd, "r+"); if(f) setvbuf((FILE*)(f), NULL, _IONBF, 0);}} else {(f) = (ptr)fdopen(pty_fd, "r+"); if(f) setvbuf((FILE*)(f), NULL, _IONBF, 0);}}}}
            #define SMOLAMBDA_CONSOLE_CLOSE(f) if(f)fclose((FILE*)f);
        #endif
    }
    @body{
        bool has_display = getenv("DISPLAY") || getenv("WAYLAND_DISPLAY");
        bool has_gui = has_display;
        if(getenv("SSH_CONNECTION") && !has_display) 
            has_gui = false;
        if(getenv("TERM_PROGRAM") && !has_display) 
            has_gui = true;
        {
            FILE* wsl_check = fopen("/proc/version","r");
            if(wsl_check){
                char buf[256];
                if(fread(buf,1,sizeof(buf)-1,wsl_check) > 0){
                    buf[sizeof(buf)-1] = 0;
                    if(strstr(buf,"Microsoft") || strstr(buf,"WSL")) 
                        has_gui = has_display;
                }
                fclose(wsl_check);
            }
        }
        if((getenv("MSYSTEM") || getenv("CYGWIN")) && !has_display) 
            has_gui = false;
        if(!has_gui && isatty(STDIN_FILENO)) has_gui = false;
    }
    if has_gui.not()
        return fail("Cannot open a console in the current environment")
    @body{
        ptr f = 0;
        SMOLAMBDA_CONSOLE(f)
    }
    @finally f {
        SMOLAMBDA_CONSOLE_CLOSE(f)
        f = 0;
    }
    return nominal.WriteFile(f)
