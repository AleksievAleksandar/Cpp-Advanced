#ifndef FILTER_NODE_H
#define FILTER_NODE_H

#include "NodeBase.h"

#include <vector>

class FilterNode : public NodeBase
{
	std::vector<byte> filtered;
public:
	FilterNode(size_t id, const std::vector<byte>& filtered) : NodeBase(id), filtered(filtered) {}

public:
	virtual void process(byte data) override
	{
		bool mustBeFiltered = false;
		for (size_t i = 0; i < this->filtered.size(); i++)
		{
			if (data == this->filtered[i])
			{
				mustBeFiltered = true;
				break;
			}
		}
		if (!mustBeFiltered)
		{
			this->sendToConnected(data);
		}
	}
};

#endif // !FILTER_NODE_H
