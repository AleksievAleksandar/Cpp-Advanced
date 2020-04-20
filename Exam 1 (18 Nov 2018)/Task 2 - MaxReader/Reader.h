#pragma once

#include <iostream>
#include <vector>

class Reader
{
private:
	int currentNumber;
	std::string line;

public:
	std::istream& info;

public:
	Reader(std::istream& info);
	Reader& operator >> (std::vector<int> &vec);
};