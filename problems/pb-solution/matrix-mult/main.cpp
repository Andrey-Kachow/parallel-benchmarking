#include "SequentialMatMult.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include "RowPartitionMatMult.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> float_dist(-100.0, 100.0);

double* generate_matrix(int N, bool zero = false)
{
    auto m = new double[N * N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (zero)
            {
                m[i * N + j] = 0.0;
            }
            else
            {
                m[i * N + j] = float_dist(gen);
            }
        }
    }

    return m;
}

void kill_matrix(double* m)
{
    delete m;
}

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
    std::vector<int> problem_sizes = {10, 50, 100, 500, 1000, 1500};

    matrix_benchmark(RowPartitionMatMult::compute, problem_sizes);
    matrix_benchmark(SequentialMatMult::forikj, problem_sizes);
    matrix_benchmark(SequentialMatMult::naive, problem_sizes);

    return 0;
}