#pragma once

#include <iostream>
#include "animal.h"

class Mammal : public Animal {
    private:
	    float pregnancyDuration;	// days
    public:
        const float getPregnancyDuration() const { return pregnancyDuration; }
        void setPregnancyDuration(const float d) { pregnancyDuration = d; }
    protected:
        Mammal(const float pd, const float weight) : Animal(weight) {
            pregnancyDuration = pd;
        }
};

class Cat : public Mammal {
    private:
	    float vibrissaLength;		// meters
    public:
        Cat(const float vl, const float pd, const float weight) : Mammal(pd, weight) { 
            vibrissaLength = vl; 
        }
        const float getVibrissaLength() const { return vibrissaLength; }
        void setVibrissaLength(const float v) { vibrissaLength = v; }
};

enum Breed { Sharpey, Terier, Chauchau };

class Dog : public Mammal {
    private:
        Breed breed;
	public:
        Dog(const Breed b, const float pd, const float weight) : Mammal(pd, weight) { 
            breed = b; 
        }
        const Breed getBreed() const { return breed; }
        void setBreed(const Breed b) { breed = b; }

        const std::string getBreedAsString() const {
            std::string strBreed = "";
            switch (breed) {
                case Sharpey: strBreed = "sharpey"; break;
                case Terier: strBreed = "terier"; break;
                case Chauchau: strBreed = "chau chau"; break;
            }

            return strBreed;
        }
};

std::ostream& operator << (std::ostream& os, const Cat& c) {
    os << "cat's vibrissa length: " << c.getVibrissaLength() << std::endl;
    os << "cat's pregnancy duration: " << c.getPregnancyDuration() << std::endl;
    os << "cat's weight: " << c.getWeight() << std::endl;
    return os;
}

std::ostream& operator << (std::ostream& os, const Dog& d) {
    
    os << "dog's breed: " << d.getBreedAsString() << std::endl;
    os << "dog's pregnancy duration: " << d.getPregnancyDuration() << std::endl;
    os << "dog's weight: " << d.getWeight() << std::endl;
    return os;
}