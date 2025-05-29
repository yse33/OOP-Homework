#pragma once

#include "../util/MyString.h"
#include <iostream>
#include <ctime>

using namespace std;

class Message {
private:
    int senderId = 0;
    MyString text;
    time_t timestamp = time(nullptr);
    bool isRead = false;
public:
    Message() = default;
    Message(int senderId, MyString text, time_t timestamp = time(nullptr), bool isRead = false);

    ~Message() = default;

    Message* clone() const;

    friend ostream& operator<<(ostream& os, const Message& message);
};