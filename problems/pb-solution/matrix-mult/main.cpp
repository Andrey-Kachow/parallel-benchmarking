#include "SequentialMatMult.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include "RowPartitionMatMult.h"
#include "matrix.h"

void matrix_benchmark(std::function<void(double*, double*, double*, int)> algorithm,
                      const std::vector<int>& problem_sizes)
{
    for (const int& N : problem_sizes)
    {
        auto m1 = generate_matrix(N);
        auto m2 = generate_matrix(N);
        auto m3 = generate_matrix(N, true);

        auto start = std::chrono::high_resolution_clock::now();

        algorithm(m1, m2, m3, N);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << "Time for problem size " << N << ": " << duration.count() << " ms"
                  << std::endl;

        kill_matrix(m1);
        kill_matrix(m2);
        kill_matrix(m3);
    }
}

int main()
{
    //std::vector<int> problem_sizes = {10, 50, 100, 500, 1000, 1500};
    //matrix_benchmark(RowPartitionMatMult::compute, problem_sizes);
    //matrix_benchmark(SequentialMatMult::forikj, problem_sizes);
    //matrix_benchmark(SequentialMatMult::naive, problem_sizes);

    return 0;
}