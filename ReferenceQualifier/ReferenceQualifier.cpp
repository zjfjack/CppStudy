#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Foo
{
public:
    Foo(std::vector<int>&& vector) : data(std::move(vector)) 
    {
        std::cout << "move vector constructor" << std::endl;
    }

    Foo(Foo&& other) noexcept : data(std::move(other.data))
    {
        std::cout << "move constructor" << std::endl;
    }

    Foo(const Foo& other) : data(other.data)
    {
        std::cout << "copy constructor" << std::endl;
    }

    Foo sorted() &&
    {
        std::sort(data.begin(), data.end());
        return std::move(*this); // std::move -> Move otherwise it will be copied
    }

    Foo sorted() &
    {
        std::sort(data.begin(), data.end());
        return *this; // COPY lvalue
    }

    // Because of const, we cannot use std::sort which is non-const
    Foo sorted() const &
    {
        auto temp = *this; // copy
        std::sort(temp.data.begin(), temp.data.end());
        return temp; // MOVE rvalue (MOVE is elided in release build)
    }

    void print(const char* const variableName) const
    {
        std::string printStr;
        for (auto i = data.begin(); i != data.end(); ++i)
        {
            printStr.append(std::to_string(*i));
            if (i != data.end() - 1)
                printStr.append(" ");
        }
        std::cout << variableName << ": " << printStr << std::endl;
    }
private:
    std::vector<int> data;
};

int main()
{
    Foo foo(std::vector<int>{2, 4, 1, 3});
    const Foo fooConst(std::vector<int>{2, 4, 1, 3});

    Foo foo1 = fooConst.sorted();                          // Foo sorted() const &
    Foo foo2 = foo.sorted();                               // Foo sorted() &
    Foo foo3 = Foo(std::vector<int>{2, 4, 1, 3}).sorted(); // Foo sorted() &&

    foo.print("foo");
    fooConst.print("fooConst");
    foo1.print("foo1");
    foo2.print("foo2");
    foo3.print("foo3");
}