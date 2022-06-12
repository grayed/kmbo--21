#pragma once
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	float weight;	// kg
	float height; // meters

	virtual std::string about() const;
};

class Mammal : public Animal {
public:
	float pregnancyDuration;	// days
	float age;                  //years

	virtual std::string about() const;
};

class Dog : public Mammal {
public:
	string woolcolor; //color

	virtual std::string about() const;
};

class Human : public Mammal {
public:
	int iq;      //scores

	virtual std::string about() const;
};

class Bird : public Animal {
public:
	bool fly;	      // true/false 
	float wingspan;   //centimeters

	virtual std::string about() const;
};

class Penguin : public Bird {
public:
	string sex;       //male/female

	virtual std::string about() const;
};

class Parrot : public Bird {
public:
	bool speak;    //true/false

	virtual std::string about() const;
};

inline std::ostream& operator <<(std::ostream& os, const Penguin& penguin) {
	return os << penguin.about();
}

inline std::ostream& operator <<(std::ostream& os, const Parrot& parrot) {
	return os << parrot.about();
}