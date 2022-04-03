#pragma once

#include <iostream>
#include "animal.h"

class Mammal : public Animal {
public:
	float pregnancyDuration;	// days
};

class Cat : public Mammal {
public:
	float vibrissaLength;		// meters
    Cat(float vibrissaLength) {this->vibrissaLength = vibrissaLength;}
};

enum Breed { Sharpey, Terier, Chauchau };

class Dog : public Mammal {
	public:
		Breed breed;
        Dog(Breed breed) {this->breed = breed;}

        std::string breedAsString() const {
            std::string breed = "";
            switch (this->breed) {
                case Sharpey: breed = "sharpey"; break;
                case Terier: breed = "terier"; break;
                case Chauchau: breed = "chau chau"; break;
            }

            return breed;
        }
};

std::ostream& operator << (std::ostream& os, const Cat& c) {
    os << "cat's vibrissa length: " << c.vibrissaLength << std::endl;
    os << "cat's pregnancy duration: " << c.pregnancyDuration << std::endl;
    os << "cat's weight: " << c.weight << std::endl;
    return os;
}

std::ostream& operator << (std::ostream& os, const Dog& d) {
    
    os << "dog's breed: " << d.breedAsString() << std::endl;
    os << "dog's pregnancy duration: " << d.pregnancyDuration << std::endl;
    os << "dog's weight: " << d.weight << std::endl;
    return os;
}