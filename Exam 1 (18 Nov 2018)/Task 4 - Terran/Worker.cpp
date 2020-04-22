#include "Worker.h"
#include <iostream>
#include "Depot.h"
#include "Barracks.h"

Worker::Worker(Id id) :
	TimedBuilder(id, "worker")
{
}

void Worker::handleCommand(const std::vector<std::string>& commandParts)
{
	if (commandParts[0] == "report" || isConstructing())
	{
		std::cout << Unit::getInfo() << " " << this->getId() << (isConstructing() ? " busy" : " free") << std::endl;
	}
	else if (commandParts[1] == "depot")
	{
		this->startBuilding(new Depot(), Depot::BUILD_TIME);
	}
	else if (commandParts[1] == "barracks")
	{
		Id id = parseId(commandParts[2]);
		this->startBuilding(new Barracks(id), Barracks::BUILD_TIME);
	}
}


