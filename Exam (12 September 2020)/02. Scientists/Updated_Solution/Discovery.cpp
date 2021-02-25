#include "Discovery.h"

#include <string>

Discovery::Discovery():
	discoveryName(nullptr), year(0), scientist(), fieldOfStudy(static_cast<Fields>(-1))
{
}

Discovery::Discovery(const char* discoveryName, int year, const Scientist& scientistName, Fields fieldOfStudy):
	discoveryName(nullptr), year(year), scientist(scientistName), fieldOfStudy(fieldOfStudy)
{
	this->setDiscoveryName(discoveryName);
}

Discovery::Discovery(const Discovery& other)
{
	this->setDiscoveryName(other.getDiscoveryName());
	this->setYear(other.getYear());
	this->setScientist(other.getScientist());
	this->setFieldOfStudy(other.getFieldOfStudy());
}

char* Discovery::getDiscoveryName() const
{
	return this->discoveryName;
}

int Discovery::getYear() const
{
	return this->year;
}

Scientist Discovery::getScientist() const
{
	return this->scientist;
}

Fields Discovery::getFieldOfStudy() const
{
	return this->fieldOfStudy;
}

void Discovery::setDiscoveryName(const char* name)
{
	std::string temp = name;

	this->discoveryName = new char[temp.size() + 1];
	this->discoveryName[temp.size()] = '\0';

	memcpy(this->discoveryName, name, temp.size());
}

void Discovery::setYear(int year)
{
	this->year = year;
}

void Discovery::setScientist(const Scientist& author)
{
	this->scientist = author;
}

void Discovery::setFieldOfStudy(Fields fieldOfStudy)
{
	this->fieldOfStudy = fieldOfStudy;
}

char* Discovery::getScientistName() const
{
	return this->scientist.getName();
}

Discovery& Discovery::operator=(const Discovery& other)
{
	if (this != &other)
	{
		if (this->discoveryName != nullptr)
		{
			delete[] this->discoveryName;
		}
		this->setDiscoveryName(other.getDiscoveryName());
		this->setYear(other.getYear());
		this->setScientist(other.getScientist());
		this->setFieldOfStudy(other.getFieldOfStudy());
	}
	return *this;
}

Discovery::~Discovery()
{
	if (this->discoveryName != nullptr)
	{
		delete[] this->discoveryName;
		this->discoveryName = nullptr;
	}
}
