// ----------------------- RUNTIME ------------------------------------------
// Runtimes are used during the compilation of smoλ programs.
// They contain implementations of system-specific memory allocations,
// and of runtime co-routines. Its goal is to make the language future-proof
// by allowing modifications to allow compilation for systems with different
// memory management capabilities (e.g., where memory management should take
// place over a static buffer) or threading infrastructure.
//
// Calls to the following functions are hard-coded to the language and
// standard library, so you should NOT change their name or signature:
// - __runtime_alloc
// - __runtime_realloc
// - __runtime_free
// - __smolambda_add_task
// - __smolambda_initialize_service_tasks
// - __smolambda_task_wait
// - __smolambda_task_sleep
// - __smolambda_task_destroy
// - __runtime_apply_linked

// ----------------------- ABOUT ------------------------------------------
// This is the default runtime that automatically switches between threads 
// (where services are co-routines) and eager execution. This kind of
// switching is particularly useful when compiling simple programs with 
// `--task assemble`, in which case users are (or are expected to be) more
// interested in seeing the assembly of their instructions rather than
// the overhead of the threaded runtime.
//
// Switching between runtimes is done by checking the value of 
// SMOLAMBDA_SERVICES, which is defined by the language to reflect the number
// of implemented services. There is always at least one main service.

// ----------------------- LICENSE ------------------------------------------
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


#if SMOLAMBDA_SERVICES > 1
#define SMOLAMBDA_RUNTIME_MESSAGE(num_threads) printf("smoλ - https://github.com/maniospas/smol\nThreads: %d\n", num_threads);
#include "threads.h"
#else
#define SMOLAMBDA_RUNTIME_MESSAGE(num_threads) printf("smoλ - https://github.com/maniospas/smol\nSingle threaded mode\n");
#include "eager.h"
#endif