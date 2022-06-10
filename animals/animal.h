#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toString(bool value) {
	if (value) { return "true"; }
	else { return "false"; }
}
int toString(int value) { return bool(value); }

class Animal {
private:
	bool heterotrophic;
protected:
	Animal() { heterotrophic = true; }
	Animal(bool heterotrophic_) { heterotrophic = heterotrophic_; }
public:
	bool get_heterotrophic() const { return heterotrophic; }
	void set_heterotrophic(bool newValue) { heterotrophic = newValue; }
	virtual string about() const;
};
string Animal::about() const {
	stringstream ss;
	ss << "heterotrophic ? " << toString(heterotrophic) << endl;
	return ss.str();
};

class Mammal : public Animal {
private:
	bool lactation;
protected:
	Mammal() { lactation = true; }
	Mammal(bool lactation_, bool heterotrophic_) {
		lactation = lactation_;
		set_heterotrophic(heterotrophic_);
	}
public:
	bool get_lactation() const { return lactation; }
	void set_lactation(bool newValue) { lactation = newValue; }
	virtual string about() const;
};
string Mammal::about() const {
	stringstream ss;
	ss << Animal::about() << "lactation ? " << toString(lactation) << endl;
	return ss.str();
};

class Crustacean : public Animal { // Ракообразное
private:
	int claw_number;
protected:
	Crustacean() { claw_number = 2; }
	Crustacean(bool claw_number_, bool heterotrophic_) {
		claw_number = claw_number_;
		set_heterotrophic(heterotrophic_);
	}
public:
	int get_claw_number() const { return claw_number; }
	void set_claw_number(int newValue) { claw_number = newValue; }
	virtual string about() const;
};
string Crustacean::about() const {
	stringstream ss;
	ss << Animal::about() << "claw_number ? " << toString(claw_number) << endl;
	return ss.str();
};

class Capybara : public Mammal {
private:
	bool the_biggest_rodent;
public:
	Capybara() { the_biggest_rodent = true; }
	Capybara(bool the_biggest_rodent_, bool lactation_, bool heterotrophic_) {
		the_biggest_rodent = the_biggest_rodent_;
		set_lactation(lactation_);
		set_heterotrophic(heterotrophic_);
	}
	bool get_the_biggest_rodent() const { return the_biggest_rodent; }
	void set_the_biggest_rodent(bool newValue) { the_biggest_rodent = newValue; }
	virtual string about() const;
};
string Capybara::about() const {
	stringstream ss;
	ss << Mammal::about() << "the_biggest_rodent ? " << toString(the_biggest_rodent) << endl;
	return ss.str();
};

class Rat : public Mammal {
private:
	bool cute_af;
public:
	Rat() { cute_af = true; }
	Rat(bool cute_af_, bool lactation_, bool heterotrophic_) {
		cute_af = cute_af_;
		set_lactation(lactation_);
		set_heterotrophic(heterotrophic_);
	}
	bool get_cute_af() const { return cute_af; }
	void set_cute_af(bool newValue) { cute_af = newValue; }
	virtual string about() const;
};
string Rat::about() const {
	stringstream ss;
	ss << Mammal::about() << "cute_af ? " << toString(cute_af) << endl;
	return ss.str();
};

class Langoustine : public Crustacean {
private:
	bool is_spikes;
public:
	Langoustine() { is_spikes = true; }
	Langoustine(bool is_spikes_, bool claw_number_, bool heterotrophic_) {
		is_spikes = is_spikes_;
		set_claw_number(claw_number_);
		set_heterotrophic(heterotrophic_);
	}
	bool get_is_spikes() const { return is_spikes; }
	void set_is_spikes(bool newValue) { is_spikes = newValue; }
	virtual string about() const;
};
string Langoustine::about() const {
	stringstream ss;
	ss << Crustacean::about() << "is_spikes ? " << toString(is_spikes) << endl;
	return ss.str();
};

class Crab : public Crustacean {
private:
	bool is_shell;
public:
	Crab() { is_shell = true; }
	Crab(bool is_shell_, bool claw_number_, bool heterotrophic_) {
		is_shell = bool(is_shell_);
		set_claw_number(claw_number_);
		set_heterotrophic(heterotrophic_);
	}
	bool get_is_shell() const { return bool(is_shell); }
	void set_is_shell(bool newValue) { is_shell = newValue; }
	virtual string about() const;
};
string Crab::about() const {
	stringstream ss;
	ss << Crustacean::about() << "is_shell ? " << toString(is_shell) << endl;
	return ss.str();
};