#include "DeathKnight.h"

#include <iostream>

DeathKnight::DeathKnight(const std::string& name, const int maxMana, const int baseManaRegenRate):
	Hero(name, maxMana, baseManaRegenRate)
{
}

void DeathKnight::castSpell(const SpellType spell)
{
	int haveEnoughtMana = this->_currMana - this->_spells[spell].manaCost;

	if (haveEnoughtMana >= 0)
	{
		std::cout << this->_name << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana" << std::endl;
		this->_currMana -= this->_spells[spell].manaCost;

		if (spell == SpellType::ULTIMATE)
		{
			std::cout << this->_name << " casted " << this->_spells[SpellType::BASIC].name << " for 0 mana" << std::endl;
		}
	}
	else
	{
		std::cout << this->_name << " - not enough mana to cast " << this->_spells[spell].name << std::endl;
	}
}

void DeathKnight::regenerateMana()
{
	int calculatedMana = this->_manaRegenRate + this->_currMana;

	if (calculatedMana <= this->_maxMana)
	{
		this->_currMana = calculatedMana;
	}
	else
	{
		this->_currMana = this->_maxMana;
	}
}
