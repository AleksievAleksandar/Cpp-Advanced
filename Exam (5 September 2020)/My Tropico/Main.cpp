#include <iostream>

#include "Tropico.h"
#include <sstream>

int main()
{
	int commands = 0;
	std::cin >> commands;
	std::cin.clear();
	std::cin.ignore();

	bool haveFirsdBuilding = false;

	Tropico tropico;
	std::string line;

	for (int i = 0; i < commands; i++)
	{
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string operation;
		iss >> operation;

		if (operation == "build" || operation == "built")
		{
			std::string typeBuilding;
			int width = 0;
			int length = 0;
			iss >> typeBuilding >> width >> length;
			
			tropico.build(typeBuilding, width, length);
			haveFirsdBuilding = true;
		}
		else if (operation == "duplicate")
		{
			int indFirst = 0;
			int indSecond = 0;
			iss >> indFirst >> indSecond;
			tropico.duplicate(indFirst, indSecond);
		}
		else if (operation == "replace")
		{
			int indFirst = 0;
			int indSecond = 0;
			iss >> indFirst >> indSecond;
			tropico.replace(indFirst, indSecond);
		}
		else
		{
			int ind = 0;
			iss >> ind;
			if (haveFirsdBuilding)
			{
				tropico.demolish(ind);
			}		
		}
	}
	
	return 0;
}
