#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <set>

#include "Discovery.h"
#include "Scientist.h"

bool operator<(const Discovery& a, const Discovery& b)
{
	return a.getYear() < b.getYear();
}

Fields getField(const std::string& fieldType)
{
	if (fieldType == "Chemistry")
	{
		return Fields::Chemistry;
	}
	else if (fieldType == "Physics")
	{
		return Fields::Physics;
	}
	else if (fieldType == "Linguistics")
	{
		return Fields::Linguistics;
	}
	else if (fieldType == "Philosophy")
	{
		return Fields::Philosophy;
	}

	return static_cast<Fields>(-1);
}

int main()
{
	int numberOfScientist = 0;
	std::cin >> numberOfScientist;
	
	std::multiset<Discovery> discovery;

	for (size_t i = 0; i < numberOfScientist; i++)
	{
		std::string scientiestName;
		int numberOfDiscoveries = 0;
		std::cin >> scientiestName >> numberOfDiscoveries;
		std::cin.ignore();

		Scientist scientiest;
		scientiest.setName(scientiestName.c_str());
		scientiest.setDiscoveriesCount(numberOfDiscoveries);

		for (size_t a = 0; a < numberOfDiscoveries; a++)
		{
			std::string discoveriesInfo;
			std::getline(std::cin, discoveriesInfo);

			std::istringstream iss(discoveriesInfo);

			std::string discName;
			int discYear = 0;
			std::string discCat;

			iss >> discName >> discYear >> discCat;
			discovery.insert(Discovery(discName.c_str(), discYear, scientiest, getField(discCat)));
		}
	}

	for (const auto& i : discovery)
	{
		std::cout << i.getDiscoveryName() << " - " << i.getScientistName() << " - " << i.getFieldOfStudy() << std::endl;;
	}

	return 0;
}
