#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set ps;
	string help = "Add to set: \"a <whole value>\"\nExample:\n>a 8\n\nRemove from set: \"r <whole value>\"\nExample:\n>r 8\n\nDecide that, the Set contains the given value: \"c <whole value>\"\nExample:\n>c 8\n\nType \"help\" to show help message\n\nType \"END\" to terminate program\n\n";
	cout << help;
	string cmdString;
	do
	{
		cout << ">";
		cin >> cmdString;
		if (cmdString == "a")
		{
			int value;
			cin >> value;
			cout << value << endl;
		}
		else if (cmdString == "r")
		{
			int value;
			cin >> value;
			cout << value << endl;
		}
	} while (cmdString != "END");
	
	vector<int> values{ 2,3,5,7,12,13 };
	Set ps2(values);

	ps.add(2);
	ps.add(3);
	ps.add(5);
	try
	{
		ps.add(5);
	}
	catch (Set::Exception e)
	{
		switch (e)
		{
		case Set::alreadyContainsValueException:
			cout << "The set already contains 5\n";
			break;
		}
	}
	ps.add(7);
	ps.add(11);
	cout << ps << ps.getEvenValuesCount() << endl;
	ps.remove(5);
	try
	{
		ps.remove(5);
	}
	catch (Set::Exception e)
	{
		switch (e)
		{
		case Set::doesNotContainValueException:
			cout << "The set does not contain 5\n";
			break;
		}
	}
	cout << ps << ps.getEvenValuesCount() << endl;
	cout << ps2 << ps2.getEvenValuesCount() << endl;
	cout << ps2.contains(5) << endl;

	cout << "Hello World!\n";
	return 0;
}
