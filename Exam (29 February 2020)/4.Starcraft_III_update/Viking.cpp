#include "Viking.h"
#include <iostream>

Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId):
	TerranAirShip(type, health, baseDamage, shipId)
{
}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	if (enemyFleet[enemyFleet.size() - 1]->getAirShipType() == AirShipType::PHOENIX)
	{
		enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage * 2);
	}
	else
	{
		enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage);
	}

	if (!enemyFleet[enemyFleet.size() - 1]->isAlive())
	{
		std::cout << "Viking with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet[enemyFleet.size() - 1]->getAirShipId() << "\n";
		enemyFleet.pop_back();
	}
}
