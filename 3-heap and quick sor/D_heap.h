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
public:
	D_heap(int d, std::vector<int>& arr);
	int First_child(int i);
	int Last_child(int i);
	int Father(int i);
	void Diving();//погружение
	void Ascent();//всплытие
	void Get_min();
	void Form_a_quere();//образовать очередь
	void Cout_array();
};

