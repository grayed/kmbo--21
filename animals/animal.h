#pragma once

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class Animal {
private:
	float weight;				// kg
	int numof_limbs;
protected:
	Animal(float weight_ ,int numof_limbs_);
	virtual ~Animal();
public:
			 float  getWeight() const       { return weight; }
			 void setWeight(float newValue) { weight = newValue; }
			 int  getNumofLimbs() const       { return numof_limbs; }
			 void setNumofLimbs(int newValue) { numof_limbs = newValue; }
			 virtual std::string about() const;
};

class Insects : public Animal{
private:
	int numof_wings;
protected:
	Insects(float weight_ ,int numof_limbs_, int numof_wings_);
public:
			 int  getNumofWings() const       { return numof_wings; }
			 void 	setNumofWings(int newValue) { numof_wings = newValue; }
			 virtual std::string about() const;

};

class Reptilies : public Animal{
private:
	bool isShell;
	float tongueLength; //meters
};

class Mammal : public Animal {
private:
	float pregnancyDuration;	// days
	 int numof_niples;
};

class Beatle : public Insects{
private:
	int numof_mustache;
public:
			 int  getNumofMustache() const       { return numof_mustache; }
			 void 	setNumofMustache(int newValue) { numof_mustache = newValue; }
			 virtual std::string about() const;
			 Beatle(float weight_,int numof_limbs_,int numof_wings_,int numof_mustache_);
};

class ButterFly : public Insects{
private:
	string colorof_wings;
public:
			 string getColorofWings() const       { return colorof_wings; }
			 void setColorofWings(string newValue) { colorof_wings = newValue; }
			 virtual std::string about() const;
			 ButterFly(float weight_,int numof_limbs_,int numof_wings_,string colorof_wings_);
};

class Snake : public Reptilies{
private:
		bool isPoisonous;
};

class Turtle : public Reptilies{
private:
	 float shellStrength; //kg
};

class Cat : public Mammal{
private:
	float vibrissaLength;		// meters
};

class Dog : public Mammal{
private:
	float dobermanLength; // meters
};

inline std::ostream& operator <<(std::ostream& os, const Beatle& beatle) {
	return os << beatle.about();
}

inline std::ostream& operator <<(std::ostream& os, const ButterFly& bttfly) {
	return os << bttfly.about();
}
