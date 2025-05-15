// Yasen Angelov 7MI0600465

#include "User.h"

int User::userCount = 0;

User::User(MyString firstName, MyString lastName, MyString password)
    : firstName(std::move(firstName)), lastName(std::move(lastName)), password(std::move(password)) {
    id = ++userCount;
}

void User::receiveMessage(const Message& message) {
    messages.push(message);
}

void User::showInbox() {
    if (messages.isEmpty()) {
        cout << "Inbox is empty!" << endl;
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

void User::changePassword(const MyString& currPassword, const MyString& newPassword) {
    if (currPassword != password) {
        cout << "Current password is incorrect!" << endl;
        return;
    }
    password = newPassword;
    cout << "Password changed successfully!" << endl;
}

int User::getId() const {
    return id;
}

MyString User::getFullName() const {
    return firstName + " " + lastName;
}

ostream& operator<<(ostream& os, const User& user) {
    os << user.getFullName() << " | " << user.getRole() << " | " << user.getId();
    return os;
}