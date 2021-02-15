#include "MemoryPool.h"

#include <cstdlib>

MemoryPool::MemoryPool(const int memoryPoolSize):
	_memoryBuffer(new int[memoryPoolSize] {}), 
	_isMemoryBufferOccupied(new bool[memoryPoolSize] {}),
	_MEMORY_POOL_SIZE(memoryPoolSize)
{
}

MemoryPool::~MemoryPool()
{
	delete[] this->_memoryBuffer;
	delete[] this->_isMemoryBufferOccupied;
}

ErrorCode MemoryPool::requestMemory(MemoryNode& outNode)
{
	if (outNode.size > this->_MEMORY_POOL_SIZE)
	{
		return ErrorCode::REQUEST_FAILURE_BIGGER_THAN_BUFFER;
	}

	size_t freeSpace = 0;
	size_t startIndexForNode = 0;
	bool findStartIndex = false;

	for (size_t i = 0; i < this->_MEMORY_POOL_SIZE; i++)
	{
		if (!this->_isMemoryBufferOccupied[i])
		{
			freeSpace++;
			if (!findStartIndex)
			{
				startIndexForNode = i;
				findStartIndex = true;
			}

			if (freeSpace == outNode.size)
			{
				break;
			}
		}
		else if (this->_isMemoryBufferOccupied[i] && freeSpace < outNode.size)
		{
			freeSpace = 0;
			findStartIndex = false;
		}
	}
	if (freeSpace < outNode.size)
	{
		return ErrorCode::REQUEST_FAILURE_NOT_ENOUGH_MEMORY;
	}

	outNode.memory = this->_memoryBuffer + startIndexForNode;
	outNode.bufferStartIndex = startIndexForNode;

	this->occupyMemory(outNode);
	
	return ErrorCode::REQUEST_SUCCESS;
}

void MemoryPool::releaseMemory(const MemoryNode& outNode)
{
	size_t cnt = outNode.bufferStartIndex;
	size_t howManySteps = outNode.size;
	while (howManySteps > 0)
	{
		this->_isMemoryBufferOccupied[cnt] = false;
		cnt++;
		howManySteps--;
	}
}

void MemoryPool::zeroMemoryValue(const MemoryNode& node)
{
	size_t cnt = node.bufferStartIndex;
	size_t howManySteps = node.size;
	while (howManySteps > 0)
	{
		this->_memoryBuffer[cnt] = 0;
		cnt++;
		howManySteps--;
	}
}

void MemoryPool::occupyMemory(const MemoryNode& node)
{
	size_t cnt = node.bufferStartIndex;
	size_t howManySteps = node.size;
	while (howManySteps > 0)
	{
		this->_isMemoryBufferOccupied[cnt] = true;
		cnt++;
		howManySteps--;
	}
}
