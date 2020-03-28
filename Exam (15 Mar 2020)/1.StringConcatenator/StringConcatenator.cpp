#include "StringConcatenator.h"

StringConcatenator::StringConcatenator()
{
}

StringConcatenator::~StringConcatenator()
{
}

std::string StringConcatenator::concatenate(const ConcatenateStrategy strategy, const char* left, const size_t leftSize, const char* right, const size_t rightSize) const
{
	std::string temp = left;
	temp += right;
	size_t tempNextSymb = 0;

	char currentSymb;

	size_t leftCntString = 0;
	size_t rightCntString = 0;
	
	size_t nextSymbLeft = 0;
	size_t nextSymbRight = 0;

	switch (strategy)
	{
	case ConcatenateStrategy::LEFT_1_RIGHT_1:		
		while (leftCntString < leftSize || rightCntString < rightSize)
		{
			if (leftCntString < leftSize)
			{
				currentSymb = left[nextSymbLeft];
				temp[tempNextSymb] = currentSymb;
				nextSymbLeft++;
				tempNextSymb++;
				leftCntString++;
			}
			if (rightCntString < rightSize)
			{
				currentSymb = right[nextSymbRight];
				temp[tempNextSymb] = currentSymb;
				nextSymbRight++;
				tempNextSymb++;
				rightCntString++;
			}
		}
		break;
	case ConcatenateStrategy::LEFT_2_RIGHT_1:
		while (leftCntString < leftSize || rightCntString < rightSize)
		{
			if (leftCntString < leftSize)
			{
				size_t localCnt = 0;
				while (localCnt < 2 && leftCntString < leftSize)
				{
					localCnt++;
					currentSymb = left[nextSymbLeft];
					temp[tempNextSymb] = currentSymb;
					nextSymbLeft++;
					tempNextSymb++;
					leftCntString++;
				}
				localCnt = 0;
			}
			if (rightCntString < rightSize)
			{
				currentSymb = right[nextSymbRight];
				temp[tempNextSymb] = currentSymb;
				nextSymbRight++;
				tempNextSymb++;
				rightCntString++;
			}
		}
		break;
	case ConcatenateStrategy::LEFT_1_RIGHT_2:		
		while (leftCntString < leftSize || rightCntString < rightSize)
		{
			if (leftCntString < leftSize)
			{
				currentSymb = left[nextSymbLeft];
				temp[tempNextSymb] = currentSymb;
				nextSymbLeft++;
				tempNextSymb++;
				leftCntString++;
			}
			if (rightCntString < rightSize)
			{
				size_t localCnt = 0;
				while (localCnt < 2 && rightCntString < rightSize)
				{
					localCnt++;
					currentSymb = right[nextSymbRight];
					temp[tempNextSymb] = currentSymb;
					nextSymbRight++;
					tempNextSymb++;
					rightCntString++;
				}
				localCnt = 0;
			}
		}
		break;

	default:
		break;
	}
	return temp;
}
