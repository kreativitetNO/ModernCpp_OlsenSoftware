#include <functional>
#include <forward_list>
#include <vector>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"

int main()
{
	struct exerciseGroup
	{
		std::string name;
		bool enabled;
		std::forward_list<std::function<void()>> exercises;
	};

	std::forward_list<exerciseGroup> exerciseGroups = {
		{
			"Lab1",
			true,
			{ Lab1::ex1, Lab2::ex2, Lab1::ex3 }
		},
		{
			"Lab2",
			true,
			{ Lab2::ex1, Lab2::ex2, Lab2::ex3 }
		},
		{
			"Lab3",
			true,
			{ Lab3::ex1 }
		},
		{
			"Lab4",
			true,
			{ Lab4::ex1 }
		}
	};

	for (auto&& exerciseGroup : exerciseGroups )
	{
		if (!exerciseGroup.enabled) continue;
		for (auto&& exercise : exerciseGroup.exercises)
		{
			exercise();
		}
	}
}


