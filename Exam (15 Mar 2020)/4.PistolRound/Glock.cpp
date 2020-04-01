#include "Glock.h"

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo):
	Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
	bool enemyKilled = false;
	bool pistolReload = false;
	int cnt = 0;

	while (cnt != 3 && pistolReload == false && enemyKilled == false)
	{
		cnt++;
		if (enemyPlayerData.armor > 0)
		{
			int halfDamage = this->_damagePerRound / 2;
			int enemyArmorLeft = enemyPlayerData.armor - halfDamage;

			if (enemyArmorLeft <= 0)
			{
				if (this->_currClipBullets > 0)
				{
					enemyPlayerData.armor = 0;
					enemyPlayerData.health -= (halfDamage + (-enemyArmorLeft));//
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
					enemyPlayerData.health -= halfDamage;
					enemyPlayerData.armor -= halfDamage;
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

	}
	return enemyKilled;
}
