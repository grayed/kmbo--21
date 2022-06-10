#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;




//Типо заголовочный файл 



class Animal {
	string herbivore_or_carnivorous; // плотоядное-true травоядное-false
protected:
	Animal() { herbivore_or_carnivorous = "hserbivore"; }

public:
	virtual string about() const;
};



class Mammal : public Animal { // млекопитающие
public:
	void setWool_cover(bool value) { wool_cover = value; }
	bool getWool_cover() { return wool_cover; }
	bool milk_glands;

	virtual string about() const;
private:
	bool wool_cover;

protected:
	Mammal() { milk_glands = true; }

};

class Tiger : public Mammal {
public:
	string color_tiger; // цвет
	int fine_for_murder; // штраф за убийство
	void setDay_of_tgers(string value) { day_of_tigers = value; }
	string getDay_of_tgers() { return day_of_tigers; }

	virtual string about() const;


private:
	string day_of_tigers;

};

class Cat : public Mammal {
public:
	string favorite_food_Cat;
	void setVibrissaLength(float value) { vibrissaLength = value; }
	float getVibrissaLength() { return vibrissaLength; }
	int sok;
	virtual string about() const;
private:
	float vibrissaLength;

protected:
	//Cat() { favorite_food_Cat = "wiski"; }
};

class Arachnids : public Animal { // павуки
public:
	float mean_age;// years
	int count_limbs; // число конечностей 

	void setType_of_birth(string value) { type_of_birth = value; }
	string getType_of_birth() { return type_of_birth; }

	virtual string about() const;
private:
	string type_of_birth;// тип рождения 

protected:
	Arachnids() { count_limbs = 8; }

};

class Black_Vdova : public Arachnids {
public:
	string geolacation;
	int favorite_temperatur;
	void setThe_presence_of_poison(bool value) { the_presence_of_poison = value; }

	bool getThe_presence_of_poison() { return the_presence_of_poison; }

	virtual string about() const;

private:
	bool the_presence_of_poison; // наличие яда

};

class tarantula : public Arachnids {
public:
	float max_weight;
	float speed;
	void setThe_presence_of_wool(bool value) { the_presence_of_wool = value; }
	bool setThe_presence_of_wool() { return the_presence_of_wool; }

	virtual string about() const;

private:
	bool the_presence_of_wool; // наличие шерстянного покрова

protected:


};