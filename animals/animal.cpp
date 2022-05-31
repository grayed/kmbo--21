#include "animal.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	Monkey		  Harambe;
	Cow				Molly;
	Worm			Anton;
	Jellyfish		 Petr;

	Harambe.alive = true;
	Harambe.milk_volume = 1;
	Harambe.tail_lenght = 28;

	Molly.alive = true;
	Molly.milk_volume = 10;
	Molly.white = true;

	Anton.alive = true;
	Anton.no_spine = 1;
	Anton.length = 8;

	Petr.alive = true;
	Petr.no_spine = 1;
	Petr.transparent = true;

	cout << Harambe.about();
	cout << Petr.about();
}
