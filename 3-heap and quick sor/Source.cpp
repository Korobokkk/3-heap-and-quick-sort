#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

#include "D_heap.h"
#include "Experiment_A.cpp"
#include "Basic_functions.h";



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

	bool flag;
	std::cout << "See sample sortings\n    1- Yes\n    2- No\n";
	std::cin >> flag;
	if (flag)
	{
		sortings(arr);
	}
	
	char type_experiment;
	std::cout << "Enter the experiment type\n    a- for A\n    b- for B\n";
	std::cin >> type_experiment;
	if (type_experiment == 'a')
	{

	}
	else if (type_experiment == 'b')
	{

	}
	else
	{
		std::cout << "Bruh... Choose 'a' or 'b'\n";
	}

	return 0;
}
