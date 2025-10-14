#include "Experiments.h";
#include "D_heap.h"
void experiment_filling_array(std::vector<int>& arr, int n, int q, int w, int type_generation_array)
{
	srand((unsigned int)time(NULL));

	if (type_generation_array < 1 || type_generation_array>3)
	{
		std::cout << "Incorrect input num!!!";
		std::exit(1);
	}
	else if (type_generation_array == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			int tmp = std::rand() % (w - q + 1) + q; //add 1 for tmp from [q, w]
			arr.push_back(tmp);
		}
	}
	else if (type_generation_array == 2)
	{
		arr.push_back(q);


		for (int i = 1; i < n; ++i)
		{
			if (q == w)
			{
				for (i; i < n; ++i)
				{
					arr.push_back(q);
				}
				break;

			}
			else
			{
				arr.push_back(q++);
			}
		}
	}
	else {
		arr.push_back(w);
		for (int i = n - 2; i >= 0; --i)
		{
			if (w == q)
			{
				for (i; i >= 0; --i)
				{
					arr.push_back(w);
				}
				break;
			}
			else
			{
				arr.push_back(w--);
			}
		}
	}
}



void quicksort_standart_walkthrough_A(std::vector<int> arr, int n, int q, int w, int type_generation)
{
	experiment_filling_array(arr, n, q, w, type_generation);

	auto wall_start = std::chrono::high_resolution_clock::now();
	quick_sort_standart(arr, 0, n - 1);
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << n << "\t" << wall_time << "\n";
}
void quicksort_optimized_walkthrough_A(std::vector<int> arr, int n, int q, int w, int type_generation)
{
	experiment_filling_array(arr, n, q, w, type_generation);

	auto wall_start = std::chrono::high_resolution_clock::now();
	quick_sort_v2(arr, 0, n - 1);
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << n << "\t" << wall_time << "\n";
}
void d_heap_walkthrough_A(std::vector<int> arr, int n, int q, int w, int type_generation)
{
	experiment_filling_array(arr, n, q, w, type_generation);

	D_heap tmp(3, arr);
	auto wall_start = std::chrono::high_resolution_clock::now();
	tmp.Sort_D();
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << n << "\t" << wall_time << "\n";
}
void experiment_A()
{

	char type_of_reading = '1';
	int n, q, w;
	q = 1, w = 1000000000, n = 1;

	for (int i = 1; i <= 3; i++)
	{
		n = 1;
		if (i == 1)
		{
			std::cout << "QuickSort_standart with pseudo-random generation\n";
		}
		else if (i == 2)
		{
			std::cout << "QuickSort_standart with ascending generation\n";
		}
		else {
			std::cout << "QuickSort_standart with descending generation\n";
		}
		std::cout << "n\tTime\n";
		for (n; n <= 1000001; n += 10000)//for QuickSort with pseudo-random generation
		{
			std::vector<int>arr;
			quicksort_standart_walkthrough_A(arr, n, q, w, i);
		}
		std::cout << "GG. i = " << i << "\n";
	}


	for (int i = 3; i <= 3; i++)
	{
		n = 1;
		if (i == 1)
		{
			std::cout << "QuickSort_optimized with pseudo-random generation\n";
		}
		else if (i == 2)
		{
			std::cout << "QuickSort_optimized with ascending generation\n";
		}
		else {
			std::cout << "QuickSort_optimized with descending generation\n";
		}
		std::cout << "n\tTime\n";
		for (n; n <= 100001; n += 10000)//for QuickSort with pseudo-random generation
		{
			std::vector<int>arr;
			quicksort_optimized_walkthrough_A(arr, n, q, w, i);
		}
		std::cout << "GG. i = " << i << "\n";
	}

	for (int i = 1; i <= 1; ++i)
	{
		n = 1;
		if (i == 1)
		{
			std::cout << "3-heap sort with pseudo-random generation\n";
		}
		else if (i == 2)
		{
			std::cout << "3-heap sort with ascending generation\n";
		}
		else {
			std::cout << "3-heap sort with descending generation\n";
		}
		std::cout << "n\tTime\n";
		for (n; n <= 1000001; n += 10000)//for QuickSort with pseudo-random generation
		{
			std::vector<int>arr;
			d_heap_walkthrough_A(arr, n, q, w, i);
		}
		std::cout << "GG. i = " << i << "\n";
	}

}


void quicksort_standart_walkthrough_B(std::vector<int> arr, int n, int q, int w, int type_generation)
{
	experiment_filling_array(arr, n, q, w, type_generation);

	auto wall_start = std::chrono::high_resolution_clock::now();
	quick_sort_standart(arr, 0, n - 1);
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << w << "\t" << wall_time << "\n";
}
void quicksort_optimized_walkthrough_B(std::vector<int> arr, int n, int q, int w, int type_generation)
{
	experiment_filling_array(arr, n, q, w, type_generation);

	auto wall_start = std::chrono::high_resolution_clock::now();
	quick_sort_v2(arr, 0, n - 1);
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << w << "\t" << wall_time << "\n";
}
void d_heap_walkthrough_B(std::vector<int> arr, int n, int q, int w, int type_generation)
{
	experiment_filling_array(arr, n, q, w, type_generation);

	D_heap tmp(3, arr);
	auto wall_start = std::chrono::high_resolution_clock::now();
	tmp.Sort_D();
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << w << "\t" << wall_time << "\n";
}
void experiment_B()
{
	char type_of_reading = '1';
	int n, q, w;
	q = 1, w = 1, n=10000;
	for (int i = 1; i <= 1; i++)
	{
		w = 1;
		if (i == 1)
		{
			std::cout << "QuickSort_standart with pseudo-random generation\n";
		}
		else if (i == 2)
		{
			std::cout << "QuickSort_standart with ascending generation\n";
		}
		else {
			std::cout << "QuickSort_standart with descending generation\n";
		}
		std::cout << "w\tTime\n";
		for (w; w <= 100; w += 1)//for QuickSort with pseudo-random generation
		{
			std::vector<int>arr;
			quicksort_standart_walkthrough_B(arr, n, q, w, i);
		}
		std::cout << "GG. i = " << i << "\n";
	}

	for (int i = 1; i <= 1; i++)
	{
		w = 1;
		if (i == 1)
		{
			std::cout << "QuickSort_optimized with pseudo-random generation\n";
		}
		else if (i == 2)
		{
			std::cout << "QuickSort_optimized with ascending generation\n";
		}
		else {
			std::cout << "QuickSort_optimized with descending generation\n";
		}
		std::cout << "w\tTime\n";
		for (w; w <= 100; w += 1)//for QuickSort with pseudo-random generation
		{
			std::vector<int>arr;
			quicksort_optimized_walkthrough_B(arr, n, q, w, i);
		}
		std::cout << "GG. i = " << i << "\n";
	}

	for (int i = 1; i <= 1; ++i)
	{
		w = 1;
		if (i == 1)
		{
			std::cout << "3-heap sort with pseudo-random generation\n";
		}
		else if (i == 2)
		{
			std::cout << "3-heap sort with ascending generation\n";
		}
		else {
			std::cout << "3-heap sort with descending generation\n";
		}
		std::cout << "w\tTime\n";
		for (w; w <= 100; w += 1)//for QuickSort with pseudo-random generation
		{
			std::vector<int>arr;
			d_heap_walkthrough_B(arr, n, q, w, i);
		}
		std::cout << "GG. i = " << i << "\n";
	}
}