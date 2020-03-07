#include <iostream>
#include <vector>
#include "Set.h"

int Set::getEvenValuesCount() const
{
	return this->_evenValuesCount;
}

Set::Set() : _evenValuesCount(0), _v() { }

Set::Set(std::vector<int>& v) : _evenValuesCount(0), _v()
{
	for (int i = 0; i < v.size(); ++i)
	{
		this->add(v[i]);
	}
}

int Set::indexOf(int item) const
{
	int result = -1;
	int i = 0;
	while (i < this->_v.size() && result == -1)
	{
		if (this->_v[i] == item)
		{
			result = i;
		}
		++i;
	}
	return result;
}

void Set::add(int item)
{
	if (!this->contains(item))
	{
		if (item % 2 == 0)
		{
			++this->_evenValuesCount;
		}
		this->_v.push_back(item);
	}
	else
	{
		throw alreadyContainsValueException;
	}
}
void Set::remove(int item)
{
	if (this->contains(item))
	{
		if (item % 2 == 0)
		{
			--this->_evenValuesCount;
		}
		this->_v[this->indexOf(item)] = this->_v[this->_v.size() - 1];
		this->_v.pop_back();
	}
	else
	{
		throw doesNotContainValueException;
	}
}
bool Set::contains(int item) const
{
	bool result = this->indexOf(item) != -1;
	return result;
}
std::ostream& operator << (std::ostream& os, const Set& s)
{
	os << "[";
	bool printedAlredy = false;
	for (int item : s._v)
	{
		if (printedAlredy)
		{
			os << "," << item;
		}
		else
		{
			os << item;
			printedAlredy = true;
		}
	}
	os << "]";
	return os;
}
