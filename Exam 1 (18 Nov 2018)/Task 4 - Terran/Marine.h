#pragma once

#include "Unit.h"
#include "ControllableUnit.h"

class Marine : public ControllableUnit
{
public:
	static const int BUILD_TIME = 15;

public:
	Marine(Id id);
	void handleCommand(const std::vector<std::string>& commandParts) override;
};