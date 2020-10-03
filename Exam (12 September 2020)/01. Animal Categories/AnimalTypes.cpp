#include "AnimalTypes.h"

#include <iostream>

AnimalTypes& operator<<(AnimalTypes& animalType, const AnimalCharacteristics& currentAnimal)
{
	switch (static_cast<Animals>(currentAnimal.category))
	{
	case Animals::CATS:
		animalType.cats.push_back(currentAnimal);
		break;
	case Animals::DOGS:
		animalType.dogs.push_back(currentAnimal);
		break;
	case Animals::BUNNIES:
		animalType.bunnies.push_back(currentAnimal);
		break;

	default:
		break;
	}
    return animalType;
}

void AnimalTypes::print()
{
	std::cout << "Cat Breeds:\n";
	for (size_t i = 0; i < this->cats.size(); i++)
	{
		std::cout << this->cats[i].name << " - " << this->cats[i].breed << " - " << this->cats[i].age << "\n";
	}

	std::cout << "Dog Breeds:\n";
	for (size_t i = 0; i < this->dogs.size(); i++)
	{
		std::cout << this->dogs[i].name << " - " << this->dogs[i].breed << " - " << this->dogs[i].age << "\n";
	}

	std::cout << "Bunny Breeds:\n";
	for (size_t i = 0; i < this->bunnies.size(); i++)
	{
		std::cout << this->bunnies[i].name << " - " << this->bunnies[i].breed << " - " << this->bunnies[i].age << "\n";
	}
}
