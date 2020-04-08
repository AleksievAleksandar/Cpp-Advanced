#include <iostream>
#include <sstream>
#include "Defines.h"


ErrorCode decryptMessage(const std::string& commands, const char* leftBufferData, const size_t leftBufferSize,
                        const char* rightBufferData, const size_t rightBufferSize,std::string& outMessage)
{
	if (commands.empty())
	{
		return ErrorCode::DECRYPT_EMPTY;
	}
	else
	{
		for (size_t i = 0; i < commands.size(); i++)
		{
			std::stringstream ss;
			if (commands[i] == 'r')
			{
				i++;
				ss << commands[i];
				int tempInd = 0;
				ss >> tempInd;

				if (tempInd >= rightBufferSize)
				{
					return ErrorCode::DECRYPT_FAILURE;
				}
				else
				{
					outMessage += rightBufferData[tempInd];
				}
			}
			else
			{
				i++;
				ss << commands[i];
				int tempInd = 0;
				ss >> tempInd;

				if (tempInd >= leftBufferSize)
				{
					return ErrorCode::DECRYPT_FAILURE;
				}
				else
				{
					outMessage += leftBufferData[tempInd];
				}
			}
		}
		return ErrorCode::DECRYPT_SUCCESS;
	}
}


void printResult(const ErrorCode errorCode, const std::string& decryptedMessage)
{
	if (errorCode == ErrorCode::DECRYPT_EMPTY)
	{
		std::cout << "No input provided\n";
	}
	else if (errorCode == ErrorCode::DECRYPT_SUCCESS)
	{
		std::cout << decryptedMessage << "\n";
	}
	else
	{
		std::cout << decryptedMessage << " Warning, buffer out-of-bound detected\n";
	}
}