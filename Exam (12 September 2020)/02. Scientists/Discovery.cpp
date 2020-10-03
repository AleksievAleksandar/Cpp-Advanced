#include "Discovery.h"

#include <cstring>

Discovery::Discovery()
{}

Discovery::Discovery(const char* discoveryName, int year, const Scientist& scientistName, Fields fieldOfStudy) :
	discoveryName(_strdup(discoveryName)), 
	year(year), 
	scientist(scientistName), 
	fieldOfStudy(fieldOfStudy)
{}

Discovery::Discovery(const Discovery& other):
	discoveryName(_strdup(other.discoveryName)), 
	year(other.year), 
	scientist(other.scientist), 
	fieldOfStudy(other.fieldOfStudy)
{}

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
	delete[] this->discoveryName;
	this->discoveryName = _strdup(name);
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
		delete[] this->discoveryName;
		this->discoveryName = _strdup(other.discoveryName);
		this->year = other.year;
		this->scientist = other.scientist;
		this->fieldOfStudy = other.fieldOfStudy;
	}
	return *this;
}

Discovery::~Discovery()
{
	delete[] this->discoveryName;
	this->discoveryName = nullptr;
}
