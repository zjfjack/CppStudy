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

// namespace alias
namespace Nested1 = NameSpace::NestedNameSpace1;

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

    std::string s5 = Nested1::func1();

    using namespace NameSpace::NestedNameSpace2;
    std::string s6 = func2();
    using namespace Nested1;
    std::string s7 = func1();

    typedef NameSpace::String TypedefNameSpaceString;
    using UsingNameSpaceString = NameSpace::String;
    TypedefNameSpaceString s8("test");
    UsingNameSpaceString s9("test");

    // typedef can defines both pointer and object in one line
    typedef NameSpace::NewClass TypedefNameSpaceNewClass, *TypedefNameSpaceNewClassPointer;
    TypedefNameSpaceNewClassPointer p = new TypedefNameSpaceNewClass(5, 3);

    // using can only define one each time
    using UsingNameSpaceNewClass = NameSpace::NewClass;
    using UsingNameSpaceNewClassPointer = NameSpace::NewClass*;
}