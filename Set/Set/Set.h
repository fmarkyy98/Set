#pragma once

#include <iostream>
#include <vector>

class Set
{
private:
	std::vector<int> _v;
	int _evenValuesCount;
	int indexOf(int item) const;

public:
	enum Exception
	{
		alreadyContainsValueException,
		doesNotContainValueException
	};

	int getEvenValuesCount() const;

	Set();
	Set(std::vector<int>& v);

	void add(int item);
	void remove(int item);
	bool contains(int item) const;
	friend std::ostream& operator << (std::ostream& os, const Set& s);
};

