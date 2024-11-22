#include <iostream>
#include <random>
#include <algorithm>
#include <ranges>
#include "Nanobench/Classes/nanobench.cpp"
#include "ClassicQuickSort.h"

const int N = 10000;
int big_array[N];

int main()
{
	int int_array[5] = { 3, 7, 10, 9, 1 };
	int int_array2[5] = { 5, 4, 1, 2, 3 };

	uint64_t iterations = 1000;

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	sort::insertion_sort(big_array, 0, N - 1);

	/*// 4
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 4", [&]
		{
			sort::insertion_sort(big_array, 0, 3);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 4", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 3);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 8
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 8", [&]
		{
			sort::insertion_sort(big_array, 0, 7);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 8", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 7);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 16
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 16", [&]
		{
			sort::insertion_sort(big_array, 0, 15);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 16", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 15);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 64
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 64", [&]
		{
			sort::insertion_sort(big_array, 0, 63);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 64", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 63);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 512
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 512", [&]
		{
			sort::insertion_sort(big_array, 0, 511);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 512", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 511);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 1024
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 1024", [&]
		{
			sort::insertion_sort(big_array, 0, 1023);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 1024", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 1023);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 2048
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 2048", [&]
		{
			sort::insertion_sort(big_array, 0, 2047);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 2048", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 2047);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 4096
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 4096", [&]
		{
			sort::insertion_sort(big_array, 0, 4095);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 4096", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 4095);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 8000
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 8000", [&]
		{
			sort::insertion_sort(big_array, 0, 7999);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 8000", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 7999);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	// 10000
	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Insertion, 10000", [&]
		{
			sort::insertion_sort(big_array, 0, 9999);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}

	ankerl::nanobench::Bench().minEpochIterations(iterations).warmup(100).run("Quick, 10000", [&]
		{
			sort::quick_sort_second_optimization(big_array, 0, 9999);
		});

	for (int i = 0; i < N; ++i)
	{
		big_array[i] = rand();
	}
		*/

	for (int i = 0; i < N; ++i)
	{
		std::cout << big_array[i] << " ";
	}

	std::cout << std::endl;

	std::cin.ignore(2);

	return 0;
}
