#include "Laptop.h"

Laptop::Laptop(const std::string& name, const double price, const double monitorSize) :
	Hardware(name, price),
	_monitorSize(monitorSize)
{
	this->printInfo();
	std::cout << " is being created\n";
}

Laptop::~Laptop()
{
	this->printInfo();
	std::cout << " is being destroyed\n";
}

Laptop::Laptop(const Laptop& other) :
	Hardware(other),
	_monitorSize(other._monitorSize)
{
	std::cout << "Copy construction for ";
	this->printInfo();
	std::cout << "\n";
}

Laptop& Laptop::operator=(const Laptop& other)
{
	if (this != &other)
	{
		this->_monitorSize = other._monitorSize;
		Hardware::operator=(Hardware(other));
		std::cout << "Copy assignment for ";
		this->printInfo();
		std::cout << "\n";

		return *this;
	}
	else
	{
		std::cout << "Self-copy prevented for ";
		this->printInfo();
		std::cout << "\n";
	}
}
