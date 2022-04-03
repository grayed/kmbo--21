#pragma once

#include "animal.h"

class Bird : public Animal {
	public:
		float wingLength;       // meters
};

class Eagle : public Bird {
    public:
        float visionStrength;   // between 0 and 1 
        Eagle(float visionStrength) { this->visionStrength = visionStrength;}
};

class Parrot : public Bird {
    public:
        int plumageColor;       // int in 16 base (5570463 -> #54ff9f)
        Parrot(int plumageColor) { this->plumageColor = plumageColor;}
};

std::ostream& operator << (std::ostream& os, const Parrot& p) {
    os << "parrot's color: " << p.plumageColor << std::endl;
    os << "parrot's wing length: " << p.wingLength << std::endl;
    os << "parrot's weight: " << p.weight << std::endl;
    return os;
}

std::ostream& operator << (std::ostream& os, const Eagle& e) {
    os << "eagle's vision strength: " << e.visionStrength << std::endl;
    os << "eagle's wing length: " << e.wingLength << std::endl;
    os << "eagle's weight: " << e.weight << std::endl;
    return os;
}