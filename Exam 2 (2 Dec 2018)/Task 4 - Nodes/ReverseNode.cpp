#include "ReverseNode.h"
#include <algorithm>

ReverseNode::ReverseNode(size_t id):
	NodeBase(id)
{
}

void ReverseNode::process(byte data)
{
    if (data == '.') 
    {
        std::reverse(this->data.begin(), this->data.end());
        for (auto b : this->data) 
        {
            this->sendToConnected(b);
        }
        this->data.clear();
    }
    else 
    {
        this->data.push_back(data);
    }
}
