#include <iostream>
#include <random>

#include "Nanobench/Classes/nanobench.cpp"
#include "ClassicQuickSort.h"
#include "CustomArray/Classes/array.hpp"

const int N1 = 10;
int array1[N1];

const int N2 = 40;
int array2[N2];

const int N3 = 70;
int array3[N3];

const int N4 = 100;
int array4[N4];

const int N5 = 130;
int array5[N5];

const int N6 = 150;
int array6[N6];

const int N7 = 200;
int array7[N7];

const int N8 = 400;
int array8[N8];

void RandomArray(int* array, int N)
{
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (int i = 0; i < N; ++i)
    {
        array[i] = mt1();
    }
}

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
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < loops_count; ++i)
    {
        RandomArray(array, n);
        sort::insertion_sort(array, array + n - 1, sort::decrease_int);
        sort::insertion_sort(array, array + n - 1, sort::increase_int);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Insertion" << "\t" << n << "\t" << elapsed.count() << "\tmicro seconds\n";
}

void run_quick_benchmark(int* array, int n, int loops_count = 100)
{
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < loops_count; ++i)
    {
        RandomArray(array, n);
        sort::quick_sort_second_optimization(array, array + n - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array, array + n - 1, sort::increase_int);
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Quick" << "\t\t" << n << "\t" << elapsed.count() << "\tmicro seconds\n";
}

int main()
{
    int loops_count = 1000;

    /*ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 4", [&]
    {
        sort::insertion_sort(array1, array1 + N1 - 1, sort::decrease_int);
        sort::insertion_sort(array1, array1 + N1 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 4", [&]
    {
        sort::quick_sort_second_optimization(array1, array1 + N1 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array1, array1 + N1 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 16", [&]
    {
        sort::insertion_sort(array2, array2 + N2 - 1, sort::decrease_int);
        sort::insertion_sort(array2, array2 + N2 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 16", [&]
    {
        sort::quick_sort_second_optimization(array2, array2 + N2 - 1, sort::decrease_int);
          sort::quick_sort_second_optimization(array2, array2 + N2 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 30", [&]
    {
        sort::insertion_sort(array3, array3 + N3 - 1, sort::decrease_int);
        sort::insertion_sort(array3, array3 + N3 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 30", [&]
    {
        sort::quick_sort_second_optimization(array3, array3 + N3 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array3, array3 + N3 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 50", [&]
    {
        sort::insertion_sort(array4, array4 + N4 - 1, sort::decrease_int);
        sort::insertion_sort(array4, array4 + N4 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 50", [&]
    {
        sort::quick_sort_second_optimization(array4, array4 + N4 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array4, array4 + N4 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 100", [&]
   {
       sort::insertion_sort(array5, array5 + N5 - 1, sort::decrease_int);
       sort::insertion_sort(array5, array5 + N5 - 1, sort::increase_int);
   });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 100", [&]
    {
        sort::quick_sort_second_optimization(array5, array5 + N5 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array5, array5 + N5 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 250", [&]
   {
       sort::insertion_sort(array6, array6 + N6 - 1, sort::decrease_int);
       sort::insertion_sort(array6, array6 + N6 - 1, sort::increase_int);
   });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 250", [&]
    {
        sort::quick_sort_second_optimization(array6, array6 + N6 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array6, array6 + N6 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Insertion, 5000", [&]
   {
       sort::insertion_sort(array7, array7 + N7 - 1, sort::decrease_int);
       sort::insertion_sort(array7, array7 + N7 - 1, sort::increase_int);
   });

    ankerl::nanobench::Bench().minEpochIterations(1000).warmup(20).run("Quick, 5000", [&]
   {
       sort::quick_sort_second_optimization(array7, array7 + N7 - 1, sort::decrease_int);
       sort::quick_sort_second_optimization(array7, array7 + N7 - 1, sort::increase_int);
   });*/

    // warmup
    run_warmup(loops_count);
    
    run_insertion_benchmark(array1, N1, loops_count);
    run_insertion_benchmark(array2, N2, loops_count);
    run_insertion_benchmark(array3, N3, loops_count);
    run_insertion_benchmark(array4, N4, loops_count);
    run_insertion_benchmark(array5, N5, loops_count);
    run_insertion_benchmark(array6, N6, loops_count);
    run_insertion_benchmark(array7, N7, loops_count);
    run_insertion_benchmark(array8, N8, loops_count);

    std::cout << std::endl;

    run_quick_benchmark(array1, N1, loops_count);
    run_quick_benchmark(array2, N2, loops_count);
    run_quick_benchmark(array3, N3, loops_count);
    run_quick_benchmark(array4, N4, loops_count);
    run_quick_benchmark(array5, N5, loops_count);
    run_quick_benchmark(array6, N6, loops_count);
    run_quick_benchmark(array7, N7, loops_count);
    run_quick_benchmark(array8, N8, loops_count);


    std::cin.ignore(2);

    return 0;
}
