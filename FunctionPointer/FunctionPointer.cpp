// FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

void HelloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

void HelloWorldA(int a)
{
    std::cout << "Hello World! Value: " << a << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

void ForEachFunctional(const std::vector<int>& values, const std::function<void(int)>& func)
{
    for (int value : values)
        func(value);
}

int main()
{
    typedef void(*HelloWorldFunction)(int);

    auto autoFunction = HelloWorld; // = auto function = &HelloWorld;
    autoFunction();
    auto autoFunctionA = HelloWorldA; // = auto function = &HelloWorld;
    autoFunctionA(3);

    void(*cherno)() = HelloWorld;
    cherno();

    HelloWorldFunction function = HelloWorldA;
    function(1);

    std::vector<int> values = { 1, 3, 4, 5, 6 };
    ForEach(values, PrintValue);

    // Lambda
    std::vector<int> valuesForLambda = { 1, 3, 4, 5, 6 };

    auto lambda = [](int value) { std::cout << "Value: " << value << std::endl; };
    ForEach(values, lambda);

    int a = 5, b = 6;
    // = pass by value & pass by reference
    auto lambdaB = [=](int value) { std::cout << "Value: " << a << b << std::endl; };
    ForEachFunctional(values, lambdaB);

    auto it = std::find_if(valuesForLambda.begin(), valuesForLambda.end(), [](int value) -> bool { return value > 3; });
    std::cout << *it << std::endl;
}

void f1(int i)
{
    int const N = 20;
    auto m1 = [=] {
        int const M = 30;
        auto m2 = [i, M] {
            int x[N][M]; // 'N' cannot be implicitly captured because no default capture mode has been specified
            x[0][0] = i; // i is explicitly captured by m2
                         // and implicitly captured by m1
        };
    };
}