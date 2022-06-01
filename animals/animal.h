#pragma once

#include <iostream>
#include <sstream>
#include <utility>

class Animal {
protected:
    float weight; // kg
    int age; // years

    Animal(float _weight, int _age);
public:
    virtual std::string about() const = 0;

    float get_weight() const { return weight; }
    void set_weight(float _weight) { weight = _weight; }

    int get_age() const { return age; }
    void set_age(int _age) { age = _age; }

    friend std::ostream& operator << (std::ostream &out, const Animal &animal);
};

class Mammal : public Animal {
protected:
    int pregnancyLength; // days

    Mammal(float _weight, int _age, int _pregnancyLength);
public:
    std::string about() const override;

    int get_pregnancyLength() const { return pregnancyLength; }
    void set_pregnancyLength(int _pregnancyLength) { pregnancyLength = _pregnancyLength; }
};

class Reptile : public Animal {
protected:
    float eggHeight; // centimeters

    Reptile(float _weight, int _age, float _eggHeight);
public:
    std::string about() const override;

    float get_eggHeight() const { return eggHeight; }
    void set_eggHeight(float _eggHeight) { eggHeight = _eggHeight; }
};

class Cat : public Mammal {
private:
    float vibrissaeLength; // centimeters
public:
    Cat(float _weight, int _age, int _pregnancyLength, float _vibrissaeLength);

    std::string about() const override;
};

class Dog : public Mammal {
private:
    std::string breed;
public:
    Dog(float _weight, int _age, int _pregnancyLength, std::string _breed);

    std::string about() const override;

    std::string get_breed() const { return breed; }
    void set_breed(std::string _breed) { breed = _breed; }
};

class Turtle : public Reptile {
private:
    float shellSize; // meters
public:
    Turtle(float _weight, int _age, float _eggHeight, float _shellSize);

    std::string about() const override;

    float get_shellSize() const { return shellSize; }
    void set_shellSize(float _shellSize) { shellSize = _shellSize; }
};

class Snake : public Reptile {
private:
    float length; // meters
public:
    Snake(float _weight,  int _age, float _eggHeight, float _length);

    std::string about() const override;

     float get_length() const { return length; }
     void set_length(float _length ) { length = _length; }
};
