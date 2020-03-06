#include "Set.h"
#include "Menu.h"

using namespace std;

#define NORMAL_MODE
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

TEST_CASE("Empty")
{
	Set s;
	CHECK(s.getEvenValuesCount() == 0); // checking invariant
}

TEST_CASE("Put something in")
{
	Set s;
	s.add(1);
	s.add(2);
	s.add(3);
	CHECK(s.contains(1));
	CHECK(s.contains(2));
	CHECK(s.contains(3));
	CHECK(s.getEvenValuesCount() == 1); // checking invariant
}

TEST_CASE("Put something in, then remove some")
{
	Set s;
	s.add(1);
	s.add(2);
	s.add(3);
	s.remove(2);
	CHECK(s.contains(1) );
	CHECK_FALSE(s.contains(2));
	CHECK(s.contains(3));
	CHECK(s.getEvenValuesCount() == 0); // checking invariant
}

TEST_CASE("Put something in, then remove everything")
{
	Set s;
	s.add(1);
	s.add(2);
	s.add(3);
	s.remove(1);
	s.remove(2);
	s.remove(3);
	CHECK_FALSE(s.contains(1));
	CHECK_FALSE(s.contains(2));
	CHECK_FALSE(s.contains(3));
	CHECK(s.getEvenValuesCount() == 0); // checking invariant
}

TEST_CASE("Put in same value twice")
{
	Set s;
	s.add(1);
	CHECK_THROWS(s.add(1));
	CHECK(s.getEvenValuesCount() == 0); // checking invariant
}

TEST_CASE("Remove uncontained value")
{
	Set s;
	CHECK_THROWS(s.remove(1));
	CHECK(s.getEvenValuesCount() == 0); // checking invariant
}

#endif