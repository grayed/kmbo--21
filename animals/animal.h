#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Animal {
private:
    float mass; // в килограммах
    float age;
    int lags;
public:
    Animal(float Mass, float Age, float Lags) {
        mass = Mass;
        age = Age;
        lags = Lags;
    }

    void setMass(float Mass) {mass = Mass;}
    void setAge(float Age) {age = Age;}
    void setLags(int Lags) {lags = Lags;}

    float getMass() {return mass;}
    float getAge() {return age;}
    int getLags() {return lags;}

    virtual string about() const {
        stringstream str;
        str << "Mass = " << mass << "; " << "Age = " << age << "; " << "Lags = " << lags << endl;
        return str.str();
    }
};

class Insects : public Animal{
private:
    bool doFly;
public: 
    Insects(bool DoFly, float Mass, float Age, float Lags) : Animal(Mass, Age, Lags) {
        doFly = DoFly;
    }

    void setDoFly(bool DoFly) {doFly = DoFly;}

    bool getDoFly() {return doFly;}

    virtual string about() const {
        stringstream str;
        str << Animal::about() << "do it fly: " << doFly << endl;
        return str.str();
    }
};

class Mosquito : public Insects {
private:
    string sex;
    bool haveSpine;
public:
    Mosquito(string Sex, bool HaveSpine, bool DoFly, float Mass, float Age, float Lags) : Insects(DoFly, Mass, Age, Lags) {
        sex = Sex;
        haveSpine = HaveSpine;
    }

    void setSex(string Sex) {sex = Sex;}
    void setHaveWings(bool HaveSpine) {haveSpine = HaveSpine;}

    string getSex() {return sex;}
    bool getHaveSpine() {return haveSpine;}

    virtual string about() const {
        stringstream str;
        str << Insects::about() << "Sex: " << sex  << "; " << "have spine: " << haveSpine << endl;
        return str.str();
    }
};

class Cockroach : public Insects {
private:
    float length;   // в сантиметрах
    bool haveWings;
public:
    Cockroach(float Length, bool HaveWings, bool DoFly, float Mass, float Age, float Lags) : Insects(DoFly, Mass, Age, Lags) {
        length = Length;
        haveWings = HaveWings;
    }

    void setLength(float Length) {length = Length;}
    void setHaveWings(bool HaveWings) {haveWings = HaveWings;}

    float getLength() {return length;}
    bool getHaveWings() {return haveWings;}

    virtual string about() const {
        stringstream str;
        str << Insects::about() << "Length = " << length  << "; " << "have wings: " << haveWings << endl;
        return str.str();
    }
};

class Mammal : public Animal {
private: 
    string eyeColor;
    string sex;
public:
    Mammal(string EyeColor, string Sex, float Mass, float Age, float Lags) : Animal(Mass, Age, Lags) {
        eyeColor = EyeColor;
        sex = Sex;
    }

    void setEyeColor(string EyeColor) {eyeColor = EyeColor;}
    void setSex(string Sex) {sex = Sex;}

    string getEyeColor() {return eyeColor;}
    string getSex() {return sex;}

    virtual string about() const {
        stringstream str;
        str << Animal::about() << "Eye Color: " << eyeColor << "; " << "Sex: " << sex << endl;
        return str.str();
    }
};

class Human : public Mammal {
private:
    string country;
    bool married;
public:
    Human(string Country, bool Married, string EyeColor, string Sex, float Mass, float Age, float Lags) : 
        Mammal(EyeColor, Sex, Mass, Age, Lags) {
            country = Country;
            married = Married;
        }
    void setCountry(string Country) {country = Country;}
    void setPoliticalOutlook(bool Married) {married = Married;}

    string getCountry() {return country;}
    bool getPoliticalOutlook() {return married;}

    virtual string about() const {
        stringstream str;
        str << Mammal::about() << "Country: " << country << "; " << "isMarried: " << married << endl;
        return str.str();
    }
};

class Cat : public Mammal{
private:
    bool isDomestic;
    int numberOfHosts;
public:
    Cat(bool IsDomestic, int NumberOfHosts, string EyeColor, string Sex, float Mass, float Age, float Lags) :
        Mammal(EyeColor, Sex, Mass, Age, Lags) {
            isDomestic = IsDomestic;
            numberOfHosts = NumberOfHosts;
        }

    void setIsDomestic(bool IsDomestic) {isDomestic = IsDomestic;}
    void setNumberOfHosts(int NumberOfHosts) {numberOfHosts = NumberOfHosts;}

    bool getIsDomestic() {return isDomestic;}
    int getNumbeOfHosts() {return numberOfHosts;}

    virtual string about() const {
        stringstream str;
        str << Mammal::about() << "isDomestic: " << isDomestic << "; " << "Number of hosts = " << numberOfHosts << endl;;
        return str.str();
    }
};