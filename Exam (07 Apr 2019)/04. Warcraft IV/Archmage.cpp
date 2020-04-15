#include "Archmage.h"
#include <iostream>

Archmage::Archmage(const std::string& name, const int maxMana, const int baseManaRegenRate, const int manaRegenModifier):
	Hero(name, maxMana, baseManaRegenRate),
	_manaRegenModifier(manaRegenModifier)
{
}

void Archmage::castSpell(const SpellType spell)
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
			std::cout << this->_name << " - not enough mana to cast " << this->_spells[0].name << "\n";
		}
		break;
	}
	case SpellType::ULTIMATE:
	{
		if (this->_currMana >= this->_spells[spell].manaCost)
		{
			std::cout << this->_name << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana\n";	
			this->_currMana -= this->_spells[spell].manaCost;
			this->regenerateMana();
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

void Archmage::regenerateMana()
{
	if (this->_currMana < this->_maxMana)
	{
		if (((this->_manaRegenRate * this->_manaRegenModifier) + this->_currMana) < this->_maxMana)
		{
			this->_currMana += (this->_manaRegenRate * this->_manaRegenModifier);
		}
		else
		{
			this->_currMana = this->_maxMana;
		}
	}
}
