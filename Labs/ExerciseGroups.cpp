#include <exception>
#include "ExerciseGroups.h"

ExerciseGroups::ExerciseGroup::ExerciseGroup(std::string name)
	: name_ { name }, active_ { false }
{
}

void ExerciseGroups::ExerciseGroup::isActive(bool value)
{
	active_ = value;
}

bool ExerciseGroups::ExerciseGroup::isActive() const
{
	return active_;
}

ExerciseGroups::ExerciseGroup& ExerciseGroups::ExerciseGroup::addExercise(std::function<void()> f)
{
	exercises_.push_back(f);
	return *this;
}

void ExerciseGroups::ExerciseGroup::runExercises() const
{
	if (active_)
	{
		for (auto&& exercise : exercises_)
			exercise();
	}
}

std::string ExerciseGroups::ExerciseGroup::name() const
{
	return name_;
}

ExerciseGroups::ExerciseGroup& ExerciseGroups::addGroup(std::string name)
{
	exerciseGroups_.push_back(ExerciseGroup{ name });
	return exerciseGroups_.back();
}

ExerciseGroups::ExerciseGroup& ExerciseGroups::operator[](std::string name)
{
	auto group = std::find_if(exerciseGroups_.begin(), exerciseGroups_.end(), [&](auto exerciseGroup) { return exerciseGroup.name() == name; });
	if (group == exerciseGroups_.end())
		throw std::runtime_error { "No such group (" + name + ")" };
	return *group;
}

void ExerciseGroups::runAll() const
{
	for (auto&& exerciseGroup : exerciseGroups_)
	{
		if (exerciseGroup.isActive())
		{
			std::cout << heading(exerciseGroup.name());
			exerciseGroup.runExercises();
		}
	}
}
