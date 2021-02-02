#ifndef SUM_NODE_H
#define SUM_NODE_H

#include "NodeBase.h"

class SumNode : public NodeBase
{
	int result;
public:
	SumNode(size_t id) : NodeBase(id), result(0) {}

public:
	virtual void process(byte data) override
	{
		if (data == 0)
		{
			this->sendToConnected(result);
		}
		else
		{
			this->result += data;
		}
	}
};

#endif // !SUM_NODE_H
