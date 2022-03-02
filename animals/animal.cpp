#include "animal.h"

using namespace std;
class  Animal {
private:
    int life_expectancy;
public:
    void setlife_expectancy(int NewLifeExpectancy) { life_expectancy = NewLifeExpectancy; }
    int get_life_expectancy() const { return life_expectancy; }
};

string Animal::about() const {
    stringstream ss;
    ss << "life_expectancy = " << life_expectancy;
    return ss.str();
}

class Mammal : public Animal {
private:
    int milk_generation;
public:
    void setMILKgeneration(int new_milk_generation) { milk_generation = new_milk_generation; }
    int get_milk_generation() const { return milk_generation; }
};

class Amphibia : public Animal {
private:
    int how_long_can_breathe_in_water;
public:
    void set_how_long_can_breathe_in_water(int new_how_long_can_breathe_in_water) { how_long_can_breathe_in_water = new_how_long_can_breathe_in_water; }
    int get_how_long_can_breathe_in_water() const { return how_long_can_breathe_in_water; }

};
class Cat : public Mammal {
private:
    int vibrissae_length;
public:
    void set_vibrissae_length(int new_vibrissae_length) { vibrissae_length = new_vibrissae_length; }
    int get_vibrissae_length() const { return vibrissae_length; }
};
class Deer : public Mammal {
private:
    int horns_length;
public:
    void set_horns_length(int new_horns_length) { horns_length = new_horns_length; }
    int get_horns_length() const { return horns_length; }
};
class Frog : public Amphibia {
private:
    int how_far_stick_tougue_out;
public:
    void set_how_far_stick_tougue_out(int new_how_far_stick_tougue_out) { how_far_stick_tougue_out = new_how_far_stick_tougue_out; }
    int get_how_far_stick_tougue_out() const { return how_far_stick_tougue_out; }
};
class Lizard : public Amphibia {
private:
    int how_long_tail_grow;
public:
    void set_how_long_tail_grow(int new_how_long_tail_grow) { how_long_tail_grow = new_how_long_tail_grow; }
    int get_how_long_tail_grow() const { return how_long_tail_grow; }
};


int main() {

	return 0;
}