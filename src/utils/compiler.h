// Copyright 2025 Emmanouil Krasanakis (maniospas@hotmail.com)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef SMOL_COMPILER_H
#define SMOL_COMPILER_H

#include <regex>
#include <map>
#include <sstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <filesystem>

using namespace std;

#if defined(_WIN32) || defined(_WIN64)
#define SMOL_POPEN _popen
#define SMOL_PCLOSE _pclose
#else
#define SMOL_POPEN popen
#define SMOL_PCLOSE pclose
#endif
#ifdef _WIN32
    #define EXEC_EXT ".exe"
    #define EXEC_PREFIX ".\\"
#else
    #define EXEC_EXT ""
    #define EXEC_PREFIX "./"
#endif


extern string compiler; // compiler name
extern string linker;   // linker flags
extern string runtime;  // runtime name or path

// Returns 0 on success, or nonzero (compiler exit code or error).
int compile_from_stringstream_with_flags(
    std::stringstream& out,
    const std::string& output_file,
    const std::string& extra_flags 
);


#endif // SMOL_COMPILER_H