#ifndef FOOD_H
#define FOOD_H

#include "Order.h"

#include <string>
#include <vector>
#include <iostream>

class Food
{
public:
	std::string type;
	std::string size;
	double price;
	std::vector<Order> orders;

public:
	Food();

	void cook(std::string type, std::string size, double price);
	void sell(int index);
	void copy(int indexFrom, int indexTo);

};

#endif // !FOOD_H
