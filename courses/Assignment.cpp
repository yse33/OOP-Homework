#include "Assignment.h"

#include <utility>

Assignment::Assignment(MyString name) : name(std::move(name)) {}

Assignment* Assignment::clone() const {
    return new Assignment(*this);
}

MyString Assignment::getName() const {
    return name;
}

MyVector<MyString> Assignment::getSubmissions() const {
    return submissions;
}

void Assignment::addSubmission(const MyString &submission) {
    submissions.push(submission);
}

ostream& operator<<(ostream &os, const Assignment &assignment) {
    os << assignment.name << endl;
    return os;
}