#include "Max.h"

std::ostream& operator << (std::ostream& out, const VectorMax& a)
{
	for (size_t i = 0; i < a.numbers.size(); i++)
	{
		out << a.numbers[i] << " ";
	}
	return out;
}

void operator >> (const std::vector<int>& vec, VectorMax& a)
{
	a.maxNumber = vec[0];
	for (size_t i = 0; i < vec.size(); i++)
	{
		a.numbers.push_back(vec[i]);
		if (a.maxNumber < vec[i])
		{
			a.maxNumber = vec[i];
		}
	}
}

bool operator<(const VectorMax& first, const VectorMax& second)
{
	return first.maxNumber < second.maxNumber;
}
