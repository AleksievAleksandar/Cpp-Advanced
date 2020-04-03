#pragma once

#include <iostream>
#include "Structs.h"
#include <vector>
#include <algorithm>

class Statistics
{
private:
	std::vector<PersonInfo> personsElders;
	std::vector<PersonInfo> personsAdults;
	std::vector<PersonInfo> personsMinors;

public:
	void printStatistics();
	Statistics& operator << (const PersonInfo &person);
};
