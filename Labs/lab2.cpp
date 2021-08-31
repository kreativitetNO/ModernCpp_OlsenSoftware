#include "BoundedBuffer.h"
#include <iomanip>
#include <iostream>
#include "lab2.h"
#include <string>
#include "utils.h"

void Lab2::ex1()
{
	BoundedBuffer<double, 6> buffer1;

	std::cout << "BoundedBuffer<double, 6> size: " << buffer1.allocsize() << std::endl;

	//BoundedBuffer<double, 5> buffer2;

	using BigType = struct { unsigned char data[100]; };

	//BoundedBuffer<BigType, 6> buffer3;
}

void Lab2::ex2()
{
	long n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5, n6 = 6;
	std::cout << "Sum of ns: " << adder(n1, n2, n3, n4, n5, n6) << std::endl;

	std::string s1 = "Andy", s2 = "Jayne", s3 = "Emily", s4 = "Tom";
	std::cout << "Sum of names: " << adder(s1, s2, s3, s4) << std::endl;
}

void Lab2::ex3()
{
	bool result1 = pair_comparer(180, 180, 42, 42, 101, 101);
	std::cout << std::boolalpha << "result1: " << result1 << std::endl << std::endl;

	bool result2 = pair_comparer("mickey", "mickey", "donald", "donald");
	std::cout << std::boolalpha << "result2: " << result2 << std::endl << std::endl;

	bool result3 = pair_comparer("mickey", "minnie", "donald", "goofy");
	std::cout << std::boolalpha << "result3: " << result3 << std::endl << std::endl;
}
