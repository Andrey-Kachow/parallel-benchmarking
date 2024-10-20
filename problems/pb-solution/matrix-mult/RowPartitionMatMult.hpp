#pragma once
#include "matrix.hpp"
#include <iostream>
#include <thread>
#include <vector>

constexpr int num_threads = 5;

class RowPartitionMatMult
{
  public:
    static void compute(std::vector<double>& mA, std::vector<double>& mB, std::vector<double>& mC,
                        int N)
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
            threads.emplace_back(compute_part, std::ref(mA), std::ref(mB), std::ref(mC), N, i * strip_len, limit);
        }

        for (auto& thread : threads)
        {
            thread.join();
        }
    }

  private:
    static void compute_part(std::vector<double>& mA, std::vector<double>& mB,
                             std::vector<double>& mC, int N, int start_row, int end_row)
    {
        for (size_t i = start_row; i < end_row; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                for (size_t k = 0; k < N; k++)
                {
                    mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
                }
            }
        }
    }
};
