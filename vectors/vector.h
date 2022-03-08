#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class vector3d {
public:
	float data[3];
public:  
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	float  operator [](int index) const { return data[index]; }
	float& operator [](int index) { return data[index]; }
    /* Ћибо так:
	vector3d operator +(const vector3d& other) { return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
	vector3d operator -(const vector3d& other) { return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
	vector3d operator *(const float value) { return vector3d(data[0] * value, data[1] * value, data[2] * value); } 
	*/
};
// Ћибо так:
vector3d operator+ (const vector3d& v1, const vector3d& v2) {
	return vector3d((v1.data[0] + v2.data[0]), (v1.data[1] + v2.data[1]), (v1.data[2] + v2.data[2]));
}
vector3d operator- (const vector3d& v1, const vector3d& v2) {
	return vector3d((v1.data[0] - v2.data[0]), (v1.data[1] - v2.data[1]), (v1.data[2] - v2.data[2]));
}
float operator* (const vector3d& v, float value) { vector3d(v.data[1] * value, v.data[0] * value, v.data[2] * value); }

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}


