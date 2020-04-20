#pragma once

#include "NodeBase.h"
#include <string>

class DigitsToIntNode : public NodeBase
{
private:
	//std::string charCollection;
	std::vector<byte> elements{ };

public:
	unsigned int result;

public:
	DigitsToIntNode(size_t id);
	void process(byte data) override;
};