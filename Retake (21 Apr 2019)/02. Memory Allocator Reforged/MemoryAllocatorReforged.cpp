#include <iostream>
#include <vector>
#include <sstream>
#include "Defines.h"

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory)
{
	std::stringstream ss;
	ss << command;
	std::string words;
	int tempInd = 0;

	while (ss >> words)
	{
		if (words == "Allocate")
		{
			MemoryNode temp;
			ss >> words;
			if (words == "Single")
			{
				ss >> tempInd;
				temp.rawMemory = new int;
				temp.memoryType = MemoryType::SINGLE;
				if (memory[tempInd].rawMemory == nullptr)
				{
					memory[tempInd] = temp;
					return ErrorCode::EXECUTE_SUCCESS;
				}
				else
				{
					return ErrorCode::MEMORY_LEAK;
				}
			}
			else
			{
				ss >> tempInd;
				temp.rawMemory = new int[MemoryType::MULTIPLE];
				temp.memoryType = MemoryType::MULTIPLE;
				if (memory[tempInd].rawMemory == nullptr)
				{
					memory[tempInd] = temp;
					return ErrorCode::EXECUTE_SUCCESS;
				}
				else
				{
					return ErrorCode::MEMORY_LEAK;
				}
			}
		}
		else // Deallocated
		{
			ss >> words;
			if (words == "Single")
			{
				ss >> tempInd;
				if (memory[tempInd].rawMemory != nullptr && memory[tempInd].memoryType == MemoryType::SINGLE)
				{
					memory[tempInd].rawMemory = nullptr;
					memory[tempInd].memoryType = MemoryType::UNKNOWN;
					return ErrorCode::EXECUTE_SUCCESS;
				}
				else
				{
					if (memory[tempInd].memoryType != MemoryType::SINGLE && memory[tempInd].rawMemory != nullptr)
					{
						return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
					}
					else// if (memory[tempInd].rawMemory == nullptr)
					{
						return ErrorCode::DOUBLE_FREE;
					}
				}
			}
			else
			{
				ss >> tempInd;
				if (memory[tempInd].rawMemory != nullptr && memory[tempInd].memoryType == MemoryType::MULTIPLE)
				{
					memory[tempInd].rawMemory = nullptr;
					memory[tempInd].memoryType = MemoryType::UNKNOWN;
					return ErrorCode::EXECUTE_SUCCESS;
				}
				else
				{
					if (memory[tempInd].memoryType != MemoryType::MULTIPLE && memory[tempInd].rawMemory != nullptr)
					{
						return ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
					}
					else// if (memory[tempInd].rawMemory == nullptr)
					{
						return ErrorCode::DOUBLE_FREE;
					}
				}
			}
		}
	}

}

void printResult(const ErrorCode errorCode, const std::string& command)
{
	if (command[0] == 'A')
	{
		if (errorCode == ErrorCode::EXECUTE_SUCCESS)
		{
			std::cout << command << " - success\n";
		}
		else// if (errorCode == ErrorCode::MEMORY_LEAK)
		{
			std::cout << command << " - memory leak prevented, will not make allocation\n";
		}
	}
	else
	{
		if (errorCode == ErrorCode::EXECUTE_SUCCESS)
		{
			std::cout << command << " - success\n";
		}
		else if (errorCode == ErrorCode::MEMORY_LEAK)
		{
			std::cout << command << " - memory leak prevented, will not make allocation\n";
		}
		else if (errorCode == ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH)
		{
			std::cout << command << " - Warning allocate/deallocate mismatch, will skip this deallocation\n";
		}
		else
		{
			std::cout << command << " - system crash prevented, will skip this deallocation\n";
		}
	}
}