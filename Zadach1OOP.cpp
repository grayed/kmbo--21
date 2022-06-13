#pragma once
#include<sstream>
#include<string>
#include <iostream>
using namespace std;

class  Animal {
private:
    float weight; 
public:
    void setweight(float newweight) { weight = newweight; }
    float getweight() const { return weight; }
    virtual string about() const;
};

string Animal::about() const {
    stringstream ss;
    ss << "weight = " << " " << weight;
    return ss.str();
}

class Mammal : public Animal {
private:
    float pregnancyduration; 
public:
    void setpregnancyduration(float newpregnancyduration) { pregnancyduration = newpregnancyduration; }
    float getpregnancyduration() const { return pregnancyduration; }
    virtual string about() const;
};

string Mammal::about() const {
    stringstream ss;
    ss << Animal::about() << " " << "pregnancyduration = " << " " << pregnancyduration;
    return ss.str();
}

class Cat : public Mammal {
private:
    int vibrissalength; 
public:
    void setvibrissalength(int newvibrissalength) { vibrissalength = newvibrissalength; }
    int getvibrissalength() const { return vibrissalength; }
    virtual string about() const;
};

string Cat::about() const {
    stringstream ss;
    ss << Mammal::about() << " " << "vibrissalength = " << " " << vibrissalength;
    return ss.str();
}

class Elephant : public Mammal {
private:
    int trunklength; 
public:
    void settrunklength(int newtrunklength) { trunklength = newtrunklength; }
    int gettrunklength() const { return trunklength; }
    virtual string about() const;
};

string Elephant::about() const {
    stringstream ss;
    ss << Mammal::about() << " " << "trunklength = " << " " << Elephant::trunklength;
    return ss.str();
}

class Bird : public Animal {
private:
    float howlongcanfly; 
public:
    void sethowlongcanfly(float newhowlongcanfly) { howlongcanfly = newhowlongcanfly; }
    int gethowlongcanfly() const { return howlongcanfly; }
    virtual string about() const;
};

string Bird::about() const {
    stringstream ss;
    ss << Animal::about() << " " << "howlongcanfly = " << " " << howlongcanfly;
    return ss.str();
}

class Eagle : public Bird {
private:
    int howfastswoopdown; 
public:
    void sethowfastswoopdown(int newhowfastswoopdown) { howfastswoopdown = newhowfastswoopdown; }
    int gethowfastswoopdown() const { return howfastswoopdown; }
    virtual string about() const;
};

string Eagle::about() const {
    stringstream ss;
    ss << Bird::about() << " " << "howfastswoopdown = " << " " << howfastswoopdown;
    return ss.str();
}

class Ostrich : public Bird {
private:
    float height;
public:
    void setheight(float newheight) { height = newheight; }
    float getheight() const { return height; }
    virtual string about() const;

};

string Ostrich::about() const {
    stringstream ss;
    ss << Bird::about() << " " << "height = " << " " << height;
    return ss.str();
}