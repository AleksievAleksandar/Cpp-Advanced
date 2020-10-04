#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class Order
{
private:
	std::string type;
	std::string size;
	double price;

public:
	Order();
	Order(std::string type, std::string size, double price);
	Order(const Order& other);
	~Order();

	Order& operator = (const Order& other);

	void printOrderInfo();

	std::string getType() const;
	std::string getSize() const;
	double getPrice() const;

	void setType(std::string type);
	void setSize(std::string size);
	void setPrice(double price);
};

#endif // !ORDER_H
