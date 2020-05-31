#pragma once
#include <string>
#include <set>

class Folder;

class Message
{
    friend Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Message(const std::string& str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*> folders;

    // Since folders is a set, which means if message is in folders, it won't be added.
    void addToFolders(const Message&);
    void removeFromFolders();
};

void swap(Message&, Message&);