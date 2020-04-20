#include "SumNode.h"

SumNode::SumNode(size_t id):
	NodeBase(id), sum(0)
{
}

void SumNode::process(byte data)
{
    int value = (int)data;
    this->sum += value;
    if (value == 0) 
    {
        this->sendToConnected(static_cast<byte>(this->sum));
        this->sum = 0;
    }
}
