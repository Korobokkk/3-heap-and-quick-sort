//#include <vector>
#include "D_heap.h"

D_heap::D_heap(int d, std::vector<int>& arr)
{
	if (d < 2)
	{
		std::cout << "D must be greater or equal than 2. auto select d=2\n";
	}
	else
	{
		this->d = d;
	}
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
	if (index_child >= n)
	{
		return -1;
	}
	return i * d + 1;
}
int D_heap::Last_child(int i)
{
	int index_child= First_child(i);
	if (index_child == -1)
	{
		return index_child;
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
	if (i < 0)
	{
		return -1;
	}
	else if(i >= n)
	{
		std::cout << "\n uncorrect i > n\n";
		return -1;
	}
	return (i - 1) / 3;
}


