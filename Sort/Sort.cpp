// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> list = { 5, 3, 7, 2, 8, 1 };
	std::sort(list.begin(), list.end());
	std::sort(list.begin(), list.end(), [](int a, int b)
	{
		return a < b;
	});

	list.push_back(13);
	list.insert(list.begin() + 2, 250); // insert for vector is very slow except last one

	std::vector<int> svector = { 33, 44, 66, 77 };
	list.insert(list.begin(), svector.end() - 1, svector.end());
	list.insert(list.begin(), svector.begin(), svector.begin() + 1);
	// Range of iterator is [begin, end)
	list.emplace_back(999);
	auto firstValue1 = list.front();
	auto firstValue2 = *list.begin();
	auto lastValue1 = list.back();
	// auto lastValue2 = *list.end(); An invalid parameter was passed to a function that considers invalid. end() iterator points to the position after last element
	auto lastValue2 = *(--list.end());
	

	for (int i : list)
		std::cout << i << std::endl;
	
	int a = 1, b = 1;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "++b: " << ++b << std::endl;
}
