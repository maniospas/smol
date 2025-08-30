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

@include std.builtins.num
@include std.builtins.err

@unsafe
@about "Standard library wrapping of C time using POSIX clock_gettime."
@about time "Retrieve time elapsed from the start of the program in f64 seconds."
@about sleep "Make the current service wait for AT LEAST a number of f64 seconds. "
             "While yielding, other services may be called asynchronously to fill in "
             "the missing time. There is no guarantee for this, though. "
             "Sleeping for 0.0 duration does not incur delays, but may still run "
             "other services. Negative durations skip over this. Use exact_slepp "
             "to sleep without yield "
@about exact_sleep "Make the current service wait for exactly a specified number "
             "of f64 seconds. Control flow is not transferred to other services, "
             "so use sparingly (e.g., in main game loops)."

smo sleep(f64 duration)
    if duration<0.0 |--
    --

smo exact_sleep(f64 duration)
    if duration<0.0 |--
    --

smo time()
    // time.h imported by runtime
    @head{
        static struct timespec __smo_time_start;
        static int __smo_time_initialized = 0;
        double __smo_time_eta() {
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
