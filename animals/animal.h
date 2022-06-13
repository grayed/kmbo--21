#pragma once

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal {
private:
	int age; //years

protected:
	Animal(int a) { age = a; }

public:
	void setAge(int years) { age = years; }
	int getAge() const { return age; }
	virtual string about() const;
};

class Mammal : public Animal {
private:
	float pregnancyDuration;	// days

protected:
	Mammal(int a, int days): Animal(a) { pregnancyDuration = days; }

public:
	void setPregnancyDuration(int days) { pregnancyDuration = days; }
	int getPregnancyDuration() const { return pregnancyDuration; }
	virtual string about() const;
};

class Cat : public Mammal {
private:
	string color;

	
public:
	Cat(int a, int days, string c) : Mammal(a, days) { color = c; }
	void setColor(string col) { color = col; }
	string getColor() const { return color; }
	virtual string about() const;

};

class Capybara : public Mammal {
private:
	float height;				// meters	
public:
	Capybara(int a, int days, float meters) : Mammal(a, days) { height = meters; }
	void setHeight(float meters) { height = meters;}
	float getHeight() { return height; }
	virtual string about() const;

};

class Arachnids : public Animal {
private:
	bool livesInRussia;		
protected:
	Arachnids(int a, bool val) : Animal(a) { livesInRussia = val; }
public:
	void setLives(bool val) { livesInRussia = val; }
	bool getLives() { return livesInRussia; }
	virtual string about() const;

};

class Spider : public Arachnids {
private:
	bool poisonous; 
public:
	Spider(int a, bool live, bool val) : Arachnids(a, live) { poisonous = val; }
	void setPoisonous(bool val) { poisonous = val; }
	bool getPoisonous() { return poisonous; }
	virtual string about() const;

};

class Scorpion : public Arachnids {
private:
	int numOfEyes;
public:
	Scorpion(int a, bool live, int eyes) : Arachnids(a, live) { numOfEyes = eyes; }
	void setNumOfEyes(int num) { numOfEyes = num; }
	virtual string about() const;
};

inline std::ostream& operator <<(std::ostream& os, const Animal& a) {
	return os << a.about();
}

string Animal::about() const {
	stringstream ss;
	ss << "Age: " << age << " years\n";
	return ss.str();
}

string Mammal::about() const {
	stringstream ss;
	ss << "Pregnancy duration: " << pregnancyDuration <<" days \n";
	return ss.str();
}

string Cat::about() const {
	stringstream ss;
	ss << Animal::about() << Mammal::about() << "Color: " << color << endl;
	return ss.str();
}

string Capybara::about() const {
	stringstream ss;
	ss << Animal::about() << Mammal::about() << "Height: " << height << endl;
	return ss.str();
}

string Arachnids::about() const {
	stringstream ss;
	ss << "Does it live in Russia: " << livesInRussia << endl;
	return ss.str();
}


string Spider::about() const {
	stringstream ss;
	ss << Animal::about() << Arachnids::about() << "Poisonous: " << poisonous << endl;
	return ss.str();
}

string Scorpion::about() const {
	stringstream ss;
	ss << Animal::about() << Arachnids::about() << "Number of eyes: " << numOfEyes << endl;
	return ss.str();
}

