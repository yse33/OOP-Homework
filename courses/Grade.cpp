// Yasen Angelov 7MI0600465

#include "Grade.h"

#include <utility>

Grade::Grade(MyString course, MyString assignment, const double grade, MyString comment)
: course(std::move(course)), assignment(std::move(assignment)), grade(grade), comment(std::move(comment)) {}

Grade* Grade::clone() const {
    return new Grade(*this);
}

MyString Grade::getCourse() const {
    return course;
}

MyString Grade::getAssignment() const {
    return assignment;
}

double Grade::getGrade() const {
    return grade;
}

MyString Grade::getComment() const {
    return comment;
}

ostream& operator<<(ostream& os, const Grade& grade) {
    os << grade.course << ", " << grade.assignment
       << ": " << grade.grade << "(" << grade.comment << ")" << endl;
    return os;
}