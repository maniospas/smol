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
// - __smolambda_task_destroy
// - __runtime_apply_linked

// ----------------------- ABOUT ------------------------------------------
// This runtime eagerly executes runtype (that is, smo function) calls
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
void* __runtime_alloc(size_t size) {return malloc(size);}
void* __runtime_calloc(size_t size) {return calloc(1, size);}
void* __runtime_realloc(void* mem, size_t size, size_t prev_sze) {return realloc(mem, size);}
void __runtime_free(void* mem) {free(mem);}

/* ---------------- TASK STRUCT ---------------- */
typedef struct __SmolambdaLinkedMemory {
    void *contents;
    struct __SmolambdaLinkedMemory* next;
} __SmolambdaLinkedMemory;

__SmolambdaLinkedMemory* __runtime_prepend_linked(__SmolambdaLinkedMemory* memory, void* contents) {
    __SmolambdaLinkedMemory* mem = (__SmolambdaLinkedMemory*)__runtime_alloc(sizeof(__SmolambdaLinkedMemory));
    mem->next = memory;
    mem->contents = contents;
    return mem;
}

void __runtime_apply_linked(__SmolambdaLinkedMemory* memory, void (*func)(void *), int is_destructor) {
    while(memory && memory->next) {
        if(memory->contents) func(memory->contents);
        __SmolambdaLinkedMemory* prev = memory;
        memory = memory->next;
        if(is_destructor) __runtime_free(prev);
    }
    if(memory && memory->contents) func(memory->contents);
    if(memory && is_destructor) __runtime_free(memory);
}


void* __smolambda_add_task(void (*func)(void *), void *arg) {func(arg);return nullptr;}

void __smolambda_task_wait(void *task_ptr) {}
void __smolambda_task_destroy(void *task_ptr) {}
int __smolambda_initialize_service_tasks(void (*initial_func)(void *), void *initial_arg) {
    printf("Compiler: smoλ (https://github.com/maniospas/smol)\n");
    printf("Threads: 1 (compiled in single threaded mode)\n");
    void* t = __smolambda_add_task(initial_func, initial_arg);
    __smolambda_task_wait(t);
    __smolambda_task_destroy(t);
    //printf("exit code %d", ((int*)initial_arg)[0]);
    return 0;
}

