#include "Message.h"

Message::Message(const int senderId, MyString text, const time_t timestamp, const bool isRead)
    : senderId(senderId), text(std::move((text))), timestamp(timestamp), isRead(isRead) {}

Message* Message::clone() const {
    return new Message(*this);
}

ostream& operator<<(ostream& os, const Message& message) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M %d.%m.%Y", localtime(&message.timestamp));

    os << buffer << ", sent by " << message.senderId << ": " << message.text << endl;
    return os;
}