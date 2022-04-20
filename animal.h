#pragma once

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal
{
private:
	int age;	// в годах
	int height; // в метрах

public:
	Animal(){};
	Animal(int Age, int Height)
	{
		Age = age;
		Height = height;
	}

	void setAge(int Age) { age = Age; }

	void setHeight(int Height) { height = Height; }

	float getAge() { return age; }

	int getHeight() { return height; }
	virtual string about() 
	{
		stringstream str;
		str << "Age = " << age << "; "
			<< "Height = " << height << endl;
		return str.str();
	}
};

// млекопитающее
class Mammal : public Animal
{
private:
	bool predator; // хищник да/нет
public:
	Mammal(){};
	Mammal(bool Predator)
	{

		predator = Predator;
	}

	bool getPredator() { return predator; }
	void setPredator(bool value) { predator = value; }

	virtual string about() const
	{
		stringstream ss;
		ss << "Predaor = " << predator;
		return ss.str();
	}
};
// человек
class Human : public Mammal
{
private:
	string sex; // пол

public:
	Human(string Sex)
	{
		sex = Sex;
	}

	void setSex(string Sex) { sex = Sex; }
	string getSex() { return sex; }
	virtual string about()
	{
		stringstream ss;
		ss << "sex = " << getSex();
		return ss.str();
	}
};

class Cat : public Mammal
{
private:
	string woolColor; // цвет шерсти

public:
	Cat(){};
	Cat(string WoolColor)
	{
		woolColor = WoolColor;
	}
	string getWoolColor() { return woolColor; }
	void setWoolColor(string value) { woolColor = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "WoolColor = " << getWoolColor();
		return ss.str();
	}
};

class Fish : public Animal
{
private:
	int weight; // в кг

public:
	Fish(){};
	Fish(int Weight)
	{
		weight = Weight;
	}
	int getWeight() { return weight; }
	void setWeight(int value) { weight = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "weight = " << getWeight();
		return ss.str();
	}
};

class Shark : public Fish
{
private:
	int speed; // в км/ч

public:
	Shark() {}
	Shark(int Speed)
	{
		speed = Speed;
	}
	int getSpeed() { return speed; };
	void setSpeed(int value) { speed = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "Speed = " << getSpeed();
		return ss.str();
	}
};
class GoldFish : public Fish
{
private:
	bool livesInAquarium; // да/ нет
public:
	GoldFish(){};
	GoldFish(bool LivesInAquarium)
	{
		livesInAquarium = LivesInAquarium;
	}
	bool getLivesInAquarium() { return livesInAquarium; };
	void setLivesInAquarium(bool value) { livesInAquarium = value; };
	virtual string about()
	{
		stringstream ss;
		ss << "lives in aquarium = " << getLivesInAquarium() << "; "
			<< "Weight = " << getWeight() << endl;
		return ss.str();
	}
};
