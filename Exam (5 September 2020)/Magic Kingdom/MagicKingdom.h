#ifndef MAGIC_KINGDOM_H
#define MAGIC_KINGDOM_H

#include <vector>
#include <sstream>
#include "Struct.h"

class MagicKingdom
{
public:
	std::vector<Villager> commoner;
	std::vector<Villager> magicians;
	std::vector<Villager> antiMags;

public:
	MagicKingdom() = default;
	void operator << (Villager& v);
	void printAll();
};




#endif // !MAGIC_KINGDOM_H
