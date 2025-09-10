#ifndef SMOLAMBDA_COMMON_OS_H
#define SMOLAMBDA_COMMON_OS_H

#if defined(_WIN32) || defined(_WIN64)
    static inline FILE* fmemopen(void *buf, size_t size, const char *mode) {
        FILE *f = tmpfile();
        if (!f) 
            return NULL;
        return f;
    }
#endif

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <time.h>

    static void __smo_exact_sleep(double duration) {
        unsigned long ms = (unsigned long)(duration * 1000.0);
        if (ms) Sleep(ms);
    }

    static LARGE_INTEGER __smo_time_freq, __smo_time_start;
    static int __smo_time_initialized = 0;

    static double __smo_time_eta(void) {
        if (!__smo_time_initialized) {
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
        if (ts.tv_sec > 0 || ts.tv_nsec > 0)
            nanosleep(&ts, NULL);
    }

    static struct timespec __smo_time_start;
    static int __smo_time_initialized = 0;

    static double __smo_time_eta(void) {
        if (!__smo_time_initialized) {
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

#endif // SMOLAMBDA_COMMON_OS_H
