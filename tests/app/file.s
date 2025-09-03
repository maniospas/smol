@include std.builtins
@include std.mem -> Memory, arena
@include std.file

smo file_stats(nom, u64 lines, u64 chars) 
    -> @struct

smo print(file_stats stats)
    printin(stats.lines)
    printin(" lines, ")
    printin(stats.chars)
    print(" bytes")
    --

smo file_reader(String path, Memory &memory)
    &stat_lines = 0
    &stat_chars = 0
    &file = ReadFile:open(path)
    endl = "\n":str.first
    on memory:arena(1024)
        file
        :while next_line(str &line)
            printin("| ")
            print(line)
            stat_lines = stat_lines + 1
            stat_chars = stat_chars + line:len
        ----
    -> nom:file_stats(stat_lines, stat_chars)

service main()
    &memory = Stack:arena(1048576) // 1MB
    stats = file_reader("README.md", memory)
    print(stats)
    --