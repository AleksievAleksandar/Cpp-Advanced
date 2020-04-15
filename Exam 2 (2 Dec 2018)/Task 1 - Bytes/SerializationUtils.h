#pragma once

#include <string>
#include <vector>

char* serializeStrings(std::vector<std::string> lines, int &serializedSize)
{
	serializedSize = lines.size();
	for (size_t i = 0; i < lines.size(); i++)
	{
		serializedSize += lines[i].size();
	}

	char* serialize = new char[serializedSize];
	size_t cnt = 0;
	for (size_t i = 0; i < lines.size(); i++)
	{
		serialize[cnt] = lines[i].size();
		cnt++;
		for (size_t a = 0; a < lines[i].size(); a++)
		{
			serialize[cnt] = lines[i][a];
			cnt++;
		}
	}

	return serialize;
}