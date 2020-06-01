#include <iostream>

class String
{
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_size = strlen(string);
        m_Data = new char[m_size+1];
        memcpy(m_Data, string, m_size+1);
    }

    // copy constructor
    String(const String& other)
    {
        printf("Copied!(constructor)\n");
        m_size = other.m_size;
        // Deep copy
        m_Data = new char[m_size];
        memcpy(m_Data, other.m_Data, m_size);
    }

    // move constructor
    String(String&& other) noexcept
    {
        printf("Moved!(constructor)\n");
        m_size = other.m_size;
        // Shallow copy
        m_Data = other.m_Data;

        other.m_size = 0;
        other.m_Data = nullptr;
    }

    // copy assignment operator
    String& operator=(const String& rhs)
    {
        printf("Copied!(assignment operator)\n");
        m_size = rhs.m_size;
        delete[] m_Data;
        m_Data = new char[m_size];
        memcpy(m_Data, rhs.m_Data, m_size);
        return *this;
    }

    // move assignment operator
    String& operator=(String&& other) noexcept
    {
        printf("Moved!((assignment operator)\n");
        m_size = other.m_size;
        delete[] m_Data;
        // Shallow copy
        m_Data = other.m_Data;

        other.m_size = 0;
        other.m_Data = nullptr;
        return *this;
    }
 
    ~String()
    {
        // should be delete[] otherwise it will only the first element of the array
        delete[] m_Data;
        printf("Destroyed!\n");
    }

    void print()
    {
        for (uint32_t i = 0; i < m_size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }
private:
    char* m_Data;
    uint32_t m_size;
};

class Entity
{
public:
                                 // copied from const String& to String
    Entity(const String& name) : m_Name(name) {}

                                   // has to use move otherwise it will be copied again
    Entity(String&& name) : m_Name(std::move(name)) {}

    void printName()
    {
        m_Name.print();
    }
private:
    String m_Name;
};

int main()
{
    Entity entity(String("Cherno"));
    entity.printName();

    String string1("Hello");
    String string2("World");
    string1 = string2;
    string1.print();
    string1 = std::move(string2); //string2 will be destroyed after std::move`
    string1.print();
}