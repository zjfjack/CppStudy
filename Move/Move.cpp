#include <iostream>

#define PRINT_VARIABLE(Variable) std::cout << #Variable << std::endl << std::endl

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

class EntityByValue
{
public:
    EntityByValue(String name) : m_Name(name) {}
private:
    String m_Name;
};

class EntityByValueAndMove
{
public:
    EntityByValueAndMove(String name) : m_Name(std::move(name)) {}
private:
    String m_Name;
};

class EntityByConstReference
{
public:
    // copied from const String& to String
    EntityByConstReference(const String& name) : m_Name(name) {}
private:
    String m_Name;
};

class EntityBylvalueReference
{
public:
    EntityBylvalueReference(String& name) : m_Name(name) {}
private:
    String m_Name;
};

class EntityByrvalueReference
{
public:
    // has to use move otherwise it will be copied again
    EntityByrvalueReference(String&& name) 
        : m_Name(std::move(name)) {}
private:
    String m_Name;
};

int main()
{
    String string1("a");                      // constructor
    String string2 = String("a");             // constructor + move constructor(elided) (move because move constructor is implemented, otherwise copy constructor will be called)
    const String& string3 = String("a");      // constructor & bind
    // String& string2 = String("a");         // cannot bind a rvalue reference to lvalue reference
    String& string4 = string1;                // bind
    String string5 = std::move(string4);      // move constructor (not elided)
    string5 = string2;                        // copy assignment operator
    string5 = std::move(string2);             // move assignment operator
    String string = string5;                  // copy constructor

    std::cout << "------------- Constructor with different types of parameters ------------" << std::endl;
    EntityByValue entityByValueWithValue(string);
    PRINT_VARIABLE(entityByValueWithValue);                                                // copy(string to name) copy(name to m_Name) destory(name)                   Copy: 2  Move: 0
    EntityByValue entityByValueWithrvalue(String("a"));
    PRINT_VARIABLE(entityByValueWithrvalue);                                               // construct move("a" to name(elided)) copy(name to m_Name) destory(name)    Copy: 1  Move: 0(+1)

    EntityByValueAndMove entityByValueAndMoveWithValue(string);
    PRINT_VARIABLE(entityByValueAndMoveWithValue);                                         // copy(string to argument name) move(name to m_Name) destory(name)          Copy: 1  Move: 1
    EntityByValueAndMove entityByValueAndMoveWithrvalue(String("a"));
    PRINT_VARIABLE(entityByValueAndMoveWithrvalue);                                        // construct move("a" to name(elided)) move(name to m_Name) destory(name)    Copy: 0  Move: 1(+1)

    EntityByConstReference entityByConstReferenceWithValue(string);
    PRINT_VARIABLE(entityByConstReferenceWithValue);                                       // bind(string to name) copy(name to m_Name)                                 Copy: 1  Move: 0
    EntityByConstReference entityByConstReferenceWithrvalue(String("a"));                  // can bind a rvalue reference to const lvalue reference
    PRINT_VARIABLE(entityByConstReferenceWithrvalue);                                      // construct bind("a" to name) copy(name to m_Name) destory(name)            Copy: 1  Move: 0

    // EntityBylvalueReference entityBylvalueReferenceWithrvalue(String("a"));             // cannot take a rvalue reference with lvalue reference required
    EntityBylvalueReference entityBylvalueReferenceWithvalue(string);
    PRINT_VARIABLE(entityBylvalueReferenceWithvalue);                                      // bind(string to name) copy(name to m_Name)                                 Copy: 1  Move: 0

    EntityByrvalueReference entityByrvalueReferenceWithrvalue(String("a"));
    PRINT_VARIABLE(entityByrvalueReferenceWithrvalue);                                     // construct bind("a" to name) move(name to m_Name) destory("a")             Copy: 0  Move: 1
    // EntityByrvalueReference entityByrvalueReferenceWithvalue(string3);                  // cannot take a lvalue reference with rvalue reference required
    EntityByrvalueReference entityByrvalueReferenceWithMovedlvalue(std::move(string));     // string3 will be destroyed after std::move
    PRINT_VARIABLE(entityByrvalueReferenceWithMovedlvalue);                                // bind(String&& string to name) move(name&string to m_Name)                 Copy: 0  Move: 1

    // EntityBylvalueReference shouldn't be used because rvalue is not supported
    // EntityByValue shouldn't be used because too many copies
    // Choose EntityByConstReference & EntityByrvalueReference combination for best performance
    // Choose EntityByValueAndMove for avoiding repetition 
    // https://stackoverflow.com/a/51706522/5514452
    // https://stackoverflow.com/a/10836286/5514452
}