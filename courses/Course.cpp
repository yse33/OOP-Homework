// Yasen Angelov 7MI0600465

#include "Course.h"

#include <utility>

Course::Course(MyString name, MyString password) : name(std::move(name)), password(std::move(password)) {}

Course* Course::clone() const {
    return new Course(*this);
}

MyString Course::getName() const {
    return name;
}

void Course::addAssignment(const Assignment &assignment) {
    assignments.push(assignment);
}

void Course::removeAssignment(const MyString &assignmentName) {
    for (size_t i = 0; i < assignments.getSize(); i++) {
        if (assignments[i]->getName() == assignmentName) {
            assignments.remove(i);
            return;
        }
    }
}

void Course::viewAssignments() const {
    for (size_t i = 0; i < assignments.getSize(); i++) {
        cout << assignments[i];
    }
}