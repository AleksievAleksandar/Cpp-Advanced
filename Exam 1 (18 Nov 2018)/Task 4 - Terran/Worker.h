#pragma once

#include "TimedBuilder.h"

class Worker : public TimedBuilder
{
public:
	Worker() = default;
	Worker(Id id);
	void handleCommand(const std::vector<std::string>& commandParts) override;
	
};