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

    getValue2() = 5;
    std::cout << getValue2() << std::endl;
}