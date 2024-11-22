#pragma once
#include <stack>

namespace sort
{
    template <typename T>
    bool decreasing_comparator(const T& a, const T& b)
    {
        return a > b;
    }

    template <typename T>
    bool increasing_comparator(const T& a, const T& b)
    {
        return a < b;
    }

#pragma region Insertion_Sort
    template <typename T>
    void insertion_sort(T* start, T* end)
    {
        for (T* i = start + 1; i <= end; ++i)
        {
            T key = *i;
            for (T* j = i - 1; j >= start; --j)
            {
                if (*j < key)
                {
                    *(j + 1) = key;
                    break;
                }

                *(j + 1) = *j;
            }
        }
    }

#pragma endregion
    // works fine
#pragma region Not_Optimized
    template <typename T>
    T* partition( T* start, T* end)
    {
        T pivot = *end;
        T* pivot_index = start - 1;

        for (T* j = start; j < end; ++j)
        {
            if (*j <= pivot)
            {
                ++pivot_index;
                std::swap(*pivot_index, *j);
            }
        }

        std::swap(*(pivot_index + 1), *end);

        return pivot_index + 1;
    }

    template <typename T>
    void quick_sort_not_optimized(T* start, T* end)
    {
        if (start >= end)
            return;

        T* pivot_index = partition(start, end);
        quick_sort_not_optimized(start, pivot_index - 1);
        quick_sort_not_optimized(pivot_index + 1, end);
    }

#pragma endregion

    // works fine
#pragma region First_Optimization
    template <typename T>
    T* get_median(T* start, T* end)
    {
        T* mid = start + (end - start) / 2;

        if (*start > *mid)
            std::swap(*start, *mid);
        if (*start > *end)
            std::swap(*start, *end);
        if (*mid > *end)
            std::swap(*mid, *end);

        std::swap(*mid, *end);

        return end;
    }

    template <typename T>
    T* median_partition(T* start, T* end)
    {
        T* pivot_index = get_median(start, end);
        T pivot = *pivot_index;
        T* i = start - 1;

        for (T* j = start; j < end; ++j)
        {
            if (*j > pivot)
                continue;

            ++i;
            std::swap(*i, *j);
        }

        std::swap(*(i + 1), *end);
        return i + 1;
    }

    template <typename T>
    void quick_sort_first_optimization(T* start, T* end)
    {
        if (start >= end)
            return;

        T* pivot_index = median_partition(start, end);
        quick_sort_first_optimization(start, pivot_index - 1);
        quick_sort_first_optimization(pivot_index + 1, end);
    }
#pragma endregion

    // works fine
#pragma region Second_Optimization
    template <typename T>
    void quick_sort_iterative(T* start, T* end)
    {
        if (end - start < 2)
            return;

        std::stack<T*> stack;
        stack.push(start);
        stack.push(end);

        while (!stack.empty())
        {
            end = stack.top();
            stack.pop();
            start = stack.top();
            stack.pop();
            T* pivot = median_partition(start, end);

            if (pivot - 1 > start)
            {
                stack.push(start);
                stack.push(pivot - 1);
            }
            if (pivot + 1 < end)
            {
                stack.push(pivot + 1);
                stack.push(end);
            }
        }
    }

    template <typename T>
    void quick_sort_second_optimization( T* start, T* end)
    {
        if (start >= end)
            return;

        T* pivot_index = median_partition(start, end);

        if (pivot_index - start > end - pivot_index)
        {
            quick_sort_second_optimization( pivot_index + 1, end);
            quick_sort_iterative( start, pivot_index - 1);
        }
        else
        {
            quick_sort_iterative( pivot_index + 1, end);
            quick_sort_second_optimization( start, pivot_index - 1);
        }
    }
#pragma endregion
}
