#ifndef SMOLAMBDA_COMMON_OS_H
#define SMOLAMBDA_COMMON_OS_H

#if defined(_WIN32) || defined(_WIN64)
    static inline FILE* fmemopen(void *buf, size_t size, const char *mode) {
        FILE *f = tmpfile();
        if(!f) 
            return NULL;
        return f;
    }
#endif

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <time.h>

    static void __smo_exact_sleep(double duration) {
        unsigned long ms = (unsigned long)(duration * 1000.0);
        if(ms) Sleep(ms);
    }

    static LARGE_INTEGER __smo_time_freq, __smo_time_start;
    static int __smo_time_initialized = 0;

    static double __smo_time_eta(void) {
        if(!__smo_time_initialized) {
            QueryPerformanceFrequency(&__smo_time_freq);
            QueryPerformanceCounter(&__smo_time_start);
            __smo_time_initialized = 1;
            return 0.0;
        }
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (double)(now.QuadPart - __smo_time_start.QuadPart) /
               (double)__smo_time_freq.QuadPart;
    }

#else
    #include <time.h>
    #include <unistd.h>

    static void __smo_exact_sleep(double duration) {
        struct timespec ts;
        ts.tv_sec = (time_t)duration;
        ts.tv_nsec = (long)((duration - ts.tv_sec) * 1000000000ULL);
        if(ts.tv_sec > 0 || ts.tv_nsec > 0)
            nanosleep(&ts, NULL);
    }

    static struct timespec __smo_time_start;
    static int __smo_time_initialized = 0;

    static double __smo_time_eta(void) {
        if(!__smo_time_initialized) {
            clock_gettime(CLOCK_MONOTONIC, &__smo_time_start);
            __smo_time_initialized = 1;
            return 0.0;
        }
        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);
        return (now.tv_sec - __smo_time_start.tv_sec) +
               (now.tv_nsec - __smo_time_start.tv_nsec) / 1e9;
    }

#endif

#include <stdio.h>      // FILE, fileno / _fileno
#include <stdint.h>     // uint64_t
#include <sys/types.h>  // struct stat / _stat64
#include <sys/stat.h>   // stat / fstat
#ifdef _WIN32
#include <io.h>         // _fileno, _fstat64
#else
#include <unistd.h>     // fileno, fstat
#endif
#include <stdint.h>

uint64_t __smo_file_size(FILE* fp) {
    if(!fp) return 0;
#if defined(_WIN32)
    struct _stat64 st;
    if(_fstat64(_fileno(fp), &st) == 0) {
        return (u64)st.st_size;
    }
#else
    struct stat st;
    if(fstat(fileno(fp), &st) == 0) 
        return (uint64_t)st.st_size;
#endif
    return 0;
}

#include <stdio.h>
#include <stdint.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>

    static inline int64_t __smo_next_key_press() {
        HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD record;
        DWORD readCount;
        int64_t code = -1;

        // Set console to raw mode
        DWORD mode;
        GetConsoleMode(hIn, &mode);
        DWORD rawMode = mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
        SetConsoleMode(hIn, rawMode);

        while (1) {
            if (!ReadConsoleInputW(hIn, &record, 1, &readCount))
                break;
            if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
                // Combine virtual key + scan code into one 64-bit value
                code = ((int64_t)record.Event.KeyEvent.wVirtualKeyCode << 16)
                     |  (int64_t)record.Event.KeyEvent.wVirtualScanCode;
                break;
            }
        }

        // Restore mode
        SetConsoleMode(hIn, mode);
        return code;
    }

#else
    #include <termios.h>
    #include <unistd.h>
    #include <string.h>

    static inline int64_t __smo_next_key_press() {
        //struct termios oldt, newt;
        unsigned char seq[8] = {0};
        int64_t code = 0;

        // Set terminal to raw mode
        // tcgetattr(STDIN_FILENO, &oldt);
        // newt = oldt;
        // newt.c_lflag &= ~(ICANON | ECHO);
        // tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // Read one byte
        ssize_t n = read(STDIN_FILENO, &seq[0], 1);

        // If ESC (start of special sequence)
        if (n > 0 && seq[0] == 27) {
            // Read rest of escape sequence
            ssize_t r1 = read(STDIN_FILENO, &seq[1], 1);
            ssize_t r2 = read(STDIN_FILENO, &seq[2], 1);
            (void)r1; (void)r2;
            // Combine the 3 bytes into a unique i64 code
            code = ((int64_t)seq[0] << 16) | ((int64_t)seq[1] << 8) | (int64_t)seq[2];
        } else if (n > 0) {
            // Normal ASCII key
            code = (int64_t)seq[0];
        }

        // Restore terminal
        //tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return code;
    }
#endif



#endif // SMOLAMBDA_COMMON_OS_H
