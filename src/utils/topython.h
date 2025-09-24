#ifndef TOPYTHON_H
#define TOPYTHON_H

#include "../def.h"
#include <string>

using namespace std;

string to_ctypes(const Type t);
string to_python_type(const Type t);

#endif // TOPYTHON_H