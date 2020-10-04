#include <iostream>
#include <string>

#include "Food.h"
#include "Order.h"

void initFood(Food& food, std::string currentCommand)
{
	if (currentCommand == "cook")
	{
		std::string type;
		std::string size;
		double price;
		std::cin >> type >> size >> price;
		food.cook(type, size, price);
	}
	else if (currentCommand == "sell")
	{
		int index = 0;
		std::cin >> index;
		food.sell(index);
	}
	else
	{
		int firstIdx = 0;
		int secondIdx = 0;
		std::cin >> firstIdx >> secondIdx;
		food.copy(firstIdx, secondIdx);
	}
}

int main()
{
	Food food;

	int numCommands = 0;
	std::cin >> numCommands;

	for (size_t i = 0; i < numCommands; i++)
	{
		std::string currentCommand;
		std::cin >> currentCommand;

		initFood(food, currentCommand);
	}

	return 0;
}
