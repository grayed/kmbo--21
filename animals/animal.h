#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Animal {
private:
	int weight;
	int age;
	int height;	
public:
	Animal(){};
	Animal(int weight, int age, int height){
		this->weight = weight;
		this->age = age;
		this->height = height;
	};
	int getWeight() { return weight;}
	int getAge() { return age;}
	int getHeight() {return height;}
	void setWeight(int _weight) {weight = _weight;}
	void setAge(int _age) {age = _age;}
	void setHeight(int _height) {height = _height;}
	virtual string about() const{
		stringstream str;
		str<<"Weight="<<weight<<"; ";
		str<<"Age="<<age<<"; ";
		str<<"Height="<<height<<"; ";
		return str.str();
	}

};

class Mammal : public Animal {
	float pregnancyDuration;
	bool isCarnivore;
public:
	Mammal(){};
	Mammal (float pregnancyDuration, bool isCarnivore){
		this->pregnancyDuration = pregnancyDuration;
		this->isCarnivore = isCarnivore;
	}
	float getPregnancyDuration() {return pregnancyDuration;}
	void setPregnancyDuration(float value) {pregnancyDuration = value;}
	bool getIsCarnivore() {return isCarnivore;}
	void setisCarnivore(bool value) {isCarnivore = value;}

	virtual string about() const{
		stringstream ss;
		ss<<"pregnancyDuration="<<pregnancyDuration<<"; ";
		ss<<"isCarnivore="<<isCarnivore<<endl;
		return ss.str();
	}

};
class Bird : public Animal {
	float wingspan;
public:
	Bird(){};
	Bird (float wingspan){
		this->wingspan = wingspan;
	}
	float getWingspan() {return wingspan;}
	void setWingspan(float value) {wingspan = value;}

	virtual string about() const{
		stringstream ss;
		ss<<"wingspan="<<wingspan<<"; ";
		return ss.str();
	}

};


class Cat : public Mammal {
 float virbissaLength;	
public:
	Cat(){};
	Cat(float virbissaLength){
		this ->virbissaLength = virbissaLength;
	}
	float getVirbissaLength() {return virbissaLength;}
	void setVirbissaLength(float value) {virbissaLength = value;}

	virtual string about() {
		stringstream ss;
		ss<<"virbissaLength="<<getVirbissaLength()<<", ";
		return ss.str();
	}
};
class Bear : public Mammal {
 bool isHibernates;
public:
	Bear(){};
	Bear(bool _isHibernates){
		isHibernates = _isHibernates;
	}
	bool getIsHibernates() {return isHibernates;}
	void setIsHibernates(bool value) {isHibernates = value;}

	virtual string about() {
		stringstream ss;
		ss<<"isHibernates="<<getIsHibernates()<<", ";
		return ss.str();
	}
};

class BrownBear : public Bear {
 float amountOfHoneyEaten;
public:
	BrownBear(){};
	BrownBear(float amountOfHoneyEaten){
		this ->amountOfHoneyEaten = amountOfHoneyEaten;
	}
	bool getAmountOfHoneyEaten() {return amountOfHoneyEaten;}
	void setAmountOfHoneyEaten(bool value) {amountOfHoneyEaten = value;}

	virtual string about() {
		stringstream ss;
		ss<<"amountOfHoneyEaten="<<getAmountOfHoneyEaten()<<", ";
		return ss.str();
	}
};

class PolarBear : public Bear {
bool driftingOnIceberg;
public:
	PolarBear(){};
	PolarBear(bool DriftingOnIceberg){
		this ->driftingOnIceberg = DriftingOnIceberg;
	}
	bool getDriftingOnIceberg() {return driftingOnIceberg;}
	void setDriftingOnIceberg(bool value) {driftingOnIceberg = value;}

	virtual string about() {
		stringstream ss;
		ss<<"DriftingOnIceberg="<<getDriftingOnIceberg()<<", ";
		return ss.str();
	}
};
class Lion : public Cat {
bool kingOfAnimals;
public:
	Lion(){};
	Lion(bool kingOfAnimals){
		this ->kingOfAnimals = kingOfAnimals;
	}
	bool getKingOfAnimals() {return kingOfAnimals;}
	void setKingOfAnimals(bool value) {kingOfAnimals = value;}

	virtual string about() {
		stringstream ss;
		ss<<"kingOfAnimals="<<getKingOfAnimals()<<", ";
		return ss.str();
	}
};


class Lynx : public Cat {
float tasselsLength;
public:
	Lynx(){};
	Lynx(bool tasselsLength){
		this ->tasselsLength = tasselsLength;
	}
	bool getTasselsLength() {return tasselsLength;}
	void setTasselsLength(bool value) {tasselsLength = value;}

	virtual string about() {
		stringstream ss;
		ss<<"tasselsLength="<<getTasselsLength()<<", ";
		return ss.str();
	}
};



