#pragma once

#include <iostream>
#include <string>
#include<sstream>
using namespace std;

class Animal {
private:
    float Number_of_species; //Количество видов

protected:
    Animal() { Number_of_species = 100000; }
public:
    void setNumber_of_species(float Numberofspec) { Number_of_species = Numberofspec; }
    float getNumber_of_species() const { return Number_of_species; }

    virtual string about() const;
};
string Animal::about() const {
    stringstream ss;
    ss << "Number_of_species ?" << Number_of_species << endl;
    return ss.str();
};

class Mammal : public Animal {
private:
    float First_beasts_count; // Количество первых зверей

protected:
    Mammal() { First_beasts_count = 36; }
public:
    void setFirst_beasts_count(float fbeasts) { First_beasts_count = fbeasts; }
    float getFirst_beasts_count() const { return First_beasts_count; }
    virtual string about() const;
};
string Mammal::about() const {
    stringstream ss;
    ss << Animal::about() << "First_beasts_count ?" << First_beasts_count << endl;
    return ss.str();
};

class Amphibia : public Animal {
private:
    float Number_of_limbs; //Количество конечностей

protected:
    Amphibia() { Number_of_limbs = 4; }
public:
    void setNumber_of_limbs(float numberoflimbs) { Number_of_limbs = numberoflimbs; }
    float getNumber_of_limbs() const { return Number_of_limbs; }
    virtual string about() const;
};
string Amphibia::about() const {
    stringstream ss;
    ss << Animal::about() << "Number_of_limbs ?" << Number_of_limbs << endl;
    return ss.str();
}

class Salamander : public Amphibia {
private:
    float Tail_length_cm; //Длина хвоста см
public:
    Salamander() { Tail_length_cm = 8; }
    void setTail_length(float Taillength_cm) { Tail_length_cm = Taillength_cm; }
    float getTail_length() const { return Tail_length_cm; }
    virtual string about() const;
};

string Salamander::about() const {
    stringstream ss;
    ss << Amphibia::about() << "Tail_length_cm ?" << Tail_length_cm;
    return ss.str();
}

class Frog : public Amphibia {
private:
    float Number_of_offspring; // Количество потомков

public:
    Frog() { Number_of_offspring = 18; }
    void setNumber_of_offspring(float Numberofoffspring) { Number_of_offspring = Numberofoffspring; }
    float getNumber_of_offspring() const { return Number_of_offspring; }
    virtual string about() const;
};

string Frog::about() const {
    stringstream ss;
    ss << Animal::about() << "Number_of_offspring ?" << Number_of_offspring;
    return ss.str();
}

class Wolf : public Mammal {
private:
    float Average_life_expectancy; //Средняя продолжительность жизни годах

public:
    Wolf() { Average_life_expectancy = 6; }
    Wolf(float Average_life_expectancy_, float First_beasts_count_, float Number_of_species_)
    {
        Average_life_expectancy = Average_life_expectancy_;
        setFirst_beasts_count(First_beasts_count_);
        setNumber_of_species(Number_of_species_);
    }
    void setAverage_life_expectancy(float Averagelifeexpectancy) { Average_life_expectancy = Averagelifeexpectancy; }
    float getAverage_life_expectancy() const { return Average_life_expectancy; }
    virtual string about() const;
};
string Wolf::about() const {
    stringstream ss;
    ss << Animal::about() << "Average_life_expectancy ?" << Average_life_expectancy << endl;
    return ss.str();
}

class Hare : public Mammal {
private:
    float Running_speed_km_ch; //скорость бега км/ч

public:
    Hare() { Running_speed_km_ch = 15; }
    void setRunning_speed_km_ch(float Runningspeed_km_ch) { Running_speed_km_ch = Runningspeed_km_ch; }
    float getRunning_speed_km_ch() const { return Running_speed_km_ch; }
    virtual string about() const;
};
string Hare::about() const{
    ostringstream ss;
    ss << Animal::about() << "Running_speed_km_ch ?" << Running_speed_km_ch << endl;
    return ss.str();
}
