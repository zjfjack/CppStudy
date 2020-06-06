#pragma once
#include <string>

namespace NameSpace
{
    class String
    {
    public:
        String(std::string);
        std::string getValue() const;
        void setValue(std::string);
    private:
        std::string value;
    };

    namespace NestedNameSpace1
    {
        inline std::string func1()
        {
            return "NestedNameSpace1";
        }
    }

    namespace NestedNameSpace2
    {
        inline std::string func2()
        {
            return NestedNameSpace1::func1();
        }
    }

    inline namespace InlineNameSpace
    {
        inline std::string func3()
        {
            return NestedNameSpace1::func1();
        }
    }
}