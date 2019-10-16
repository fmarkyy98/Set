#include <iostream>

using namespace std;

struct Node
{
	string brand;
	int value = 0;
};

Node set[20];
int setCount = 0;

int setIndexOf(string item)
{
	int index = -1;
	bool found = false;

	int i = 0;
	while (i < setCount && !found)
	{
		if (set[i].brand == item)
		{
			found = true;
			index = i;
		}
		++i;
	}
	return index;
}

bool setContains(string item)
{
	bool result = setIndexOf(item) != -1;
	return result;
}

void setAdd(string item)
{
	if (!setContains(item))
	{
		set[setCount].brand = item;
		++set[setCount].value;
		++setCount;
	}
	else
	{
		++set[setIndexOf(item)].value;
	}
}

string setToString()
{
	for (int i = 0; i < setCount; ++i)
	{
		// TODO
	}
	return "";
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string text;
		int num;
		cin >> text;
		cin >> num;
		if (num > 500)
		{
			setAdd(text);
		}
	}
	return 0;
}
