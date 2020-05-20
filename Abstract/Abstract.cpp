// Abstract.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class AbstractBaseClass
{
protected:
    // Pure Virtual Function = 0
    virtual void virtualFunction() = 0;
};

class BaseClass
{
public:
    void baseFunction()
    {
        std::cout << "base function implemented" << std::endl;
    }
};

class ConcreteClassA : public BaseClass, protected AbstractBaseClass
{
public:
    void concreteFunction()
    {
        baseFunction();
        virtualFunction();
    }

    void virtualFunction() override
    {
        std::cout << "virtual function implemented" << std::endl;
    }
};


int main()
{
    ConcreteClassA concreteOjbA;
    std::cout << "Hello World!\n";
    concreteOjbA.virtualFunction();
    concreteOjbA.concreteFunction();
}