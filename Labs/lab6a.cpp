#include "lab6a.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void printsum(int i, int j)
{
	std::cout << (i + j) << std::endl;
}

void Lab6a::ex1()
{
	std::vector<int> v{ 100, 200, 300 };

	std::for_each(v.begin(), v.end(), std::bind(printsum, std::placeholders::_1, 10));
}