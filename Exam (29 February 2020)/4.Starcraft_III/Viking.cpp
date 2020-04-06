#include "Viking.h"
#include <iostream>

Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId) :
	TerranAirShip(type, health, baseDamage, shipId)
{
}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{

	int currentEnemyShipInd = enemyFleet.size() - 1;

	if (currentEnemyShipInd >= 0)
	{
		if (enemyFleet[currentEnemyShipInd]->getAirShipType() == AirShipType::PHOENIX)
		{
			enemyFleet[currentEnemyShipInd]->takeDamage(this->_damage * 2);
		}
		else
		{
			enemyFleet[currentEnemyShipInd]->takeDamage(this->_damage);
		}

		if (enemyFleet[currentEnemyShipInd]->getCurrHealth() <= 0)
		{
			//Print enemy killed
			std::cout << "Viking with ID: " << this->getAirShipId() <<
				" killed enemy airship with ID: " << enemyFleet[currentEnemyShipInd]->getAirShipId() << "\n";
			enemyFleet.pop_back();
		}
	}
}
