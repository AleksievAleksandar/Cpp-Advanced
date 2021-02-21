#include "MemoryMonitor.h"

#include <iostream>
#include <cstdlib>

MemoryMonitor::MemoryMonitor()
{
}

MemoryMonitor::~MemoryMonitor()
{
	for (size_t i = 0; i < this->_nodes.size(); i++)
	{
		delete[] this->_nodes[i].data;
	}
}

void MemoryMonitor::pushNode(const int nodeSize)
{
	MemoryNode memoryNode;
	memoryNode.data = new int[nodeSize];
	memoryNode.size = nodeSize;

	this->_nodes.push_back(memoryNode);
	std::cout << "Pushed node with memory occupation: " << memoryNode.size * sizeof(int) << std::endl;
}

void MemoryMonitor::popNode()
{
	if (this->_nodes.empty())
	{
		std::cout << "No nodes to pop" << std::endl;
	}
	else
	{
		std::cout << "Popped node with memory occupation: " << this->_nodes.back().size * sizeof(int) << std::endl;
		delete[] this->_nodes.back().data;
		this->_nodes.pop_back();
	}
}

void MemoryMonitor::printMemoryOccupation(const int numberOfNodes)
{
	size_t resultSize = 0;

	if (numberOfNodes > this->_nodes.size())
	{
		for (size_t i = 0; i < this->_nodes.size(); i++)
		{
			resultSize += this->_nodes[i].size;
		}
	}
	else
	{
		for (size_t i = 0; i < numberOfNodes; i++)
		{
			resultSize += this->_nodes[i].size;
		}
	}
	std::cout << "Memory occupation for first " << numberOfNodes << " memory nodes is: " << resultSize * sizeof(int) << std::endl;
}

MemoryNode MemoryMonitor::getLastNode() const
{
	return this->_nodes.back();
}
