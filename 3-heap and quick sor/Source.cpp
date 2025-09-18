#include <iostream>
#include <vector>
#include <cstdlib>
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
		}//need fix problem with continie working prog
		return type_of_reading;
	}
	catch (const char* error_massage)
	{
		std::cout << error_massage;
	}
	return type_of_reading;
}
void sellection_of_parameters(int &n, int &q, int &w)
{
	try
	{
		std::cout << "Sellect n. *(This is the number of elements in array)\n";
		std::cin >> n;
		if (n < 2 )
		{
			throw "incorrect 'n'.'n' must be greater than 1.\n";
		}

		std::cout << "Sellect 'q'. *(This is the minimum value of the element in array)\n";
		std::cin >> q;
		if (q < 1)
		{
			throw "incorrect 'q'.'q' must be greater or equal than 1.\n";
		}

		std::cout << "Sellect 'w'. *(This is the minimum value of the element)\n";
		std::cin >> w;
		if (w <= q)
		{
			throw "incorrect 'w'.'w' must be greater or equal than 'q'.\n";
		}
	}
	catch (const char* error_massage)
	{
		std::cout << error_massage;
	}
}
void filling_an_array()
{
	//in progress
}


int main()
{
	char type_of_reading = type_data_input();
	int n, q, w;
	sellection_of_parameters(n, q, w);
	//init arr
	std::vector<int> arr;
	std::cout <<"n - "<< n << ", q - " << q << ", w - " << w << "\n";//debug
	std::cout << "You generated array:\n";
	if (type_of_reading =='1')//for rand
	{
		for (int i = 0; i < n; i++)
		{
			int tmp = std::rand()%w+q;
			arr.push_back(tmp);
			std::cout << tmp<< " ";
			if (i % 10 == 9)
			{
				std::cout << "\n";
			}
		}

	}
	else//for .exe file
	{

	}
			
	// work with arr
	// work with arr 2
	// output arr and time sorting

	return 0;
}
