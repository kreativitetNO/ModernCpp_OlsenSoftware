#include "ExerciseGroups.h"
#include <iostream>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6a.h"
#include <string>
#include "utils.h"
#include <vector>

int main()
{
	try
	{
		auto eg = ExerciseGroups{};

		eg.addGroup("Lab 1")
			.addExercise(Lab1::ex1)
			.addExercise(Lab1::ex2)
			.addExercise(Lab1::ex3);

		eg.addGroup("Lab 2")
			.addExercise(Lab2::ex1)
			.addExercise(Lab2::ex2)
			.addExercise(Lab2::ex3);

		eg.addGroup("Lab 3")
			.addExercise(Lab3::ex1);

		eg.addGroup("Lab 4")
			.addExercise(Lab4::ex1);

		eg.addGroup("Lab 5")
			.addExercise(Lab5::ex1);

		eg.addGroup("Lab 6a")
			.addExercise(Lab6a::ex1);

		eg["Lab 6a"].isActive(true);

		eg.runAll();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}


