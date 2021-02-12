#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Defines.h"

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory)
{
	std::istringstream iss(command);
	std::string currentCommand;
	std::string typeOfMemory;
	size_t index = 0;

	iss >> currentCommand >> typeOfMemory >> index;

	if (currentCommand == "Allocate")
	{
		if (memory[index].rawMemory != nullptr)
		{
			return ErrorCode::MEMORY_LEAK;
		}
		else
		{
			if (typeOfMemory == "Single")
			{
				memory[index].rawMemory = new int();
				memory[index].memoryType = MemoryType::SINGLE;
			}
			else
			{
				memory[index].rawMemory = new int[MemoryType::MULTIPLE];
				memory[index].memoryType = MemoryType::MULTIPLE;
			}
		}
	}
	else
	{
		if (memory[index].rawMemory == nullptr)
		{
			return ErrorCode::DOUBLE_FREE; //system crash prevented
		}
		else
		{
			if (typeOfMemory == "Single")
			{
				if (memory[index].memoryType == MemoryType::SINGLE)
				{
					delete memory[index].rawMemory;
					memory[index].rawMemory = nullptr;
					memory[index].memoryType = MemoryType::UNKNOWN;
				}
				else
				{
					return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH; // mismatch
				}
			}
			else
			{
				if (memory[index].memoryType == MemoryType::MULTIPLE)
				{
					delete[] memory[index].rawMemory;
					memory[index].rawMemory = nullptr;
					memory[index].memoryType = MemoryType::UNKNOWN;
				}
				else
				{
					return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH; // mismatch
				}
			}
		}
	}
	return ErrorCode::EXECUTE_SUCCESS;
}

void printResult(const ErrorCode errorCode, const std::string& command)
{
	std::cout << command << " - ";

	switch (errorCode)
	{
	case ErrorCode::EXECUTE_SUCCESS:
		std::cout << "success";
		break;

	case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
		std::cout << "Warning allocate/deallocate mismatch, will skip this deallocation";
		break;

	case ErrorCode::DOUBLE_FREE:
		std::cout << "system crash prevented, will skip this deallocation";
		break;

	case ErrorCode::MEMORY_LEAK:
		std::cout << "memory leak prevented, will not make allocation";
		break;

	default:
		break;
	}

	std::cout << std::endl;
}
