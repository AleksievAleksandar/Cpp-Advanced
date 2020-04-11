#include "Store.h"

void Store::remove(const int index)
{
	if (!this->_laptops.empty())
	{
		this->_laptops.erase(this->_laptops.begin() + index);
	}
}

void Store::copy(const int fromIndex, const int toIndex)
{
	this->_laptops[toIndex] = this->_laptops[fromIndex];
}
