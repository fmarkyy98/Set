#pragma once

#include <iostream>
#include <vector>

class Set
{
private:
	std::vector<int> _v;
	int _evenValuesCount;

public:
	int getEvenValuesCount();

	Set();
	Set(std::vector<int>& v);

	void add(int item);
	void remove(int item);
	bool contains(int item) const;
	friend std::ostream& operator << (std::ostream& os, const Set s);
};

