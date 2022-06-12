#include "animal.h"
#include <string>
using namespace std;

string Animal::about() const {
	stringstream ss;
	ss << "Weight = " << weight << '\n' << "Height = " << height;
	return ss.str();
}

string Bird::about() const {
	stringstream ss;
	ss << Animal::about() << '\n' << "Ability to fly = " << fly << '\n' << "Wingspan =" << wingspan;
	return ss.str();
}

string Penguin::about() const {
	stringstream ss;
	ss << Bird::about() << '\n' << "Sex = " << sex;
	return ss.str();
}

string Parrot::about() const {
	stringstream ss;
	ss << Bird::about() << '\n' << "Ability to speak = " << speak;
	return ss.str();
}

string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << '\n' << "Duration of pregnancy = " << pregnancyDuration << '\n' << "Age =" << age;
	return ss.str();
}

string Dog::about() const {
	stringstream ss;
	ss << Mammal::about() << '\n' << "Color of wool = " << woolcolor;
	return ss.str();
}

string Human::about() const {
	stringstream ss;
	ss << Mammal::about() << '\n' << "IQ = " << iq;
	return ss.str();
}

int main() {
	Penguin Skipper;
	Skipper.weight = 3;
	Skipper.height = 0.4;
	Skipper.fly = false;
	Skipper.wingspan = 40;
	Skipper.sex = "Male";
	cout << "Skipper : " << Skipper.about() << endl << endl;

	Parrot Kesha;
	Kesha.weight = 0.04;
	Kesha.height = 0.18;
	Kesha.fly = true;
	Kesha.wingspan = 30;
	Kesha.speak = true;
	cout << "Kesha : " << Kesha.about() << endl << endl;

	Dog Masyanya;
	Masyanya.weight = 30;
	Masyanya.height = 0.57;
	Masyanya.pregnancyDuration = 63;
	Masyanya.age = 10;
	Masyanya.woolcolor = "White";
	cout << "Masyanya : " << Masyanya.about() << endl << endl;

	Human Vasilisa;
	Vasilisa.weight = 50;
	Vasilisa.height = 1.70;
	Vasilisa.pregnancyDuration = 280;
	Vasilisa.age = 30;
	Vasilisa.iq = 126;
	cout << "Vasilisa : " << Vasilisa.about() << endl;
}