#include "Scientist.h"

#include <iostream>
#include <cstring>

Scientist::Scientist() : 
	name(nullptr), 
	discoveriesCount(0)
{}

Scientist::Scientist(char* name, int discoveriesCount) : 
	name(_strdup(name)), 
	discoveriesCount(discoveriesCount)
{}

Scientist::Scientist(const Scientist& other) : 
	name(_strdup(other.name)), 
	discoveriesCount(other.discoveriesCount)
{}

Scientist& Scientist::operator=(const Scientist& other)
{
	if (this != &other)
	{
		delete[] this->name;
		this->name = _strdup(other.name);
		this->discoveriesCount = other.discoveriesCount;
	}
	return *this;
}

Scientist::~Scientist()
{
	delete[] this->name;
	this->name = nullptr;
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
	delete[] this->name;
	this->name = _strdup(name);
}

void Scientist::setDiscoveriesCount(int count)
{
	this->discoveriesCount = count;
}

void Scientist::Print() const
{
	std::cout << this->getName() << " - " << this->getDiscoveriesCount();
}
