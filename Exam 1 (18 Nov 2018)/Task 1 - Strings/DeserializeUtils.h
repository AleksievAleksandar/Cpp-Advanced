#pragma once

#include <sstream>
#include <vector>

std::vector<std::string> deserializeStrings(char* serialized)
{
	std::string wordContainer;
	std::vector<std::string> output;
	size_t cntWords = 0;

	int numberWords = serialized[0];
	int lenghtOfCurrentWord = serialized[1];
	size_t wordNextIndex = 2;

	while (cntWords != numberWords)
	{
		for (int i = 0; i < lenghtOfCurrentWord; i++)
		{
			char symbol = serialized[wordNextIndex];
			wordContainer += symbol;
			wordNextIndex++;
		}
		output.push_back(wordContainer);
		wordContainer.clear();

		lenghtOfCurrentWord = serialized[wordNextIndex];
		wordNextIndex++;

		cntWords++;
	}

	return output;
}
