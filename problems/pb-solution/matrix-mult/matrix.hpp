#pragma once
#include <memory>
#include <functional>
#include <vector>

std::unique_ptr<std::vector<double>> generate_matrix(int N, bool zero = false);

void print_matrix(std::vector<double>& m, int N);

using MatrixMultAlg = std::function<void(std::vector<double>&, std::vector<double>&, std::vector<double>&, int)>;