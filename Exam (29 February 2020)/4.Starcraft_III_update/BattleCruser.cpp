#include "BattleCruser.h"
#include <iostream>

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId):
	TerranAirShip(type, health, damage, shipId)
{
}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	if (this->_passedTurns == YAMATO_CANNON_LOADING_TIME)
	{
		enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage * 5);
		this->_passedTurns = -1;
	}
	else
	{
		enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage);
	}

	if (!enemyFleet[enemyFleet.size() - 1]->isAlive())
	{
		std::cout << "BattleCruser with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet[enemyFleet.size() - 1]->getAirShipId() << "\n";
		enemyFleet.pop_back();
	}
}
