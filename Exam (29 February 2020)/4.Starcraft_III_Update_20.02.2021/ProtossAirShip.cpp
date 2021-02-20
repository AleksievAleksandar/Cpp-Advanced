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
	this->_currShield -= damage;

	if (this->_currShield < 0)
	{
		this->_currHealth += this->_currShield;
		this->_currShield = 0;
	}
}

void ProtossAirShip::finishTurn()
{
	if (this->_maxShield >= this->_currShield + this->_shieldRegenerateRate)
	{
		this->_currShield += this->_shieldRegenerateRate;
	}
	else
	{
		this->_currShield = this->_maxShield;
	}
}
