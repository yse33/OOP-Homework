// Yasen Angelov 7MI0600465

#include "Student.h"

//#include <utility>
#include "../util/MyString.h"

Student::Student(MyString firstName, MyString lastName, MyString password)
    : User(std::move(firstName), std::move(lastName), std::move(password)) {}

User* Student::clone() const {
    return new Student(*this);
}

void Student::showMenu() const {
    cout << "1. View courses" << endl;
    cout << "2. View assignments" << endl;
    cout << "3. Submit assignment" << endl;
    cout << "4. View grades" << endl;
    cout << "5. Send message" << endl;
    cout << "6. View inbox" << endl;
    cout << "7. Clear inbox" << endl;
    cout << "8. Change password" << endl;
    cout << "9. Logout" << endl;
}

MyString Student::getRole() const {
    return MyString("Student");
}

void Student::addGrade(const Grade& grade) {
    grades.push(grade);
}

void Student::viewGrades() const {
    cout << "Grades:" << endl;
    for (int i = 0; i < grades.getSize(); ++i) {
        cout << grades[i] << endl;
    }
}
