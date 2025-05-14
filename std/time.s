smo time()
    @head{#include <chrono>}
    @head{auto start = std::chrono::high_resolution_clock::now();}
    @body{f64 elapsed = std::chrono::duration<double> (std::chrono::high_resolution_clock::now() - start).count();}
    -> elapsed