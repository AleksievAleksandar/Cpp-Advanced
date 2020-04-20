#pragma once

#include "NodeBase.h"
#include <set>
#include <vector>
#include <string>

class FilterNode : public NodeBase
{
private:
	//std::vector<byte> filter;
	std::set<byte> filtered;

public:
	std::string result;

public:
	FilterNode(size_t id, std::vector<byte> filter);
	void process(byte data) override;
};