#include <iostream>
#include <random>

#include "Nanobench/Classes/nanobench.cpp"
#include "ClassicQuickSort.h"
#include "CustomArray/Classes/array.hpp"

const int N1 = 10;
std::vector<int> array1(N1);

const int N2 = 40;
std::vector<int> array2(N2);

const int N3 = 70;
std::vector<int> array3(N3);

const int N4 = 100;
std::vector<int> array4(N4);

const int N5 = 130;
std::vector<int> array5(N5);

const int N6 = 150;
std::vector<int> array6(N6);

const int N7 = 200;
std::vector<int> array7(N7);

const int N8 = 400;
std::vector<int> array8(N8);

void RandomArray(int* array, int N)
{
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (int i = 0; i < N; ++i)
    {
        array[i] = mt1();
    }
}

void RandomArray(std::vector<int> array)
{
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (auto value : array)
    {
        value = mt1();
    }

    std::sort(array.begin(), array.end());
}

/*void run_warmup(int loops_count)
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
}*/

int main()
{
    int loops_count = 1000;

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 4", [&]
    {
        RandomArray(array1);
        sort::insertion_sort(array1._Unchecked_begin(), array1._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 4", [&]
    {
        RandomArray(array1);
        sort::quick_sort_second_optimization(array1._Unchecked_begin(), array1._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 16", [&]
    {
        RandomArray(array2);
        sort::insertion_sort(array2._Unchecked_begin(), array2._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 16", [&]
    {
        RandomArray(array2);
        sort::quick_sort_second_optimization(array2._Unchecked_begin(), array2._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 30", [&]
    {
        RandomArray(array3);
        sort::insertion_sort(array3._Unchecked_begin(), array3._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 30", [&]
    {
        RandomArray(array3);
        sort::quick_sort_second_optimization(array3._Unchecked_begin(), array3._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 50", [&]
    {
        RandomArray(array4);
        sort::insertion_sort(array4._Unchecked_begin(), array4._Unchecked_end(), sort::decrease_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 50", [&]
    {
        RandomArray(array4);
        sort::quick_sort_second_optimization(array4._Unchecked_begin(), array4._Unchecked_end(), sort::decrease_int);
    });

   /* ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 100", [&]
    {
        RandomArray(array5);
        sort::insertion_sort(array5, array5 + N5 - 1, sort::decrease_int);
        sort::insertion_sort(array5, array5 + N5 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 100", [&]
    {
        //RandomArray(array5, N5);
        sort::quick_sort_second_optimization(array5, array5 + N5 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array5, array5 + N5 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 250", [&]
    {
        //RandomArray(array6, N6);
        sort::insertion_sort(array6, array6 + N6 - 1, sort::decrease_int);
        sort::insertion_sort(array6, array6 + N6 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 250", [&]
    {
        //RandomArray(array6, N6);
        sort::quick_sort_second_optimization(array6, array6 + N6 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array6, array6 + N6 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Insertion, 5000", [&]
    {
        //RandomArray(array7, N7);
        sort::insertion_sort(array7, array7 + N7 - 1, sort::decrease_int);
        sort::insertion_sort(array7, array7 + N7 - 1, sort::increase_int);
    });

    ankerl::nanobench::Bench().minEpochIterations(loops_count).warmup(20).run("Quick, 5000", [&]
    {
        //RandomArray(array7, N7);
        sort::quick_sort_second_optimization(array7, array7 + N7 - 1, sort::decrease_int);
        sort::quick_sort_second_optimization(array7, array7 + N7 - 1, sort::increase_int);
    });*/

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
