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

@unsafe
@about "Standard library wrapping of C time using POSIX clock_gettime."

smo time()
    @head{#include <time.h>}
    @head{

        static struct timespec __smo_time_start;
        static int __smo_time_initialized = 0;

        static double __smo_time_eta() {
            if (!__smo_time_initialized) {
                clock_gettime(CLOCK_MONOTONIC, &__smo_time_start);
                __smo_time_initialized = 1;
                return 0.0;
            }
            struct timespec now;
            clock_gettime(CLOCK_MONOTONIC, &now);
            return (now.tv_sec - __smo_time_start.tv_sec) +
                   (now.tv_nsec - __smo_time_start.tv_nsec) / 1000000000.0;
        }
    }
    @body{f64 elapsed = __smo_time_eta();}
    -> elapsed
