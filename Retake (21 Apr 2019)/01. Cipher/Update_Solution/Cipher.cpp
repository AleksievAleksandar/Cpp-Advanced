#include "Defines.h"

#include <iostream>
#include <string>

ErrorCode decryptMessage(const std::string& commands, const char* leftBufferData, const size_t leftBufferSize,
	const char* rightBufferData, const size_t rightBufferSize, std::string& outMessage)
{
	if (commands.empty())
	{
		return ErrorCode::DECRYPT_EMPTY;
	}

	size_t cnt = 0;
	while (cnt < commands.size())
	{
		char bufferSelection = commands[cnt];
		cnt++;

		size_t index = commands[cnt] - '0';
		cnt++;

		if (bufferSelection == 'l')
		{
			if (index < leftBufferSize)
			{
				outMessage += leftBufferData[index];
			}
			else
			{
				return ErrorCode::DECRYPT_FAILURE;
			}
		}
		else
		{
			if (index < rightBufferSize)
			{
				outMessage += rightBufferData[index];
			}
			else
			{
				return ErrorCode::DECRYPT_FAILURE;
			}
		}
	}

	return ErrorCode::DECRYPT_SUCCESS;
}

void printResult(const ErrorCode errorCode, const std::string& decryptedMessage)
{
	switch (errorCode)
	{
	case ErrorCode::DECRYPT_SUCCESS:
		std::cout << decryptedMessage;
		break;

	case ErrorCode::DECRYPT_FAILURE:
		std::cout << decryptedMessage << " Warning, buffer out-of-bound detected";
		break;

	case ErrorCode::DECRYPT_EMPTY:
		std::cout << "No input provided";
		break;

	default:
		break;
	}
}
