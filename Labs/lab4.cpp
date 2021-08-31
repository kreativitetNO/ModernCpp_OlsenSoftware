#include "InternationalStudent.h"
#include "lab4.h"
#include <memory>
#include "Student.h"
#include <vector>

void Lab4::ex1()
{
	Student s1 { "Christian", { "Knitting", "Taekwando"} };
	Student s2 { "Fred" };
	Student s3 ("David");
	Student s4 ("Richard", { "Acting", "Drinking" });

	InternationalStudent s5{ "Gunther", { "Lederhosen production", "Stereotyping 101" } };
	InternationalStudent s6{ "Hans" };

	s1.display();
	s2.display();
	s3.display();
	s4.display();
	s5.display();
	s6.display();
}