#include <iostream>
#include <string>
#include <memory>

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    Derived() = default;
    ~Derived() = default;
};

class AnotherClass : public Base
{
public:
    AnotherClass() = default;
    ~AnotherClass() = default;
};

int main()
{
    double value = 5.25;
    double constValue = 3.3;
    const double* constPointer = &constValue;
    void* voidDoublePointer = &value;
    Derived* derived = new Derived();
    Base* base = derived;
    std::shared_ptr<Derived> smartDerived = std::make_unique<Derived>();
    std::shared_ptr<Base> smartBase = smartDerived;

    // C style casting
    double a = (int)value + 5.3; 

    // static_cast
    double b = static_cast<int>(value) + 5.3;
    // AnotherClass* a = (AnotherClass*)&value;                 // compilable but incorrect
    // AnotherClass* c = static_cast<AnotherClass*>(&value);    // uncompilable
    double c = *static_cast<double*>(voidDoublePointer);
    // double c = *static_cast<int*>(voidDoublePointer);        // compilable but incorrect value: 0.000000
    // double* d = static_cast<double*>(constPointer);          // uncompilable because bottom-level const
    // AnotherClass* ac3 = static_cast<AnotherClass*>(base);    // compilable but incorrect value is there but base is derived, should use dynamic_cast instead

    // const_cast (only applicable for bottom-level const)
    double* d = const_cast<double*>(constPointer);              // correct but chaning d value is undefined
    // *d = 5;                                                  // constValue can be changed in VS but shouldn't do this
    // double* d = const_cast<int*>(constPointer);              // uncompilable
    // const_cast is mainly used for function overloading
    struct OverloadUsage
    {
        const std::string& shorterString(const std::string& s1, const std::string& s2)
        {
            return s1.length() < s2.length() ? s1 : s2;
        }
        std::string& shorterString(std::string& s1, std::string& s2)
        {
            const std::string& shorterStr = shorterString(const_cast<const std::string&>(s1),
                                                          const_cast<const std::string&>(s2));
            return const_cast<std::string&>(shorterStr);
        }
    };

    // reinterpret_cast (dangerous)
    AnotherClass* e = reinterpret_cast<AnotherClass*>(&value);  // compilable but we shouldn't do this

    // dynamic_cast (RTTI(dynamic_cast & typeid) needed with a bit overhead)
    AnotherClass* ac1 = dynamic_cast<AnotherClass*>(base);
    if (!ac1)
        std::cout << "dynamic cast fail" << std::endl;

    if (auto ac2 = dynamic_cast<Derived*>(base))
        std::cout << "dynamic cast succeed" << std::endl;

    // double f = dynamic_cast<int>(value) + 5.3;               // uncompilable dynamic cast should be specifically along inheritance

    if (auto ac3 = std::dynamic_pointer_cast<Derived>(smartBase))
        std::cout << "dynamic pointer cast succeed" << std::endl;

    // static_pointer_cast and const_pointer_cast are also available
    
    if (typeid(*base) == typeid(Derived))
        std::cout << "typeid succeed" << std::endl;

    if (typeid(*smartBase.get()) == typeid(Derived))
        std::cout << "typeid smart pointer succeed" << std::endl;

}