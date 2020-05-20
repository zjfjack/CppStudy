#include<iostream>

class Entity
{
public:
	float X, Y, Z;

	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	Entity(float x, float y, float z) : X(x), Y(y), Z(z) { }

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

void Function()
{
	Entity e;
	e.Print();
}

int main()
{
	//Entity e;
	Entity e(10.f, 5.f);
	Entity e1(10.f, 10.f, 88.f);
	Function();
	std::cout << e.X << std::endl;
	std::cout << e1.Z << std::endl;
	e.Print();
}