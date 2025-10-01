//#include <vector>
#include "D_heap.h"

D_heap::D_heap(int d, std::vector<int>& arr)
{
	if (d < 2)
	{
		std::cout << "D must be greater or equal than 2. Auto select d=2\n";
	}
	else
	{
		this->d = d;
	}

	this->key = arr;
	this->array=arr;
	this->n = array.size();
}
void D_heap::Cout_array()
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << array[i] << " ";
	}

	std::cout << "\nVector size = " << n << "\nCurr D index d = \n" << d << "\n";
}
int D_heap::First_child(int i) {
	int index_child = i * d + 1;
	if (out_range(index_child))
	{
		return -1;
	}

	return i * d + 1;
}
int D_heap::Last_child(int i)
{
	int index_child= First_child(i);
	if (out_range(index_child))
	{
		return -1;
	}
	else if (index_child + 2 < n)
	{
		return index_child + 2;
	}
	else if (index_child + 1 < n)
	{
		return index_child + 1;
	}

	return index_child;
}
int D_heap::Father(int i)
{
	if (out_range(i))
	{
		return -1;
	}

	return (i - 1) / 3;
}

int D_heap::Min_child(int i)
{
	int x = First_child(i);
	int y = Last_child(i);
	if (x == -1)
	{
		return i;
	}
	int ind_tmp_min_key = x;
	for (x ; x <= y; ++x)
	{
		if (key[x]<key[ind_tmp_min_key])
		{
			ind_tmp_min_key = x;
		}
	}
	return ind_tmp_min_key;
}
bool D_heap::out_range(int i)
{
	if (i >= 0 && i < n) 
	{
		return false;
	} 
};