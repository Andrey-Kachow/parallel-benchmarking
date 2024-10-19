#include "matrix.h"
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> float_dist(-100.0, 100.0);

double* generate_matrix(int N, bool zero)
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

void print_matrix(double* m, int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << '|';
        for (int j = 0; j < N; j++)
        {
            std::cout << '\t' << m[i * N + j];
        }
        std::cout << "\t|\n";
    }
}
