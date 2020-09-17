#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H

#include <vector>
#include "Discovery.h"

class ScientificField
{
public:
	std::vector<Discovery> philosophy;
	std::vector<Discovery> linguistics;
	std::vector<Discovery> physics;
	std::vector<Discovery> chemistry;

public:
	ScientificField() = default;
	void operator << (Discovery &d);
	void print();
};

#endif // !SCIENTIFIC_H