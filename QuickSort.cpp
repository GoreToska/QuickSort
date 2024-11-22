#include <iostream>
#include <random>
#include "Nanobench/Classes/nanobench.cpp"
#include "ClassicQuickSort.h"

const int N1 = 4;
int array1[N1];

const int N2 = 16;
int array2[N2];

const int N3 = 64;
int array3[N3];

const int N4 = 100;
int array4[N4];

const int N5 = 128;
int array5[N5];

const int N6 = 350;
int array6[N6];

const int N7 = 4096;
int array7[N7];

void RandomArray(int* array, int N)
{
    for (int i = 0; i < N; ++i)
    {
        array[i] = rand();
    }
}

int main()
{
    /*int int_array[5] = { 3, 7, 10, 9, 1 };
    int int_array2[5] = { 5, 4, 1, 2, 3 };

    uint64_t iterations = 100;

    RandomArray(array1, N1);
    RandomArray(array2, N1);
    RandomArray(array3, N1);
    RandomArray(array4, N1);
    RandomArray(array5, N1);
    RandomArray(array6, N1);
    RandomArray(array7, N1);

    // 4
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 4", [&]
        {
            RandomArray(array1, N1);
            sort::insertion_sort(array1, array1 + N1 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 4", [&]
        {
            RandomArray(array1, N1);
            sort::quick_sort_second_optimization(array1, array1 + N1 - 1, sort::increase_int);
        });

    // 16
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 16", [&]
        {
            RandomArray(array2, N2);
            sort::insertion_sort(array2, array2 + N2 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 16", [&]
        {
            RandomArray(array2, N2);
            sort::quick_sort_second_optimization(array2, array2 + N2 - 1, sort::increase_int);
        });


    // 64
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 64", [&]
        {
            RandomArray(array3, N3);
            sort::insertion_sort(array3, array3 + N3 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 64", [&]
        {
            RandomArray(array3, N3);
            sort::quick_sort_second_optimization(array3, array3 + N3 - 1, sort::increase_int);
        });

    // 128
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 100", [&]
        {
            RandomArray(array4, N4);
            sort::insertion_sort(array3, array4 + N4 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 100", [&]
        {
            RandomArray(array4, N4);
            sort::quick_sort_second_optimization(array4, array4 + N4 - 1, sort::increase_int);
        });

    // 512
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 128", [&]
        {
            RandomArray(array5, N5);
            sort::insertion_sort(array5, array5 + N5 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 128", [&]
        {
            RandomArray(array5, N5);
            sort::quick_sort_second_optimization(array5, array5 + N5 - 1, sort::increase_int);
        });

    // 4096
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 350", [&]
        {
            RandomArray(array6, N6);
            sort::insertion_sort(array6, array6 + N6 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 350", [&]
        {
            RandomArray(array6, N6);
            sort::quick_sort_second_optimization(array6, array6 + N6 - 1, sort::increase_int);
        });

    // 1000
    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Insertion, 4096", [&]
        {
            RandomArray(array7, N7);
            sort::insertion_sort(array7, array7 + N7 - 1, sort::increase_int);
        });

    ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(10).run("Quick, 4096", [&]
        {
            RandomArray(array7, N7);
            sort::quick_sort_second_optimization(array7, array7 + N7 - 1, sort::increase_int);
        });*/
    sort::sort(array7, array7 + N7, sort::decrease_int);
    std::cin.ignore(2);

    return 0;
}
