#include "vehicle.h"

Vehicle::Vehicle(int wheelCount_) {
	wheelCount = wheelCount_;
	truck = nullptr;
}

Vehicle::~Vehicle()
{
	delete truck;
}

std::string Vehicle::about() const {
	std::stringstream ss;
	ss << "wheelCount = " << wheelCount;
	return ss.str();
}

Automobile::Automobile(int wheelCount_, float zeroTo100Time_) : Vehicle(wheelCount_)
{
	zeroTo100Time = zeroTo100Time_;
}

Automobile::Automobile(float zeroTo100Time_) : Vehicle(4)
{
	zeroTo100Time = zeroTo100Time_;
}

std::string Automobile::about() const {
	std::stringstream ss;
	ss << Vehicle::about() << ", zeroTo100Time = " << zeroTo100Time;
	return ss.str();
}
