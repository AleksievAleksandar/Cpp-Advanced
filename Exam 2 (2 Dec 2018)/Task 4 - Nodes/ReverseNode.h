#pragma once

#include "NodeBase.h"
#include <vector>

class ReverseNode : public NodeBase
{
public:
	std::vector<byte> data;

public:
	ReverseNode(size_t id);
	void process(byte data) override;
};