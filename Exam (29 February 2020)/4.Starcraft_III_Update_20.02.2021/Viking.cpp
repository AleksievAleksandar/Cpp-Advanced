#include "Viking.h"

#include <iostream>

Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId) :
	TerranAirShip(type, health, baseDamage, shipId)
{
}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	int shipForAttacking = enemyFleet[enemyFleet.size() - 1]->getAirShipId();

	int damageToMake = this->_damage;
	if (enemyFleet[shipForAttacking]->getAirShipType() == AirShipType::PHOENIX)
	{
		damageToMake *= 2;
	}

	enemyFleet[shipForAttacking]->takeDamage(damageToMake);

	if (!enemyFleet[shipForAttacking]->isAlive())
	{
		std::cout << "Viking with ID: " << this->getAirShipId() << " killed enemy airship with ID: "
			<< enemyFleet[shipForAttacking]->getAirShipId() << std::endl;
		enemyFleet.pop_back();
	}
}
