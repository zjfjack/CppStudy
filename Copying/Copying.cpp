// Copying.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // Add null termination character '\0'
        //memcpy(m_Buffer, string, m_Size);
        //m_Buffer[m_Size] = 0;
        strcpy_s(m_Buffer, m_Size + 1, string);
    }

    // default copy constructor can be deleted if you don't want it
    // String(const String& other) = delete;

    // Copy constructor (default by C++ is shallow copy)
    String(const String& other)
        : m_Size(other.m_Size) // Shallow copy int
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    // char& enables the return value modifiable
    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

// String will be copied without &
void PrintString(const String& string)
{
    std::cout << string << std::endl;
}


int main()
{
    // This will crash without copy constructor implemented because of default shallow copy.
    // m_Buffer in two strings points to the same address
    // When the String is getting destructed, the second destructor cannot delete that already deleted pointer
    String first = "First";
    String second = first;

    second[1] = 'b';

    std::cout << first << std::endl;
    std::cout << second << std::endl;
}