#include "Scientist.h"

Scientist::Scientist():
	name(nullptr), discoveriesCount(0)
{
}

Scientist::Scientist(char* name, int discoveriesCount):
	name(nullptr), discoveriesCount(discoveriesCount)
{
	this->setName(name);
}

Scientist::Scientist(const Scientist& other)
{
	this->setName(other.getName());
	this->setDiscoveriesCount(other.getDiscoveriesCount());
}

Scientist& Scientist::operator=(const Scientist& other)
{
	if (this != &other)
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
		}
		this->setName(other.getName());
		this->setDiscoveriesCount(other.getDiscoveriesCount());
	}

	return *this;
}

Scientist::~Scientist()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

char* Scientist::getName() const
{
	return this->name;
}

int Scientist::getDiscoveriesCount() const
{
	return this->discoveriesCount;
}

void Scientist::setName(const char* name)
{
	std::string temp = name;

	this->name = new char[temp.size() + 1];
	this->name[temp.size()] = '\0';

	memcpy(this->name, name, temp.size());
}

void Scientist::setDiscoveriesCount(int count)
{
	this->discoveriesCount = count;
}

void Scientist::Print() const
{
	std::cout << this->getName();
}
