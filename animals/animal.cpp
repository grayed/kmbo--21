#include "animal.h"
#include<iostream>
#include<sstream>


using namespace std;
class  Animal {
private:
    int life_expectancy;
public:
    void setlife_expectancy(int NewLifeExpectancy) { life_expectancy = NewLifeExpectancy; }
    int get_life_expectancy() const { return life_expectancy; }
    string Animal::about() const {
        stringstream ss;
        ss << "life_expectancy =" << life_expectancy;
        return ss.str();
    }
};

class Mammal : public Animal {
private:
    int pregnancyDuration;
public:
    void setPregnancyDuration(int new_pregnancy_Duration) { pregnancyDuration = new_pregnancy_Duration; }
    int get_pregnancy_duration() const { return pregnancyDuration; }
    string Mammal::about() const {
        stringstream ss;
        ss << Animal::about() << "pregnancyDuration =" << pregnancyDuration;
        return ss.str();
    }
};

class Amphibia : public Animal {
private:
    int how_long_can_breathe_in_water;
public:
    void set_how_long_can_breathe_in_water(int new_how_long_can_breathe_in_water) { how_long_can_breathe_in_water = new_how_long_can_breathe_in_water; }
    int get_how_long_can_breathe_in_water() const { return how_long_can_breathe_in_water; }
    string Amphibia::about() const {
        stringstream ss;
        ss << Animal::about() << "how_long_can_breathe_in_water =" << how_long_can_breathe_in_water;
        return ss.str();
    }
};



class Cat : public Mammal {
private:
    int vibrissae_length;
public:
    void set_vibrissae_length(int new_vibrissae_length) { vibrissae_length = new_vibrissae_length; }
    int get_vibrissae_length() const { return vibrissae_length; }
    string Cat::about() const {
        stringstream ss;
        ss << Mammal::about() << "vibrissae_length =" << vibrissae_length;
        return ss.str();
    }
};

class Deer : public Mammal {
private:
    int horns_length;
public:
    void set_horns_length(int new_horns_length) { horns_length = new_horns_length; }
    int get_horns_length() const { return horns_length; }
    string Deer::about() const {
        stringstream ss;
        ss << Mammal::about() << "horns_length =" << Deer::horns_length;
        return ss.str();
    }
};




class Frog : public Amphibia {
private:
    int how_far_stick_tougue_out;
public:
    void set_how_far_stick_tougue_out(int new_how_far_stick_tougue_out) { how_far_stick_tougue_out = new_how_far_stick_tougue_out; }
    int get_how_far_stick_tougue_out() const { return how_far_stick_tougue_out; }
    string Frog::about() const {
        stringstream ss;
        ss << Amphibia::about() << "how_far_stick_tougue_out =" << how_far_stick_tougue_out;
        return ss.str();
    }
};



class Lizard : public Amphibia {
private:
    int how_long_tail_grow;
public:
    void set_how_long_tail_grow(int new_how_long_tail_grow) { how_long_tail_grow = new_how_long_tail_grow; }
    int get_how_long_tail_grow() const { return how_long_tail_grow; }
    string Lizard::about() const {
        stringstream ss;
        ss << Amphibia::about() << "how_long_tail_grow =" << how_long_tail_grow;
        return ss.str();
    }
};





int main() {
    Cat cat();
    Lizard lizard();
    cat().set_vibrissae_length(6);
    lizard().set_how_long_tail_grow(5);
    int res = cat().get_vibrissae_length();
    cout << res <<;
    return 0;
}
