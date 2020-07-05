#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId):
	AirShip(type, health, damage, shipId), _maxShield(maxShield), _currShield(maxShield), _shieldRegenerateRate(shieldRegenerateRate)
{
}

void ProtossAirShip::takeDamage(const int damage)
{
	if (this->_currShield > 0)
	{
		int tempDamage = damage - this->_currShield;

		if (tempDamage > 0)
		{
			this->_currShield = 0;
			this->_currHealth -= tempDamage;
		}
		else
		{
			this->_currShield -= damage;
		}

	}
	else
	{
		this->_currHealth -= damage;
	}
	
}

void ProtossAirShip::finishTurn()
{
	if (this->_currShield + this->_shieldRegenerateRate <= this->_maxShield)
	{
		this->_currShield += this->_shieldRegenerateRate;
	}
	else
	{
		this->_currShield = this->_maxShield;
	}
}
