#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

#include "Discovery.h"
#include "Scientist.h"

Fields getFieldsOfStudy(std::string input)
{
	if (input == "Chemistry")
	{
		return Fields::Chemistry;
	}
	else if (input == "Physics")
	{
		return Fields::Physics;
	}
	else if (input == "Linguistics")
	{
		return Fields::Linguistics;
	}
	else
	{
		return Fields::Philosophy;
	}
}

void sortData(std::vector<Discovery>& discoveries)
{
	std::sort(discoveries.begin(), discoveries.end(), [](Discovery& a, Discovery& b) {return a.getYear() < b.getYear(); });
}

std::string printInfo(std::vector<Discovery>& discoveries)
{
	sortData(discoveries);

	std::ostringstream oss;
	
	for (size_t i = 0; i < discoveries.size(); i++)
	{
		oss << discoveries[i].getDiscoveryName() << " - " 
			<< discoveries[i].getScientistName() << " - " 
			<< discoveries[i].getFieldOfStudy() << "\n";
	}
	return oss.str();
}

int main()
{
	std::vector<Discovery> discoveries{};

	int numberOfScientists = 0;
	std::cin >> numberOfScientists;
	
	for (size_t i = 0; i < numberOfScientists; i++)
	{
		std::string nameOfPerson;
		int numDisc = 0;

		std::cin >> nameOfPerson >> numDisc;

		Scientist person(_strdup(nameOfPerson.c_str()), numDisc);

		for (size_t a = 0; a < numDisc; a++)
		{
			std::string discoveryName;
			int year = 0;
			std::string fieldOfStudy;

			std::cin >> discoveryName >> year >> fieldOfStudy;
			discoveries.emplace_back(Discovery(_strdup(discoveryName.c_str()), year, person, getFieldsOfStudy(fieldOfStudy)));
		}
	}
	std::cout << printInfo(discoveries);

	return 0;
}
