#include<iostream>

// template<class T> class is also fine but it not just for class, such as int. Ambiguous
template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
}

template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:

	int GetSize() const
	{
		return N;
	}
};

int main()
{
	Print(5);
	Print<int>(5);
	Print(std::string("hello"));
	Print<std::string>(std::string("hello"));

	Array<int, 4> array;
	std::cout << array.GetSize() << std::endl;
}