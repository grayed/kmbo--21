#pragma once
#include <iostream>
#include <sstream> 
#include <string>

class Animal {
private:
	float weight;
protected:
	Animal() { weight = 0.0; }
	Animal(float weight_) { weight = weight_; };
public:
	float getWeight() const { return weight; }
	void setWeight(float value) { weight = value; }
	virtual std::string about() const { return (std::stringstream() << "Weight =" << weight).str(); }
};


class Mammal : public Animal {
private:
	int pregnancyDuration;
protected:
	Mammal() { pregnancyDuration = 12; }
	Mammal(float weight_, int pregnancyDuration_) : Animal(weight_) { pregnancyDuration = pregnancyDuration_; };
public:
	int getPregnancyDuration() const { return pregnancyDuration; }
	void setPregnancyDuration(int value) { pregnancyDuration = value; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << "PregnancyDuration =" << pregnancyDuration).str(); }
};


class Cat : public Mammal {
private:
	float vibrissaLength;
protected:
public:
	Cat() { vibrissaLength = 0; };
	Cat(float weight_, int pregnancyDuration_, float vibrissaLength_) : Mammal(weight_, pregnancyDuration_) { vibrissaLength = vibrissaLength_; };
	float getVibrissaLength() const { return	vibrissaLength; }
	void setVibrissaLength(float vibrissaLength_) { vibrissaLength = vibrissaLength_; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "VibrissaLength =" << vibrissaLength).str(); }
};


class Horse : public Mammal {
private:
	float runningSpeed;

protected:
public:
	Horse() { runningSpeed = 0; };
	Horse(float weight_, int pregnancyDuration_, float runningSpeed_) : Mammal(weight_, pregnancyDuration_) { runningSpeed = runningSpeed_; };
	float getRunningSpeed() const { return runningSpeed; }
	void setRunningSpeed(float runningSpeed_) { runningSpeed = runningSpeed_; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "RunningSpeed =" << runningSpeed).str(); }
};


class Fish : public Animal {
private:
	float size;
protected:
	Fish() { size = 0.0; }
	Fish(float weight_, float size_) : Animal(weight_) { size = size_; };
public:
	float getSize() const { return size; }
	void setSize(float size_) { size = size_; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << "Size =" << size).str(); }
};


class Bass : public Fish {
private:
	float gillSize;
protected:
public:
	Bass() { gillSize = 0; };
	Bass(float weight_, float size_, float gillSize_) : Fish(weight_, size_) { gillSize = gillSize_; };
	float getGillsSize() const { return gillSize; }
	void setGillsSize(float value) { gillSize = value; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Fish::about() << ", " << "GillSize =" << gillSize).str(); }
};


class Shark : public Fish {
private:
	float finSize;
protected:
public:
	Shark() { finSize = 0; };
	Shark(float weight_, float size_, float finSize_) : Fish(weight_, size_) { finSize = finSize_; };
	float getFinSize() const { return finSize; }
	void setFinSize(float finSize_) { finSize = finSize_; }
	virtual std::string about() const { return (std::stringstream() << Animal::about() << ", " << Fish::about() << ", " << "FinSize =" << finSize).str(); }
};

