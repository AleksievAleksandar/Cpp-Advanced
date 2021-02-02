#ifndef REVERSE_NODE_H
#define REVERSE_NODE_H

#include "NodeBase.h"

#include <vector>

class ReverseNode : public NodeBase
{
	std::vector<byte> result;
public:
	ReverseNode(size_t id) : NodeBase(id) {}

public:
	virtual void process(byte data) override
	{
		if (data != '.')
		{
			this->result.push_back(data);
		}
		else
		{
			for (int i = this->result.size() - 1; i >= 0; i--)
			{
				this->sendToConnected(this->result[i]);
			} 
			this->result.clear();
		}
	}
};

#endif // !REVERSE_NODE_H
