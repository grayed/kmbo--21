#pragma once

#include <iostream>
#include <sstream> 
#include <string>
using namespace std;

class Animal
{
public:
	float getWeight() const { return weight; }
	void setWeight(float weight) { this->weight = weight; }
	virtual std::string about() const { return (std::stringstream() << "weight =" << weight).str(); }
private:
	float weight;
protected:
	Animal() //как конструктор по умолчанию
	{
		weight = 0.;
	}
	Animal(float weight)
	{
		this->weight = weight;
	}
};

class Mammal : public Animal 
{
private:
int pregnancyDuration;
public:
	int  getPregnancyDuration() const { return pregnancyDuration; }
	void setpregnancyDuration(int period) { pregnancyDuration = period; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << "pregnancyDuration =" << pregnancyDuration).str(); }
protected:
	Mammal() {
		pregnancyDuration = 0;
	}
	Mammal(float weight, int period) :Animal(weight) { pregnancyDuration = period; }

	
};

class Cat : public Mammal 
{
private:
	float vibrissaLength;
public:
	float  getVibrissaLength() const { return vibrissaLength; }
	void setvibrissaLength(int length) { vibrissaLength = length; }
	Cat(float weight, int period, float length) :Mammal(weight, period) { vibrissaLength = length; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "vibrasaLength =" << vibrissaLength).str(); }
	Cat() {
		vibrissaLength = 0;
	}
};

class Giraffe : public Mammal 
{
private:
	int height;
public:
	int getHeight() const { return height; }
	void setHeight(int height) { this->height = height; }
	Giraffe(float weight, int period, int height) :Mammal(weight, period) { setHeight(height); }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "heigth = " << height).str(); }
	Giraffe() { height = 0; }
};

class Fish : public Animal
{
private: 
	int size;
public:
	int getSize() const { return size; }
	void setSize(int size) { this->size = size; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << "size =" << size).str(); }
protected:
	Fish(float weight, int size) :Animal(weight) { setSize(size); }
	Fish() {
		size = 0;
	}

};

class Shark : public Fish
{
private:
	int jawSize;// размер челюсти
public:
	int getJawSize() const { return jawSize; }
	void setJawSize(int size) { jawSize = size; }
	Shark(float weight, int size, int jawSize) :Fish(weight, size) {setJawSize(jawSize);}
	Shark() { jawSize = 0; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Fish::about() << ", " << "jawSize =" << jawSize).str();}

};

