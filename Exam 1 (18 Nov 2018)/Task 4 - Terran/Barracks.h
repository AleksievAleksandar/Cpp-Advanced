#pragma once

#include "TimedBuilder.h"
#include <queue>

class Barracks : public TimedBuilder
{
private:
	static const int MAX_QUEUE_SIZE = 5;
	std::queue<Id> buildQueue{ };

public:
	static const int BUILD_TIME = 50;

public:
	Barracks() = default;
	Barracks(Id id);
	void handleCommand(const std::vector<std::string>& commandParts) override;
	void handleConstructionCompleted() override;
};