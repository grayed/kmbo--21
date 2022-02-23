#pragma once

#include <iostream>

class Animal {
public:
	float weight;				// kg

	virtual std::string about() const { /* TODO 1) */ }
};

class Mammal : public Animal {
public:
	float pregnancyDuration;	// days
};

// TODO: 2) Add another descendant of Animal class.

class Cat : public Mammal {
public:
	float vibrissaLength;		// meters
};

// TODO: 3) Add another descendant of Mammal class.

// TODO: 4) Add at least 2 descendants of class from (2).

// NOTE: Each class must have at least one unique property,
// representing something unique to this class.
// I.e., "weight" cannot be used for, e.g., "Mammal",
// because not only mammals have weight.

// TODO: 5) Implement about() in all classes.

// TODO: 6) Implement operator << for printing animal information
// into std::ostream object.

// NOTE: See vehicles.h and vehicles.cpp for examples.
