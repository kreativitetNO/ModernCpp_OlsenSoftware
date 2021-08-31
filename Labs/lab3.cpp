#include <fstream>
#include <iostream>
#include "lab3.h"
#include <string>
#include <regex>

void Lab3::ex1()
{
	std::ifstream file("Data.txt");
	std::string line;
	while (std::getline(file, line))
	{
		parse_line(line);
	}
}

void Lab3::parse_line(const std::string& line)
{
	std::regex const re{ R"((\d{3})\s(\w+),(\w+),(\d+))" };
	std::smatch match;
	if (std::regex_search(line, match, re))
	{
		std::cout << "id: " << match.str(1)
			      << " name: " << match.str(2)
			      << " location: " << match.str(3)
			      << " age: " << match.str(4)
			      << std::endl;
	}
}
