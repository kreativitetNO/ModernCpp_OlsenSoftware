#ifndef INTERNATIONAL_STUDENT_H
#define INTERNATIONAL_STUDENT_H

#include "Student.h"

class InternationalStudent :
    public Student
{
public:
    using Student::Student;

    void display() const override;
};

#endif