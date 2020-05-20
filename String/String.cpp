#include<iostream>
#include<string>


// You don't want to copy string and add const to make it immutable
void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}

int main()
{
	char test1[] = "Hello";
	// char* test1 = "Helllo"; cannot access string literals which is constant
	char test2[6] = { 'H', 'e', 'l', 'l', 'o', 0 };
	char* test3 = test1;

	std::string test4 = "Hello";
	std::cout << test4 << std::endl;
	test4 += "Hello";
	std::cout << "sizeof: " << sizeof(test4) << "size(): " << test4.size() << "capacity: " << test4.capacity() << std::endl;
}