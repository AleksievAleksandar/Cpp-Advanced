#include "Carrier.h"
#include <iostream>

Carrier::Carrier(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId):
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId), _activeInterceptors(MAX_INTERCEPTORS)
{
}

void Carrier::takeDamage(const int damage)
{
	Carrier::ProtossAirShip::takeDamage(damage);
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	if (this->getCurrHealth() == this->_maxHealth)
	{
		int cnt = 0;
		while (cnt != MAX_INTERCEPTORS)
		{
			enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage);

			if (!enemyFleet[enemyFleet.size() - 1]->isAlive())
			{
				std::cout << "Carrier with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet[enemyFleet.size() - 1]->getAirShipId() << "\n";
				enemyFleet.pop_back();
			}
			if (enemyFleet.empty())
			{
				break;
			}
			cnt++;
		}	
	}
	else
	{
		int cnt = 0;
		while (cnt != DAMAGED_STATUS_INTERCEPTORS)
		{
			enemyFleet[enemyFleet.size() - 1]->takeDamage(this->_damage);

			if (!enemyFleet[enemyFleet.size() - 1]->isAlive())
			{
				std::cout << "Carrier with ID: " << this->getAirShipId() << " killed enemy airship with ID: " << enemyFleet[enemyFleet.size() - 1]->getAirShipId() << "\n";
				enemyFleet.pop_back();
			}
			if (enemyFleet.empty())
			{
				break;
			}
			cnt++;
		}
	}
}
