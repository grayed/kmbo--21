#pragma once

#include <iostream>
using namespace std;

class Animal {
private:
	float weight;
public:
    Animal(float w = 0.) {
        weight = w;
    }
    float getWeight() const { return weight; }
    void setWeight(float w) { weight = w; }
    virtual void about() {
        cout << "Weight = " << weight << "\n";
    }
};

class Mammal : public Animal {
private:
	int pregnancyDuration;
public:
    Mammal(float w = 0., int p = 0) : Animal(w) {
        pregnancyDuration = p;
    }
    float getPregnancyDuration() const { return pregnancyDuration; }
    void setPregnancyDuration(int p) { pregnancyDuration = p; }
    virtual void about() {
        cout << "PregnancyDuration = " << pregnancyDuration << "\n";
    }
};

class Cat : public Mammal {
private:
	int vibrissaLength;
public:
    Cat(int v = 0, float w = 0., int p = 0) : Mammal(w, p) {
        vibrissaLength = v;
    }
    float getVibrissaLength() const { return vibrissaLength; }
    void setVibrissaLength(float v) { vibrissaLength = v; }
    virtual void about() {
        cout << "VibrissaLength = " << vibrissaLength << "\n";
    }
};

class Elephant : public Mammal {
private:
    int trunkLength;
public:
    Elephant(int t = 0, float w = 0., int p = 0) : Mammal(w, p) {
        trunkLength = t;
    }
    float getTrunkLength() const { return trunkLength; }
    void setTrunkLength(float t) { trunkLength = t; }
    virtual void about() {
        cout << "TrunkLength = " << trunkLength << "\n";
    }
};

class Birds : public Animal {
private:
    bool canFly;
public:
    Birds(bool b = false, float w = 0.) : Animal(w) {
        canFly = b;
    }
    bool getCanFly() const { return canFly; }
    void setCanFly(bool b) { canFly = b; }
    virtual void about() {
        cout << "CanFly = " << canFly << "\n";
    }
};

class Penguin : public Birds {
private:
    int height;
public:
    Penguin(int h = 0, float w = 0.) : Birds(false, w) {
        height = h;
    }
    bool getHeight() const { return height; }
    void setHeight(int h) { height = h; }
    virtual void about() {
        cout << "Height = " << height << "\n";
    }
};

class Colibri : public Birds {
private:
    string color;
public:
    Colibri(string c = "green", float w = 0.) : Birds(true, w) {
        color = c;
    }
    string getColor() const { return color; }
    void setColor(string c) { color = c; }
    virtual void about() {
        cout << "Color = " << color << "\n";
    }
};
