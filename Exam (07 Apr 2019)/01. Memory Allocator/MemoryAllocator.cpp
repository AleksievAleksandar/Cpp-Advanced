#include <iostream>
#include <vector>
#include <sstream>
#include "Defines.h"

ErrorCode executeCommand(const std::string& command, std::vector<int*>& memory)
{
	std::stringstream ss(command);
	int ind = 0;
	std::string word;
	ss >> word;

	if (word == "Allocate")
	{
		ss >> ind;
		if (ind < memory.size())
		{
			if (memory[ind] == nullptr)
			{
				int* temp = new int;
				memory[ind] = temp;

				return ErrorCode::EXECUTE_SUCCESS;
			}
			else
			{
				return ErrorCode::MEMORY_LEAK; //memory leak prevent
			}

		}
		else
		{
			return ErrorCode::INDEX_OUT_OF_BOUND;
		}
	}
	else if (word == "Deallocate")
	{
		ss >> ind;
		if (ind < memory.size())
		{
			if (memory[ind] != nullptr)
			{
				delete memory[ind];
				memory[ind] = nullptr;
				return ErrorCode::EXECUTE_SUCCESS;
			}
			else
			{
				return ErrorCode::DOUBLE_FREE; //system crash prevent
			}
		}
		else
		{
			return ErrorCode::INDEX_OUT_OF_BOUND;
		}
	}
	else //Idle
	{
		return ErrorCode::EXECUTE_IDLE;
	}
}

void printResult(const ErrorCode errorCode, const std::string& command)
{
	std::cout << command;

	switch (errorCode)
	{
	case ErrorCode::EXECUTE_SUCCESS:
	{
		std::cout << " - success\n";
		break;
	}
	case ErrorCode::DOUBLE_FREE:
	{
		std::cout << " - system crash prevented, will skip this deallocation\n";
		break;
	}
	case ErrorCode::EXECUTE_IDLE:
	{
		std::cout << " - this exam is a piece of cake! Where is the OOP already?!?\n";
		break;
	}
	case ErrorCode::INDEX_OUT_OF_BOUND:
	{
		std::cout << " - out of bound\n";
		break;
	}
	case ErrorCode::MEMORY_LEAK:
	{
		std::cout << " - memory leak prevented, will not make allocation\n";
		break;
	}
	default:
		break;
	}
}