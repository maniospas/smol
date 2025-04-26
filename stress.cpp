#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <string>
#include <vector>
#include <chrono>
#include <filesystem>

void generate_code(const std::string& filename, int n) {
    std::ofstream ofs(filename);

    if (!ofs.is_open()) {
        std::cerr << "Failed to open file for writing!" << std::endl;
        std::exit(1);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> type_dis(0, 1);
    std::uniform_int_distribution<> op_dis(0, 1);
    std::uniform_real_distribution<> real_dis(0.0, 1000.0);
    std::uniform_int_distribution<int64_t> int_dis(0, 1000000);

    ofs << "#include <iostream>\n#include <cstdint>\nusing namespace std;\n\n";
    ofs << "int main() {\n";

    for (int i = 0; i < n; ++i) {
        if (type_dis(gen) == 0) {
            ofs << "    int64_t var" << i << " = " << int_dis(gen) << ";\n";
        } else {
            ofs << "    double var" << i << " = " << real_dis(gen) << ";\n";
        }
    }

    for (int i = 1; i < n; ++i) {
        int idx = gen() % i;
        if (op_dis(gen) == 0)
            ofs << "    var" << i << " = var" << i << " + var" << idx << ";\n";
        else
            ofs << "    var" << i << " = var" << i << " * var" << idx << ";\n";
    }

    ofs << "    cout << var" << (n-1) << " << endl;\n";
    ofs << "    return 0;\n";
    ofs << "}\n";

    ofs.close();
}

auto measure_and_run(const std::string& command) {
    auto start = std::chrono::high_resolution_clock::now();
    int ret = std::system((command + " > /dev/null").c_str());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return std::make_pair(ret, elapsed.count());
}

std::pair<int, double> compile_and_measure(const std::string& compile_command, const std::string& output_log) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string full_command = "/usr/bin/time -v " + compile_command + " > /dev/null 2> " + output_log;
    int ret = std::system(full_command.c_str());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return {ret, elapsed.count()};
}

int main() {
    const int n = 100000;
    const std::string filename = "main_stress.cpp";
    std::cout << "Generating file...\n";
    generate_code(filename, n);

    std::cout << "Compiling (-O0)... "<<std::flush;
    auto [ret_compile0, time_compile0] = compile_and_measure("g++ main_stress.cpp -o main_stress_O0", "compile_O0.txt");
    std::cout << time_compile0 << " seconds\n";

    std::cout << "Compiling (-O3)... "<<std::flush;
    auto [ret_compile3, time_compile3] = compile_and_measure("g++ main_stress.cpp -o main_stress_O3 -O3", "compile_O3.txt");
    std::cout << time_compile3 << " seconds\n";

    std::cout << "Running (-O0)... ";
    auto [ret0, time0] = measure_and_run("./main_stress_O0");
    if (ret0 != 0) {
        std::cerr << "Execution failed (O0)!" << std::endl;
    } else {
        std::cout << time0 << " seconds\n";
    }

    std::cout << "Running (-O3)... ";
    auto [ret3, time3] = measure_and_run("./main_stress_O3");
    if (ret3 != 0) {
        std::cerr << "Execution failed (O3)!" << std::endl;
    } else {
        std::cout << time3 << " seconds\n";
    }

    std::filesystem::remove("main_stress.cpp");
    std::filesystem::remove("main_stress_O0");
    std::filesystem::remove("main_stress_O3");
    std::filesystem::remove("compile_O0.txt");
    std::filesystem::remove("compile_O3.txt");

    std::cout << "All generated files have been removed.\n";

    return 0;
}
