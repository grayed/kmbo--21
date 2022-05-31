#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Animal {
public:
	bool alive;
	string about() const {
		stringstream ss;
		ss << "alive - " << alive << endl;
		return ss.str();
	};
};


class Mammal : public Animal {
public:
	int milk_volume;
	string about() const {
		stringstream ss;
		ss << Animal::about() << "milk_volume - " << milk_volume << endl;
		return ss.str();
	};
};

class Spineless : public Animal {
public:
	bool no_spine;
	string about() const {
		stringstream ss;
		ss << Animal::about() << "no_spine - " << no_spine << endl;
		return ss.str();
	};
};

class Monkey : public Mammal {
public:
	int tail_lenght;
	string about() const {
		stringstream ss;
		ss << Mammal::about()  << "tail_lenght - " << tail_lenght << endl;
		return ss.str();
	};
};

class Cow : public Mammal {
public:
	bool white;
	string about() const {
		stringstream ss;
		ss << Mammal::about() << "white - " << white << endl;
		return ss.str();
	};
};

class Worm : public Spineless {
public:
	int length;
	string about() const {
		stringstream ss;
		ss << Spineless::about() << "length - " << length << endl;
		return ss.str();
	};
};

class Jellyfish : public Spineless {
public:
	bool transparent;
	string about() const {
		stringstream ss;
		ss << Spineless::about() << "transparent - " << transparent << endl;
		return ss.str();
	};
};

inline ostream& operator <<(ostream& os, const Animal& animal) {
	return os << animal.about();
}
