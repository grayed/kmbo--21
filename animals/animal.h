#pragma once

#include <iostream>

class Animal {
private:
	float weight;				// kg

public:
	float getweight() {return weight;}
	void setweight(float newweight) {weight = newweight;}
};

class Mammal : public Animal {
private:
	float pregnancyDuration;	// days
public:
	float getpregnancyDuration() { return pregnancyDuration; }
	void setpregnancyDuration(float newpregnancyDuration) { pregnancyDuration = newpregnancyDuration; }
};

class Cat : public Mammal {
private:
	float vibrissaLength;		// meters
public:
	float getvibrissaLength() { return vibrissaLength; }
	void setvibrissaLength(float newvibrissaLength) { vibrissaLength = newvibrissaLength;  }
};

class Dog : public Mammal {
private:
	float razorLength;		// meters
public:
	float getrazorLength() { return razorLength; }
	void setrazorLength(float newrazorLength) { razorLength = newrazorLength; }
};

class Bird : public Animal {
private:
	float fearthLength;	// meters
public:
	float getfearthLength() { return fearthLength; }
	void setfearthLength(float newfearthLength) { fearthLength = newfearthLength; }
};

class Sparrow : public Bird {
private:
	float razorLength;		// meters
public:
	float getrazorLength() { return razorLength; }
	void setrazorLength(float newrazorLength) { razorLength = newrazorLength; }
};

class Raven : public Bird {
private:
	float height;		// meters
public:
	float getheight() { return height; }
	void setheight(float newheight) { height = newheight; }
};
