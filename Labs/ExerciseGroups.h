#ifndef EXERCISE_GROUPS_H
#define EXERCISE_GROUPS_H

#include <functional>
#include <iostream>
#include <string>
#include "utils.h"
#include <vector>

class ExerciseGroups
{
public:
	class ExerciseGroup
	{
	public:
		ExerciseGroup(std::string name);
		void isActive(bool value);
		bool isActive() const;
		ExerciseGroup& addExercise(std::function<void()> f);
		void runExercises() const;
		std::string name() const;
	private:
		std::string name_;
		bool active_;
		std::vector<std::function<void()>> exercises_;
	};

	ExerciseGroup& addGroup(std::string name);
	ExerciseGroup& operator[](std::string name);
	void runAll() const;

private:
	std::vector<ExerciseGroup> exerciseGroups_;
};

#endif
