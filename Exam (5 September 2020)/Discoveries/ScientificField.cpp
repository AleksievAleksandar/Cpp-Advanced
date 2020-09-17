#include "ScientificField.h"
#include <iostream>
#include <algorithm>

void ScientificField::operator<<(Discovery& d)
{
	if (d.fieldType == 1)
	{
		this->philosophy.push_back(d);
	}
	else if (d.fieldType == 2)
	{
		this->linguistics.push_back(d);
	}
	else if (d.fieldType == 3)
	{
		this->physics.push_back(d);
	}
	else
	{
		this->chemistry.push_back(d);
	}
}

void ScientificField::print()
{
	std::cout << "Physics:\n";
	if (!this->physics.empty())
	{
		std::sort(this->physics.begin(), this->physics.end(), [&](Discovery& a, Discovery& b) { return a.year < b.year; });
		for (size_t i = 0; i < this->physics.size(); i++)
		{
			std::cout << this->physics[i].name << " " << this->physics[i].year << " - " << this->physics[i].scientistName << "\n";
		}
	}

	std::cout << "Linguistics:\n";
	if (!this->linguistics.empty())
	{
		std::sort(this->linguistics.begin(), this->linguistics.end(), [&](Discovery& a, Discovery& b) { return a.year < b.year; });
		for (size_t i = 0; i < this->linguistics.size(); i++)
		{
			std::cout << this->linguistics[i].name << " " << this->linguistics[i].year << " - " << this->linguistics[i].scientistName << "\n";
		}
	}

	std::cout << "Philosophy:\n";
	if (!this->philosophy.empty())
	{
		std::sort(this->philosophy.begin(), this->philosophy.end(), [&](Discovery& a, Discovery& b) { return a.year < b.year; });
		for (size_t i = 0; i < this->philosophy.size(); i++)
		{
			std::cout << this->philosophy[i].name << " " << this->philosophy[i].year << " - " << this->philosophy[i].scientistName << "\n";
		}
	}

	std::cout << "Chemistry:\n";
	if (!this->chemistry.empty())
	{
		std::sort(this->chemistry.begin(), this->chemistry.end(), [&](Discovery& a, Discovery& b) { return a.year < b.year; });
		for (size_t i = 0; i < this->chemistry.size(); i++)
		{
			std::cout << this->chemistry[i].name << " " << this->chemistry[i].year << " - " << this->chemistry[i].scientistName << "\n";
		}
	}

}
