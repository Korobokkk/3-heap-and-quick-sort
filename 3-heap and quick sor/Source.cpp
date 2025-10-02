#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "D_heap.h"

#include <optional>

char type_data_input()
{
	char type_of_reading;
	try
	{
		std::cout << "Select the data entry type:\n    1- for manual data entry\n    2- for to read a txt file with data\n";
		std::cin >> type_of_reading;
		if (type_of_reading == '1')
		{
			std::cout << "You choose: manual entry.\n";
		}
		else if (type_of_reading == '2')
		{
			std::cout << "You choose: reading txt file.\n";
		}
		else
		{
			throw "Error! Incorrect input!!!";
		}
		return type_of_reading;
	}
	catch (const char* error_massage)
	{
		std::cout << error_massage;
		std::exit(1);
	}
	return type_of_reading;
}
void sellection_of_parameters(int &n, int &q, int &w)
{
	try
	{
		std::cout << "Sellect n. *(This is the number of elements in array)\n";
		std::cin >> n;
		if (n < 1 )
		{
			throw "incorrect 'n'.'n' must be greater than 1.\n";
		}

		std::cout << "Sellect 'q'. *(This is the min value of the element in array)\n";
		std::cin >> q;
		if (q < 1)
		{
			throw "incorrect 'q'.'q' must be greater or equal than 1.\n";
		}

		std::cout << "Sellect 'w'. *(This is the max value of the element)\n";
		std::cin >> w;
		if (w < q)
		{
			throw "incorrect 'w'.'w' must be greater or equal than 'q'.\n";
		}
	}
	catch (const char* error_massage)
	{
		std::cout << error_massage;
		std::exit(1);
	}
}

void filling_an_array( std::vector<int> &arr, char type_of_reading, int n, int q, int w)
{
	srand((unsigned int)time(NULL));
	if (type_of_reading == '1')//for rand
	{

		std::cout << "n - " << n << ", q - " << q << ", w - " << w << "\n\n" << "Select an array generation method:\n    1.-Pseudo-random generation\n    2- Ascending generation\n    3- Descending generation\n";//debug
		int choose;
		std::cin >> choose;
		if (choose < 1 || choose>3)
		{
			std::cout << "Incorrect input num!!!";
			std::exit(1);
		}
		else if (choose == 1)
		{
			for (int i = 0; i < n; ++i)
			{
				int tmp = std::rand() % (w - q + 1) + q; //add 1 for tmp from [q, w]
				arr.push_back(tmp);
				std::cout << tmp << " ";
			}
		}
		else if (choose == 2)
		{
			arr.push_back(q);
			std::cout << q++<< " ";
			

			for (int i = 1; i < n; ++i)
			{
				if (q == w)
				{
					for (i; i < n; ++i)
					{
						std::cout << q << " ";
						arr.push_back(q);
					}
					break;
					
				}
				else
				{
					std::cout << q << " ";
					arr.push_back(q++);				
				}
			}
		}
		else {
			arr.push_back(w);
			std::cout << w-- << " ";
			for (int i = n-2; i >= 0; --i)
			{
				if (w == q)
				{
					for (i; i >= 0; --i)
					{
						std::cout << w << " ";
						arr.push_back(w);
					}
					break;
				}
				else
				{
					std::cout << w << " ";
					arr.push_back(w--);
				}
			}
		}

		std::cout << "\n";
	}
	else//for .exe file
	{
		//need write
	}
}

int dividing(std::vector<int>& arr, int l, int r)
{
	int pivot = arr[(l + r) / (2)];
	int i = l , j = r ;
	
	while (true)
	{
		while (arr[i] < pivot  )
		{
			++i;
		}
		while (arr[j]> pivot )
		{
			--j;
		}
		if (i >= j)
		{
			return j;
		}
		std::swap(arr[i], arr[j]);
		++i, --j;

	}
}
void Cout_quick_sort_res(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}
}

void quick_sort_v2(std::vector<int>& arr, int l, int r)
{
	if (l < r)
	{
		int tmp = dividing(arr, l, r);
		quick_sort_v2(arr, l,tmp);
		quick_sort_v2(arr, tmp + 1, r);
	}
}


void sortings(std::vector<int>& arr)
{
	std::cout << "Quicksort\n";
	std::vector<int> copy_arr = arr;
	auto wall_start = std::chrono::high_resolution_clock::now();
	quick_sort_v2(copy_arr, 0,copy_arr.size() - 1);
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::seconds>(wall_stop - wall_start).count();
	std::cout << "Time Quicksort - " << wall_time << " n = " << copy_arr.size() << "\n[Quicksort] You want to see the sorted array?\n    1-Yes\n    0-No\n";
	bool flag;
	std::cin >> flag;
	if (flag)
	{
		Cout_quick_sort_res(copy_arr);
	}


	std::cout << "\n3-heap sort\n";
	D_heap tmp(3, arr);
	wall_start = std::chrono::high_resolution_clock::now();
	tmp.Sort_D();
	wall_stop = std::chrono::high_resolution_clock::now();
	wall_time = std::chrono::duration_cast<std::chrono::seconds>(wall_stop - wall_start).count();
	
	std::cout << "Time D-heap sort - " << wall_time << " n = " << arr.size()<< "\n[D-heap sort] You want to see the sorted array?\n    1-Yes\n    0-No\n";
	std::cin >> flag;
	if (flag)
	{
		tmp.Cout_result_sorting_array();
	}


}


int main()
{
	std::ios::sync_with_stdio(0);//disable sinc between c++ and c input/output 
	std::cin.tie(nullptr);//disable sinc between clear cout/cin buffer
	std::cout.tie(nullptr);



	char type_of_reading = type_data_input();
	int n, q, w;
	sellection_of_parameters(n, q, w);
	
	//init arr
	std::vector<int> arr;
	filling_an_array(arr, type_of_reading, n, q, w);
	
	sortings(arr);
	//std::cout << "\n3-heap sort\n";
	//D_heap tmp(3, arr);
	//tmp.Cout_array();
	////Check up child and father
	//std::cout << "First child = " << tmp.First_child(n) << " Last Child = " << tmp.Last_child(n) << " Father - " << tmp.Father(n) << "\n";
	//std::cout << "First child = " << tmp.First_child(n - 1) << " Last Child = " << tmp.Last_child(n - 1) << " Father - " << tmp.Father(n - 1) << "\n";
	//std::cout << "First child = " << tmp.First_child(3) << " Last Child = " << tmp.Last_child(3) << " Father - " << tmp.Father(3) << "\n";
	//std::cout << "First child = " << tmp.First_child(4) << " Last Child = " << tmp.Last_child(4) << " Father - " << tmp.Father(4) << "\n";
	//std::cout << "First child = " << tmp.First_child(0) << " Last Child = " << tmp.Last_child(0) << " Father - " << tmp.Father(0) << "\n";

	//std::cout << "Min child = " << tmp.Min_child(n) << "\n";
	//std::cout << "Min child = " << tmp.Min_child(n-1) << "\n";
	//std::cout << "Min child = " << tmp.Min_child(3) << "\n";
	//std::cout << "Min child = " << tmp.Min_child(4) << "\n";
	//std::cout << "Min child = " << tmp.Min_child(0) << "\n";

	//std::cout << "D-heap sorting result\n";
	//tmp.Sort_D();



	//std::cout << "Quicksort\n";
	//quick_sort_v2(arr, 0, arr.size() - 1);

	//std::cout << "You want to see the sorted array?\n    1-Yes\n    0-No\n";
	//bool flag;
	//std::cin >>  flag;
	//if (flag)
	//{
	//	for (int i = 0; i < arr.size(); ++i)
	//	{
	//		std::cout << arr[i] << " ";
	//	}
	//}
	//
	
	

	return 0;
}
