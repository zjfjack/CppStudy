#pragma once
#include <set>

class Message;

class Folder
{
    friend Message;
    friend void swap(Folder& lhs, Folder& rhs);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);

    void save(Message&);
    void remove(Message&);

private:
    std::set<Message*> messages;
    void addMessage(Message* m);
    void removeMessage(Message* m);
};

void swap(Folder& lhs, Folder& rhs);