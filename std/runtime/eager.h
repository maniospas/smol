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
// This runtime eagerly executes runtype (that is, def function) calls
// using a single thread. You can explicitly set it by compiling
//     smol main.s --runtime eager

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

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <time.h>
#endif

/* ---------------- TASK STRUCT ---------------- */
static inline void* __runtime_alloc(size_t size) {return malloc(size);}
static inline void* __runtime_calloc(size_t size) {return calloc(1, size);}
static inline void* __runtime_realloc(void* mem, size_t size, size_t prev_sze) {return realloc(mem, size);}
static inline void __runtime_free(void* mem) {free(mem);}

/* ---------------- TASK STRUCT ---------------- */

typedef struct __SmolambdaLinkedMemory {
    void *contents;
    struct __SmolambdaLinkedMemory* next;
} __SmolambdaLinkedMemory;

static inline __SmolambdaLinkedMemory* __runtime_prepend_linked(__SmolambdaLinkedMemory* memory, void* contents) {
    __SmolambdaLinkedMemory* mem = (__SmolambdaLinkedMemory*)__runtime_alloc(sizeof(__SmolambdaLinkedMemory));
    mem->next = memory;
    mem->contents = contents;
    return mem;
}

static inline void __runtime_apply_linked(__SmolambdaLinkedMemory* memory, void (*func)(void *), int is_destructor) {
    while (memory) {
        if (memory->contents)
            func(memory->contents);
        __SmolambdaLinkedMemory* next = memory->next;
        if (is_destructor)
            __runtime_free(memory);
        memory = next;
    }
}


static inline void* __smolambda_add_task(void (*func)(void *), void *arg) {func(arg);return 0;}

static inline void __smolambda_task_wait(void *task_ptr) {}

/* ---------------- TASK SLEEP ---------------- */
static inline void __smolambda_task_sleep(double secs) {
    if (secs <= 0.0) return;
#ifdef _WIN32
    DWORD ms = (DWORD)(secs * 1000.0);
    if (ms > 0) Sleep(ms);
#else
    struct timespec ts;
    ts.tv_sec = (time_t)secs;
    ts.tv_nsec = (long)((secs - ts.tv_sec) * 1e9);
    if (ts.tv_sec > 0 || ts.tv_nsec > 0)
        nanosleep(&ts, NULL);
#endif
}

#ifndef SMOLAMBDA_RUNTIME_MESSAGE
#define SMOLAMBDA_RUNTIME_MESSAGE(num_threads)
#endif 

static inline void __smolambda_task_destroy(void *task_ptr) {}
static inline int __smolambda_initialize_service_tasks(void (*initial_func)(void *), void *initial_arg) {
    SMOLAMBDA_RUNTIME_MESSAGE(num_threads)
    void* t = __smolambda_add_task(initial_func, initial_arg);
    __smolambda_task_wait(t);
    __smolambda_task_destroy(t);
    //printf("exit code %d", ((int*)initial_arg)[0]);
    return 0;
}

