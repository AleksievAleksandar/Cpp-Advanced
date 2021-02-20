#include "StringConcatenator.h"

#include <cstdlib>

StringConcatenator::StringConcatenator()
{
}

StringConcatenator::~StringConcatenator()
{
}

std::string StringConcatenator::concatenate(const ConcatenateStrategy strategy, const char* left, const size_t leftSize, const char* right, const size_t rightSize) const
{
	std::string result;
	size_t cntLeft = 0;
	size_t cntRight = 0;

	switch (strategy)
	{
	case ConcatenateStrategy::LEFT_1_RIGHT_1:
		while (cntLeft < leftSize || cntLeft < rightSize)
		{
			for (size_t i = cntLeft; i < leftSize; i++)
			{
				result += left[cntLeft];
				break;
			}
			for (size_t i = cntLeft; i < rightSize; i++)
			{
				result += right[cntLeft];
				break;
			}
			cntLeft++;
		}
		break;

	case ConcatenateStrategy::LEFT_1_RIGHT_2:
		while (cntLeft < leftSize || cntRight < rightSize)
		{
			for (size_t i = cntLeft; i < leftSize; i++)
			{
				result += left[cntLeft++];
				break;
			}
			int localCnt = 0;
			for (size_t i = cntRight; i < rightSize; i++)
			{
				result += right[cntRight++];
				localCnt++;
				if (localCnt > 1)
				{
					break;
				}				
			}
		}
		break;

	case ConcatenateStrategy::LEFT_2_RIGHT_1:
		while (cntLeft < leftSize || cntRight < rightSize)
		{
			int localCnt = 0;
			for (size_t i = cntLeft; i < leftSize; i++)
			{
				result += left[cntLeft++];
				localCnt++;
				if (localCnt > 1)
				{
					break;
				}
			}			
			for (size_t i = cntRight; i < rightSize; i++)
			{
				result += right[cntRight++];
				break;
			}
		}
		break;

	default:
		break;
	}

	return result;
}
