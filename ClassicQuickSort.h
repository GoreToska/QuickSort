﻿#pragma once
#include <stack>

namespace sort
{
    int insertion_threshold = 170;

    inline bool decrease_int(int a, int b)
    {
        return a > b;
    }

    inline bool increase_int(int a, int b)
    {
        return a < b;
    }

    inline bool decrease_float(int a, int b)
    {
        return a > b;
    }

    inline bool increase_float(int a, int b)
    {
        return a < b;
    }

#pragma region Insertion_Sort
    template <typename T, typename Compare>
    void insertion_sort(T* start, T* end, Compare comp)
    {
        for (T* i = start + 1; i <= end; ++i)
        {
            T key = *i;
            T* j = i - 1;

            while (j >= start && comp(key, *j))
            {
                *(j + 1) = *j;
                --j;
            }

            *(j + 1) = key;
        }
    }

#pragma endregion
    // works fine
#pragma region Not_Optimized
    template <typename T, typename Compare>
    T* partition(T* start, T* end, Compare comp)
    {
        T pivot = *end;
        T* pivot_index = start - 1;

        for (T* j = start; j < end; ++j)
        {
            if (comp(*j, pivot))
            {
                ++pivot_index;
                std::swap(*pivot_index, *j);
            }
        }

        std::swap(*(pivot_index + 1), *end);

        return pivot_index + 1;
    }

    template <typename T, typename Compare>
    void quick_sort_not_optimized(T* start, T* end, Compare comp)
    {
        if (start >= end)
            return;

        T* pivot_index = partition(start, end, comp);
        quick_sort_not_optimized(start, pivot_index - 1, comp);
        quick_sort_not_optimized(pivot_index + 1, end, comp);
    }

#pragma endregion

#pragma region First_Optimization
    template <typename T, typename Compare>
    T* get_median(T* start, T* end, Compare comp)
    {
        T* mid = start + (end - start) / 2;

        if (comp(*start, *mid))
            std::swap(*start, *mid);
        if (comp(*start, *end))
            std::swap(*start, *end);
        if (comp(*mid, *end))
            std::swap(*mid, *end);

        std::swap(*mid, *end);

        return end;
    }

    template <typename T, typename Compare>
    T* median_partition(T* start, T* end, Compare comp)
    {
        T* pivot_index = get_median(start, end, comp);
        T pivot = *pivot_index;
        T* i = start - 1;

        for (T* j = start; j < end; ++j)
        {
            if (!comp(*j, pivot))
                continue;

            ++i;
            std::swap(*i, *j);
        }

        std::swap(*(i + 1), *end);
        return i + 1;
    }

    template <typename T, typename Compare>
    void quick_sort_first_optimization(T* start, T* end, Compare comp)
    {
        if (start >= end)
            return;

        T* pivot_index = median_partition(start, end, comp);
        quick_sort_first_optimization(start, pivot_index - 1, comp);
        quick_sort_first_optimization(pivot_index + 1, end, comp);
    }
#pragma endregion

#pragma region Second_Optimization
    template <typename T, typename Compare>
    void quick_sort_iterative(T* start, T* end, Compare comp)
    {
        if (end - start < 2)
            return;

        std::stack<T*> stack;

        stack.push(start);
        stack.push(end);

        while (!stack.empty())
        {
            T* right = stack.top();
            stack.pop();
            T* left = stack.top();
            stack.pop();

            T* pivot_index = median_partition(left, right, comp);

            if (pivot_index - 1 > left)
            {
                stack.push(left);
                stack.push(pivot_index - 1);
            }
            if (pivot_index + 1 < right)
            {
                stack.push(pivot_index + 1);
                stack.push(right);
            }
        }
    }

    template <typename T, typename Compare>
    void quick_sort_second_optimization(T* start, T* end, Compare comp)
    {
        if (start >= end)
            return;

        T* pivot_index = median_partition(start, end, comp);

        if (pivot_index - start > end - pivot_index)
        {
            quick_sort_second_optimization(pivot_index, end, comp);
            quick_sort_iterative(start, pivot_index, comp);
        }
        else
        {
            quick_sort_second_optimization(start, pivot_index, comp);
            quick_sort_iterative(pivot_index, end, comp);
        }
    }
#pragma endregion

    template <typename T, typename Compare>
    void sort(T* start, T* end, Compare comp)
    {
        end -= 1;

        if (end - start < insertion_threshold)
        {
            insertion_sort(start, end, comp);
        }
        else
        {
            quick_sort_second_optimization(start, end, comp);
        }
    }
}
