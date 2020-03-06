#pragma once

#include "Set.h"

class Menu
{
private:
	Set s;
	std::string addInfo = "Add to set: \"a <whole value>\"\nExample:\n>a 8\n\n";
	std::string removeInfo = "Remove from set: \"r <whole value>\"\nExample:\n>r 8\n\n";
	std::string containsInfo = "Decide that, the Set contains the given value : \"c <whole value>\"\nExample:\n>c 8\n\n";
	std::string evenInfo = "Write out, the count of the even element in the Set : \"e\"\nExample:\n>e\n\n";
	std::string helpInfo = "Type \"help\" to show help message\n\n";
	std::string END = "Type \"END\" to terminate program\n\n";
	std::string cmdString;

	void menuAdd();
	void menuRemove();
	void menuContains();
	void menuEven();
	void menuHelp();

public:
	Menu();

	void run();
};

