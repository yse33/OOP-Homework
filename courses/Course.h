// Yasen Angelov 7MI0600465

#pragma once

#include "../util/MyString.h"
#include "../util/MyVector.hpp"
#include "Assignment.h"

using namespace std;

class Course {
private:
    MyString name;
    MyString password;
    MyVector<Assignment> assignments;
public:
    Course() = default;
    explicit Course(MyString name, MyString password = MyString(""));

    ~Course() = default;

    Course* clone() const;

    MyString getName() const;

    void addAssignment(const Assignment& assignment);
    void removeAssignment(const MyString& assignmentName);
    void viewAssignments() const;
};
