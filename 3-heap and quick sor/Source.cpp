#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
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
void pseudo_random(int tmp, int &q, int &w)
{
	return;
}
void ascending_generation(int tmp,int& q, int& w)
{
	q = tmp;
	return;
}
void descending_generation(int tmp, int& q, int& w)
{
	w = tmp;
	return;
}


void filling_an_array( std::vector<int> &arr, char type_of_reading, int n, int q, int w)//
{
	srand((unsigned int)time(NULL));
	if (type_of_reading == '1')//for rand
	{

		std::cout << "n - " << n << ", q - " << q << ", w - " << w << "\n\n" << "Select an array generation method:\n    1.-Pseudo-random generation\n    2- Ascending generation\n    3- Descending generation\n";//debug
		int choose;
		std::cin >> choose;
		//void (*function_selection)(int, int&, int&) {};
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
				/*if (i % 10 == 9)
				{
					std::cout << "\n";
				}*/
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
//void devive(std::vector<int>, int i, int j, int i1)
//{
//
//}
//
//std::vector<int> quick_sortv2(std::vector<int> arr, int i, int j)
//{
//	int i1;
//	if (i < j)
//	{
//		devive(arr, i, j);
//		quick_sortv2(arr, i, i1 - 1);
//		quick_sortv2(arr, i1 + 1, j);
//	}
//
//}

//std::vector<int> quick_sort(std::vector<int> arr, int min_index_value, int n)
//{
//	if (min_index_value >= n)
//	{
//		return arr;
//	}
//
//	/*std::vector<int> less_or_equal_than;
//	std::vector<int> more_than;*/
//	
//	//int index_last_elem = (int)arr.size() - 1;
//	int index_last_elem = n- 1;
//
//	/*for (int i = 0; i < index_last_elem; i++)
//	{
//		if (arr[i] <= arr[index_last_elem])
//		{
//			less_or_equal_than.push_back(arr[i]);
//		}
//		else
//		{
//			more_than.push_back(arr[i]);
//		}
//	}*/
//
//	for (int i = 0; i < index_last_elem; i++)
//	{
//		if (arr[i] >= arr[index_last_elem])
//		{
//			arr.push_back(arr[i]);
//			arr.erase(arr.begin()+ i);
//			i--;
//			index_last_elem--;
//		}
//	}
//	quick_sort(arr, 0, index_last_elem);
//	quick_sort(arr, index_last_elem + 1, n);
//	
//
//	less.push_back(arr[index_last_elem]);
//	std::copy(more.begin(), more.end(),std::back_inserter(less));
//
//	return less;//need refuct with create vector
//}

std::vector<int> quick_sort(std::vector<int> arr, int min_value, int n)
{
	if (arr.size() <= 1)
	{
		return arr;
	}

	std::vector<int> less_or_equal_than;
	std::vector<int> more_than;

	int index_last_elem = (int)arr.size() - 1;

	for (int i = 0; i < index_last_elem; i++)
	{
		if (arr[i] <= arr[index_last_elem])
		{
			less_or_equal_than.push_back(arr[i]);
		}
		else
		{
			more_than.push_back(arr[i]);
		}
	}
	std::vector<int> less(quick_sort(less_or_equal_than, min_value, n));
	std::vector<int> more(quick_sort(more_than,min_value, n));

	less.push_back(arr[index_last_elem]);
	std::copy(more.begin(), more.end(), std::back_inserter(less));

	return less;//need refuct with create vector
}



// 3-heapsort function

int parent(int i)
{
	return (i - 1) / 3;
}
int child(int i, int k)//k from [1, 2, 3] maybe[1,]
{
	return 3 * i + k;
}

void shift_down(std::vector<int>& arr, int i, int n)
{
	int index_max_child = i;
	while (true)
	{
		for (int k = 1; k <= 3; k++)
		{
			int tmp = child(i, k);
			if (tmp < n && arr[index_max_child] < arr[tmp])
			{
				index_max_child = tmp;
			}
		}
		if (i == index_max_child)
		{
			break;
		}
		std::swap(arr[i], arr[index_max_child]);
		i = index_max_child;
	}
	return;
}



std::vector<int> three_heap_sort(std::vector<int> arr, int i, int n)//added n in input args and in QuickSort 
{
	
	for (int i = n-2 / 3; i >= 0; i--)
	{
		shift_down(arr, i, n);
	}

	for (int i = n - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);    // Перемещаем максимум в конец
		shift_down(arr, 0, i);
	}
	return arr;
}


void out_array_sort_res(std::vector<int> arr)
{
	std::cout << "Result:\n";
	int cout_counter = 0;
	for (int x : arr)
	{
		std::cout << x << " ";
		cout_counter++;
		if (cout_counter % 10 == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << "\n";

}

bool sort_selection(std::vector<int> arr, int min_index_elemint, int n)
{
	char select;
	std::cout << "Sorting selection:\n    1-for Quicksort\n    2-for 3-heap sort\n    3-for exit\n";
	std::cin >> select;
	std::vector<int>(*select_sort)(std::vector<int> arr,int min_index_elem, int n);

	if (select == '1')
	{
		select_sort = quick_sort;
	}
	else if(select == '2')
	{/*
		std::cout << "tmp not working\n";
		return false;*/
		select_sort = three_heap_sort;
	}
	else
	{
		std::cout << "Exit Complete\n";
		return false;
	}

	auto wall_start = std::chrono::high_resolution_clock::now();
	std::vector<int> sort_res(select_sort(arr,0, n));
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::seconds>(wall_stop - wall_start).count();
	
	bool see_result;
	std::cout << "Do you want to see the sorted array?\n    1-YES\n    0-NO\n";
	std::cin >> see_result;
	if (see_result)
	{
		out_array_sort_res(sort_res);
	}
	std::cout <<  "Time Quicksort: " << wall_time << "\n";
	return true;
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
	
	//work with arr
	while (sort_selection(arr,0, n))
	{
	}
	return 0;
}
