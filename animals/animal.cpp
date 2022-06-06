#include "animal.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

inline ostream& operator <<(ostream& os, const Animal& animal) {
	return os << animal.about();
}

int main() {
	Wolf v1(4, 5, 8);
	//v1.setAverage_life_expectancy(10);
	//v1.setFirst_beasts_count(11);
	//v1.setNumber_of_species(5);
	cout << v1.about() << endl;
	Hare h1;
	h1.setRunning_speed_km_ch(5);
	h1.setFirst_beasts_count(10);
	h1.setNumber_of_species(99);
	cout << h1.about() << endl;
}
