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

	std::cout << "\nVector size = " << n << "\nCurr D index d = " << d << "\n";
}
int D_heap::First_child(int i) {
	int index_child = i * d + 1;
	if (Out_range(index_child))
	{
		return -1;
	}

	return i * d + 1;
}
int D_heap::Last_child(int i)
{
	int index_child= First_child(i);
	if (Out_range(index_child))
	{
		return -1;
	}
	else if ((index_child + d - 1) < n-1) {
		return index_child + d - 1;
	}
	else {
		return n-1;
	}
	
	/*else if (index_child + 2 < n)
	{
		return index_child + 2;
	}
	else if (index_child + 1 < n)
	{
		return index_child + 1;
	}*/

	return index_child;
}
int D_heap::Father(int i)
{
	if (Out_range(i))
	{
		return -1;
	}

	return (i - 1) / d;
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

void D_heap::Diving(int i)
{
	int diving_key = key[i];
	int diving_el_array = array[i];
	int c = Min_child(i);
	while (c != i && diving_key > key[c])
	{
		key[i] = key[c];
		array[i] = array[c];
		
		i = c;
		c = Min_child(i);
	}
	key[i] = diving_key;
	array[i] = diving_el_array;
}

void D_heap::Ascent(int i)
{
	int ascent_key = key[i];
	int ascent_array = array[i];
	int p = Father(i);
	while (p != 0 && key[i]<key[p])
	{
		key[i] = key[p];
		array[i] = array[p];
		i = p;
		p = Father(i);
	}
	key[i] = ascent_key;
	array[i] = ascent_array;
}

void D_heap::Get_min() {
	 int min_key = key[0];
	 int min_el_array = array[0];
	key[0] = key[n - 1];
	array[0] = array[n - 1];

	key.pop_back();
	array.pop_back();

	n -= 1;
	if (n > 1)
	{
		Diving(0);
	}
	result_array.push_back(min_el_array);
}

void D_heap::Form_a_quere()
{
	for (int i = n - 1; i >= 0; --i)//можно бустануть обращаясь только к родителям
	{
		Diving(i);
	}
}
bool D_heap::Out_range(int i)
{
	if (i >= 0 && i < n) 
	{
		return false;
	} 
	return true;
};
void D_heap::Sort_D()
{
	Form_a_quere();
	while (n > 0)
	{
		Get_min();
	}
	int tmp;
	int index_replaced_elem;
	int size = result_array.size();

}

void D_heap::Cout_result_sorting_array()
{
	std::cout << d << "-Heap sort result\n";
	for (int i = 0; i < result_array.size(); ++i)
	{
		std::cout << result_array[i] << " ";
	}
	std::cout << "\n";
	
}