#pragma once

#include <bits/stdc++.h>
using namespace std;

class Animal {
private:
    float weight;
protected:
    Animal() {}
    Animal(float weight1) {weight = weight1; };
public:
    float GETweight() const {return weight;}
    void SETweight(float value) {weight = value;}
    virtual string about() const { return (stringstream() << "Weight =" << weight).str(); }
};
inline ostream& operator <<(ostream &os, const Animal &a){
    return os << "weigth = " << a.GETweight() << endl;
}

class Mammal: public Animal {
private:
    float pregnancy_duration; ///продолжительность беременности
protected:
    Mammal(){}
    Mammal(float weight1, float pregnancy_duration1) : Animal(weight1){pregnancy_duration = pregnancy_duration1;}
public:
    float GETpregnancy_duration() const {return pregnancy_duration;}
    void SETpregnancy_duration(int value1){pregnancy_duration = value1;}
    virtual string about() const {
        return (stringstream()<< Animal::about() << ", " << '\n' << "pregnancy_duration =" <<pregnancy_duration).str();}
    };

class Reptiles: public Animal {
private:
    bool skin_scales; ///наличие чешуи
protected:
    Reptiles() {}
    Reptiles(float weight1, bool skin_scales1) : Animal(weight1){skin_scales = skin_scales1;}
public:
    float GETskin_scales() const {return skin_scales;}
    void SETskin_scales(int value1){skin_scales = value1;}
    virtual string about() const {
        return (stringstream() << Animal::about() << ", " << '\n' << "skin_scales =" <<skin_scales).str();}
};

class Cat: public Mammal{ ///Кошка
private:
    float vibrissaLength; ///длина вибриссов
public:
    Cat(float weight1, int pregnancy_duration1, float vibrissaLength1) : Mammal(weight1, pregnancy_duration1) {
        vibrissaLength = vibrissaLength1;
    }
    float GETvibrissaLength() const {return vibrissaLength; }
    void SETvibrissaLength(float vibrissaLength1) {vibrissaLength = vibrissaLength1; }
    virtual string about() const {
        return (stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "vibrissaLength =" <<
        vibrissaLength).str();}
};

class Platypus: public Mammal{ ///Утконос
private:
    float size_beak; ///длина клюва
public:
    Platypus(float weight1, int pregnancy_duration1, float size_beak1) : Mammal(weight1, pregnancy_duration1) {
        size_beak = size_beak1;
    }
    float GETsize_beak() const {return size_beak; }
    void SETsize_beak(float size_beak1) { size_beak = size_beak1; }
    virtual string about() const {
        return (stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "size_beak =" <<
        size_beak).str();
    }
};

class Turtle: public Reptiles{ ///Черепашка
private:
    bool IsShell; ///наличие панциря
public:
    Turtle(float weight1, int pregnancy_duration1, bool IsShell1) : Reptiles(weight1, pregnancy_duration1)
    {IsShell = IsShell1;}
    float GETIsShell() const {return IsShell; }
    void SETIsShell(float IsShell1) {IsShell = IsShell1; }
    virtual string about() const {
        return (stringstream() << Animal::about() << ", " << Reptiles::about() << ", " << "IsScales =" <<IsShell).str();
    }
};

class Snake: public Reptiles{ ///Змея
private:
    float Duration_of_molting; ///длительность линьки
public:
    Snake(float weight1, int pregnancy_duration1, float Duration_of_molting1) : Reptiles(weight1, pregnancy_duration1)
    {Duration_of_molting = Duration_of_molting1; }
    float GETDuration_of_molting() const {return Duration_of_molting; }
    void SETDuration_of_molting(float Duration_of_molting1) {Duration_of_molting = Duration_of_molting1; }
    virtual  string about() const {
        return (stringstream () << Animal::about() << ", " << Reptiles::about() << ", " << "Duration_of_molting ="
        << Duration_of_molting).str();
    }
};