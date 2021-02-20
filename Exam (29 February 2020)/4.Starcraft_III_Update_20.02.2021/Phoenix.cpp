#include "Phoenix.h"

#include <iostream>

Phoenix::Phoenix(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId) :
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId)
{
}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	int shipForAttacking = enemyFleet[enemyFleet.size() - 1]->getAirShipId();

	enemyFleet[shipForAttacking]->takeDamage(this->_damage);

	if (!enemyFleet[shipForAttacking]->isAlive())
	{
		std::cout << "Phoenix with ID: " << this->getAirShipId() << " killed enemy airship with ID: "
			<< enemyFleet[shipForAttacking]->getAirShipId() << std::endl;
		enemyFleet.pop_back();
	}
}
