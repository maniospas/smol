#include <iostream>
#include <vector>
#include <chrono>
#include <cstdint>

// Simple dot product for std::vector<double>
double dot(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    std::size_t size = a.size();
    for (std::size_t i = 0; i < size; ++i) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    std::uint64_t n = 100000;
    std::vector<double> x1(n, 0.0);
    std::vector<double> x2(n, 0.0);

    x1[0] = 1.0;
    x2[0] = 1.0;

    auto tic = std::chrono::high_resolution_clock::now();
    double z = dot(x1, x2);
    auto toc = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = toc - tic;

    std::cout << elapsed.count() << " seconds" << std::endl;
    std::cout << z << std::endl;

    return 0;
}
