#pragma once
#include<sstream>
#include<string>
#include <iostream>
using namespace std;

class  Animal {
private:
    float life_expectancy; /*Days*/
public:
    void set_life_expectancy(float NewLifeExpectancy) { life_expectancy = NewLifeExpectancy; }
    float get_life_expectancy() const { return life_expectancy; }
    virtual string about() const;
};

string Animal::about() const {
    stringstream ss;
    ss << "life_expectancy = " << " " << life_expectancy;
    return ss.str();
}

class Mammal : public Animal {
private:
    float pregnancy_duration; /*Weeks*/
public:
    void set_pregnancy_duration(float new_pregnancy_Duration) { pregnancy_duration = new_pregnancy_Duration; }
    float get_pregnancy_duration() const { return pregnancy_duration; }
    virtual string about() const;
};

string Mammal::about() const {
    stringstream ss;
    ss << Animal::about() << " " << "pregnancy_duration = " << " " << pregnancy_duration;
    return ss.str();
}


class Amphibia : public Animal {
private:
    int how_long_can_breathe_in_water; /*seconds*/
public:
    void set_how_long_can_breathe_in_water(int new_how_long_can_breathe_in_water) { how_long_can_breathe_in_water = new_how_long_can_breathe_in_water; }
    int get_how_long_can_breathe_in_water() const { return how_long_can_breathe_in_water; }
    virtual string about() const;
};

string Amphibia::about() const {
    stringstream ss;
    ss << Animal::about() << " " << "how_long_can_breathe_in_water = " << " " << how_long_can_breathe_in_water;
    return ss.str();
}

class Cat : public Mammal {
private:
    int vibrissae_length; /*cm*/
public:
    void set_vibrissae_length(int new_vibrissae_length) { vibrissae_length = new_vibrissae_length; }
    int get_vibrissae_length() const { return vibrissae_length; }
    virtual string about() const;
};

string Cat::about() const {
    stringstream ss;
    ss << Mammal::about() << " " << "vibrissae_length = " << " " << vibrissae_length;
    return ss.str();
}

class Deer : public Mammal {
private:
    int horns_length; /*cm*/
public:
    void set_horns_length(int new_horns_length) { horns_length = new_horns_length; }
    int get_horns_length() const { return horns_length; }
    virtual string about() const;
};

string Deer::about() const {
    stringstream ss;
    ss << Mammal::about() << " " << "horns_length = " << " " << Deer::horns_length;
    return ss.str();
}


class Frog : public Amphibia {
private:
    int how_far_stick_tougue_out; /*cm*/
public:
    void set_how_far_stick_tougue_out(int new_how_far_stick_tougue_out) { how_far_stick_tougue_out = new_how_far_stick_tougue_out; }
    int get_how_far_stick_tougue_out() const { return how_far_stick_tougue_out; }
    virtual string about() const;
};

string Frog::about() const {
    stringstream ss;
    ss << Amphibia::about() << " " << "how_far_stick_tougue_out = " << " " << how_far_stick_tougue_out;
    return ss.str();
}

class Lizard : public Amphibia {
private:
    float how_long_tail_grow; /*days*/
public:
    void set_how_long_tail_grow(float new_how_long_tail_grow) { how_long_tail_grow = new_how_long_tail_grow; }
    float get_how_long_tail_grow() const { return how_long_tail_grow; }
    virtual string about() const;

};

string Lizard::about() const {
    stringstream ss;
    ss << Amphibia::about() << " " << "how_long_tail_grow = " << " " << how_long_tail_grow;
    return ss.str();
}