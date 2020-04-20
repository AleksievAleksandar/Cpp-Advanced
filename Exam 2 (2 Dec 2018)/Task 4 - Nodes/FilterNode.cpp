#include "FilterNode.h"

FilterNode::FilterNode(size_t id, std::vector<byte> filter):
	NodeBase(id), filtered(filter.begin(), filter.end()), result("")
{
}

void FilterNode::process(byte data)
{
    if (this->filtered.find(data) == this->filtered.end()) 
    {
        this->sendToConnected(data);
    }
}

