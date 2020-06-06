#include "NameSpace.h"

namespace NameSpace
{
    String::String(std::string str) : value(std::move(str)) { }

    std::string String::getValue() const
    {
        return value;
    }

    void String::setValue(std::string str)
    {
        value = std::move(str);
    }
}