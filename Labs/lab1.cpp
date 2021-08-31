#include <iostream>
#include <array>
#include "BoundedBuffer.h"
#include "lab1.h"
#include <map>
#include "utils.h"

void Lab1::ex1()
{
	auto fancyDoubler = [&](auto n) { return 2 * n; };

	std::cout << get_type(fancyDoubler) << std::endl;
}

void Lab1::ex2()
{
	int oldSchoolArray[] { 1, 2, 3, 4, 5 };

	for (auto const i : oldSchoolArray)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::array<int, 5> myArr { 1, 2, 3, 4, 5 };

	for (auto const i : myArr)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::map<int, std::string> team = { { 1, "Alisson"},
										{ 2, "Robertson"}};

	for (auto const& player : team)
	{
		std::cout << player.first << ": " << player.second << std::endl;
	}
}
void Lab1::ex3()
{
	BoundedBuffer<int, 8> myBuffer;

	int i = 1;
	for (auto& v : myBuffer)
	{
		v = i;
		i *= 2;
	}

	for (auto v : myBuffer)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
}