#include "Message.h"
#include "Folder.h"

Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
    addToFolders(m);
}

Message& Message::operator=(const Message& rhs)
{
    removeFromFolders();
    contents = rhs.contents;
    folders = rhs.folders;
    addToFolders(rhs);
    return *this;
}

Message::~Message()
{
    removeFromFolders();
}

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMessage(this);
}
void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.removeMessage(this);
}

// Since folders is a set, which means if message is in folders, it won't be added.
void Message::addToFolders(const Message& m)
{
    for (auto f : m.folders)
        f->addMessage(this);
}
void Message::removeFromFolders()
{
    for (auto f : folders)
        f->removeMessage(this);
}

void swap(Message& lhs, Message& rhs)
{
    lhs.removeFromFolders();
    rhs.removeFromFolders();
    std::swap(lhs.contents, rhs.contents);
    std::swap(lhs.folders, rhs.folders);
    lhs.addToFolders(lhs);
    rhs.addToFolders(rhs);
}