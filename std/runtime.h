#include <stdio.h>
#include <stdlib.h>

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
void init_task_queue(TaskQueue *queue) {
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
void* __smolambda_add_task(void (*func)(void *), void *arg) {
    Task *task = (Task*)malloc(sizeof(Task));
    if (!task) return NULL;
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

/* ---------------- WAIT FOR TASK COMPLETION ---------------- */
void __smolambda_task_wait(void *task_ptr) {
    Task *task = (Task*)task_ptr;
    if (!task) return;
#ifdef _WIN32
    EnterCriticalSection(&task->wait_mutex);
    while (!task->completed) {
        SleepConditionVariableCS(&task->wait_cond, &task->wait_mutex, INFINITE);
    }
    LeaveCriticalSection(&task->wait_mutex);
#else
    pthread_mutex_lock(&task->wait_mutex);
    while (!task->completed) {
        pthread_cond_wait(&task->wait_cond, &task->wait_mutex);
    }
    pthread_mutex_unlock(&task->wait_mutex);
#endif
}

/* ---------------- DESTROY TASK ---------------- */
void __smolambda_task_destroy(void *task_ptr) {
    Task *task = (Task*)task_ptr;
    if (!task) return;
#ifdef _WIN32
    DeleteCriticalSection(&task->wait_mutex);
#else
    pthread_mutex_destroy(&task->wait_mutex);
    pthread_cond_destroy(&task->wait_cond);
#endif
    free(task);
}

/* ---------------- GET TASK ---------------- */
Task* __smolambda_get_task() {
    Task *task = NULL;
#ifdef _WIN32
    EnterCriticalSection(&task_queue.mutex);
    while (!task_queue.head && !task_queue.stop) {
        SleepConditionVariableCS(&task_queue.cond, &task_queue.mutex, INFINITE);
    }
    if (task_queue.stop) {
        LeaveCriticalSection(&task_queue.mutex);
        return NULL;
    }
    task = task_queue.head;
    if (task) task_queue.head = task->next;
    LeaveCriticalSection(&task_queue.mutex);
#else
    pthread_mutex_lock(&task_queue.mutex);
    while (!task_queue.head && !task_queue.stop) {
        pthread_cond_wait(&task_queue.cond, &task_queue.mutex);
    }
    if (task_queue.stop) {
        pthread_mutex_unlock(&task_queue.mutex);
        return NULL;
    }
    task = task_queue.head;
    if (task) task_queue.head = task->next;
    pthread_mutex_unlock(&task_queue.mutex);
#endif
    return task;
}

/* ---------------- STOP ALL THREADS ---------------- */
void __smolambda_stop_all_threads() {
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
void* __smolambda_worker_thread(void *arg)
#endif
{
    (void)arg;
    for (;;) {
        Task *task = __smolambda_get_task();
        if (!task) break;
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

/* ---------------- START SERVICE WITH EXAMPLE ---------------- */
int __smolambda_initialize_service_tasks(void (*initial_func)(void *), void *initial_arg) {
    int num_threads = __smolambda_get_core_count();
    printf("Number of threads: %d\n", num_threads);
    init_task_queue(&task_queue);

    /* Create worker threads */
#ifdef _WIN32
    HANDLE *threads = (HANDLE*)malloc(sizeof(HANDLE) * num_threads);
    for (int i = 0; i < num_threads; i++)
        threads[i] = CreateThread(NULL, 0, worker_thread, NULL, 0, NULL);
#else
    pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t) * num_threads);
    for (int i = 0; i < num_threads; i++)
        pthread_create(&threads[i], NULL, __smolambda_worker_thread, NULL);
#endif

    /* Add initial task and wait for it */
    void *t = NULL;
    if (initial_func) {
        t = __smolambda_add_task(initial_func, initial_arg);
        __smolambda_task_wait(t);
        __smolambda_task_destroy(t);
    }

    /* Stop and join */
    __smolambda_stop_all_threads();
#ifdef _WIN32
    for (int i = 0; i < num_threads; i++) {
        WaitForSingleObject(threads[i], INFINITE);
        CloseHandle(threads[i]);
    }
    free(threads);
    DeleteCriticalSection(&task_queue.mutex);
#else
    for (int i = 0; i < num_threads; i++) pthread_join(threads[i], NULL);
    free(threads);
    pthread_mutex_destroy(&task_queue.mutex);
    pthread_cond_destroy(&task_queue.cond);
#endif
    return 0;
}

