// Yasen Angelov 7MI0600465

#pragma once

#include "../util/MyString.h"

using namespace std;

class Grade {
private:
    MyString course;
    MyString assignment;
    double grade = 0;
    MyString comment;
public:
    Grade() = default;
    Grade(MyString course, MyString assignment, double grade, MyString comment = MyString(""));

    Grade* clone() const;

    MyString getCourse() const;
    MyString getAssignment() const;
    double getGrade() const;
    MyString getComment() const;

    friend ostream& operator<<(ostream& os, const Grade& grade);
};
