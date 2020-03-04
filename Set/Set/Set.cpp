#include <iostream>
#include <vector>
#include "Set.h"

int Set::indexOf(int item) const
{
	int result = -1;
	int i = 0;
	while (i < this->_v.size() && i == -1)
	{
		if (this->_v[i] == item)
		{
			result = i;
		}
		++i;
	}
	return result;
}

int Set::getEvenValuesCount()
{
	return this->_evenValuesCount;
}

Set::Set() : _evenValuesCount(0) { }
Set::Set(std::vector<int>& v) : _evenValuesCount(0)
{
	for (int i = 0; i < v.size(); ++i)
	{
		this->add(v[i]);
	}
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
}
void Set::remove(int item)
{
	if (this->contains(item))
	{
		if (item % 2 == 0)
		{
			--this->_evenValuesCount;
		}
		this->_v[this->indexOf(item)] = this->_v[this->_v.size()];
		this->_v.pop_back();
	}

	//std::vector<int>::iterator it = std::find(this->_v.begin(), this->_v.end(), item);
	//int index = std::distance(this->_v.begin(), it);
	//this->_v.erase(this->_v.begin() + index);
	// Shorter:
	//this->_v.erase(this->_v.begin() + std::distance(this->_v.begin(), std::find(this->_v.begin(), this->_v.end(), item)));
}
bool Set::contains(int item) const
{
	bool result = this->indexOf(item) != -1;
	//bool result = std::find(this->_v.begin(), this->_v.end(), item) != this->_v.end();
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
