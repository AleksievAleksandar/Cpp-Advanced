#include "BattleCruser.h"

#include <iostream>

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId) :
	TerranAirShip(type, health, damage, shipId)
{
}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	int shipForAttacking = enemyFleet[enemyFleet.size() - 1]->getAirShipId();

	int damageToMake = this->_damage;
	if (this->_passedTurns == BattleCruserDefines::YAMATO_CANNON_LOADING_TIME)
	{
		damageToMake *= 5;
		this->_passedTurns = -1;
	}

	enemyFleet[shipForAttacking]->takeDamage(damageToMake);

	if (!enemyFleet[shipForAttacking]->isAlive())
	{
		std::cout << "BattleCruser with ID: " << this->getAirShipId() << " killed enemy airship with ID: "
			<< enemyFleet[shipForAttacking]->getAirShipId() << std::endl;
		enemyFleet.pop_back();
	}
}
