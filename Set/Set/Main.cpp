#include "Set.h"
#include "Menu.h"

using namespace std;

//#define NORMAL_MODE
#ifdef  NORMAL_MODE
int main()
{
	Menu m;
	m.run();

	return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "./Test/src/catch.hpp"

#endif