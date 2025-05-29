// Yasen Angelov 7MI0600465

#pragma once

#include "Student.h"
#include "User.h"
#include "../courses/Course.h"

class Teacher : public User {
public:
    Teacher() = default;
    Teacher(MyString firstName, MyString lastName, MyString password);

    void createAssignment(const Course& course, const Assignment& assignment);
    void gradeAssignment(const Grade& grade, Student& student) const;

    User* clone() const override;
    void showMenu() const override;
    MyString getRole() const override;
};