#ifndef DIGIT_TO_INT_NODE_H
#define DIGIT_TO_INT_NODE_H

#include "NodeBase.h"

#include <string>
#include <istream>

class DigitsToIntNode : public NodeBase
{
	std::string result;
public:
	DigitsToIntNode(size_t id) : NodeBase(id) {}

public:
	virtual void process(byte data) override
	{
		if (data >= 48 && data <= 57)
		{
			this->result += data;
		}

		if (data == '.')
		{
			int resultToSend = 0;
			resultToSend = std::stoi(this->result);
			resultToSend = std::abs(resultToSend);

			byte tempData = (char)resultToSend;

			this->sendToConnected(tempData);

			this->result.clear();
		}
	}
};

#endif // !DIGIT_TO_INT_NODE_H
