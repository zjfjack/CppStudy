// C++ Primer 5th 13.4

#include <iostream>
#include "Folder.h"
#include "Message.h"

int main() {
    Folder f1, f2;
    Message m1("Hello"), m2("World"), m3("Happy"), m4("New Year"), m5(":-)");

    f1.save(m1);
    f1.save(m2);
    f1.save(m5);

    f2.save(m3);
    f2.save(m4);
    f2.save(m5);

    return 0;
}