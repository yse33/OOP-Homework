// Yasen Angelov 7MI0600465

#pragma once

#include "../util/MyString.h"
#include "../util/MyVector.hpp"

using namespace std;

class Assignment {
private:
    MyString name;
    MyVector<MyString> submissions;
public:
    Assignment() = default;
    explicit Assignment(MyString name);

    ~Assignment() = default;

    Assignment* clone() const;

    MyString getName() const;
    MyVector<MyString> getSubmissions() const;

    void addSubmission(const MyString& submission);

    friend ostream& operator<<(ostream& os, const Assignment& assignment);
};
