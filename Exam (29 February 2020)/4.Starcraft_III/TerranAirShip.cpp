#include "TerranAirShip.h"

TerranAirShip::TerranAirShip(const AirShipType type, const int maxHealth, const int damage, const int shipId):
	AirShip(type, maxHealth, damage, shipId)
{
	this->_passedTurns = 0;
}

void TerranAirShip::takeDamage(const int damage)
{
	this->_currHealth -= damage;
}

void TerranAirShip::finishTurn()
{
	if (this->isAlive())
	{
		this->_passedTurns++;
	}
}
