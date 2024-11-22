#pragma once
#include <stack>

namespace sort
{
	template<typename T>
	bool decreasing_comparator(const T& a, const T& b)
	{
		return a > b;
	}

	template<typename T>
	bool increasing_comparator(const T& a, const T& b)
	{
		return a < b;
	}

#pragma region Insertion_Sort
	template <typename T>
	void insertion_sort(T* array, int start, int end)
	{
		for (int i = start + 1; i <= end; ++i)
		{
			T key = array[i];
			for (int j = i - 1; j >= 0; --j)
			{
				if (array[j] < key)
				{
					array[j + 1] = key;
					break;
				}

				array[j + 1] = array[j];
			}
		}
	}

#pragma endregion
	// works fine
#pragma region Not_Optimized
	template <typename T>
	int partition(T* array, int start, int end)
	{
		T pivot = array[end];
		int pivot_index = start - 1;

		for (int j = start; j <= end - 1; ++j)
		{
			if (array[j] <= pivot)
			{
				++pivot_index;
				std::swap(array[pivot_index], array[j]);
			}
		}

		std::swap(array[pivot_index + 1], array[end]);

		return pivot_index + 1;
	}

	template <typename T>
	void quick_sort_not_optimized(T* array, int start, int end)
	{
		if (start >= end)
			return;

		int pivot_index = partition(array, start, end);
		quick_sort_not_optimized(array, start, pivot_index - 1);
		quick_sort_not_optimized(array, pivot_index + 1, end);
	}

#pragma endregion

	// works fine
#pragma region First_Optimization
	template <typename T>
	int get_median(T* array, int start, int end)
	{
		int mid = start + (end - start) * 0.5;

		if (array[start] > array[mid])
			std::swap(array[start], array[mid]);
		if (array[start] > array[end])
			std::swap(array[start], array[end]);
		if (array[mid] > array[end])
			std::swap(array[mid], array[end]);

		std::swap(array[mid], array[end]);

		return end;
	}

	template <typename T>
	int median_partition(T* array, int start, int end)
	{
		int pivot_index = get_median(array, start, end);
		T pivot = array[pivot_index];

		int i = pivot_index - 1;
		for (int j = pivot_index; j < end; ++j)
		{

			if (array[j] > pivot)
				continue;

			++i;
			std::swap(array[i], array[j]);
		}

		std::swap(array[i + 1], array[end]);
		return i + 1;
	}

	template <typename T>
	void quick_sort_first_optimization(T* array, int start, int end)
	{
		if (start >= end)
			return;

		int pivot_index = median_partition(array, start, end);
		quick_sort_first_optimization(array, start, pivot_index - 1);
		quick_sort_first_optimization(array, pivot_index + 1, end);
	}
#pragma endregion

	// works fine
#pragma region Second_Optimization
	template <typename T>
	void quick_sort_iterative(T* array, int start, int end)
	{
		if (end - start < 2)
			return;

		std::stack<T> stack;
		stack.push(start);
		stack.push(end);

		while (!stack.empty())
		{
			end = stack.top();
			stack.pop();
			start = stack.top();
			stack.pop();
			int pivot = median_partition(array, start, end);

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
	void quick_sort_second_optimization(T* array, int start, int end)
	{
		if (start >= end)
			return;

		int pivot_index = median_partition(array, start, end);

		if (pivot_index - start > end - pivot_index)
		{
			quick_sort_second_optimization(array, pivot_index + 1, end);
			quick_sort_iterative(array, start, pivot_index - 1);
		}
		else
		{
			quick_sort_iterative(array, pivot_index + 1, end);
			quick_sort_second_optimization(array, start, pivot_index - 1);
		}
	}
#pragma endregion
}
