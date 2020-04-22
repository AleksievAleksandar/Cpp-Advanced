#include "Barracks.h"
#include "Marine.h"

Barracks::Barracks(Id id) :
	TimedBuilder(id, "barracks")
{
}

void Barracks::handleCommand(const std::vector<std::string>& commandParts)
{
    if (this->buildQueue.size() <= MAX_QUEUE_SIZE && commandParts[0] == "train" && commandParts[1] == "marine") 
    {
        Id id = parseId(commandParts[2]);
        this->buildQueue.emplace(id);
        if (!TimedBuilder::isConstructing()) 
        {
            startBuilding(new Marine(id), Marine::BUILD_TIME);
        }
    }
}

void Barracks::handleConstructionCompleted()
{
    TimedBuilder::handleConstructionCompleted();
    this->buildQueue.pop();
    if (!this->buildQueue.empty()) 
    {
        startBuilding(new Marine(this->buildQueue.front()), Marine::BUILD_TIME);
    }
}
