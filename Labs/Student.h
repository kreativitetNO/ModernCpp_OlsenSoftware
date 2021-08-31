#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include <iostream>

class Student
{
public:
	// TODO:
	// Declare 2 constructors here:
	//   - the 1st constructor takes just the student's name.
	//   - the 2nd constructor takes the student's name plus a list of subjects.
	Student(std::string const& name_);
	Student(std::string const& name_, std::initializer_list<std::string> subjects_);


	virtual void display() const;

private:
	std::string name;
	std::list<std::string> subjects;
	int credits[4] = { 10, 0, 0, 0 };

	double fine_accrued = 50.0;

	int id = generateId();

	static int generateId()
	{
		static int id = 0;
		int result = id++;
		return result;
	};
};


// TODO: 
// Define an international_student class.
// An international student is a kind of student, with the same constructors.
// Override display() to display a prefix message "[International student]", 
// followed by the normal student data.

#endif