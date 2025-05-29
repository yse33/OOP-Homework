// Yasen Angelov 7MI0600465

#include "Teacher.h"

Teacher::Teacher(MyString firstName, MyString lastName, MyString password)
    : User(std::move(firstName), std::move(lastName), std::move(password)) {}

User* Teacher::clone() const {
    return new Teacher(*this);
}

void Teacher::showMenu() const {

}

MyString Teacher::getRole() const {
    return MyString("Teacher");
}

void Teacher::createAssignment(const Course& course, const Assignment& assignment) {
    for (size_t i = 0; i < courses.getSize(); ++i) {
        if (courses[i]->getName() == course.getName()) {
            courses[i]->addAssignment(assignment);
            break;
        }
    }
}

void Teacher::gradeAssignment(const Grade& grade, Student& student) const {
    for (size_t i = 0; i < courses.getSize(); ++i) {
        if (courses[i]->getName() == grade.getCourse()) {
            student.addGrade(grade);
            break;
        }
    }
}