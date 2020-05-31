#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder& f) : messages(f.messages)
{
    for (auto m : messages)
        m->folders.insert(this);
}

Folder& Folder::operator=(const Folder& rhs)
{
    for (auto m : messages)
        m->folders.erase(this);
    messages = rhs.messages;
    for (auto m : rhs.messages)
        m->folders.insert(this);
    return *this;
}

void Folder::save(Message& m)
{
    messages.insert(&m);
    m.folders.insert(this);
}

void Folder::remove(Message& m)
{
    messages.erase(&m);
    m.folders.erase(this);
}

void Folder::addMessage(Message* m)
{
    messages.insert(m);
}

void Folder::removeMessage(Message* m)
{
    messages.erase(m);
}

void swap(Folder& lhs, Folder& rhs) {
    using std::swap;
    for (auto m : lhs.messages)
        m->folders.erase(&lhs);
    for (auto m : rhs.messages)
        m->folders.erase(&rhs);
    swap(lhs.messages, rhs.messages);
    for (auto m : lhs.messages)
        m->folders.insert(&lhs);
    for (auto m : rhs.messages)
        m->folders.insert(&rhs);
}
