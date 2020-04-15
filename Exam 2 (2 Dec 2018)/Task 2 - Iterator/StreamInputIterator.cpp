#include "StreamInputIterator.h"
#include <sstream>

StreamInputIterator::StreamInputIterator(std::istream& in) :
	current(nullptr), next(nullptr), num(0), sizeTemp(0), cnt(0), hasNumber(false), transfer(false), getNext(false)
{
	while (in >> this->num)
	{
		this->hasNumber = true;
		this->numbers.push_back(num);
		break;
	}
	if (this->hasNumber)
	{
		this->current = &numbers[0];
	}
}

StreamInputIterator::StreamInputIterator(std::istream& in, std::string endString) :
	current(nullptr), next(nullptr), num(0), sizeTemp(0), cnt(0), hasNumber(false), transfer(false), getNext(false)
{
	while (in >> this->num)
	{
		this->hasNumber = true;
		this->numbers.push_back(num);
	}
	if (this->hasNumber)
	{
		this->current = nullptr;
	}
}

StreamInputIterator StreamInputIterator::begin(std::istream& in)
{
	return StreamInputIterator(in);
}

StreamInputIterator StreamInputIterator::end(std::istream& in, std::string endString)
{
	return StreamInputIterator(in, endString);
}

StreamInputIterator& StreamInputIterator::operator++()
{
	if (!this->getNext)
	{
		this->current = next;
		this->getNext = true;
	}
	else
	{
		if (this->cnt < this->sizeTemp)
		{
			this->current++;
			this->cnt++;
		}
		else
		{
			this->current = nullptr;
		}
	}
	
	return *this;
}

bool StreamInputIterator::operator!=(StreamInputIterator& other)
{
	if (!this->transfer)
	{
		this->next = &other.numbers[0];
		this->transfer = true;
		this->sizeTemp = other.numbers.size() - 1;
	}	
	return this->current != other.current;
}

bool StreamInputIterator::operator==(StreamInputIterator& other)
{
	return this->current == other.current;
}

int StreamInputIterator::operator*()
{
	return *this->current;
}
