#include "DeathKnight.h"
#include <iostream>

DeathKnight::DeathKnight(const std::string& name, const int maxMana, const int baseManaRegenRate):
	Hero(name, maxMana, baseManaRegenRate)
{
}

void DeathKnight::castSpell(const SpellType spell)
{
	switch (spell)
	{
	case SpellType::BASIC:
	{
		if (this->_currMana >= this->_spells[spell].manaCost)
		{
			std::cout << this->_name << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana\n";
			this->_currMana -= this->_spells[spell].manaCost;
		}
		else
		{
			std::cout << this->_name << " - not enough mana to cast " << this->_spells[spell].name << "\n";
		}
		break;
	}
	case SpellType::ULTIMATE:
	{
		if (this->_currMana >= this->_spells[spell].manaCost)
		{
			std::cout << this->_name << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana\n";
			std::cout << this->_name << " casted " << this->_spells[spell].name << " for 0 mana\n";
			this->_currMana -= this->_spells[spell].manaCost;
		}
		else
		{
			std::cout << this->_name << " - not enough mana to cast " << this->_spells[spell].name << "\n";
		}
		break;
	}
	default:
		break;
	}
}

void DeathKnight::regenerateMana()
{
	if (this->_currMana < this->_maxMana)
	{
		if ((this->_currMana + this->_manaRegenRate) < this->_maxMana)
		{
			this->_currMana += this->_manaRegenRate;
		}
		else
		{
			this->_currMana = this->_maxMana;
		}
	}
}
