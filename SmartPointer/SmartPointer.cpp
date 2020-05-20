#include<iostream>
#include<memory>
#include<string>

class PointerEntity {
private:
	std::string m_name;

public:
	PointerEntity(const std::string& name) : m_name(name)
	{
		std::cout << "Created Entity for " << m_name << std::endl;
	}

	~PointerEntity()
	{
		std::cout << "Destroyed Entity for " << m_name << std::endl;
	}
};



int main()
{
	{
		std::shared_ptr<PointerEntity> e0;
		std::weak_ptr<PointerEntity> e1;
		{
			std::unique_ptr<PointerEntity> uniquePointer = std::make_unique<PointerEntity>("uniquePointer");
			//std::unique_ptr<PointerEntity> e0 = entity; //unique point cannot be copied

			// Reference counting
			std::shared_ptr<PointerEntity> sharedPointer = std::make_shared<PointerEntity>("sharedPointer");
			//e0 = sharedPointer;
			e1 = sharedPointer;
		} // uniquePointer died | sharedPointer with e1 died because no reference now (weak pointer won't add counting)
	} // sharedPointer with e0 died because no reference now

}