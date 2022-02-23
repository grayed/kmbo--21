#pragma once

#include <iostream>
#include <sstream>

class Automobile;

class Vehicle {
private:
	int wheelCount;

protected:
	Vehicle(int wheelCount_);
	virtual ~Vehicle();

public:
	Automobile* truck;

	int  getWheelCount() const		 { return wheelCount; }
	void setWheelCount(int newValue) { wheelCount = newValue; }

	virtual std::string about() const;
};

class Automobile : public Vehicle {
public:
	float zeroTo100Time;	// seconds

	Automobile(int wheelCount_, float zeroTo100Time_);
	Automobile(float zeroTo100Time_);

	virtual std::string about() const;
};

class Garage {
private:
	Vehicle &vehicle;

public:
	Garage(Vehicle &vehicle_) : vehicle(vehicle_) { }
};

inline std::ostream& operator <<(std::ostream& os, const Vehicle& vehicle) {
	return os << vehicle.about();
}
