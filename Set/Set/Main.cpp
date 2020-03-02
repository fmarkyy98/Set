#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set ps1;

	vector<int> values{ 2,3,5,7,12,13 };
	Set ps2(values);

	ps1.add(2);
	ps1.add(3);
	ps1.add(5);
	ps1.add(7);
	ps1.add(11);
	cout << ps1 << ps1.getEvenValuesCount() << endl;
	ps1.remove(5);
	cout << ps1 << ps1.getEvenValuesCount() << endl;
	cout << ps2 << ps2.getEvenValuesCount() << endl;
	cout << ps2.contains(5) << endl;

	cout << "Hello World!\n";
	return 0;
}
