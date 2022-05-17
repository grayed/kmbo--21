#pragma once

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class Animal {
public:
	float weight;				// kg
	int numof_limbs;

	virtual std::string about() const;
};

class Insects : public Animal{
public:
	int numof_wings;

	virtual std::string about() const;

};

class Reptilies : public Animal{
public:
	bool isShell;
	float tongueLength; //meters
};

class Mammal : public Animal {
public:
	float pregnancyDuration;	// days
	 int numof_niples;
};

class Beatle : public Insects{
public:
	string numof_mustache;

	virtual std::string about() const;
};

class ButterFly : public Insects{
public:
	string colorof_wings;

	virtual std::string about() const;
};

class Snake : public Reptilies{
public:
		bool isPoisonous;
};

class Turtle : public Reptilies{
public:
	 float shellStrength; //kg
};

class Cat : public Mammal{
public:
	float vibrissaLength;		// meters
};

class Dog : public Mammal{
public:
	float dobermanLength; // meters
};

inline std::ostream& operator <<(std::ostream& os, const Beatle& beatle) {
	return os << beatle.about();
}

inline std::ostream& operator <<(std::ostream& os, const ButterFly& bttfly) {
	return os << bttfly.about();
}
