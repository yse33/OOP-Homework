// Yasen Angelov 7MI0600465

#include "User.h"

int User::userCount = 0;

User::User(MyString firstName, MyString lastName, MyString password)
    : firstName(std::move(firstName)), lastName(std::move(lastName)), password(std::move(password)) {
    id = ++userCount;
}

int User::getId() const {
    return id;
}

MyString User::getFullName() const {
    return firstName + " " + lastName;
}

int User::getCourseId(const MyString& courseName) {
    for (int i = 0; i < courses.getSize(); ++i) {
        if (courses[i]->getName() == courseName) {
            return i;
        }
    }
    return -1;
}

void User::changePassword(const MyString& currPassword, const MyString& newPassword) {
    if (currPassword != password) {
        cout << "Current password is incorrect!" << endl;
        return;
    }
    password = newPassword;
    cout << "Password changed successfully!" << endl;
}

void User::addCourse(const Course& course) {
    const int courseId = getCourseId(course.getName());
    if (courseId != -1) cout << "You are already enrolled in this course!" << endl;
    else courses.push(course);
}

void User::removeCourse(const Course& course) {
    const int courseId = getCourseId(course.getName());
    if (courseId == -1) cout << "Course not found!" << endl;
    else courses.remove(courseId);
}

void User::viewCourses() const {
    if (courses.isEmpty()) {
        cout << "No courses enrolled!" << endl;
        return;
    }
    cout << "Your courses:" << endl;
    for (size_t i = 0; i < courses.getSize(); ++i) {
        cout << courses[i]->getName() << endl;
    }
}

void User::receiveMessage(const Message& message) {
    messages.push(message);
}

void User::showInbox() {
    if (messages.isEmpty()) {
        cout << "No messages to show!" << endl;
        return;
    }
    for (size_t i = 0; i < messages.getSize(); i++) {
        cout << messages[i] << endl;
    }
}

void User::clearInbox() {
    messages.clear();
    cout << "Inbox cleared!" << endl;
}

ostream& operator<<(ostream& os, const User& user) {
    os << user.getFullName() << " | " << user.getRole() << " | " << user.getId();
    return os;
}