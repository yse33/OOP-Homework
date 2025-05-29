// Yasen Angelov 7MI0600465

#pragma once

#include "../message/Message.h"
#include "../util/MyString.h"
#include "../util/MyVector.hpp"
#include "../courses/Course.h"

using namespace std;

class User {
protected:
    static int userCount;
    int id = 0;
    MyString firstName;
    MyString lastName;
    MyString password;
    MyVector<Message> messages;
    MyVector<Course> courses;
public:
    User() = default;
    User(MyString firstName, MyString lastName, MyString password);

    virtual ~User() = default;

    int getId() const;
    MyString getFullName() const;
    int getCourseId(const MyString& courseName);

    void changePassword(const MyString& currPassword, const MyString& newPassword);
    void addCourse(const Course& course);
    void removeCourse(const Course& course);
    void viewCourses() const;
    void receiveMessage(const Message& message);
    void showInbox();
    void clearInbox();

    friend ostream& operator<<(ostream& os, const User& user);

    virtual User* clone() const = 0;
    virtual MyString getRole() const = 0;
    virtual void showMenu() const = 0;
};