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
// This is the default runtime. You can explicitly set it by compiling
//     smol main.s --runtime threads

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
    while(memory) {
        if(memory->contents)
            func(memory->contents);
        __SmolambdaLinkedMemory* next = memory->next;
        if(is_destructor)
            __runtime_free(memory);
        memory = next;
    }
}

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#endif

/* ---------------- TASK STRUCT ---------------- */
typedef struct Task {
    void (*func)(void *arg);
    void *arg;
    struct Task *next;
    int completed;
#ifdef _WIN32
    CRITICAL_SECTION wait_mutex;
    CONDITION_VARIABLE wait_cond;
#else
    pthread_mutex_t wait_mutex;
    pthread_cond_t wait_cond;
#endif
} Task;

/* ---------------- TASK QUEUE ---------------- */
typedef struct {
    Task *head;
#ifdef _WIN32
    CRITICAL_SECTION mutex;
    CONDITION_VARIABLE cond;
#else
    pthread_mutex_t mutex;
    pthread_cond_t cond;
#endif
    int stop; /* Used to signal threads to exit */
} TaskQueue;

TaskQueue task_queue;

/* ---------------- INIT FUNCTION ---------------- */
static inline void __smolambda_init_task_queue(TaskQueue *queue) {
    queue->head = NULL;
    queue->stop = 0;
#ifdef _WIN32
    InitializeCriticalSection(&queue->mutex);
    InitializeConditionVariable(&queue->cond);
#else
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
#endif
}

/* ---------------- ADD TASK (returns void*) ---------------- */
static inline void* __smolambda_add_task(void (*func)(void *), void *arg) {
    Task *task = (Task*)__runtime_alloc(sizeof(Task));
    if(!task) return NULL;
    task->func = func;
    task->arg = arg;
    task->next = NULL;
    task->completed = 0;
#ifdef _WIN32
    InitializeCriticalSection(&task->wait_mutex);
    InitializeConditionVariable(&task->wait_cond);
#else
    pthread_mutex_init(&task->wait_mutex, NULL);
    pthread_cond_init(&task->wait_cond, NULL);
#endif

#ifdef _WIN32
    EnterCriticalSection(&task_queue.mutex);
    task->next = task_queue.head;
    task_queue.head = task;
    WakeConditionVariable(&task_queue.cond);
    LeaveCriticalSection(&task_queue.mutex);
#else
    pthread_mutex_lock(&task_queue.mutex);
    task->next = task_queue.head;
    task_queue.head = task;
    pthread_cond_signal(&task_queue.cond);
    pthread_mutex_unlock(&task_queue.mutex);
#endif
    return (void*)task;
}

/* ---------------- TRY GET TASK (non-blocking) ---------------- */
static inline Task* __smolambda_try_get_task() {
    Task *task = NULL;
#ifdef _WIN32
    if(!TryEnterCriticalSection(&task_queue.mutex)) {
        return NULL; /* someone else has the lock */
    }
    if(task_queue.head) {
        task = task_queue.head;
        task_queue.head = task->next;
    }
    LeaveCriticalSection(&task_queue.mutex);
#else
    if(pthread_mutex_trylock(&task_queue.mutex) != 0) {
        return NULL; /* lock busy */
    }
    if(task_queue.head) {
        task = task_queue.head;
        task_queue.head = task->next;
    }
    pthread_mutex_unlock(&task_queue.mutex);
#endif
    return task;
}


/* ---------------- WAIT FOR TASK COMPLETION ---------------- */
static inline void __smolambda_task_wait(void *task_ptr) {
    Task *target = (Task*)task_ptr;
    if(!target) return;

    for(;;) {
        /* Fast path: check completion */
#ifdef _WIN32
        EnterCriticalSection(&target->wait_mutex);
        int done = target->completed;
        LeaveCriticalSection(&target->wait_mutex);
#else
        pthread_mutex_lock(&target->wait_mutex);
        int done = target->completed;
        pthread_mutex_unlock(&target->wait_mutex);
#endif
        if(done) break;

        /* Help: run one available task */
        Task *task = __smolambda_try_get_task();
        if(task) {
            task->func(task->arg);

            /* Signal completion of the task we just ran */
#ifdef _WIN32
            EnterCriticalSection(&task->wait_mutex);
            task->completed = 1;
            WakeAllConditionVariable(&task->wait_cond);
            LeaveCriticalSection(&task->wait_mutex);
#else
            pthread_mutex_lock(&task->wait_mutex);
            task->completed = 1;
            pthread_cond_broadcast(&task->wait_cond);
            pthread_mutex_unlock(&task->wait_mutex);
#endif
            /* If that task was the one we're waiting for, next loop will see done */
            continue;
        }

        /* Nothing to help with; do a short timed wait on the target to avoid spinning */
#ifdef _WIN32
        EnterCriticalSection(&target->wait_mutex);
        if(!target->completed) {
            /* ~1 ms; adjust as desired */
            SleepConditionVariableCS(&target->wait_cond, &target->wait_mutex, 1);
        }
        LeaveCriticalSection(&target->wait_mutex);
#else
        pthread_mutex_lock(&target->wait_mutex);
        if(!target->completed) {
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            ts.tv_nsec += 50000000; // +50ms
            if(ts.tv_nsec >= 1000000000L) {
                ts.tv_sec += 1;
                ts.tv_nsec -= 1000000000L;
            }
            pthread_cond_timedwait(&target->wait_cond, &target->wait_mutex, &ts);
        }
        pthread_mutex_unlock(&target->wait_mutex);
#endif
    }
}

/* ---------------- TASK SLEEP ---------------- */
static inline void __smolambda_task_sleep(double secs) {
    if(secs < 0.0) return;
    if(secs == 0.0) {
        Task *task = __smolambda_try_get_task();
        if(task) {
            task->func(task->arg);
#ifdef _WIN32
            EnterCriticalSection(&task->wait_mutex);
            task->completed = 1;
            WakeAllConditionVariable(&task->wait_cond);
            LeaveCriticalSection(&task->wait_mutex);
#else
            pthread_mutex_lock(&task->wait_mutex);
            task->completed = 1;
            pthread_cond_broadcast(&task->wait_cond);
            pthread_mutex_unlock(&task->wait_mutex);
#endif
        }
        return;
    }

    /* Compute deadline */
#ifdef _WIN32
    LARGE_INTEGER freq, start, now;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    double deadline = (double)start.QuadPart / (double)freq.QuadPart + secs;
#else
    struct timespec start, now;
    clock_gettime(CLOCK_MONOTONIC, &start);
    double deadline = start.tv_sec + start.tv_nsec / 1e9 + secs;
#endif

    for(;;) {
        /* Check if deadline passed */
#ifdef _WIN32
        QueryPerformanceCounter(&now);
        double current = (double)now.QuadPart / (double)freq.QuadPart;
#else
        clock_gettime(CLOCK_MONOTONIC, &now);
        double current = now.tv_sec + now.tv_nsec / 1e9;
#endif
        if(current >= deadline) break;

        /* Run a pending task if any */
        Task *task = __smolambda_try_get_task();
        if(task) {
            task->func(task->arg);
#ifdef _WIN32
            EnterCriticalSection(&task->wait_mutex);
            task->completed = 1;
            WakeAllConditionVariable(&task->wait_cond);
            LeaveCriticalSection(&task->wait_mutex);
#else
            pthread_mutex_lock(&task->wait_mutex);
            task->completed = 1;
            pthread_cond_broadcast(&task->wait_cond);
            pthread_mutex_unlock(&task->wait_mutex);
#endif
            continue;
        }

        /* Nothing to run, so short sleep to avoid busy spinning */
#ifdef _WIN32
        Sleep(1); /* ~1 ms granularity */
#else
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 1000000L; /* 1 ms */
        nanosleep(&ts, NULL);
#endif
    }
}



/* ---------------- DESTROY TASK ---------------- */
static inline void __smolambda_task_destroy(void *task_ptr) {
    Task *task = (Task*)task_ptr;
    if(!task) return;
#ifdef _WIN32
    DeleteCriticalSection(&task->wait_mutex);
#else
    pthread_mutex_destroy(&task->wait_mutex);
    pthread_cond_destroy(&task->wait_cond);
#endif
    __runtime_free(task);
}

/* ---------------- GET TASK ---------------- */
Task* __smolambda_get_task() {
    Task *task = NULL;
#ifdef _WIN32
    EnterCriticalSection(&task_queue.mutex);
    while(!task_queue.head && !task_queue.stop) {
        SleepConditionVariableCS(&task_queue.cond, &task_queue.mutex, INFINITE);
    }
    if(task_queue.stop) {
        LeaveCriticalSection(&task_queue.mutex);
        return NULL;
    }
    task = task_queue.head;
    if(task) task_queue.head = task->next;
    LeaveCriticalSection(&task_queue.mutex);
#else
    pthread_mutex_lock(&task_queue.mutex);
    while(!task_queue.head && !task_queue.stop) {
        pthread_cond_wait(&task_queue.cond, &task_queue.mutex);
    }
    if(task_queue.stop) {
        pthread_mutex_unlock(&task_queue.mutex);
        return NULL;
    }
    task = task_queue.head;
    if(task) task_queue.head = task->next;
    pthread_mutex_unlock(&task_queue.mutex);
#endif
    return task;
}

/* ---------------- STOP ALL THREADS ---------------- */
static inline void __smolambda_stop_all_threads() {
#ifdef _WIN32
    EnterCriticalSection(&task_queue.mutex);
    task_queue.stop = 1;
    WakeAllConditionVariable(&task_queue.cond);
    LeaveCriticalSection(&task_queue.mutex);
#else
    pthread_mutex_lock(&task_queue.mutex);
    task_queue.stop = 1;
    pthread_cond_broadcast(&task_queue.cond);
    pthread_mutex_unlock(&task_queue.mutex);
#endif
}

/* ---------------- WORKER FUNCTION ---------------- */
#ifdef _WIN32
DWORD WINAPI worker_thread(LPVOID arg)
#else
static inline void* __smolambda_worker_thread(void *arg)
#endif
{
    (void)arg;
    for(;;) {
        Task *task = __smolambda_get_task();
        if(!task) break;
        task->func(task->arg);

        /* Signal completion */
#ifdef _WIN32
        EnterCriticalSection(&task->wait_mutex);
        task->completed = 1;
        WakeAllConditionVariable(&task->wait_cond);
        LeaveCriticalSection(&task->wait_mutex);
#else
        pthread_mutex_lock(&task->wait_mutex);
        task->completed = 1;
        pthread_cond_broadcast(&task->wait_cond);
        pthread_mutex_unlock(&task->wait_mutex);
#endif
    }
    return 0;
}

/* ---------------- GET CORE COUNT ---------------- */
int __smolambda_get_core_count() {
#ifdef _WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return (int)sysinfo.dwNumberOfProcessors;
#else
    return (int)sysconf(_SC_NPROCESSORS_ONLN);
#endif
}


#ifndef SMOLAMBDA_RUNTIME_MESSAGE
#define SMOLAMBDA_RUNTIME_MESSAGE(num_threads)
#endif 

/* ---------------- START SERVICE WITH EXAMPLE ---------------- */
static inline int __smolambda_initialize_service_tasks(void (*initial_func)(void *), void *initial_arg) {
    int num_threads = __smolambda_get_core_count();
    SMOLAMBDA_RUNTIME_MESSAGE(num_threads)
    __smolambda_init_task_queue(&task_queue);

    /* Create worker threads */
#ifdef _WIN32
    HANDLE *threads = (HANDLE*)__runtime_alloc(sizeof(HANDLE) * num_threads);
    for(int i = 0; i < num_threads; i++)
        threads[i] = CreateThread(NULL, 0, worker_thread, NULL, 0, NULL);
#else
    pthread_t *threads = (pthread_t*)__runtime_alloc(sizeof(pthread_t) * num_threads);
    for(int i = 0; i < num_threads; i++)
        pthread_create(&threads[i], NULL, __smolambda_worker_thread, NULL);
#endif

    /* Add initial task and wait for it */
    void *t = NULL;
    if(initial_func) {
        t = __smolambda_add_task(initial_func, initial_arg);
        __smolambda_task_wait(t);
        __smolambda_task_destroy(t);
    }

    /* Stop and join */
    __smolambda_stop_all_threads();
#ifdef _WIN32
    for(int i = 0; i < num_threads; i++) {
        WaitForSingleObject(threads[i], INFINITE);
        CloseHandle(threads[i]);
    }
    __runtime_free(threads);
    DeleteCriticalSection(&task_queue.mutex);
#else
    for(int i = 0; i < num_threads; i++) pthread_join(threads[i], NULL);
    __runtime_free(threads);
    pthread_mutex_destroy(&task_queue.mutex);
    pthread_cond_destroy(&task_queue.cond);
#endif
    return 0;
}

