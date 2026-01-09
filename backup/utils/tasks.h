#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <stdexcept>
#include "../def.h"

enum class Task {
    Assemble,
    Transpile,
    Compile,
    Verify,
    Run,
    Library
};
Task parse_task(const string& arg);

#endif // TASKS_H