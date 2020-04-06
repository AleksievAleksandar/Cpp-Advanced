#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type, const int health, const int damage, const int maxShield, const int shieldRegenerateRate, const int shipId):
	AirShip(type, health, damage, shipId),
	_maxShield(maxShield),
	_currShield(maxShield),
	_shieldRegenerateRate(shieldRegenerateRate)
{
}

void ProtossAirShip::takeDamage(const int damage)
{
	if (this->_currShield >= damage)
	{
		this->_currShield -= damage;
	}
	else
	{
		if (this->_currShield > 0)
		{
			int takeTheRestDamageAfterShieldEnd = damage - this->_currShield;
			this->_currShield = 0;
			this->_currHealth -= takeTheRestDamageAfterShieldEnd;
		}
		else
		{
			this->_currHealth -= damage;
		}
	}
}

void ProtossAirShip::finishTurn()
{
	if (this->isAlive())
	{
		if (this->_shieldRegenerateRate + this->_currShield < this->_maxShield)
		{
			this->_currShield += this->_shieldRegenerateRate;
		}
		else
		{
			this->_currShield = this->_maxShield;
		}
	}
}
