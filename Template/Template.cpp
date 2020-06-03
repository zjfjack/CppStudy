#include<iostream>
#include<vector>
#include<type_traits>

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
	T m_Array[N] = {0};
public:
	Array(T m_Array[N]);

	int GetSize() const
	{
		return N;
	}

	T GetFirstItem() const;
};

template<typename T, int N>               // required template<>
Array<T, N>::Array(T array[N])            // required Array<T, N>::
{
	for (int i = 0; i < N; i++)
		m_Array[i] = array[i];
}

template<typename T, int N>             // required template<>
T Array<T, N>::GetFirstItem() const     // required Array<T, N>::
{
	return m_Array[0];
}

template<typename It>
auto fcn(It beg, It end) -> decltype(*beg)  // trailing return type
{
	return *beg;
}

template<typename It>
auto fcn2(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type  // T&&, T&, T ->(remove_reference) T
{
	return *beg;
}

int main()
{
	Print(5);
	Print<int>(5);
	Print(std::string("hello"));
	Print<std::string>(std::string("hello"));

	int intArray[4] = { 1,2,3,4 };
	Array<int, 4> array(intArray);
	std::cout << array.GetSize() << std::endl;
	std::cout << array.GetFirstItem() << std::endl;

	std::vector<int> vec = { 1, 2, 3, 4 };
	int& a = fcn(vec.begin(), vec.end());    // fcn return type: int&
	std::cout << a << std::endl;

	int b = fcn2(vec.begin(), vec.end());
}