#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Animal
{
protected:
	int Paws;

	Animal(int paws) { Paws = paws; }

public:
	virtual string about() const
	{
		return "";
	}

	int setPaws(int paws_) { Paws = paws_; }
	void getPaws() { cout << Paws; }

};


class Mammal : public Animal
{
protected:
	Mammal(int paws, string squad) : Animal(paws) { Squad = squad; }

	string Squad;

	virtual string about() const
	{
		stringstream ss;
		ss << "Paws: " << Paws << ", " << "Squad: " << Squad << endl;
		return ss.str();
	}

public:
	string setSquad(string squad_) { Squad = squad_; }
	void getSquad() { cout << Squad; }

};


class Cat : public Mammal
{
protected:
	float Vibrissae_length;
	int Lives_number;

public:
	Cat(int paws, string squad, float vibrissae_length, int lives_number) : Mammal(paws, squad) { Vibrissae_length = vibrissae_length; Lives_number = lives_number; }

	float setVibrissae_length(float vibrissae_length_) { Vibrissae_length = vibrissae_length_; }
	void getVibrissae_length() { cout << Vibrissae_length; }

	int setLives_number(int lives_number_) { Lives_number = lives_number_; }
	void getLives_number() { cout << Lives_number; }

	virtual string about() const
	{
		stringstream ss;
		ss << "Paws: " << Paws << ", Squad: " << Squad << ", Vibrissae length: " << Vibrissae_length << ", Lives number: " << Lives_number << endl;
		return ss.str();
	}
};


class Cow : public Mammal
{
protected:
	int Spots_number;
	int Milk_volume;


public:
	Cow(int paws, string squad, int spots_number, int milk_volume) : Mammal(paws, squad) { Spots_number = spots_number; Milk_volume = milk_volume; }
	Cow(int paws, string squad, int spots_number) : Mammal(paws, squad) { Spots_number = spots_number; Milk_volume = 0; }

	int setSpots_number(int spots_number_) { Spots_number = spots_number_; }
	void getSpots_number() { cout << Spots_number; }

	int setMilk_volume(int milk_volume_) { Milk_volume = milk_volume_; }
	void getMilk_volume() { cout << Milk_volume; }

	virtual string about() const
	{
		stringstream ss;
		ss << "Paws: " << Paws << ", Squad: " << Squad << ", Spots number: " << Spots_number << ", Milk volume: " << Milk_volume << endl;
		return ss.str();
	}
};


class Reptile : public Animal
{
protected:
	bool Shell;

	Reptile(int paws, bool shell) : Animal(paws) { Shell = shell; }

	virtual string about() const
	{
		stringstream ss;
		ss << "Paws: " << Paws << ", " << "Shell: " << Shell << endl;
		return ss.str();
	}

public:
	bool setShell(bool shell_) { Shell = shell_; }
	void getShell() { cout << Shell; }

};


class Snake : public Reptile
{
protected:
	float Lenth;

public:
	Snake(int paws, bool shell, float lenth) : Reptile(paws, shell) { Lenth = lenth; }

	float setLenth(float lenth_) { Lenth = lenth_; }
	void getLenth() { cout << Lenth; }

	virtual string about() const
	{
		stringstream ss;
		ss << "Paws: " << Paws << ", Shell: " << Shell << ", Lenth: " << Lenth << endl;
		return ss.str();
	}
};


class Turtle : public Reptile
{
private:
	string Area;

public:
	Turtle(int paws, bool shell, string area) : Reptile(paws, shell) { Area = area; }

	string setArea(string area_) { Area = area_; }
	void getArea() { cout << Area; }

	virtual string about() const
	{
		stringstream ss;
		ss << "Paws: " << Paws << ", Shell: " << Shell << ", Area: " << Area << endl;
		return ss.str();
	}

};

inline ostream& operator<< (ostream& os, const Animal& animal)
{
	return os << animal.about();
}
