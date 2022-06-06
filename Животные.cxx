#include "animal.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	return 0;
} 


class Animal {
private:
	float the_average_value_of_the_duration_of_life;
public:
	void set_the_average_value_of_the_duration_of_life(float new_the_average_value_of_the_duration_of_life) { the_average_value_of_the_duration_of_life = new_the_average_value_of_the_duration_of_life; }
	float get_the_average_value_of_the_duration_of_life() const { return the_average_value_of_the_duration_of_life; }

	bool Gender;
	virtual string about() const;
};

string Animal::about() const {
	stringstream ss;
	ss << "Gender = " << " " << Gender;
	return ss.str();
};

class Mammal : public Animal {
private:
	int number_of_individuals;
public:
	void set_number_of_individuals(int new_number_of_individuals) { number_of_individuals = new_number_of_individuals; }
	int get_number_of_individuals() const { return number_of_individuals; }

	string Coat_color;
	virtual string about() const;
};

string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << " " <<  " Coat_color = " << " " << Coat_color;
	return ss.str();
};



class Quadrupeds : public Mammal {
private:
	float percentage_of_quality_of_life;
public:
	void set_percentage_of_quality_of_life(float new_percentage_of_quality_of_life) { percentage_of_quality_of_life = new_percentage_of_quality_of_life; }
	float get_percentage_of_quality_of_life() const { return percentage_of_quality_of_life; }

	bool limbs;
	virtual string about() const;
};

string Quadrupeds::about() const {
	stringstream ss;
	ss << Animal::about() << " " << " limbs = " << " " << limbs;
	return ss.str();
};


class Birds : public Mammal {
private:
	int the_average_value_of_the_flight_for_one_season;
public:
	void set_the_average_value_of_the_flight_for_one_season(int new_the_average_value_of_the_flight_for_one_season) { the_average_value_of_the_flight_for_one_season = new_the_average_value_of_the_flight_for_one_season; }
	int get_the_average_value_of_the_flight_for_one_season() const { return the_average_value_of_the_flight_for_one_season; }


	bool ability_to_fly;
	virtual string about() const;
};

string Birds::about() const {
	stringstream ss;
	ss << Mammal::about() << " " << " ability_to_fly = " << " " << ability_to_fly;
	return ss.str();
};

class Cat : public Animal {
private:
	int the_number_of_mice_caught_per_unit_of_time;
public:
	void set_the_number_of_mice_caught_per_unit_of_time(int new_the_number_of_mice_caught_per_unit_of_time) { the_number_of_mice_caught_per_unit_of_time = new_the_number_of_mice_caught_per_unit_of_time; }
	int get_the_number_of_mice_caught_per_unit_of_time() const { return the_number_of_mice_caught_per_unit_of_time; }


	float vibrissaLength;
	virtual string about() const;
};

string Cat::about() const {
	stringstream ss;
	ss << Animal::about() << " " << " vibrissaLength = " << " " << vibrissaLength;
	return ss.str();
};

class Manul : public Cat {
private:
	int average_weight;
public:
	void set_average_weight(int new_average_weight) { average_weight = new_average_weight; }
	int get_average_weight() const { return average_weight; }


	float Average_length_of_wool;
	virtual string about() const;
};

string Manul::about() const {
	stringstream ss;
	ss << Cat::about() << " " << " Average_length_of_wool = " << " " << Average_length_of_wool;
	return ss.str();
};

class Mainkun : public Cat {
private:
	string eye_color;
public:
	void set_eye_color(string new_eye_color) { eye_color = new_eye_color; }
	string get_eye_color() const { return eye_color; }

	float Number_of_fleas;
	virtual string about() const;
};

string Mainkun::about() const {
	stringstream ss;
	ss << Cat::about() << " " << " Number_of_fleas = " << " " << Number_of_fleas;
	return ss.str();
};


int main(){
	Mainkun kot_bOris;
	Manul   kot_Vasily;
	Cat     Roudi;
	Birds   ANgry_birds;
	Quadrupeds  dogs;

	kot_bOris.Gender = true;
	kot_bOris.Number_of_fleas = 50000;
	kot_bOris.vibrissaLength = 5;

	kot_Vasily.Average_length_of_wool = 3;
	kot_Vasily.Gender = true;
	kot_Vasily.vibrissaLength = 6;

	Roudi.Gender = true;
	Roudi.vibrissaLength = 4;

	ANgry_birds.ability_to_fly = true;
	ANgry_birds.Coat_color = "red";
	ANgry_birds.Gender = false;

	dogs.Coat_color = "red";
	dogs.Gender = true;
	dogs.limbs = 4;

	cout << "-------------------------------------------------------------" << endl;
	cout << "kot_bOris: " << kot_bOris.about() << endl;
	cout << "kot_Vasily: " << kot_Vasily.about() << endl;
	cout << "Roudi: " << Roudi.about() << endl;
	cout << "ANgry_birds: " << ANgry_birds.about() << endl;
	cout << "dogs: " << dogs.about() << endl;
	cout << "-------------------------------------------------------------";


}
