#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

// Function to run a task and measure its real-time execution
template<typename Func>
void benchmark(Func&& myentrypoint, const std::vector<int>& problem_sizes)
{
    for (const int& N : problem_sizes)
    {
        // Record start time
        auto start = std::chrono::high_resolution_clock::now();

        // Start the function (assume myentrypoint will create and join threads internally)
        myentrypoint(N);

        // Record end time
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate duration in milliseconds
        std::chrono::duration<double, std::milli> duration = end - start;

        std::cout << "Time for problem size " << N << ": " << duration.count() << " ms"
                  << std::endl;
    }
}


int main()
{
    std::vector<int> problem_sizes = {10, 100, 1000, 100000};

    // Pass the function to benchmark and the problem sizes to test
    // benchmark(exampleTask, problem_sizes);

    return 0;
}