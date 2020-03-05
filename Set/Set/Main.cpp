#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set s;
	string addHelp = "Add to set: \"a <whole value>\"\nExample:\n>a 8\n\n";
	string removeHelp = "Remove from set: \"r <whole value>\"\nExample:\n>r 8\n\n";
	string containsHelp = "Decide that, the Set contains the given value : \"c <whole value>\"\nExample:\n>c 8\n\n";
	string evenHelp = "Write out, the count of the even element in the Set : \"e\"\nExample:\n>e\n\n";
	string help = "Type \"help\" to show help message\n\n";
	string END = "Type \"END\" to terminate program\n\n";

	cout << addHelp << removeHelp << containsHelp << evenHelp << help << END;
	string cmdString;
	do
	{
		cout << "Your Set: " << s << endl;
		cout << ">";
		cin >> cmdString;
		if (cmdString == "a")
		{
			int value;
			cin >> value;
			try
			{
				s.add(value);
			}
			catch (Set::Exception e)
			{
				switch (e)
				{
				case Set::alreadyContainsValueException:
					cout << "The set already contains " << value << endl;
					break;
				}
			}
		}
		else if (cmdString == "r")
		{
			int value;
			cin >> value;
			try
			{
				s.remove(value);
			}
			catch (Set::Exception e)
			{
				switch (e)
				{
				case Set::doesNotContainValueException:
					cout << "The set does not contain " << value << endl;
					break;
				}
			}
		}
		else if (cmdString == "c")
		{
			int value;
			cin >> value;
			cout << "Your Set " << (s.contains(value) ? "contains " : "does not contains ") << value << endl;
		}
		else if (cmdString == "e")
		{
			cout << "Your Set contains " << s.getEvenValuesCount() << " even value(s)" << endl;
		}
		else if (cmdString == "help")
		{
			cout << addHelp << removeHelp << containsHelp << help << END;
		}
		else
		{
			if (cmdString != "END")
			{

				cout << "Unknown command, for help type \"help\"";
			}
		}
	} while (cmdString != "END");

	cout << "Hello World!\n";

	return 0;
}
