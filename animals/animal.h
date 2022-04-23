#pragma once

#include <iostream>

class Animal {
protected:
    float weight; //kg
    int age; //years

    Animal(float weight, int age);
public:
    float getWeight() const { return weight; }
    void setWeight(float _weight) { weight = _weight; }

    int getAge() const { return age; }
    void setAge(int _age) { age = _age; }

    virtual std::string about() const = 0;

    friend std::ostream& operator << (std::ostream &out, const Animal &a);
};

class Mammal : public Animal {
protected:
    int pregnancyDuration; //days

    Mammal(float weight, int age, int pregnancyDuration);
public:
    int getPregnancyDuration() const { return pregnancyDuration; }
    void setPregnancyDuration(int _pregnancyDuration) { pregnancyDuration = _pregnancyDuration; }

    std::string about() const override;
};

class Reptile : public Animal {
protected:
    float eggDiameter; //centimeters

    Reptile(float weight, int age, float eggDiameter);
public:
    float getEggDiameter() const { return eggDiameter; }
    void setEggDiameter(float _eggDiameter) { eggDiameter = _eggDiameter; }

    std::string about() const override;
};

class Dog : public Mammal {
private:
    std::string breed;
public:
    Dog(float weight, int age, int pregnancyDuration, std::string&& breed);

    std::string getBreed() const { return breed; }
    void setBreed(std::string&& _breed) { breed = _breed; }

    std::string about() const override;
};

class Cat : public Mammal {
private:
    float vibrissaLength; //centimeters
public:
    Cat(float weight, int age, int pregnancyDuration, float vibrissaLength);

    float getVibrissaLength() const { return vibrissaLength; }
    void setVibrissaLength(float _vibrissaLength) { vibrissaLength = _vibrissaLength; }

    std::string about() const override;
};

class Turtle : public Reptile {
private:
    float shellSize; //meters
public:
    Turtle(float weight, int age, float eggDiameter, float shellSize);

    float getShellSize() const { return shellSize; }
    void setShellSize(float _shellSize) { shellSize = _shellSize; }

    std::string about() const override;
};

class Snake : public Reptile {
private:
    float length; //meters
public:
    Snake(float weight, int age, float eggDiameter, float length);

    float getLength() const { return length; }
    void setLength(float _length) { length = _length; }

    std::string about() const override;
};
