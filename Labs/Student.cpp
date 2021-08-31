#include "Student.h"

Student::Student(std::string const& name_)
	: Student{ name_, {} }
{
}

Student::Student(std::string const& name_, std::initializer_list<std::string> subjects_)
	: name {name_}, subjects { subjects_ }
{
}

void Student::display() const
{
	std::cout << name << "[id " << id << "], subjects: ";
	for (auto s : subjects)
	{
		std::cout << s << " ";
	}

	std::cout << std::endl << "Credits: ";
	for (auto c : credits)
	{
		std::cout << c << " ";
	}

	std::cout << std::endl << "Fine accrued: " << fine_accrued << std::endl << std::endl;
}

// TODO:
// Implement international_student::display() here.
