#include<iostream>
#include<string>

class Const
{
private:
	int m_x, m_y;
	int* m_px;
	std::string m_name = "bca";
	mutable int m_debugCount;

public:
	int GetX() const
	{
		m_debugCount++; // inside a const!!
		return m_x;
	}

	// 1. return a pointer cannot be modified
	// 2. content of this pointer cannot be modified
	// 3. content of the entity class  won't be modified
	const int* const GetPX() const
	{
		return m_px;
	}

	void SetX(int x)
	{
		m_x = x;
	}

	const std::string& GetName() const
	{
		return m_name;
	}
};

void PrintConst(const Const& c)
{
	// GetX() has to be const otherwise it won't be complied
	std::cout << c.GetX() << std::endl;
}

int main()
{
	const int MAX_AGE = 90;
	int a = 40, b = 30;

	const int* constA1 = &a; // const int *constA1
	*constA1 = 50;
	constA1 = &b;

	int const* constA2 = &a; // int const *constA2
	*constA2 = 50;
	constA2 = &b;

	int* const constA3= &a; // int* const constA3
	*constA3 = 50;
	constA3 = &b;

	const int* const constA4 = &a;
	*constA4 = 50;
	constA4 = &b;

	Const c;
	//int* px = c.GetPX();
	const int* px = c.GetPX();
	*px = 4;
	px = &a; // this looks fine (a bit werid why complier not restricted to make it `const int* const px`)

	const Const c1;
	std::string name = c1.GetName();
	name = "abc";
	std::cout << "name: " << name << " c1.name" << c1.GetName() << std::endl;
}