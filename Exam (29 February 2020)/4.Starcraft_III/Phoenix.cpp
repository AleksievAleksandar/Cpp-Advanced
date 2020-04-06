#include "Phoenix.h"
#include <iostream>

Phoenix::Phoenix(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId) :
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId)
{
}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	int currentEnemyShipInd = enemyFleet.size() - 1;

	if (currentEnemyShipInd >= 0)
	{
		enemyFleet[currentEnemyShipInd]->takeDamage(this->_damage);

		if (enemyFleet[currentEnemyShipInd]->getCurrHealth() <= 0)
		{
			//Print enemy killed
			std::cout << "Phoenix with ID: " << this->getAirShipId() <<
				" killed enemy airship with ID: " << enemyFleet[currentEnemyShipInd]->getAirShipId() << "\n";
			enemyFleet.pop_back();
		}
	}
}
