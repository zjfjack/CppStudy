#include "NameSpace.h"
#include <iostream>

namespace NameSpace
{
    class NewClass
    {
    public:
        NewClass(int, int);
        int getAPlusBPlusOutScopeVar() const;
    private:
        int a = 0;
        int b = 0;
    };
}

NameSpace::NewClass::NewClass(int a, int b) : a(a), b(b) { }

int outScopeVar = 2;

int NameSpace::NewClass::getAPlusBPlusOutScopeVar() const
{
    return a + b + ::outScopeVar;
}

int main()
{
    NameSpace::String s("test");
    std::cout << s.getValue() << std::endl;
    NameSpace::NewClass n1(3, 5);
    std::cout << n1.getAPlusBPlusOutScopeVar() << std::endl;

    std::string s1 = NameSpace::NestedNameSpace1::func1();
    std::string s2 = NameSpace::NestedNameSpace2::func2();
    std::string s3 = NameSpace::InlineNameSpace::func3();
    std::string s4 = NameSpace::func3();
}