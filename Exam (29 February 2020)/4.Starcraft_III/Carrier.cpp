#include "Carrier.h"
#include <iostream>

Carrier::Carrier(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId):
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId)
{
	this->_activeInterceptors = 8;
}

void Carrier::takeDamage(const int damage)
{
	ProtossAirShip::takeDamage(damage);
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	int currentEnemyShipInd = enemyFleet.size() - 1;

	if (currentEnemyShipInd >= 0)
	{
		if (this->getCurrHealth() == this->_maxHealth)
		{
			this->_activeInterceptors = Carrier::MAX_INTERCEPTORS;
		}
		else
		{
			this->_activeInterceptors = Carrier::DAMAGED_STATUS_INTERCEPTORS;
		}

		int cnt = 0;
		while (cnt < this->_activeInterceptors)
		{
			int currentEnemyShipInd = enemyFleet.size() - 1;
			enemyFleet[currentEnemyShipInd]->takeDamage(this->_damage);

			if (enemyFleet[currentEnemyShipInd]->getCurrHealth() <= 0)
			{
				//Print enemy killed
				std::cout << "Carrier with ID: " << this->getAirShipId() <<
					" killed enemy airship with ID: " << enemyFleet[currentEnemyShipInd]->getAirShipId() << "\n";
				enemyFleet.pop_back();
			}
			cnt++;
		}
	}
}
