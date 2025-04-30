#include <iostream>
#include <vector>
#include <stack>
#include <thread>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <atomic>

struct Task {
    void* (*function)(void*);
    void* input;
    void* output;
    std::mutex mtx;
    std::condition_variable cv;
    bool done;

    Task(void* (*func)(void*), void* in) : function(func), input(in), output(nullptr), done(false) {}
    Task() : function(nullptr), input(nullptr), output(nullptr), done(false) {}
};

class TaskManager {
public:
    TaskManager(size_t num_threads) : stop(false), active_tasks(0) {for (size_t i = 0; i < num_threads; ++i)workers.emplace_back(&TaskManager::workerThread, this);}
    ~TaskManager() {{std::lock_guard<std::mutex> lock(mtx);stop = true;} cv.notify_all(); for(auto& thread : workers) thread.join();}
    void addTask(Task* task) {{std::lock_guard<std::mutex> lock(mtx);tasks.push(task);active_tasks++;} cv.notify_one();}
    void waitAll() {std::unique_lock<std::mutex> lock(mtx);cv_done.wait(lock, [this](){return tasks.empty() && active_tasks == 0;});}
    void* getOutput(Task* task) {std::unique_lock<std::mutex> lock(task->mtx);while (!task->done) task->cv.wait(lock);return task->output;}

private:
    std::vector<std::thread> workers;
    std::stack<Task*> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    std::condition_variable cv_done;
    bool stop;
    int active_tasks;

    void workerThread() {
        while (true) {
            Task* task;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this](){ return stop || !tasks.empty(); });
                if (stop && tasks.empty()) return;
                task = tasks.top();
                tasks.pop();
            }
            void* result = task->function(task->input);
            {
                std::lock_guard<std::mutex> lock(task->mtx);
                task->output = result;
                task->done = true;
                task->cv.notify_all();
            }
            {
                std::lock_guard<std::mutex> lock(mtx);
                active_tasks--;
                if (tasks.empty() && active_tasks == 0) cv_done.notify_all();
            }
        }
    }
};

void* exampleFunc1(void* input) {int* val = static_cast<int*>(input);int* result = new int((*val) * 2);return static_cast<void*>(result);}
void* exampleFunc2(void* input) {int* val = static_cast<int*>(input);int* result = new int((*val) + 10);return static_cast<void*>(result);}

int main() {
    int cores = std::thread::hardware_concurrency();
    if(cores<=0) cores = 1;
    TaskManager manager(cores);
    std::cout << "Initializing for "<<cores<<" green threads\n";
    std::vector<std::unique_ptr<Task>> taskList;
    for (int i = 0; i < 1000000; ++i) {
        int* input = new int(i);
        void* (*func)(void*) = (i % 2 == 0) ? exampleFunc1 : exampleFunc2;
        taskList.push_back(std::make_unique<Task>(func, input));
    }
    for (auto& task : taskList) manager.addTask(task.get());
    for (auto& task : taskList) {
        int* output = static_cast<int*>(manager.getOutput(task.get()));
        if (output) {std::cout << "Result: " << *output << std::endl; delete output;}
        else {std::cout << "Task not computed yet." << std::endl;}
        delete static_cast<int*>(task->input);
    }
    return 0;
}
