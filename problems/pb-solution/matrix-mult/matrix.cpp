#include "matrix.hpp"
#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> float_dist(-100.0, 100.0);

std::unique_ptr<std::vector<double>> generate_matrix(int N, bool zero)
{
    auto m = std::make_unique<std::vector<double>>(N * N, 0.0);
    if (!zero)
    {
        for (int i = 0; i < N * N; i++)
        {
            (*m)[i] = float_dist(gen);
        }
    }

    return m;
}

void print_matrix(std::vector<double>& m, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        std::cout << '|';
        for (size_t j = 0; j < N; j++)
        {
            std::cout << '\t' << m[i * N + j];
        }
        std::cout << "\t|\n";
    }
}
