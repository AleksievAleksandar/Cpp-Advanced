#include "Carrier.h"

#include <iostream>

Carrier::Carrier(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId) :
	ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId),
	_activeInterceptors(InterceptorDefines::MAX_INTERCEPTORS)
{
}

void Carrier::takeDamage(const int damage)
{
	ProtossAirShip::takeDamage(damage);

	if (this->_currHealth < this->_maxHealth)
	{
		this->_activeInterceptors = InterceptorDefines::DAMAGED_STATUS_INTERCEPTORS;
	}
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet)
{
	for (size_t i = 0; i < this->_activeInterceptors; i++)
	{
		if (!enemyFleet.empty())
		{
			int shipForAttacking = enemyFleet[enemyFleet.size() - 1]->getAirShipId();

			enemyFleet[shipForAttacking]->takeDamage(this->_damage);

			if (!enemyFleet[shipForAttacking]->isAlive())
			{
				std::cout << "Carrier with ID: " << this->getAirShipId() << " killed enemy airship with ID: "
					<< enemyFleet[shipForAttacking]->getAirShipId() << std::endl;
				enemyFleet.pop_back();
			}
		}
	}
}
