#pragma once

#include "animal.h"

class Bird : public Animal {
    private:
	    float wingLength;       // meters
    public:
        const float getWingLength() const { return wingLength; }
		void setWingLength(const float v) { wingLength = v; } 
    protected:
        Bird(const float wl, const float weight) : Animal(weight) { wingLength = wl;}
};

class Eagle : public Bird {
    private:
        float visionStrength;   // between 0 and 1 
    public:
        Eagle(const float vs, const float wl, const float weight) : Bird(wl, weight) { 
            visionStrength = vs;
        }
        const float getVisionStrength() const { return visionStrength; }
		void setVisionStrength(const float v) { visionStrength = v; } 
};

class Parrot : public Bird {
    private:
        int plumageColor;       // int in 16 base (5570463 -> #54ff9f)
    public:
        Parrot(const int pc, const float wl, const float weight) : Bird(wl, weight) { 
            plumageColor = pc;
        }
        const int getPlumageColor() const { return plumageColor; }
		void setPlumageColor(const int v) { plumageColor = v; } 

};

std::ostream& operator << (std::ostream& os, const Parrot& p) {
    os << "parrot's color: " << p.getPlumageColor() << std::endl;
    os << "parrot's wing length: " << p.getWingLength() << std::endl;
    os << "parrot's weight: " << p.getWeight() << std::endl;
    return os;
}

std::ostream& operator << (std::ostream& os, const Eagle& e) {
    os << "eagle's vision strength: " << e.getVisionStrength() << std::endl;
    os << "eagle's wing length: " << e.getWingLength() << std::endl;
    os << "eagle's weight: " << e.getWeight() << std::endl;
    return os;
}