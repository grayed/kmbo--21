#include "vehicle.h"

using namespace std;

Vehicle::Vehicle(int wheelCount_) {
	wheelCount = wheelCount_;
	truck = nullptr;
}

Vehicle::~Vehicle()
{
	delete truck;
}

string Vehicle::about() const {
	stringstream ss;
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

string Automobile::about() const {
	stringstream ss;
	ss << Vehicle::about() << ", zeroTo100Time = " << zeroTo100Time;
	return ss.str();
}

int main()
{
	Automobile a1(5.3f);
	
	cout << "Automobile 1: " << a1 << endl;
	
	
}
