#include "BattleCruser.h"
#include <iostream>

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId):
	TerranAirShip(type, health, damage, shipId)
{
}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	int currentEnemyShipInd = enemyFleet.size() - 1;
	
	if (currentEnemyShipInd >= 0)
	{
		if (this->_passedTurns == BattleCruserDefines::YAMATO_CANNON_LOADING_TIME)
		{
			enemyFleet[currentEnemyShipInd]->takeDamage(this->_damage * 5);
			this->_passedTurns = -1;
		}
		else
		{
			enemyFleet[currentEnemyShipInd]->takeDamage(this->_damage);
		}

		if (enemyFleet[currentEnemyShipInd]->getCurrHealth() <= 0)
		{
			//Print enemy killed
			std::cout << "BattleCruser with ID: " << this->getAirShipId() <<
				" killed enemy airship with ID: " << enemyFleet[currentEnemyShipInd]->getAirShipId() << "\n";
			enemyFleet.pop_back();
		}
	}
}
