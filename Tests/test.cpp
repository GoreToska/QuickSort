#include <random>

#include "gtest/gtest.h"
#include "../ClassicQuickSort.h"

TEST(InsertionSort, IntFloat)
{
    int int_array[5] = {2, 3, 5, 4, 1};
    float float_array[5] = {2.01f, 3.33f, 5.21f, 4.31f, 1.95f};

    sort::insertion_sort(int_array, int_array + 4, sort::increase_int);
    EXPECT_EQ(int_array[0], 1);
    EXPECT_EQ(int_array[1], 2);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 4);
    EXPECT_EQ(int_array[4], 5);

    sort::insertion_sort(int_array, int_array + 4, sort::decrease_int);
    EXPECT_EQ(int_array[0], 5);
    EXPECT_EQ(int_array[1], 4);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 2);
    EXPECT_EQ(int_array[4], 1);

    sort::insertion_sort(float_array, float_array + 4, sort::increase_int);
    EXPECT_EQ(float_array[0], 1.95f);
    EXPECT_EQ(float_array[1], 2.01f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 4.31f);
    EXPECT_EQ(float_array[4], 5.21f);

    sort::insertion_sort(float_array, float_array + 4, sort::decrease_float);
    EXPECT_EQ(float_array[0], 5.21f);
    EXPECT_EQ(float_array[1], 4.31f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 2.01f);
    EXPECT_EQ(float_array[4], 1.95f);
}

TEST(QuickSortNotOptimized, IntFloat)
{
    int int_array[5] = {2, 3, 5, 4, 1};
    float float_array[5] = {2.01f, 3.33f, 5.21f, 4.31f, 1.95f};

    sort::quick_sort_not_optimized(int_array, int_array + 4, sort::increase_int);
    EXPECT_EQ(int_array[0], 1);
    EXPECT_EQ(int_array[1], 2);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 4);
    EXPECT_EQ(int_array[4], 5);

    sort::quick_sort_not_optimized(int_array, int_array + 4, sort::decrease_int);
    EXPECT_EQ(int_array[0], 5);
    EXPECT_EQ(int_array[1], 4);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 2);
    EXPECT_EQ(int_array[4], 1);

    sort::quick_sort_not_optimized(float_array, float_array + 4, sort::increase_int);
    EXPECT_EQ(float_array[0], 1.95f);
    EXPECT_EQ(float_array[1], 2.01f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 4.31f);
    EXPECT_EQ(float_array[4], 5.21f);

    sort::quick_sort_not_optimized(float_array, float_array + 4, sort::decrease_float);
    EXPECT_EQ(float_array[0], 5.21f);
    EXPECT_EQ(float_array[1], 4.31f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 2.01f);
    EXPECT_EQ(float_array[4], 1.95f);
}

TEST(QuickSortFirstOptimization, IntFloat)
{
    int int_array[5] = {2, 3, 5, 4, 1};
    float float_array[5] = {2.01f, 3.33f, 5.21f, 4.31f, 1.95f};

    sort::quick_sort_first_optimization(int_array, int_array + 4, sort::increase_int);
    EXPECT_EQ(int_array[0], 1);
    EXPECT_EQ(int_array[1], 2);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 4);
    EXPECT_EQ(int_array[4], 5);

    sort::quick_sort_first_optimization(int_array, int_array + 4, sort::decrease_int);
    EXPECT_EQ(int_array[0], 5);
    EXPECT_EQ(int_array[1], 4);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 2);
    EXPECT_EQ(int_array[4], 1);

    sort::quick_sort_first_optimization(float_array, float_array + 4, sort::increase_int);
    EXPECT_EQ(float_array[0], 1.95f);
    EXPECT_EQ(float_array[1], 2.01f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 4.31f);
    EXPECT_EQ(float_array[4], 5.21f);

    sort::quick_sort_first_optimization(float_array, float_array + 4, sort::decrease_float);
    EXPECT_EQ(float_array[0], 5.21f);
    EXPECT_EQ(float_array[1], 4.31f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 2.01f);
    EXPECT_EQ(float_array[4], 1.95f);
}

TEST(QuickSortSecondOptimization, IntFloat)
{
    int int_array[5] = {2, 3, 5, 4, 1};
    float float_array[5] = {2.01f, 3.33f, 5.21f, 4.31f, 1.95f};

    sort::quick_sort_second_optimization(int_array, int_array + std::size(int_array) - 1, sort::increase_int);
    EXPECT_EQ(int_array[0], 1);
    EXPECT_EQ(int_array[1], 2);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 4);
    EXPECT_EQ(int_array[4], 5);

    sort::quick_sort_second_optimization(int_array, int_array + std::size(int_array) - 1, sort::decrease_int);
    EXPECT_EQ(int_array[0], 5);
    EXPECT_EQ(int_array[1], 4);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 2);
    EXPECT_EQ(int_array[4], 1);

    sort::quick_sort_second_optimization(float_array, float_array + std::size(float_array) - 1, sort::increase_int);
    EXPECT_EQ(float_array[0], 1.95f);
    EXPECT_EQ(float_array[1], 2.01f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 4.31f);
    EXPECT_EQ(float_array[4], 5.21f);

    sort::quick_sort_second_optimization(float_array, float_array + std::size(float_array) - 1, sort::decrease_float);
    EXPECT_EQ(float_array[0], 5.21f);
    EXPECT_EQ(float_array[1], 4.31f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 2.01f);
    EXPECT_EQ(float_array[4], 1.95f);
}

TEST(QuickSortNotOptimized, BigArray)
{
    const int N = 19;
    int big_array[N];
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (int i = 0; i < N; ++i)
    {
        big_array[i] = mt1();
    }

    sort::quick_sort_not_optimized(big_array, big_array + std::size(big_array) - 1, sort::increase_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_LT(big_array[i], big_array[i+1]);
    }

    sort::quick_sort_not_optimized(big_array, big_array + std::size(big_array) - 1, sort::decrease_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_GT(big_array[i], big_array[i+1]);
    }
}

TEST(QuickSortFirstOptimization, BigArray)
{
    const int N = 19;
    int big_array[N];
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (int i = 0; i < N; ++i)
    {
        big_array[i] = mt1();
    }

    sort::quick_sort_first_optimization(big_array, big_array + std::size(big_array) - 1, sort::increase_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_LT(big_array[i], big_array[i+1]);
    }

    sort::quick_sort_first_optimization(big_array, big_array + std::size(big_array) - 1, sort::decrease_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_GT(big_array[i], big_array[i+1]);
    }
}

TEST(QuickSortSecondOptimization, BigArray)
{
    const int N = 19;
    int big_array[N];
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (int i = 0; i < N; ++i)
    {
        big_array[i] = mt1();
    }
    sort::quick_sort_second_optimization(big_array, big_array + std::size(big_array) - 1, sort::increase_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_LT(big_array[i], big_array[i+1]);
    }

    sort::quick_sort_second_optimization(big_array, big_array + std::size(big_array) - 1, sort::decrease_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_GT(big_array[i], big_array[i+1]);
    }
}

TEST(MainSort, IntFloat)
{
    int int_array[5] = {2, 3, 5, 4, 1};
    float float_array[5] = {2.01f, 3.33f, 5.21f, 4.31f, 1.95f};

    sort::sort(int_array, int_array + std::size(int_array), sort::increase_int);
    EXPECT_EQ(int_array[0], 1);
    EXPECT_EQ(int_array[1], 2);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 4);
    EXPECT_EQ(int_array[4], 5);

    sort::sort(int_array, int_array + std::size(int_array), sort::decrease_int);
    EXPECT_EQ(int_array[0], 5);
    EXPECT_EQ(int_array[1], 4);
    EXPECT_EQ(int_array[2], 3);
    EXPECT_EQ(int_array[3], 2);
    EXPECT_EQ(int_array[4], 1);

    sort::sort(float_array, float_array + std::size(float_array), sort::increase_int);
    EXPECT_EQ(float_array[0], 1.95f);
    EXPECT_EQ(float_array[1], 2.01f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 4.31f);
    EXPECT_EQ(float_array[4], 5.21f);

    sort::sort(float_array, float_array + std::size(float_array), sort::decrease_float);
    EXPECT_EQ(float_array[0], 5.21f);
    EXPECT_EQ(float_array[1], 4.31f);
    EXPECT_EQ(float_array[2], 3.33f);
    EXPECT_EQ(float_array[3], 2.01f);
    EXPECT_EQ(float_array[4], 1.95f);
}

TEST(MainSort, BigArray)
{
    const int N = 500;
    int big_array[N];
    std::random_device rd;
    std::mt19937 mt1(rd());

    for (int i = 0; i < N; ++i)
    {
        big_array[i] = mt1();
    }

    sort::sort(big_array, big_array + N, sort::increase_int);

    for (int i = 0; i < N; ++i)
    {
        std::cout << big_array[i] << " ";
    }

    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_LE(big_array[i], big_array[i+1]);
    }

    sort::sort(big_array, big_array + N, sort::decrease_int);
    for (int i = 0; i < N - 1; ++i)
    {
        EXPECT_GE(big_array[i], big_array[i+1]);
    }
}

TEST(MainSort, SortEmptyArray)
{
    int arr[2] = {};
    sort::sort(arr, arr + 0, sort::decrease_float);
}

TEST(MainSort, SortSingleElement)
{
    int arr[1] = {1};
    sort::sort(arr, arr + 0, sort::decrease_float);
    EXPECT_EQ(arr[0], 1);
}

TEST(MainSort, SortStrings)
{
    std::string arr[] = {"one", "two", "three"};
    sort::sort(arr, arr + 3, std::less<std::string>());
    EXPECT_EQ(arr[0], "one");
    EXPECT_EQ(arr[1], "three");
    EXPECT_EQ(arr[2], "two");
}

TEST(MainSort, SortSortedStrings)
{
    std::string arr[] = {"one", "three", "two"};
    sort::sort(arr, arr + 3, std::less<std::string>());
    EXPECT_EQ(arr[0], "one");
    EXPECT_EQ(arr[1], "three");
    EXPECT_EQ(arr[2], "two");
}

TEST(MainSort, SortStringsWithCases)
{
    std::string arr[] = {"one", "Two", "threE"};
    sort::sort(arr, arr + 3, [](const std::string& a, const std::string& b)
    {
        return std::lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end(),
            [](char a, char b)
            {
                return tolower(a) < tolower(b);
            });
    });

    EXPECT_EQ(arr[0], "one");
    EXPECT_EQ(arr[1], "threE");
    EXPECT_EQ(arr[2], "Two");
}

TEST(MainSort, SortDuplicateStrings)
{
    std::string arr[] = {"one", "two", "three", "one", "two"};
    sort::sort(arr, arr + 5, std::less<std::string>());
    EXPECT_EQ(arr[0], "one");
    EXPECT_EQ(arr[1], "one");
    EXPECT_EQ(arr[2], "three");
    EXPECT_EQ(arr[3], "two");
    EXPECT_EQ(arr[4], "two");
}
