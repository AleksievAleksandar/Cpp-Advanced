#include "Marine.h"
#include <iostream>

Marine::Marine(Id id):
	ControllableUnit(id, "marine")
{
}

void Marine::handleCommand(const std::vector<std::string>& commandParts)
{
	if (commandParts[0] == "report") 
	{
		std::cout << "marine " << this->getId() << " reporting" << std::endl;
	}
}


