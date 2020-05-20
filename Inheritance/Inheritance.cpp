#include<iostream>
#include<string>

class Entity1
{
private:
	int value;
public:
	float X = 0.f, Y = 0.f;

	virtual std::string GetName()
	{
		return "Entity";
	}

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player : public Entity1
{
public:
	const char* Name;

	// No need to specify virtual here for the subclasses
	std::string GetName() override
	{
		return "Player";
	}

	void Move(float xa, float ya)
	{
		X += xa + 1;
		Y += ya + 1;
	}
};

class PlayerSubclass : public Player
{
	std::string GetName() override
	{
		return "PlayerSubclass";
	}
};

void Print(Entity1* e)
{
	std::cout << e->GetName() << std::endl;
}

void PrintPlayer(Player* e)
{
	std::cout << e->GetName() << std::endl;
}

int main()
{
	Player* p = new Player();
	Entity1* e = new Entity1();

	Print(p);
	Print(e);

	PlayerSubclass ps;
	PrintPlayer(&ps);
}