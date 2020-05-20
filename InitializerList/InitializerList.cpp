// InitializerList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void printDivier()
{
    std::cout << "----------------------------------------" << std::endl;
}

struct Example
{
    int x = 0;

    Example()
    {
        std::cout << "Example Default Constructor" << std::endl;
    }

    Example(int x) : x(x)
    {
        std::cout << "Example Constructor with int " << x << std::endl;
    }

    // override copy constructor for print purpose, not working
    Example(const Example&)
    {
        std::cout << "Example Copy Constructor" << std::endl;
    }

    // override assignment operator for print purpose, not working
    Example& operator=(const Example&)
    {
        std::cout << "Example Assignment Operator (Copy)" << std::endl;
        return *this;
    }
};

struct Entity1
{
    Example example;

    // Default Example constructor is called without Initializer List
    // int constructor is called
    // Assignment operator is called (Copy)
    Entity1()
    {
        Example e = Example(8);
        example = e;
        printDivier();
    }
};

struct Entity2
{
    Example example;

    // int constructor is called
    // Default Example constructor isn't called
    // Assignment operator isn't called
    Entity2() : example(Example(8)) // or example(8) implicit conversion
    {
        printDivier();
    }
};

struct Entity3
{
    Example example;

    // Copied (copy constructor) when passed object as an argument
    // Default Example constructor is called without Initializer List
    // Assignment operator is called (Copy function scope example to memeber variable)
    // Outside ---copy(copy constructor)---> Function ---copy(assignment operator)---> Memeber variable
    Entity3(Example example)
    {
        this->example = example;
        printDivier();
    }
};

struct Entity4
{
    Example example;

    // Copied (copy constructor) when passed object as an argument
    // Copy constructor is called by Initializer List
    // Outside ---copy(copy constructor)---> Initializer List ---copy(copy constructor)---> Memeber variable
    Entity4(Example example) : example(example)
    {
        printDivier();
    }
};

struct Entity5
{
    Example example;

    // No copy when passed reference as an argument
    // Copy constructor is called by Initializer List (reference to object)
    Entity5(const Example& example) : example(example)
    {
        printDivier();
    }
};

// Not allowed because it has to call default initialiser without list initialiser to instantiate example
//struct Entity5
//{
//    Example& example;
//
//    Entity5(Example& example)
//    {
//        this->example = example;
//        printDivier();
//    }
//};

struct Entity6
{
    Example& example;

    // Nothing copied and assignment operator called
    // Pass by reference and set it to a reference
    // Outside example memory == function argument memory == member variable memory
    Entity6(Example& example) : example(example)
    {
        printDivier();
    }
};

int main()
{
    Entity1 e1;
    Entity2 e2;

    Example example;
    printDivier();
    Entity3 e3 = Entity3(example);
    Entity4 e4 = Entity4(example);
    Entity5 e5 = Entity5(example);
    Entity6 e6 = Entity6(example);

    std::string a;
    auto b = std::string("f");
    a = b;
}