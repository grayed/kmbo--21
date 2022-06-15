using namespace std ;

#include "animal.h"

string Animal::about() const {
	stringstream ss;
	ss << "Animal_color = " << " " << Animal_color;
	return ss.str();
};

string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << " " <<  " gender = " << " " << gender;
	return ss.str();
};

string Predator::about() const {
	stringstream ss;
	ss << Animal::about() << " " << " omnivorous = " << " " << omnivorous;
	return ss.str();
};

string Whales::about() const {
	stringstream ss;
	ss << Mammal::about() << " " << " opportunity_to_get_out_of_the_water = " << " " << opportunity_to_get_out_of_the_water;
	return ss.str();
};

string Dog::about() const {
	stringstream ss;
	ss << Mammal::about() << " " << " Tail_length = " << " " << Tail_length;
	return ss.str();
};

string Husky::about() const {
	stringstream ss;
	ss << Dog::about() << " " << " Average_length_of_wool = " << " " << Average_length_of_wool;
	return ss.str();
};

string Pug::about() const {
	stringstream ss;
	ss << Dog::about() << " " << " Leg_length = " << " " << Leg_length;
	return ss.str();
};









int main(){
	Pug pes_Solnyshk0;
	Husky   sobaka_Marta;
	Dog     Sam;
	Whales   Dolphin;
	Predator  Bears;

	pes_Solnyshk0.gender = true;
	pes_Solnyshk0.Animal_color = "yellow";
	pes_Solnyshk0.Leg_length = 10;
	pes_Solnyshk0.Tail_length = 5;

	sobaka_Marta.Average_length_of_wool = 5;
	sobaka_Marta.gender = false;
	sobaka_Marta.Animal_color = "white";
	sobaka_Marta.Tail_length = 20;

	Sam.gender = true;
	Sam.Tail_length = 15;
	Sam.Animal_color = "black";

	Dolphin.opportunity_to_get_out_of_the_water = false;
	Dolphin.Animal_color = "blue";
	Dolphin.gender = true;

	Bears.Animal_color = "brown";
	Bears.gender = true;
	Bears.omnivorous = true;

	cout << "-------------------------------------------------------------" << endl;
	cout << "pes_Solnyshk0: " << pes_Solnyshk0.about() << endl;
	cout << "sobaka_Marta: " << sobaka_Marta.about() << endl;
	cout << "Sam: " << Sam.about() << endl;
	cout << "Dolphin: " << Dolphin.about() << endl;
	cout << "Bears: " << Bears.about() << endl;
	cout << "-------------------------------------------------------------";
	
	
}