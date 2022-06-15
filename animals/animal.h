#pragma once
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
	float weight;	// kg
	float height; // meters
protected:
	Animal() {};
	Animal(float weight_, float height_) { weight = weight_; height = height_; }
public:
	float getWeight() const { return weight; }
	void setWeight(float newWeight) { weight = newWeight; }
	float getHeight() const { return height; }
	void setHeight(float newHeight) { height = newHeight; }

	virtual string about() const { return (stringstream() << "Weight = " << weight << '\n' << "Height = " << height).str(); }
};

class Mammal : public Animal {
private:
	float pregnancyDuration;	// days
	float age;                  //years
protected:
	Mammal() {};
	Mammal(float weight_, float height_, float pregnancyDuration_, float age_) :Animal(weight_, height_) { pregnancyDuration = pregnancyDuration_; age = age_; };
public:
	float getPregnancyDuration() const { return pregnancyDuration; }
	void setPregnancyDuration(float newPregnancyDuration) { pregnancyDuration = newPregnancyDuration; }
	float getAge() const { return age; }
	void setAge(float newAge) { age = newAge; }

	virtual string about() const { return (stringstream() << Animal::about() << '\n' << "Duration of pregnancy = " << pregnancyDuration << '\n' << "Age = " << age).str(); }
};

class Dog : public Mammal {
private:
	string woolcolor; //color
public:
	Dog() {};
	Dog(float weight_, float height_, float pregnancyDuration_, float age_, string woolcolor_) :Mammal(weight_, height_, pregnancyDuration_, age_) {
		woolcolor = woolcolor_;
	}

	string getWoolcolor() const { return woolcolor; }
	void setWoolcolor(string newWoolcolor) { woolcolor = newWoolcolor; }

	virtual string about() const { return (stringstream() << Mammal::about() << '\n' << "Woolcolor = " << woolcolor).str(); }
};

class Human : public Mammal {
private:
	int iq;      //scores
public:
	Human() {};
	Human(float weight_, float height_, float pregnancyDuration_, float age_, int iq_) :Mammal(weight_, height_, pregnancyDuration_, age_) {
		iq = iq_;
	}
	int getIQ() const { return iq; }
	void setIQ(int newIQ) { iq = newIQ; }

	virtual string about() const { return (stringstream() << Mammal::about() << '\n' << "IQ = " << iq).str(); }
};

class Bird : public Animal {
private:
	bool fly;	      // true/false 
	float wingspan;   //centimeters
protected:
	Bird() {};
	Bird(float weight_, float height_, bool fly_, float wingspan_) :Animal(weight_, height_) { fly = fly_; wingspan = wingspan_; };
public:
	bool getFly() const { return fly; }
	void setFly(bool newFly) { fly = newFly; }
	float getWingspan() const { return wingspan; }
	void setWingspan(float newWingspan) { wingspan = newWingspan; }

	virtual string about() const { return (stringstream() << Animal::about() << '\n' << "Fly = " << fly << '\n' << "Wingspan = " << wingspan).str(); }
};

class Penguin : public Bird {
private:
	string sex;       //male/female
public:
	Penguin() {};
	Penguin(float weight_, float height_, bool fly_, float wingspan_, string sex_) :Bird(weight_, height_, fly_, wingspan_) {
		sex = sex_;
	}
	string getSex() const { return sex; }
	void setSex(string newSex) { sex = newSex; }

	virtual string about() const { return (stringstream() << Bird::about() << '\n' << "Sex = " << sex).str(); }
};

class Parrot : public Bird {
private:
	bool speak;    //true/false
public:
	Parrot() {};
	Parrot(float weight_, float height_, bool fly_, float wingspan_, bool speak_) :Bird(weight_, height_, fly_, wingspan_) {
		speak = speak_;
	}
	bool getSpeak() const { return speak; }
	void setSpeak(bool newSpeak) { speak = newSpeak; }

	virtual string about() const { return (stringstream() << Bird::about() << '\n' << "Speak " << speak).str(); }
};