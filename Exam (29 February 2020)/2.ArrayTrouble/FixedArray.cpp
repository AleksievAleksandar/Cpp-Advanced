#include "FixedArray.h"

FixedArray::FixedArray(const int arraySize) :
	BrokenArray(arraySize)
{
}

FixedArray::~FixedArray()
{
	//delete[] this->_array;
}

FixedArray::FixedArray(const FixedArray& other) :
	BrokenArray(other.getSize())
{
	for (int i = 0; i < other.getSize(); i++)
	{
		this->_array[i] = other._array[i];
	}
}

FixedArray& FixedArray::operator=(const FixedArray& other)
{
	if (this != &other)
	{	
		delete[] this->_array;	
		::BrokenArray::operator=(other);
		
		this->_array = new int[other.getSize()];	
	
		for (int i = 0; i < other.getSize(); i++)
		{
			this->_array[i] = other._array[i];
		}
		
		return *this;
	}
}

void FixedArray::addValueToMemory(const int value)
{
	for (int i = 0; i < this->getSize(); i++)
	{
		this->_array[i] += value;
	}
}

int FixedArray::getMemorySumValue() const
{
	int temp = 0;

	for (int i = 0; i < this->getSize(); i++)
	{
		temp += this->_array[i];
	}

	return temp;
}
