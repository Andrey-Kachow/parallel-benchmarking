#pragma once
#include <thread>
#include <vector>
#include "matrix.hpp"
#include <iostream>

constexpr int num_threads = 5;

class RowPartitionMatMult
{
  public:
    static void compute(double* mA, double* mB, double* mC, int N)
    {
        std::vector<std::thread> threads;

        int strip_len = N / num_threads;
        for (int i = 0; i < num_threads; i++)
        {
            int limit = N;
            if (i != num_threads - 1)
            {
                limit = (i + 1) * strip_len;
            }
            threads.emplace_back(compute_part, mA, mB, mC, N, i * strip_len, limit);
        }

        for (auto& thread : threads)
        {
            thread.join();
        }
    }

  private:
    static void compute_part(double* mA, double* mB, double* mC, int N, int start_row, int end_row)
    {
        for (int i = start_row; i < end_row; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
                }
            }
        }
    }
};
