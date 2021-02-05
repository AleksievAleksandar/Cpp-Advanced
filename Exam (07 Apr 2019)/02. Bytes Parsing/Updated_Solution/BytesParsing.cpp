#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#include "Defines.h"

enum Type
{
	SHORT = 0,
	INTEGER = 1,
	LONG_LONG = 2,

	UNKNOWN = 256
};

const Type getType(const char c, size_t& sizeOfBytes)
{
	switch (c)
	{
	case 's':
		sizeOfBytes = 2;
		return Type::SHORT;
		break;
	case 'i':
		sizeOfBytes = 4;
		return Type::INTEGER;
		break;
	case 'l':
		sizeOfBytes = 8;
		return Type::LONG_LONG;
		break;

	default:
		sizeOfBytes = 256;
		return Type::UNKNOWN;
		break;
	}
}

std::string getNewSubData(const size_t size, size_t& startIndex, const char* rawDataBytes)
{
	//char* c = new char[size];
	std::string c;
	for (size_t i = 0; i < size; i++)
	{
		//c[i] = rawDataBytes[startIndex];
		c += rawDataBytes[startIndex];
		startIndex++;
	}

	return c;
}

ErrorCode parseData(const std::string& commands, const char* rawDataBytes, const size_t rawDataBytesCount, std::vector<long long>& outParsedNumbers)
{

	if (commands.empty() || rawDataBytesCount == 0)
	{
		return ErrorCode::PARSE_EMPTY;
	}

	size_t rawDataIndex = 0;

	for (size_t i = 0; i < commands.size(); i++)
	{
		size_t sizeOfBytes = 0;
		const Type type = getType(commands[i], sizeOfBytes);		
		long long value = 0;

		//const char* c = getNewSubData(sizeOfBytes, rawDataIndex, rawDataBytes);
		std::string c = getNewSubData(sizeOfBytes, rawDataIndex, rawDataBytes);

		if (rawDataBytesCount < rawDataIndex)
		{
			return ErrorCode::PARSE_FAILURE;
		}

		switch (type)
		{
		case Type::SHORT:
			
			//std::memcpy(&value, c, sizeof(short));
			std::memcpy(&value, c.c_str(), sizeof(short));
			outParsedNumbers.push_back(value);
			break;
		case Type::INTEGER:

			std::memcpy(&value, c.c_str(), sizeof(int));
			outParsedNumbers.push_back(value);
			break;
		case Type::LONG_LONG:
			std::memcpy(&value, c.c_str(), sizeof(long long));
			outParsedNumbers.push_back(value);
			break;

		default:
			break;
		}
		//delete[] c;

	}
	return ErrorCode::PARSE_SUCCESS;
}

void printResult(const ErrorCode errorCode, const std::vector<long long>& parsedNumbers)
{
	for (size_t i = 0; i < parsedNumbers.size(); i++)
	{
		std::cout << parsedNumbers[i] << " ";
	}

	switch (errorCode)
	{
	case ErrorCode::PARSE_SUCCESS:
		break;
	case ErrorCode::PARSE_FAILURE:
		std::cout << "Warning, buffer underflow detected";
		break;
	case ErrorCode::PARSE_EMPTY:
		std::cout << "No input provided";
		break;
	default:
		break;
	}
}
