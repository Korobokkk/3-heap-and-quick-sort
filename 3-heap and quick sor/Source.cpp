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
		void (*function_selection)(int, int&, int&) {};
		if (choose < 1 || choose>3)
		{
			std::cout << "Incorrect input num!!!";
			std::exit(1);
		}
		else if (choose == 1)
		{
			function_selection = pseudo_random;
		}
		else if (choose == 2)
		{
			function_selection = ascending_generation;
		}
		else {
			function_selection = descending_generation;
		}

		std::cout << "You generated array:\n";		
		for (int i = 0; i < n; i++)
		{
			int tmp = std::rand() % (w-q+1) + q;
			arr.push_back(tmp);
			std::cout << tmp << " ";
			if (i % 10 == 9)
			{
				std::cout << "\n";
			}
			function_selection(tmp, q, w);
		}
		std::cout << std::endl;
	}
	else//for .exe file
	{
		//need write
	}
}

std::vector<int> quick_sort(std::vector<int> arr)
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
	std::vector<int> less(quick_sort(less_or_equal_than));
	std::vector<int> more(quick_sort(more_than));
	
	less.push_back(arr[index_last_elem]);
	std::copy(more.begin(), more.end(),std::back_inserter(less));

	return less;//need refuct with create vector
}

int parent(int i)
{
	return (i - 1) / 3;
}
int child(int i, int k)//k from [1, 2, 3] maybe[1,]
{
	return 3 * i + k;
}

void shift_down(std::vector<int> arr, int i, int n)
{
	int index_max_child = child(i, 0);
	while (true)
	{
		for (int k = 1; k < 3; k++)
		{
			int tmp = child(i, k);
			if (tmp > n && arr[index_max_child] < arr[tmp])//will be no crash because the first condition is checked earlier
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

std::vector<int> three_heap_sort(std::vector<int> arr)//added n in input args and in QuickSort 
{
	int n = (int)arr.size();//tmp


	// code
	return arr;// другой return
}

bool sort_selection(std::vector<int> arr)
{
	char select;
	std::cout << "Sorting selection:\n    1-for Quicksort\n    2-for 3-heap sort\n    3-for exit\n";
	std::cin >> select;
	std::vector<int>(*select_sort)(std::vector<int> arr);

	if (select == '1')
	{
		select_sort = quick_sort;
	}
	else if(select == '2')
	{
		select_sort = three_heap_sort;
	}
	else
	{
		std::cout << "Exit Complete\n";
		return false;
	}

	auto wall_start = std::chrono::high_resolution_clock::now();
	std::vector<int> sort_res(select_sort(arr));
	auto wall_stop = std::chrono::high_resolution_clock::now();
	auto wall_time = std::chrono::duration_cast<std::chrono::milliseconds>(wall_stop - wall_start).count();

	std::cout << "Result:\n";
	int cout_counter = 0;
	/*make void check_result_sort!!!!!!!!!!!!!*/
	for (int x : sort_res)
	{
		std::cout << x << " ";
		cout_counter++;
		if (cout_counter % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl << "Time Quicksort: " << wall_time << "\n";
	return true;
}


int main()
{
	char type_of_reading = type_data_input();
	int n, q, w;
	sellection_of_parameters(n, q, w);
	
	//init arr
	std::vector<int> arr;
	filling_an_array(arr, type_of_reading, n, q, w);
	
	//work with arr
	while (sort_selection(arr))
	{
	}

	
	// work with arr 2
	// output arr and time sorting

	return 0;
}
