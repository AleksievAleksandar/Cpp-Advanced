#pragma once

#include "NodeBase.h"
#include <vector>

class SumNode : public NodeBase
{
private:
	//std::vector<int> collection;
	int sum;

public:
	int result;

public:
	SumNode(size_t id);
	void process(byte data) override;

};
