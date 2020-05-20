#include<iostream>
#include<string>
#include<vector>
#include<array>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{

	}

	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices)
{
	//Example
}

void PrintArray(const std::array<int, 5>& data)
{
	for (int i = 0; i < data.size(); i++)
	{

	}
}

int main()
{
	// Normal Array: Array is just like a pointer pointing to the first item address

	int example[4] = { -1, -1, -1, -1 };
	int* ptr = example;
	example[0] = 0;
	ptr[1] = 1;
	*(ptr + 2) = 2;
	// *((char*)ptr + 4 * 3) = 3; it works but value is -253 instead of 3 because haven't casted it back to int* 
	// and cause the last 4 bytes memery becomes 03 ff ff ff
	*(int*)((char*)ptr + 4 * 3) = 3;
	// the number of bytes are added based on the pointer type, char is 1 byte, int is 4 byte, 
	// if we want to move to third int array item, then it should be 12 bytes, which means + 12 because current pointer type is cased to char

	std::cout << example[0] << ", " << example[1] << ", " << example[2] << ", " << example[3] << std::endl;

	/////////////////////////////////////////////////////////////

	// Vector

	//Vertex vertices[5]; //Vertex* vertices = new Vertex[5];
	std::vector<Vertex> vertices;
	vertices.reserve(3); // Remove capacity change copy
	std::cout << vertices.size() << std::endl;

	//vertices.push_back(Vertex(1, 2, 3)); // Copied 1 (copied from the main function to vector)
	//vertices.push_back(Vertex(4, 5, 6)); // Copied 2 (capacity from 1 to 2 and copied the 0 index vertex)
	//vertices.push_back(Vertex(7, 8, 9)); // Copied 3 (capacity from 2 to 3 and copied the 0, 1 index vertex)

	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9); 

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	//vertices.clear();
	vertices.erase(vertices.begin() + 1);

	for (const Vertex& vertex : vertices) // Vertex vertex will copy!
		std::cout << vertex << std::endl;

	//////////////////////////////////////////////////////////////

	// Static array, size cannot be changed, size is the same as normal array

	std::array<int, 5> data;
	data[0] = 2;
	data[4] = 1;
	std::cout << sizeof(data) << std::endl; // 20!!!
}