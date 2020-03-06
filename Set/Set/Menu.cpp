#include <iostream>
#include "Menu.h"

Menu::Menu() : s() { }

void Menu::menuAdd()
{
	int value;
	std::cin >> value;
	try
	{
		s.add(value);
	}
	catch (Set::Exception e)
	{
		switch (e)
		{
		case Set::alreadyContainsValueException:
			std::cout << "The set already contains " << value << std::endl;
			break;
		}
	}
}
void Menu::menuRemove()
{
	int value;
	std::cin >> value;
	try
	{
		s.remove(value);
	}
	catch (Set::Exception e)
	{
		switch (e)
		{
		case Set::doesNotContainValueException:
			std::cout << "The set does not contain " << value << std::endl;
			break;
		}
	}
}
void Menu::menuContains()
{
	int value;
	std::cin >> value;
	std::cout << "Your Set " << (s.contains(value) ? "contains " : "does not contains ") << value << std::endl;
}
void Menu::menuEven()
{
	std::cout << "Your Set contains " << s.getEvenValuesCount() << " even value(s)" << std::endl;
}
void Menu::menuHelp()
{
	std::cout << addInfo << removeInfo << containsInfo << helpInfo << END;
}

void Menu::run()
{
	menuHelp();
	do
	{
		std::cout << "Your Set: " << s << std::endl;
		std::cout << ">";
		std::cin >> cmdString;
		if (cmdString == "a")
		{
			menuAdd();
		}
		else if (cmdString == "r")
		{
			menuRemove();
		}
		else if (cmdString == "c")
		{
			menuContains();
		}
		else if (cmdString == "e")
		{
			menuEven();
		}
		else if (cmdString == "help")
		{
			menuHelp();
		}
		else
		{
			if (cmdString != "END")
			{
				std::cout << "Unknown command, for help type \"help\"";
			}
		}
	} while (cmdString != "END");
}