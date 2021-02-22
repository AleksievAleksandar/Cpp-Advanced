#include "Glock.h"

#include <cstdlib>

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo) :
	Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
	if (this->_currClipBullets <= 0)
	{
		this->reload();
	}
	else
	{
		bool shouldReloadThisRound = (this->_currClipBullets < 3);
		size_t bulletsLeftForTheTurn = this->_currClipBullets;

		for (size_t i = 0; i < this->ROUNDS_PER_FIRE && i < bulletsLeftForTheTurn; i++)
		{
			this->_currClipBullets--;

			if (enemyPlayerData.armor <= 0) // no Armor
			{
				enemyPlayerData.health -= this->_damagePerRound;
			}
			else
			{
				enemyPlayerData.armor -= ((this->_damagePerRound * 50.0) / 100.0);

				if (enemyPlayerData.armor > 0)
				{
					enemyPlayerData.health -= ((this->_damagePerRound * 50.0) / 100.0);
				}
				else
				{
					enemyPlayerData.health -= ((this->_damagePerRound * 50.0) / 100.0);
					enemyPlayerData.health += enemyPlayerData.armor;
					enemyPlayerData.armor = 0;
				}
			}
			std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor\n";
			if (enemyPlayerData.health <= 0)
			{
				return true;
			}
		}
		if (shouldReloadThisRound)
		{
			this->reload();
		}
	}
	return false;
}
