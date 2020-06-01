#include <iostream>

int getValue1()
{
    return 10;
}

// return lvalue reference
int& getValue2()
{
    static int value = 10;
    return value;
}

void setValue(int) {}

void printNamelvalue(std::string& name)
{
    std::cout << name << std::endl;
}

void printNamervalue(std::string&& name)
{
    std::cout << name << std::endl;
}

void printName(const std::string& name)
{
    std::cout << name << std::endl;
}

int main()
{
    //  l   r
    int i = 10;
    //10 = i

    //  l   l
    int a = i;

    //  l   r
    int j = getValue1();
    // getValue() = 5; expression must be a modifiable lvalue

    // l          r
    getValue2() = 5;
    std::cout << getValue2() << std::endl; // print 5!!

    //       l
    setValue(i);
    //       r
    setValue(10);

    // int& a = 10; initial value of reference to non-const must be an lvalue
    const int& a = 10;

    //          l           r
    std::string firstName = "Jeff";
    //          l          r
    std::string lastName = "Zhang";
    //          l          r(firstName + lastName whole expression)
    std::string fullName = firstName + lastName;

    // printNamelvalue(firstName + lastName); initial value of reference to non-const must be an lvalue
    printNamelvalue(fullName);
    printName(firstName + lastName);
    // printNamervalue(fullName); an rvalue reference cannot be bound to an lvalue
    printNamervalue(firstName + lastName);


    // lvalue is variable that has storage and rvalue is temporary value
    // lvalue reference can only take in lvalue unless they're const
    // rvalue reference can conly take in temporary rvalue
}