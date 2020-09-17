#include "Palace.h"
#include <iostream>

void Palace::print()
{
	std::cout << "Building type: Palace, measurements: " << this->getWidth() << " x " << this->getLength() << "\n";
}

Palace::Palace(int width, int length):
	Building(width, length)
{
	this->print();
	std::cout << "| Constructor is called\n";
}

Palace::~Palace()
{
	this->print();
	std::cout << "| Destructor is called\n";
}
