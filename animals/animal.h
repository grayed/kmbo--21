#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Animal {
private:
	int weight;
	int age;
	int height;
public:
	Animal(){};
	Animal(int Weight, int Age, int Height){
		Weight = weight;
		Age = age;
		Height = height;
	}
	void setWeight(int Weight) {weight = Weight;}
	void setAge(int Age) {age = Age;}
	void setHeight(int Height) {height = Height;}

	int getWeight() { return weight;}
	int getAge() { return age;}
	int getHeight() {return height;}
	virtual string about() const{
		stringstream str;
		str<<"Weight="<<weight<<"; ";
		str<<"Age="<<age<<"; ";
		str<<"Height="<<height<<"; ";
		return str.str();
	}
};

class Mammal : public Animal {
private:
	string haveWool;
	bool herbivore;
public:
	Mammal(){};
	Mammal (string HaveWool, bool Herbivore){
		HaveWool = haveWool;
		Herbivore = herbivore;
	}
	string getHaveWool() {return haveWool;}
	void setHaveWool(int value) {haveWool = value;}
	bool getHerbivore() {return herbivore;}
	void setHerbivore(bool value) {herbivore = value;}

	virtual string about() const{
		stringstream ss;
		ss<<"haveWool="<<haveWool<<"; ";
		ss<<"herbivore="<<herbivore<<endl;
		return ss.str();
	}
};

class Cat : public Mammal {
private:
	float virbissaLength;
public:
	Cat(){};
	Cat(float VirbissaLength){
		virbissaLength = VirbissaLength;
	}
	float getVirbissaLength() {return virbissaLength;}
	void setVirbissaLength(float value) {virbissaLength = value;}

	virtual string about() {
		stringstream ss;
		ss<<"virbissaLength="<<getVirbissaLength()<<", ";
		return ss.str();
	}
};

class Kapibara : public Mammal{
private:
	bool isFunny;
public:
	Kapibara(){};
	Kapibara(bool IsFunny){
		isFunny = IsFunny;
	}
	bool getIsFunny() {return isFunny;}
	void setIsFunny(bool value) {isFunny = value;}

	virtual string about(){
		stringstream ss;
		ss<<"isFunny= "<<getIsFunny()<<endl;
		return ss.str();
	}
};

class Sphinks : public Cat{
private:
	float woolLength;
	bool blueEyes;
public:
	Sphinks(){};
	Sphinks(float WoolLength, bool BlueEyes){
		woolLength = WoolLength;
		blueEyes = BlueEyes;
	}
	float getWoolLength() {return woolLength;}
	void setWoolLength( float value ) { woolLength = value;}
	bool getBlueEyes() {return blueEyes;}
	void setBlueEyes( bool value) {blueEyes = value;}

	virtual string about() const{
		stringstream ss;
		ss<<"woolLength= "<<woolLength<<"; ";
		ss<<"blueEyes= "<<blueEyes<<endl;
		return ss.str();
	}
};

class Human : public Mammal{
private:
	bool inRussia;
	float age;
public:
	Human(){};
	Human(bool InRussia, float Age){
		inRussia = InRussia;
		age = Age;
	}
	bool getInRussia() {return inRussia;}
	void setInRussia(bool value) {inRussia = value;}
	float getAge() {return age;}
	void setAge(float value) {age = value;}

	virtual string about() const{
		stringstream str;
		str<<"inRussia= "<<inRussia<<"; ";
		str<<"Age= "<<age<<endl;
		return str.str();
	}
};
