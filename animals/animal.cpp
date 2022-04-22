#include "animal.h"

using namespace std;

Animal::Animal(float weight_) {
	weight = weight_;
}

string Animal::about() const{
	stringstream ss;
	ss << "weight = " << weight;
	return ss.str();
}

ostream& operator <<(ostream& os, const Animal& animal) {
	return os << animal.about();
}

Mammal::Mammal(float weight_, float pregnancyDuration_) : Animal(weight_) {
	pregnancyDuration = pregnancyDuration_;
}

string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << " pregnancyDuration = " << pregnancyDuration;
	return ss.str();
}

Insect::Insect(float weight_, float antennasLength_) : Animal(weight_) {
	antennasLength = antennasLength_;
}

string Insect::about() const {
	stringstream ss;
	ss << Animal::about() << " antennasLength = " << antennasLength;
	return ss.str();
}

Cat::Cat(float weight_, float pregnancyDuration_, float vibrissaLength_) : Mammal(weight_, pregnancyDuration_) {
	vibrissaLength = vibrissaLength_;
}

string Cat::about() const {
	stringstream ss;
	ss << Mammal::about() << " vibrissaLength = " << vibrissaLength;
	return ss.str();
}

Dog::Dog(float weight_, float pregnancyDuration_, float tailLength_) : Mammal(weight_, pregnancyDuration_) {
	tailLength = tailLength_;
}

string Dog::about() const {
	stringstream ss;
	ss << Mammal::about() << " tailLength = " << tailLength;
	return ss.str();
}

Bug::Bug(float weight_, float antennasLength_, float wingLength_) : Insect(weight_, antennasLength_) {
	wingLength = wingLength_;
}

string Bug::about() const {
	stringstream ss;
	ss << Insect::about() << " wingLength = " << wingLength;
	return ss.str();
}

Dragonfly::Dragonfly(float weight_, float antennasLength_, float airspeed_) : Insect(weight_, antennasLength_) {
	airspeed = airspeed_;
}

string Dragonfly::about() const {
	stringstream ss;
	ss << Insect::about() << " airspeed = " << airspeed;
	return ss.str();
}

int main() {
	Cat cat = Cat(3.9, 60, 0.007);
	Dog dog = Dog(40, 68, 0.018);
	Bug bug = Bug(0.154, 0.003, 0.022);
	Dragonfly dragonfly = Dragonfly(0.011, 0.0008, 27);

	cout << cat << endl << dog << endl << bug << endl << dragonfly << endl;
}