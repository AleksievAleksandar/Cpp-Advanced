#include "MagicKingdom.h"
#include <iostream>
#include <algorithm>

void MagicKingdom::operator<<(Villager& v)
{
	if (v.power >= 0 && v.power <= 99)
	{
		this->commoner.push_back(v);
	}
	else if (v.power >= 100)
	{
		this->magicians.push_back(v);
	}
	else if (v.power < 0)
	{
		this->antiMags.push_back(v);
	}

}

void MagicKingdom::printAll()
{
	
	std::cout << "Anti-Mages:\n";
	if (!this->antiMags.empty())
	{
		std::sort(this->antiMags.begin(), this->antiMags.end(), [](Villager& a, Villager& b) { return a.power < b.power; });
		for (size_t i = 0; i < this->antiMags.size(); i++)
		{
			std::cout << this->antiMags[i].name << " - " << this->antiMags[i].magicItem << "\n";
		}
	}


	std::cout << "Commoners:\n";
	if (!this->commoner.empty())
	{
		std::sort(this->commoner.begin(), this->commoner.end(), [](Villager& a, Villager& b) { return a.power > b.power; });
		for (size_t i = 0; i < this->commoner.size(); i++)
		{
			std::cout << this->commoner[i].name << " - " << this->commoner[i].magicItem << "\n";
		}
	}


	std::cout << "Mages:\n";
	if (!this->magicians.empty())
	{
		std::sort(this->magicians.begin(), this->magicians.end(), [](Villager& a, Villager& b) { return a.power > b.power; });
		for (size_t i = 0; i < this->magicians.size(); i++)
		{
			std::cout << this->magicians[i].name << " - " << this->magicians[i].magicItem << "\n";
		}
	}
	
}
