#include "Group.h"
#include <set>

const int Group::MAX_UNITS = 12;

Group::Group():
	units(new UnitPtr[MAX_UNITS]), unitsAdded(0)
{
	for (size_t i = 0; i < MAX_UNITS; i++)
	{
		units[i] = nullptr;
	}
}

Group::Group(const Group& other)
{
	this->units = new UnitPtr[MAX_UNITS];
	for (size_t i = 0; i < other.unitsAdded; i++)
	{
		this->units[i] = other.units[i];
	}

	this->unitsAdded = other.unitsAdded;
}

void Group::add(UnitPtr unit)
{
	//this->units[unitsAdded] = unit;
	//this->unitsAdded++;

	for (unsigned int i = 0; i < this->unitsAdded; ++i) {
		if (unit->getId() == this->units[i]->getId()) {
			return;
		}
	}
	
	int index = this->unitsAdded;
	
	if (index == Group::MAX_UNITS) {
		index = 0;
	}
	else {
		this->unitsAdded++;
	}
	
	this->units[index] = unit;
}

void Group::clear()
{
	//for (size_t i = 1; i < MAX_UNITS; i++)
	//{
	//	delete units[i];
	//	units[i] = nullptr;
	//}
	
	this->unitsAdded = 0;
}

Group& Group::operator=(const Group& other)
{
	if (this != &other)
	{
		//for (size_t i = 0; i < MAX_UNITS; i++)
		//{
		//	delete this->units[i];
		//	this->units[i] = nullptr;
		//}
		//
		//for (size_t i = 0; i < other.unitsAdded; i++)
		//{
		//	this->units[i] = other.units[i];
		//}
		//this->unitsAdded = other.unitsAdded;
		//
		//return *this;

		auto unitsCopy = new UnitPtr[MAX_UNITS]{ };
		
		for (unsigned int i = 0; i < other.unitsAdded; i++) {
			unitsCopy[i] = other.units[i];
		}
		
		delete[] this->units;
		this->unitsAdded = other.unitsAdded;
		this->units = unitsCopy;
	}

	return *this;
}

Group& Group::operator<<(const Group& other)
{
	//int cntUnit = 0;
	//while (cntUnit != other.unitsAdded && this->unitsAdded < MAX_UNITS)
	//{
	//	this->units[this->unitsAdded] = other.units[cntUnit];
	//	this->unitsAdded++;
	//	cntUnit++;
	//}
	//return *this;

	for (unsigned int i = 0; i < other.unitsAdded; ++i) {
		this->add(other.units[i]);
	}
	return *this;
}

Group::~Group()
{
	delete[] this->units;
}

std::ostream& operator<<(std::ostream& out, const Group& group)
{
	std::set<Id> tempIds;

	for (size_t i = 0; i < group.unitsAdded; i++)
	{
		tempIds.insert(group.units[i]->getId());
	}

	for (auto const i : tempIds)
	{
		out << i << " ";
	}

	return out;
}
