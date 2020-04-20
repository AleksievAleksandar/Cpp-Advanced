#pragma once

#include <vector>
#include <sstream>

class VectorMax
{
private:
	std::vector<int> numbers;

public:
	int maxNumber = 0;

public:
	VectorMax() = default;
	friend std::ostream& operator << (std::ostream& out, const VectorMax& a);
	friend void operator >> (const std::vector<int>& vec, VectorMax& a);
};

bool operator < (const VectorMax& first, const VectorMax& second);