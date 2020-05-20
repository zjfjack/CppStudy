#include <iostream>

int pointer()
{
    char* buffer = new char[9];
    memset(buffer, 0, 9);
    char** ptr = &buffer;
    int a = 5;
    int& b = a;
    std::cout << sizeof(b) << " " << &b << " " << &a;
    //std::cout << a << "  " << b;
    return 0;
}

void printValue(std::string text)
{
    text = "Changed";
    std::cout << __FUNCTION__ << ": " << text << std::endl;
}

void printReference(std::string& text)
{
    text = "Changed";
    //&text = nullptr; Can¡¯t be reassigned to another memory address (But you can access address)
    //*(&text) = "Changed"; doesn't work
    std::cout << __FUNCTION__ << ": " << text << std::endl;
}

void printConstReference(const std::string& text)
{
    //text = "Changed";
    std::cout << __FUNCTION__ << ": " << text << std::endl;
}

void printPointer(std::string* text)
{
    *text = "Changed";
    //text = nullptr; Can be reassigned to another memory location	
    std::cout << __FUNCTION__ << ": " << *text << std::endl;
}

void printConstPointer(const std::string* text)
{
    //*text = "Changed";
    std::cout << __FUNCTION__ << ": " << *text << std::endl;
}


int main()
{
    std::string printValueStr = "printValue";
    printValue(printValueStr);
    std::cout << "text: " << printValueStr << std::endl;

    std::string printReferenceStr = "printReference";
    printReference(printReferenceStr);
    std::cout << "text: " << printReferenceStr << std::endl;

    std::string printPointerStr = "printPointer";
    printPointer(&printPointerStr);
    std::cout << "text: " << printPointerStr << std::endl;

    // Pass by pointer can accept nullptr arguments

    /*printPointer(nullptr);
    std::cout << "text: " << printPointerStr << std::endl;*/
}