#pragma once

#include <iostream>

#include<sstream>

class Animal {
private:
    int Number_of_species; //Количество видов

public:
    void setNumber_of_species(int Numberofspec) { Number_of_species = Numberofspec; }
    int getNumber_of_species() const { return Number_of_species; }

    string about() const {
        stringstream strs;
        strs << "Number_of_species = " << Number_of_species;
        return strs.str();
    }
};

class Mammal : public Animal {
private:
    int First_beasts_count; // Количество первых зверей

public:
    void setFirst_beasts_count(int fbeasts) { First_beasts_count = fbeasts; }
    int getFirst_beasts_count() const { return First_beasts_count; }

    string about() const {
        stringstream strs;
        strs << Animal::about() << "First_beasts = " << First_beasts_count;
        return strs.str();
    }
};

class Amphibia : public Animal {
private:
    int Number_of_limbs; //Количество конечностей

public:
    void setNumber_of_limbs(int numberoflimbs) { Number_of_limbs = numberoflimbs; }
    int getNumber_of_limbs() { return Number_of_limbs; }

    string about() const {
        stringstream strs;
        strs << Animal::about() << "Number_of_limbs = " << Number_of_limbs;
        return strs.str();
    }
};

class Salamander : public Amphibia {
private:
    int Tail_length_cm; //Длина хвоста см

public:
    void setTail_length(int Taillength_cm) { Tail_length_cm = Taillength_cm; }
    int getTail_length() { return Tail_length_cm; }

    string about() const {
        stringstream strs;
        strs << Amphibia::about() << "Tail_length = " << Tail_length_cm;
        return strs.str();
    }
};

class Frog : public Amphibia {
private:
    int Number_of_offspring; // Количество потомков

public:
    void setNumber_of_offspring(int Numberofoffspring) { Number_of_offspring = Numberofoffspring; }
    int getNumber_of_offspring() { return Number_of_offspring; }

    string about() const {
        stringstream strs;
        strs << Amphibia::about() << "Number_of_offspring = " << Number_of_offspring;
        return strs.str();
    }
};

class Wolf : public Mammal {
private:
    int Average_life_expectancy; //Средняя продолжительность жизни годах

public:
    void setAverage_life_expectancy(int Averagelifeexpectancy) { Average_life_expectancy = Averagelifeexpectancy; }
    int getAverage_life_expectancy() { return Average_life_expectancy; }

    string about() const {
        stringstream strs;
        strs << Mammal::about() << "Average_life_expectancy = " << Average_life_expectancy;
        return strs.str();
    }
};

class Hare : public Mammal {
private:
    int Running_speed_km_ch; //скорость бега км/ч

public:
    void setRunning_speed_km_ch(int Runningspeed_km_ch) { Running_speed_km_ch = Runningspeed_km_ch; }
    int getRunning_speed_km_ch() { return Running_speed_km_ch; }

    string about() const {
        stringstream strs;
        strs << Mammal::about() << "Running_speed_km_ch = " << Running_speed_km_ch;
        return strs.str();
    }
};
