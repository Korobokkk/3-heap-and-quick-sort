#pragma once
#include <iostream>
#include <vector>
//#include "D_heap.cpp"
class D_heap
{
private:
	int d = 2;
	std::vector<int> array;
	int n=0;
	std::vector<int> key;
	std::vector<int> result_array;
public:
	D_heap(int d, std::vector<int>& arr);
	int First_child(int i);
	int Last_child(int i);
	int Father(int i);
	int Min_child(int i);
	void Diving(int i);//погружение
	void Ascent(int i);//всплытие
	void Get_min();
	void Form_a_quere();//образовать очередь
	void Cout_array();
	bool Out_range(int i);
	void Sort_D();
	void Cout_result_sorting_array();
};

