// Yasen Angelov 7MI0600465

#pragma once

#include "User.h"
#include "../util/MyString.h"
#include "../util/MyVector.hpp"
#include "../courses/Grade.h"

using namespace std;

class Student : public User {
private:
    MyVector<Grade> grades;
public:
    Student() = default;
    Student(MyString firstName, MyString lastName, MyString password);

    User* clone() const override;
    void showMenu() const override;
    MyString getRole() const override;

    void addGrade(const Grade& grade);
    void viewGrades() const;
};
