#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include "D_heap.h"

char type_data_input();
void sellection_of_parameters(int& n, int& q, int& w);
void filling_an_array(std::vector<int>& arr, char type_of_reading, int n, int q, int w);
int dividing(std::vector<int>& arr, int l, int r);
void Cout_quick_sort_res(std::vector<int>& arr);
void quick_sort_v2(std::vector<int>& arr, int l, int r);
void sortings(std::vector<int>& arr);