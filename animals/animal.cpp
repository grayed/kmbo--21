#include "animal.h"
#include <iostream>

using namespace std;

double Animal::get_weight() { return weight; }
void Animal::set_weight(double _weight) {
	if (_weight > 0) {
		weight = _weight;
	}
}

int Animal::get_age() { return age; }
void Animal::set_age(int _age) {
	if (_age >= 0) {
		age = _age;
	}
}

string Animal::about() const {
	stringstream ss;	
	ss << "weight = " << weight << ", age = " << age;

	return ss.str();
}

Animal::Animal(double _weight, int _age) {
	set_weight(_weight);
	set_age(_age);
}

ostream& operator << (ostream& os, const Animal& animal) { return os << animal.about(); }

double Mammal::get_pregnance_dyration() { return pregnance_dyration; }
void Mammal::set_pregnance_dyration(double _pregnance_dyration) {
	if (pregnance_dyration > 0) {
		pregnance_dyration = _pregnance_dyration;
	}
}

string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << ", pregnance_dyration = " << pregnance_dyration;

	return ss.str();
}

Mammal::Mammal(double _weight, int _age, double _pregnance_dyration) : Animal(_weight, _age) {
	set_pregnance_dyration(_pregnance_dyration);
}

double Cat::get_vibrissa_length() { return vibrissa_length; }
void Cat::set_vibrissa_length(double _vvibrissa_length) {
	if (vibrissa_length > 0) {
		vibrissa_length = vibrissa_length;
	}
}

string Cat::about() const {
	stringstream ss;
	ss << Mammal::about() << ", vibrissa length = " << vibrissa_length;

	return ss.str();
}

Cat::Cat(double _weight, int _age, double _vibrissa_length) : Mammal(_weight, _age, 2) {
	set_vibrissa_length(_vibrissa_length);
}

bool Dog::get_is_domestic() { return is_domestic; }
void Dog::set_is_domestic(bool _is_domestic) { is_domestic = _is_domestic; }

string Dog::about() const {
	stringstream ss;
	ss << Mammal::about() << ", is_domestic = " << is_domestic;

	return ss.str();
}

Dog::Dog(double _weight, int _age, bool _is_domestic) : Mammal(_weight, _age, 2) {
	set_is_domestic(_is_domestic);
}

double Reptile::get_egg_period() { return egg_period; }
void Reptile::set_egg_period(double _egg_period) {
	if (_egg_period > 0) {
		egg_period = _egg_period;
	}
}

string Reptile::about() const {
	stringstream ss;
	ss << Animal::about() << ", egg period = " << egg_period;

	return ss.str();
}

Reptile::Reptile(double _weight, int _age, double _egg_period) : Animal(_weight, _age) {
	set_egg_period(_egg_period);
}

string Crocodile::get_tooth_shape() { return tooth_shape; }
void Crocodile::set_tooth_shape(string _tooth_shape) { tooth_shape = _tooth_shape; }

string Crocodile::about() const {
	stringstream ss;
	ss << Reptile::about() << ", tooth shape = " << tooth_shape;

	return ss.str();
}

Crocodile::Crocodile(double _weight, int _age, string _tooth_shape) : Reptile(_weight, _age, 3) {
	set_tooth_shape(_tooth_shape);
}

string Snake::get_pattern() { return pattern;}
void Snake::set_pattern(string _pattern) { pattern = _pattern; }

string Snake::about() const {
	stringstream ss;
	ss << Reptile::about() << ", pattern = " << pattern;

	return ss.str();
}

Snake::Snake(double _weight, int _age, string _pattern) : Reptile(_weight, _age, 1) {
	set_pattern(_pattern);
}

int main() {
	Cat cat = Cat(9.3, 4, 0.23);
	cout << cat << endl;

	Dog dog = Dog(12, 2, true);
	cout << dog << endl;

	Crocodile crocodile = Crocodile(100, 20, "triangle");
	cout << crocodile << endl;

	Snake snake = Snake(2.3, 3, "spots");
	cout << snake << endl;
}