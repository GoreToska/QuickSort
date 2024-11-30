#include <iostream>
#include <random>

#include "Nanobench/Classes/nanobench.cpp"
#include "ClassicQuickSort.h"
#include "CustomArray/Classes/array.hpp"

const int N8 = 400;
int array8[N8];
std::random_device rd;
std::mt19937 mt1(rd());

void RandomArray(int* array, int N)
{
    for (int i = 0; i < N; ++i)
    {
        array[i] = mt1();
    }
}

/*void RandomArray(std::vector<int> array)
{
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (auto a = array.begin(); a < array.end(); ++a)
    {
        int i = 0;
        array[i] = mt1();
    }

    std::sort(array.begin(), array.end(), std::greater<>());
}*/

void run_warmup(int loops_count)
{
    for (int i = 0; i < loops_count; ++i)
    {
        RandomArray(array8, N8);
        sort::quick_sort_second_optimization(array8, array8 + N8 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array8, array8 + N8 - 1, sort::increase_int);
    }
}

void run_insertion_benchmark(int* array, int n, int loops_count = 100)
{
    auto elapsedSum = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - std::chrono::steady_clock::now());

    for (int i = 0; i < loops_count; ++i)
    {
        RandomArray(array, n);
        sort::quick_sort_second_optimization(array, array + n - 1, sort::decrease_int);

        auto start = std::chrono::steady_clock::now();
        sort::insertion_sort(array, array + n - 1, sort::increase_int);
        auto end = std::chrono::steady_clock::now();
        elapsedSum += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::cout << "Insertion" << "\t" << n << "\t" << elapsedSum.count() / loops_count << "\tmicro seconds\n";
}

void run_quick_benchmark(int* array, int n, int loops_count = 100)
{
    auto elapsedSum = std::chrono::duration_cast<
        std::chrono::microseconds>(std::chrono::steady_clock::now() - std::chrono::steady_clock::now());

    for (int i = 0; i < loops_count; ++i)
    {
        RandomArray(array, n);
        sort::insertion_sort(array, array + n - 1, sort::decrease_int);

        auto start = std::chrono::steady_clock::now();
        sort::quick_sort_first_optimization(array, array + n - 1, sort::increase_int);
        auto end = std::chrono::steady_clock::now();
        elapsedSum += std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

    std::cout << "Quick" << "\t\t" << n << "\t" << elapsedSum.count() / loops_count << "\tmicro seconds\n";
}

int main()
{
    int loops_count = 100000;
    // TODO: mesure copy array

    run_warmup(1000);
    run_insertion_benchmark(array8, 10,loops_count);
    run_quick_benchmark(array8, 10,loops_count);
    run_insertion_benchmark(array8, 16,loops_count);
    run_quick_benchmark(array8, 16,loops_count);
    run_insertion_benchmark(array8, 32,loops_count);
    run_quick_benchmark(array8, 32,loops_count);
    run_insertion_benchmark(array8, 64,loops_count);
    run_quick_benchmark(array8, 64,loops_count);
    run_insertion_benchmark(array8, 80,loops_count);
    run_quick_benchmark(array8, 80,loops_count);
    run_insertion_benchmark(array8, 100,loops_count);
    run_quick_benchmark(array8, 100,loops_count);
    run_insertion_benchmark(array8, 128,loops_count);
    run_quick_benchmark(array8, 128,loops_count);
    run_insertion_benchmark(array8, 170,loops_count);
    run_quick_benchmark(array8, 170,loops_count);
    // warmup
    /*run_warmup(loops_count);

    run_insertion_benchmark(array1, N1, loops_count);
    run_insertion_benchmark(array2, N2, loops_count);
    run_insertion_benchmark(array3, N3, loops_count);
    run_insertion_benchmark(array4, N4, loops_count);
    run_insertion_benchmark(array5, N5, loops_count);
    run_insertion_benchmark(array6, N6, loops_count);
    run_insertion_benchmark(array7, N7, loops_count);
    run_insertion_benchmark(array8, N8, loops_count);*/

    std::cout << std::endl;

    /*run_quick_benchmark(array1, N1, loops_count);
    run_quick_benchmark(array2, N2, loops_count);
    run_quick_benchmark(array3, N3, loops_count);
    run_quick_benchmark(array4, N4, loops_count);
    run_quick_benchmark(array5, N5, loops_count);
    run_quick_benchmark(array6, N6, loops_count);
    run_quick_benchmark(array7, N7, loops_count);
    run_quick_benchmark(array8, N8, loops_count);*/


    std::cin.ignore(2);

    return 0;
}
