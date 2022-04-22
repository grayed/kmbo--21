#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Animal {
private:
	float weight;				// kg

protected:
	Animal(float weight_);

public:
	float getWeight() const { return weight; }
	void setWeigh(float newValue) { weight = newValue; }

	virtual string about() const;
};

ostream& operator <<(ostream& os, const Animal& animal);

class Mammal : public Animal {
private:
	float pregnancyDuration;	// days

protected:
	Mammal(float weight_, float pregnanceDuration_);

public:
	float getPregnancyDuration() const { return pregnancyDuration; }
	void setPregnancyDuration(float newValue) { pregnancyDuration = newValue; }

	virtual string about() const;
};

class Insect : public Animal {
private:
	float antennasLength; 		// meters

protected:
	Insect(float weight_, float antennasLength_);

public:
	float getAntennasLenght() const { return antennasLength; }
	void setAntennasLength(float newValue) { antennasLength = newValue; }

	virtual string about() const;
};

class Cat : public Mammal {
private:
	float vibrissaLength;		// meters

public:
	Cat(float weight_, float pregnancyDuration_, float vibrissaLength_);

	float getVibrissaLength() const { return vibrissaLength; }
	void setVibrissaLength(float newValue) {vibrissaLength = newValue; }

	virtual string about() const;
};

class Dog : public Mammal {
private:
	float tailLength; 			// meters

public:
	Dog(float weight_, float pregnancyDuration_, float tailLength);

	float getTailLength() const { return tailLength; }
	void setTailLength(float newValue) { tailLength = newValue; }

	virtual string about() const;
};

class Bug : public Insect {
private:
	float wingLength; 			// meters

public:
	Bug(float weight_, float antennasLength_, float wingLength_);

	float getWingLength() const { return wingLength; }
	void setWingLength(float newValue) { wingLength = newValue; }

	virtual string about() const;
};

class Dragonfly : public Insect {
private:
	float airspeed; 			// meters per second

public:
	Dragonfly(float weight_, float antennasLength_, float airspeed_);

	float getAirSpeed() const { return airspeed; }
	void setAirSpeed(float newValue) { airspeed = newValue; }

	virtual string about() const;
};