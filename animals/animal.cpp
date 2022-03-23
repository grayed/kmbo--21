// 1.  ак сделать так, чтобы выводилась не 1, а true/false?
// 2.  ак вывести все пол€ через about, а не только последнее? (иначе не очень пон€тно, зачем писать about дл€ промежуточных классов)
// 3. «ачем в этих файлах использовать директиву #pragma once ?

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Animal {
public:
	bool heterotrophic;
	virtual string about() const;
};
string Animal::about() const {
	stringstream ss;
	ss << "heterotrophic? " << heterotrophic << endl;
	return ss.str();
};

class Mammal : public Animal {
public:
	bool lactation;
	string about() const;
};
string Mammal::about() const {
	stringstream ss;
	ss << "lactation? " << lactation << endl;
	return ss.str();
};

class Crustacean : public Animal {
public:
	int claw_number;
	string about() const;
};
string Crustacean::about() const {
	stringstream ss;
	ss << "claw_number? " << claw_number << endl;
	return ss.str();
};

class Capybara : public Mammal {
public:
	bool the_biggest_rodent;
	string about() const;
};
string Capybara::about() const {
	stringstream ss;
	ss << "the_biggest_rodent? " << the_biggest_rodent << endl;
	return ss.str();
};

class Rat : public Mammal {
public:
	bool cute_af;
	string about() const;
};
string Rat::about() const {
	stringstream ss;
	ss << "cute_af? " << cute_af << endl;
	return ss.str();
};

class Langoustine : public Crustacean {
public:
	bool is_spikes;
	string about() const;
};
string Langoustine::about() const {
	stringstream ss;
	ss << "is_spikes? " << is_spikes << endl;
	return ss.str();
};

class Crab : public Crustacean {
public:
	bool is_shell;
	string about() const;
};
string Crab::about() const {
	stringstream ss;
	ss << "is_shell? " << is_shell << endl;
	return ss.str();
};

inline ostream& operator <<(ostream& os, const Animal& animal) {
	return os << animal.about();
}

int main()
{
	Capybara	 Marcus;
	Rat			 Mickey;
	Langoustine	 Anton;
	Crab		 Crabsburger;

	Marcus.heterotrophic = true;
	Marcus.lactation = true;
	Marcus.the_biggest_rodent = true;

	Mickey.heterotrophic = true;
	Mickey.lactation = true;
	Mickey.cute_af = true;

	Anton.heterotrophic = true;
	Anton.claw_number = 0;
	Anton.is_spikes = true;

	Crabsburger.heterotrophic = true;
	Crabsburger.claw_number = 2;
	Crabsburger.is_shell = true;

	cout << Crabsburger;
	cout << Marcus;
}
// 1.  ак сделать так, чтобы выводилась не 1, а true/false?
// 2.  ак вывести все пол€ через about, а не только последнее? (иначе не очень пон€тно, зачем писать about дл€ промежуточных классов)
// 3. «ачем в этих файлах использовать директиву #pragma once ?