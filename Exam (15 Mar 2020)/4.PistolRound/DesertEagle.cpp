#include "DesertEagle.h"
#include <iostream>

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo):
	Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData)
{
	bool enemyKilled = false;
	bool pistolReload = false;

	if (enemyPlayerData.armor > 0)
	{
		int healthDamage = this->_damagePerRound * 0.75;
		int armorDamage = this->_damagePerRound * 0.25;
		int enemyArmorLeft = enemyPlayerData.armor - armorDamage;

		if (enemyArmorLeft <= 0)
		{
			if (this->_currClipBullets > 0)
			{
				enemyPlayerData.armor = 0;
				enemyPlayerData.health -= (armorDamage + (-enemyArmorLeft));//
				this->_currClipBullets--;
			}
			else
			{
				//enemyPlayerData.armor = 0;
				this->reload();
				pistolReload = true;
			}
		}
		else
		{
			if (this->_currClipBullets > 0)
			{
				enemyPlayerData.health -= healthDamage;
				enemyPlayerData.armor -= armorDamage;
				this->_currClipBullets--;
			}
			else
			{
				this->reload();
				pistolReload = true;
			}
		}
	}
	else
	{
		if (this->_currClipBullets > 0)
		{
			enemyPlayerData.health -= this->_damagePerRound;
			this->_currClipBullets--;
		}
		else
		{
			this->reload();
			pistolReload = true;
		}
	}

	if (pistolReload == false)
	{
		if (enemyPlayerData.health > 0)
		{
			std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor\n";
		}
		else
		{
			std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor\n";
			enemyKilled = true;
		}
	}

	
	return enemyKilled;
}
