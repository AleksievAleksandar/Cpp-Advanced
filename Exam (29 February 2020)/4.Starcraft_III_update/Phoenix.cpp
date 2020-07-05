#include "Phoenix.h"
#include <iostream>

Phoenix::Phoenix(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId):
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId)
{
}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage);

	if (!enemyFleet[enemyFleet.size() - 1]->isAlive())
	{
		std::cout << "Phoenix with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet[enemyFleet.size() - 1]->getAirShipId() << "\n";
		enemyFleet.pop_back();
	}
}
