// CopyConstructorBasendBasessignmentOperation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Base
{
    int base = 0;
    Base()
    {
        std::cout << "Base default constructor" << std::endl;
    }
    Base(int base) : base(base) {}
    Base(const Base&)
    {
        std::cout << "Base Copied" << std::endl;
    }

    Base& operator=(const Base&)
    {
        std::cout << "Assignment operator" << std::endl;
        return *this;
    }
};

struct Test
{
    Base base;

    //Test(Base base) { this->base = base; }

    Test(Base base) : base(base) {}
};



int main()
{
    Base base = Base(5);
    Test test = Test(base);
}
