#include "DesertEagle.h"

#include <iostream>

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo):
	Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData)
{
	if (this->_currClipBullets <= 0)
	{
		this->reload();
	}
	else
	{
		this->_currClipBullets--;
		if (enemyPlayerData.armor <= 0) //no Armor
		{
			enemyPlayerData.health -= this->_damagePerRound;
		}
		else
		{
			enemyPlayerData.armor -= ((this->_damagePerRound * 25.0) / 100.0);

			if (enemyPlayerData.armor > 0)
			{
				enemyPlayerData.health -= ((this->_damagePerRound * 75.0) / 100.0);
			}
			else
			{
				enemyPlayerData.health -= ((this->_damagePerRound * 75.0) / 100.0);
				enemyPlayerData.health += enemyPlayerData.armor;
				enemyPlayerData.armor = 0;
			}			
		}		
		std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor\n";
	}

	return enemyPlayerData.health <= 0;
}
