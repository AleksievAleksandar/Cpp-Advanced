#pragma once

#include <iostream>
#include <string>
#include <vector>

class StreamInputIterator
{
public:
	StreamInputIterator(std::istream& in);
	StreamInputIterator(std::istream& in, std::string endString);

	static StreamInputIterator begin(std::istream& in);
	static StreamInputIterator end(std::istream& in, std::string endString);

	StreamInputIterator& operator ++();
	bool operator !=(StreamInputIterator& other);
	bool operator ==(StreamInputIterator& other);
	int operator*();

private:
	int* current;
	int* next;
	int num;
	int sizeTemp;
	int cnt;
	bool hasNumber;
	bool transfer;
	bool getNext = false;
	std::vector<int> numbers;
};
