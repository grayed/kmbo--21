#pragma once

#include <iostream>
#include <sstream>
#include <string>

class Animal
{
private:
	int age;	// в годах :)
	int weight; // в кг
	int height; // в метрах

public:
	Animal(){};
	Animal(int Age, int Weight, int Height)
	{
		Age = age;
		Weight = weight;
		Height = height;
	}

	void setAge(float Age) { age = Age; }
	void setWeight(float Weight) { weight = Weight; }
	void setHeight(int Height) { height = Height; }

	float getAge() { return age; }
	float getWeight() { return weight; }
	int getHeight() { return height; }
	virtual string about() const
	{
		stringstream str;
		str << "Age = " << age << "; "
			<< "Weight = " << weight << "; "
			<< "Height = " << height << endl;
		return str.str();
	}
};

// млекопитающее
class Mammal : public Animal
{
private:
	string woolColor; // цвет шерсти
	bool predator;	  // хищник да/нет
public:
	Mammal(){};
	Mammal(string WoolColor, bool Predator)
	{
		woolColor = WoolColor;
		predator = Predator;
	}
	string getWoolColor() { return woolColor; }
	void setWoolColor(int value) { woolColor = value; }
	bool getPredator() { return predator; }
	void setPredator(bool value) { predator = value; }

	virtual string about() const
	{
		stringstream ss;
		ss << "woolColor = " << woolColor << ", "
		   << "Predaor = " << predator;
		return ss.str();
	}
};
// человек
class Human : public Mammal
{
private:
	bool isWorking; // устроен ли на работу да/ нет
	int iq;			// Коэффициент интеллекта до 150

public:
	Human(bool IsWorking, int Iq)
	{
		isWorking = IsWorking;
		iq = Iq;
	}

	bool getIsWorking() { return isWorking; };
	void setIsWorking(bool value) { isWorking = value; }
	int getIq() { return iq; };
	void setIq(int value) { iq = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "iq = " << getIq() << ", "
		   << "IsWorking = " << getIsWorking();
		return ss.str();
	}
};
class Deer : public Mammal
{
private:
	int lengthOfHorns; // длина рогов в см

public:
	Deer(){};
	Deer(int LengthOfHorns)
	{
		lengthOfHorns = LengthOfHorns;
	}
	int getLengthOfHorns() { return lengthOfHorns; };
	void setLengthOfHorns(int value) { lengthOfHorns = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "lengthOfHorns = " << getLengthOfHorns();
		return ss.str();
	}
};
class Bird : public Animal
{
private:
	bool canFly; // может летать да/ нет
	bool canSwim; // может плавать да/нет

public:
	Bird(){};
	Bird(bool CanFly, bool CanSwim)
	{
		canFly = CanFly;
		canSwim = CanSwim;
	}
	bool getCanFly() { return canFly; }
	void setCanFly(bool value) { canFly = value; }
	bool getCanSwim() { return canSwim; }
	void setCanSwim(int value) { canSwim = value; }
	virtual string about() const
	{
		stringstream ss;
		ss << "Can fly = " << getCanFly << ", "
		   << "Can swim = " << getCanSwim;
		return ss.str();
	}
};
class Parrot : public Bird
{
private: 
	bool livesInCity; // живет в городе да/нет

public:
	Parrot(){}
	Parrot(bool LivesInCity)
	{
		livesInCity = LivesInCity;
	}
	int getLivesInCity() { return livesInCity; };
	void setLivesInCity(int value) { livesInCity = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "Can fly = " << getCanFly() << ", "
		   << "Lives in city = " << getLivesInCity();
		return ss.str();
	}
};
class Eagle : public Bird
{
private:
	int speed; // в км/ч
public:
	Eagle() {};
	Eagle(int Speed)
	{
		speed = Speed;
	}
	int getSpeed() { return speed; };
	void setSpeed(int value) { speed = value; }
	virtual string about()
	{
		stringstream ss;
		ss << "can fly = " << getCanFly() << ", "
		   << "speed = " << getSpeed();
		return ss.str();
	}
};
