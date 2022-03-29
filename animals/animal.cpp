#include"animal.h"
#include<iostream>
using namespace std;
int main() {
	Cat c1;
	Deer d1;
	c1.set_life_expectancy(365);
	c1.set_pregnancy_duration(12);
	c1.set_vibrissae_length(6);
	cout << c1.about() << endl;
	d1.set_life_expectancy(365);
	d1.set_pregnancy_duration(5);
	d1.set_horns_length(50);
	cout << d1.about();
}