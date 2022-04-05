#pragma once

#include <sstream>
#include<string>
#include <iostream>

using namespace std;

class Animal {
private:
	float weight;				// kg
protected:
	Animal(){}
	Animal(float newweight) {
		weight = newweight;
	}
public:
	float getweight() {return weight;}
	void setweight(float newweight) {weight = newweight;}
	string about() const {
		stringstream ss;
		ss << "Weight = " << weight << " kg";
		return ss.str();
	}
};

class Mammal : public Animal {
private:
	float pregnancyDuration;	// days
protected:
	Mammal() {}
	Mammal(float newweight, float newpregnancyDuration) {
		pregnancyDuration = newpregnancyDuration;
		setweight(newweight);
	}
public:
	float getpregnancyDuration() { return pregnancyDuration; }
	void setpregnancyDuration(float newpregnancyDuration) { pregnancyDuration = newpregnancyDuration; }
	string about() const {
		stringstream ss;
		ss << Animal::about() << " Pregnancy Duration = " << pregnancyDuration << " days";
		return ss.str();
	}
};

class Cat : public Mammal {
private:
	float vibrissaLength;		// meters
public:
	float getvibrissaLength() { return vibrissaLength; }
	void setvibrissaLength(float newvibrissaLength) { vibrissaLength = newvibrissaLength;  }
	string about() const {
		stringstream ss;
		ss << Mammal::about() << " Vibrissa Length = " << vibrissaLength;
		return ss.str();
	}
	Cat() {}
	Cat(float newweight, float newpregnancyDuration, float newvibrissaLength) {
		vibrissaLength = newvibrissaLength;
		setpregnancyDuration(newpregnancyDuration);
		setweight(newweight);
	}
};
inline ostream& operator<<(ostream& os, const Cat& cat) {
	return os << cat.about();
}


class Dog : public Mammal {
private:
	float razorLength;		// meters
public:
	float getrazorLength() { return razorLength; }
	void setrazorLength(float newrazorLength) { razorLength = newrazorLength; }
	string about() const {
		stringstream ss;
		ss << Mammal::about() << " Razor Length = " << razorLength;
		return ss.str();
	}
	Dog() {}
	Dog(float newweight, float newpregnancyDuration, float newrazorlength) {
		razorLength = newrazorlength;
		setpregnancyDuration(newpregnancyDuration);
		setweight(newweight);
	}
};
inline ostream& operator<<(ostream& os, const Dog& dog) {
	return os << dog.about();
}


class Bird : public Animal {
private:
	float fearthLength;	// meters
protected:
	Bird() {}
	Bird(float newweight, float newfearthlength) {
		fearthLength = newfearthlength;
		setweight(newweight);
	}
public:
	float getfearthLength() { return fearthLength; }
	void setfearthLength(float newfearthLength) { fearthLength = newfearthLength; }
	string about() const {
		stringstream ss;
		ss << Animal::about() << " Fearth Length = " << fearthLength;
		return ss.str();
	}
};

class Sparrow : public Bird {
private:
	float razorLength;   // meters
public:
	float getrazorLength() { return razorLength; }
	void setrazorLength(float newrazorLength) { razorLength = newrazorLength; }
	string about() const {
		stringstream ss;
		ss << Bird::about() << " Razor Length = " << razorLength;
		return ss.str();
	}
	Sparrow() {}
	Sparrow(float newweight, float newfearthlength, float newrazorlength) {
		razorLength = newrazorlength;
		setfearthLength(newfearthlength);
		setweight(newweight);
	}
};
inline ostream& operator<<(ostream& os, const Sparrow& sparrow) {
	return os << sparrow.about();
}

class Raven : public Bird {
private:
	float height;		// meters
public:
	float getheight() { return height; }
	void setheight(float newheight) { height = newheight; }
	string about() const {
		stringstream ss;
		ss << Bird::about() << " Height = " << height;
		return ss.str();
	}
	Raven() {}
	Raven(float newweight, float newfearthlength, float newheight) {
		height = newheight;
		setfearthLength(newfearthlength);
		setweight(newweight);
	}
};
inline ostream& operator<<(ostream& os, const Raven& raven) {
	return os << raven.about();
}
