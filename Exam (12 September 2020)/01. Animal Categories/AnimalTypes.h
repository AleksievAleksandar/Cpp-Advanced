#ifndef ANIMAL_TYPES_H
#define ANIMAL_TYPES_H

#include "AnimalCharacteristics.h"
#include "Defines.h"

#include <vector>

class AnimalTypes
{
private:
	std::vector<AnimalCharacteristics> cats;
	std::vector<AnimalCharacteristics> dogs;
	std::vector<AnimalCharacteristics> bunnies;

public:
	void print();
	friend AnimalTypes& operator<<(AnimalTypes& animalType, const AnimalCharacteristics& currentAnimal);
};

AnimalTypes& operator<<(AnimalTypes& animalType, const AnimalCharacteristics& currentAnimal);

#endif // !ANIMAL_TYPES_H
