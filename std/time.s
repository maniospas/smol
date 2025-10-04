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
@include std.core.err

@unsafe
@about "Standard library wrapping of C time (provided by posix time.h or windows.h)."
@about time  "Retrieve time elapsed from the start of the program in f64 seconds."
@about sleep "Make the current service wait for AT LEAST a number of f64 seconds."
             "\n\nWhile yielding, other services may be called asynchronously to fill in "
             "the missing time. There is no guarantee for this, though. "
             "Sleeping for 0.0 duration does not incur delays, but may still run "
             "other services. Negative durations skip over this. Use exact_slepp "
             "to sleep without yielding and thus get a guarantee on the sleep "
             "duration. This method's exact implementation is ported from the runtime."
             "\n\nExample: <pre>sleep(1.0) // yields for at least 1 sec</pre> "
@about exact_sleep "Make the current service wait for exactly a specified number "
             "of f64 seconds. Control flow is not transferred to other services, "
             "so use sparingly (e.g., in main game loops)."
             "\n\nExample: <pre>sleep(1.0) // waits for 1 sec of inactivity</pre> "

// time.h or windows.h imported by all runtimes

def sleep(f64 duration)
    @body{__smolambda_task_sleep(duration);}
    end

def exact_sleep(f64 duration)
    if duration<=0.0
        return nothing
    @head{#include "std/oscommon.h"}
    @body{__smo_exact_sleep(duration);}
    end

def time()
    @head{#include "std/oscommon.h"}
    @body{f64 elapsed = __smo_time_eta();}
    return elapsed
