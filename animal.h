#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Animal
{
private:
	int age;
	int weight;
	int height;
public:
	void animal(int age, int weight, int height) {
		age = age;
		height = height;
		weight = weight;
	}
	void set_age(int age) { age = age; }
	void set_height(float height) { height = height; }
	void set_weight(float weight) { weight = weight; }

	int get_age() { return age; }
	float get_height() { return height; }
	float get_weight() { return weight; }
	virtual string about() const
	{
		stringstream ss;
		ss << "age = " << get_age << ";"
			<< "height = " << get_height << " ;"
			<< "weight = " << get_weight << endl;

	}

};

class Mammal :public Animal
{
private:
	string hair_color;
	bool meat_eater;
public:
	void mammal(string hair_color, bool meat_eater) {
		hair_color = hair_color;
		meat_eater = meat_eater;
	}
	void set_hair_color() { hair_color = hair_color; }
	void set_meat_eater() { meat_eater = meat_eater; }
	string get_hair_color() { return hair_color; }
	bool get_meat_eater() { return meat_eater; }
	virtual string about() const
	{
		stringstream ss;
		ss << "hair color is - " << get_hair_color << ";"
			<< "he/she is meat eater? - " << get_meat_eater << endl;
	}
};

class Human :public Mammal
{
private:
	bool have_work;
	string lifestyle;
public:
	void human(bool have_work, string lifestyle) {
		have_work = have_work;
		lifestyle = lifestyle;
	}
	void set_work() { have_work = have_work; }
	void set_life_style() { lifestyle = lifestyle; }
	bool get_work() { return have_work; }
	string get_life_style() { lifestyle = lifestyle; }
	virtual string about() const
	{
		stringstream ss;
		ss << " have work ? - " << get_work << ", "
			<< "lifestyle = " << get_life_style;
		return ss.str();
	}
};
