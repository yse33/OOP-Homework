// Yasen Angelov 7MI0600465

#pragma once

#include "../message/Message.h"
#include "../util/MyString.h"
#include "../util/MyVector.h"

using namespace std;

class User {
protected:
    static int userCount;
    int id = 0;
    MyString firstName;
    MyString lastName;
    MyString password;
    MyVector<Message> messages;
public:
    User(MyString firstName, MyString lastName, MyString password);

    virtual ~User() = default;

    virtual void showMenu() = 0;
    void receiveMessage(const Message& message);
    void showInbox();
    void clearInbox();
    void changePassword(const MyString& currPassword, const MyString& newPassword);

    virtual MyString getRole() const = 0;
    int getId() const;
    MyString getFullName() const;

    friend ostream& operator<<(ostream& os, const User& user);
};