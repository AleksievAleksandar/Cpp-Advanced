#include "Archmage.h"

#include <iostream>

Archmage::Archmage(const std::string& name, const int maxMana, const int baseManaRegenRate, const int manaRegenModifier) :
	Hero(name, maxMana, baseManaRegenRate), _manaRegenModifier(manaRegenModifier)
{
}

void Archmage::castSpell(const SpellType spell)
{
	int haveEnoughtMana = this->_currMana - this->_spells[spell].manaCost;

	if (haveEnoughtMana >= 0)
	{
		std::cout << this->_name << " casted " << this->_spells[spell].name << " for " << this->_spells[spell].manaCost << " mana" << std::endl;
		this->_currMana -= this->_spells[spell].manaCost;

		if (spell == SpellType::ULTIMATE)
		{
			this->regenerateMana();
		}
	}
	else
	{
		std::cout << this->_name << " - not enough mana to cast " << this->_spells[spell].name << std::endl;
	}
}

void Archmage::regenerateMana()
{
	int calculatedMana = (this->_manaRegenModifier * this->_manaRegenRate) + this->_currMana;

	if (calculatedMana <= this->_maxMana)
	{
		this->_currMana = calculatedMana;
	}
	else
	{
		this->_currMana = this->_maxMana;
	}
}
