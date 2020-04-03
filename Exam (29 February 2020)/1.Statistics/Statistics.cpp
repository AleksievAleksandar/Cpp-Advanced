#include "Statistics.h"


void Statistics::printStatistics()
{

	std::cout << "Elders data:\n";
	std::sort(this->personsElders.begin(), this->personsElders.end(),
		[](const PersonInfo& first, const PersonInfo& second) {return first.age > second.age; });
	for (size_t i = 0; i < this->personsElders.size(); i++)
	{
		std::cout << this->personsElders[i].firstName << " " << this->personsElders[i].lastName << " " << this->personsElders[i].height << "\n";
	}

	std::cout << "Adults data:\n";
	std::sort(this->personsAdults.begin(), this->personsAdults.end(),
		[](const PersonInfo& first, const PersonInfo& second) {return first.age < second.age; });
	for (size_t i = 0; i < this->personsAdults.size(); i++)
	{
		std::cout << this->personsAdults[i].firstName << " " << this->personsAdults[i].lastName << " " << this->personsAdults[i].height << "\n";
	}

	std::cout << "Minors data:\n";
	std::sort(this->personsMinors.begin(), this->personsMinors.end(),
		[](const PersonInfo& first, const PersonInfo& second) {return first.age < second.age; });
	for (size_t i = 0; i < this->personsMinors.size(); i++)
	{
		std::cout << this->personsMinors[i].firstName << " " << this->personsMinors[i].lastName << " " << this->personsMinors[i].height << "\n";
	}
}

Statistics& Statistics::operator<<(const PersonInfo& person)
{
	if (person.age > 62)
	{
		this->personsElders.push_back(person);
	}
	else if (person.age > 18 && person.age < 63)
	{
		this->personsAdults.push_back(person);
	}
	else
	{
		this->personsMinors.push_back(person);
	}

	return *this;
}
