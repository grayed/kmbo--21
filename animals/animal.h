#pragma once

#include <iostream>

class Animal {
public:
	float weight;				// kg
};

class Mammal : public Animal {
public:
	float pregnancyDuration = 9;	// days
	void setAbout() {
		cout << pregnancyDuration;
	}
};

class Cat : public Mammal {
public:
	float vibrissaLength;		// meters

};