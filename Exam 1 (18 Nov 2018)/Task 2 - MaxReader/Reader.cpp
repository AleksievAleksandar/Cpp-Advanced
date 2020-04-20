#include "Reader.h"
#include <sstream>
#include <iostream>

Reader::Reader(std::istream& info):
	info(info), currentNumber(0), line("")
{
}

Reader& Reader::operator>>(std::vector<int> &vec)
{
	std::stringstream temp;
	while (std::getline(info, this->line))
	{
		temp << line;
		while (temp >> this->currentNumber)
		{
			vec.push_back(currentNumber);
		}
		break;
	}
	return *this;
}
