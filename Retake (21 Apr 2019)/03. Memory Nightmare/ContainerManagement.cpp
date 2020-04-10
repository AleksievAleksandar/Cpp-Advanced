#include "Defines.h"
#include <stack>
#include "ContainerInterface.h"
#include "MemoryContainer.h"
#include <iostream>


void pushContainer(const ContainerType containerType, const size_t containerSize,
                   std::stack<ContainerInterface*>& containers, size_t& occupiedMemory)
{
	switch (containerType)
	{
	case ContainerType::SHORT_CONTAINER:
	{
		//MemoryContainer<short> *a = new MemoryContainer<short>(containerSize);
		containers.push(new MemoryContainer<short>(containerSize));
		occupiedMemory += containers.top()->getOccupiedMemory();
		std::cout << "occupiedMemory: " << occupiedMemory << "\n";
		break;
	}
	case ContainerType::INT_CONTAINER:
	{
		//MemoryContainer<int>* a = new MemoryContainer<int>(containerSize);
		containers.push(new MemoryContainer<int>(containerSize));
		occupiedMemory += containers.top()->getOccupiedMemory();
		std::cout << "occupiedMemory: " << occupiedMemory << "\n";
		break;
	}
	case ContainerType::LONG_LONG_CONTAINER:
	{
		//MemoryContainer<long long>* a = new MemoryContainer<long long>(containerSize);
		containers.push(new MemoryContainer<long long>(containerSize));
		occupiedMemory += containers.top()->getOccupiedMemory();
		std::cout << "occupiedMemory: " << occupiedMemory << "\n";
		break;
	}
	default:
		break;
	}
}

void popContainer(std::stack<ContainerInterface*>& containers, size_t& occupiedMemory)
{
	if (!containers.empty())
	{
		occupiedMemory -= containers.top()->getOccupiedMemory();
		delete containers.top();
		containers.pop();
		std::cout << "occupiedMemory: " << occupiedMemory << "\n";
	}
	else
	{
		std::cout << "occupiedMemory: " << occupiedMemory << "\n";
	}
}

void freeMemory(std::stack<ContainerInterface*>& containers)
{
	//according the task, the body of this func must be empty
}