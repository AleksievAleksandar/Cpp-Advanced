#include "Player.h"
#include "DesertEagle.h"
#include "Glock.h"

void Player::buyPistol(const PistolType pistolType, const int damagePerRound, const int clipSize, const int remainingAmmo)
{
	switch (pistolType)
	{
	case PistolType::DESERT_EAGLE:
	{
		this->_pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
		break;
	}
	case PistolType::GLOCK:
	{
		this->_pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
		break;
	}
	default:
		break;
	}
}
