class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get()
	{
		static Singleton instance;
		return instance;
	}
public:
	void Hello() {}
};

Singleton* Singleton::s_Instance = nullptr;


struct Entity
{
	static int x, y;
};

int Entity::x;
int Entity::y;

int main() 
{
	Singleton::Get().Hello();
}