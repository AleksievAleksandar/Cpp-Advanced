#include "MemoryMonitor.h"
#include <iostream>

MemoryMonitor::MemoryMonitor()
{
}

MemoryMonitor::~MemoryMonitor()
{
}

void MemoryMonitor::pushNode(const int nodeSize)
{
	int tempSize = nodeSize * sizeof(int);
	std::cout << "Pushed node with memory occupation: " << tempSize << "\n";

	MemoryNode* temp = new MemoryNode();
	temp->size = nodeSize;
	temp->data = new int[nodeSize];

	this->_nodes.push_back(*temp);
}

void MemoryMonitor::popNode()
{
	if (this->_nodes.size() > 0)
	{
		int tempSize = this->_nodes[this->_nodes.size() - 1].size * sizeof(int);
		std::cout << "Popped node with memory occupation: " << tempSize << "\n";

		delete[] this->_nodes[this->_nodes.size() - 1].data;
		//this->_nodes[this->_nodes.size() - 1].data = nullptr;

		this->_nodes.pop_back();
	}
	else
	{
		std::cout << "No nodes to pop\n";
	}

}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes)
{
	int temp = numberOfNodes - 1;
	if (this->_nodes.size() < 1)
	{
		std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << 0 << "\n";
	}
	else
	{
		if (numberOfNodes < this->_nodes.size())
		{
			std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << this->_nodes[temp].size * sizeof(int) << "\n";
		}
		else
		{
			int tempSize = 0;
			for (size_t i = 0; i < this->_nodes.size(); i++)
			{
				tempSize += this->_nodes[i].size * sizeof(int);
			}
			std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << tempSize << "\n";
		}
	}

}

MemoryNode MemoryMonitor::getLastNode() const
{
	return this->_nodes[_nodes.size() - 1];
}
