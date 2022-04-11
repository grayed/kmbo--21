#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toString(bool value) {
	if (value) { return "true"; }
	else	   { return "false"; }
}

class Animal {
public:
	bool heterotrophic;
	virtual string about() const;
};
string Animal::about() const {
	stringstream ss;
	ss << "heterotrophic ? " << toString(heterotrophic) << endl;
	return ss.str();
};

class Mammal : public Animal {
public:
	bool lactation;
	virtual string about() const;
};
string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << "lactation ? " << toString(lactation) << endl;
	return ss.str();
};

class Crustacean : public Animal { // Ракообразное
public:
	int claw_number;
	virtual string about() const;
};
string Crustacean::about() const {
	stringstream ss;
	ss << Animal::about() << "claw_number ? " << claw_number << endl;
	return ss.str();
};

class Capybara : public Mammal {
public:
	bool the_biggest_rodent;
	virtual string about() const;
};
string Capybara::about() const {
	stringstream ss;
	ss << Mammal::about() << "the_biggest_rodent ? " << toString(the_biggest_rodent) << endl;
	return ss.str();
};

class Rat : public Mammal {
public:
	bool cute_af;
	virtual string about() const;
};
string Rat::about() const {
	stringstream ss;
	ss << Mammal::about() << "cute_af ? " << toString(cute_af) << endl;
	return ss.str();
};

class Langoustine : public Crustacean {
public:
	bool is_spikes;
	virtual string about() const;
};
string Langoustine::about() const {
	stringstream ss;
	ss << Crustacean::about() << "is_spikes ? " << toString(is_spikes) << endl;
	return ss.str();
};

class Crab : public Crustacean {
public:
	bool is_shell;
	virtual string about() const;
};
string Crab::about() const {
	stringstream ss;
	ss << Crustacean::about() << "is_shell ? " << toString(is_shell) << endl;
	return ss.str();
};
