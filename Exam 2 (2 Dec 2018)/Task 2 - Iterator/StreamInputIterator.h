#ifndef STREAM_INPUT_ITERATOR_H
#define STREAM_INPUT_ITERATOR_H

#include <istream>
#include <sstream>
#include <string>
#include <vector>

class StreamInputIterator
{
	std::istream& in;
	std::string endString;
	static int number;
public:
	StreamInputIterator(std::istream& in, const std::string& endString) :
		in(in), endString(endString) {}
public:
	static StreamInputIterator begin(std::istream& in)
	{
		return StreamInputIterator(in, std::string(""));
	}

	static StreamInputIterator end(std::istream& in, const std::string& endString)
	{
		return StreamInputIterator(in, endString);
	}

	bool operator!=(const StreamInputIterator& other) const
	{
		return &(this->in) != &(other.in) || this->endString != other.endString;
	}

	StreamInputIterator& operator++()
	{		
		std::string current;
		this->in >> current;
		std::istringstream iss(current);

		if (iss >> StreamInputIterator::number)
		{
			return *this;
		}
		else
		{
			this->endString = current;
			StreamInputIterator::number = 0;
			return *this;
		}	
	}

	int operator*() const
	{
		return StreamInputIterator::number;
	}
};

int StreamInputIterator::number = 0;

#endif // !STREAM_INPUT_ITERATOR_H
