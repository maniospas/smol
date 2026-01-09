#include "tasks.h"

Task parse_task(const string& arg) {
    if(arg == "compile") 
        return Task::Compile;
    if(arg == "verify") 
        return Task::Verify;
    if(arg == "doc") {
        Def::export_docs=true; 
        return Task::Verify;
    }
    if(arg == "lsp") {
        Def::lsp=true; 
        return Task::Verify;
    }
    if(arg == "run") 
        return Task::Run;
    if(arg == "assemble") 
        return Task::Assemble;
    if(arg == "transpile") 
        return Task::Transpile;
    if(arg == "lib") 
        return Task::Library;
    throw invalid_argument("Unknown task: " + arg+" is not one of --run, --assemble, --transpile, --lib, --lsp, --verify, --doc");
}