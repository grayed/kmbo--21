#include <iostream>
#include "animal.h"
#include <sstream>
using namespace std;


string Animal::about() const {
	stringstream ss;
	ss << "herbivore_or_carnivorous? : " << herbivore_or_carnivorous << endl;
	return ss.str();
}


string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << "\t" << "milk_glands: " << milk_glands << endl;
	return ss.str();
}


string Tiger::about() const {
	stringstream ss;
	ss << Animal::about() << "\t" << Mammal::about() << "color_tiger: " << color_tiger << endl;
	return ss.str();
}



string Cat::about() const {
	stringstream ss;
	ss << Animal::about() << Mammal::about() << "\t" << "favorite_food_Cat: " << favorite_food_Cat << endl;
	return ss.str();
}


string Arachnids::about() const {
	stringstream ss;
	ss << Animal::about() << "\t" << " type_of_birth: " << type_of_birth << endl;
	return ss.str();
}

string Black_Vdova::about() const {
	stringstream ss;
	ss << Arachnids::about() << "\t" << " geolacation: " << geolacation << endl;
	return ss.str();
}

string tarantula::about() const {
	stringstream ss;
	ss << Arachnids::about() << " max_weight: " << max_weight << endl;
	return ss.str();
}



inline ostream& operator <<(ostream& os, const Animal& animal) {
	return os << animal.about();
}


int main() {
	Black_Vdova tt;
	tt.count_limbs = 65;
	tt.geolacation = "49494946.78668887";
	tt.setType_of_birth("egg");
	cout << "Black_Vdova" << endl;
	cout << tt.about();

	Tiger sherhan;
	sherhan.color_tiger = "orange-white";
	sherhan.fine_for_murder = 100000;
	cout << "Tiger" << endl;
	cout << sherhan.about();


	tarantula vik;
	vik.speed = 1010;
	vik.max_weight = 4;
	vik.setType_of_birth("egg");
	cout << "tarantula" << endl;
	cout << vik.about() << endl;

	Cat Arsik;
	Arsik.setVibrissaLength(5);
	Arsik.favorite_food_Cat = "wiski";
	cout << "Cat" << endl;
	cout << Arsik.about();




}
