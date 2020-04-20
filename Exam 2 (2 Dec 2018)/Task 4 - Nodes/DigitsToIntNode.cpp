#include "DigitsToIntNode.h"

DigitsToIntNode::DigitsToIntNode(size_t id):
	NodeBase(id),result(0)
{
}

void DigitsToIntNode::process(byte data)
{
    if (data == '.') 
    {
        std::string result(this->elements.begin(), this->elements.end());
        this->sendToConnected(static_cast<byte>(stoi(result)));
        this->elements.clear();
    }
    else if (data >= '0' && data <= '9')
    {
        this->elements.push_back(data);
    }
}

