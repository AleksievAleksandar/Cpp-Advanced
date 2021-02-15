#include "MemoryPool.h"

MemoryPool::MemoryPool(const int memoryPoolSize) :
	_isMemoryBufferOccupied(new bool[memoryPoolSize] {}),
	_MEMORY_POOL_SIZE(memoryPoolSize)
{
	this->_memoryBuffer = new int[this->_MEMORY_POOL_SIZE]{};	
}

MemoryPool::~MemoryPool()
{
	delete[] this->_memoryBuffer;
	delete[] this->_isMemoryBufferOccupied;
}

ErrorCode MemoryPool::requestMemory(MemoryNode& outNode)
{
	int freeMemory = 0;
	for (int i = 0; i < this->_MEMORY_POOL_SIZE; i++)
	{
		if (this->_isMemoryBufferOccupied[i] == false)
		{
			freeMemory++;
		}
	}

	if (freeMemory > 0)
	{
		int firstFreeStartInd = 0;
		for (int i = 0; i < this->_MEMORY_POOL_SIZE; i++)
		{
			if (this->_isMemoryBufferOccupied[i] == false)
			{
				firstFreeStartInd = i;
				break;
			}
		}
		outNode.bufferStartIndex = firstFreeStartInd;		
	}
	if (outNode.size <= this->_MEMORY_POOL_SIZE)
	{
		if (outNode.size <= freeMemory)
		{
			outNode.memory = this->_memoryBuffer + outNode.bufferStartIndex;

			this->occupyMemory(outNode);

			return ErrorCode::REQUEST_SUCCESS;
		}
		else if (outNode.size > freeMemory)
		{
			return ErrorCode::REQUEST_FAILURE_NOT_ENOUGH_MEMORY;
		}
	}
	else
	{
		return ErrorCode::REQUEST_FAILURE_BIGGER_THAN_BUFFER;
	}

}

void MemoryPool::releaseMemory(const MemoryNode& outNode)
{
	int cnt = 0;
	int ind = outNode.bufferStartIndex;

	while (cnt < outNode.size)
	{
		this->_isMemoryBufferOccupied[ind] = false;
		ind++;
		cnt++;
	}
}

void MemoryPool::zeroMemoryValue(const MemoryNode& node)
{
	int cnt = 0;
	int ind = node.bufferStartIndex;

	while (cnt < node.size)
	{
		this->_memoryBuffer[ind] = 0;
		ind++;
		cnt++;
	}
}

void MemoryPool::occupyMemory(const MemoryNode& node)
{
	int cnt = 0;
	int ind = node.bufferStartIndex;

	while (cnt < node.size)
	{
		this->_isMemoryBufferOccupied[ind] = true;
		ind++;
		cnt++;
	}
}
