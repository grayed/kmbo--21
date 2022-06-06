#pragma once
#include <iostream>
#include <cmath>
using namespace std;


class Vector3d {
public:

	float data[3];
public:  
	Vector3d() { data[2] = data[1] = data[0] = 0; }
	Vector3d(float value) { data[2] = data[1] = data[0] = value; }
	Vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
	float  operator [](int index) const { return data[index]; }
	float& operator [](int index) { return data[index]; }
	//
	Vector3d operator +(const Vector3d& other) { return Vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
	//
	Vector3d operator -(const Vector3d& other) { return Vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
	//
	Vector3d operator *(const float value) { return Vector3d(data[0] * value, data[1] * value, data[2] * value); }
	//
	Vector3d operator /(const float value) { 
		if (value != 0) return Vector3d(data[0] / value,data[1]/value,data[2]/value);
		else cout << "¬ведите значение не равное нулю";
	}
	//
	Vector3d operator -() { Vector3d(-data[0], -data[1], -data[2]); }
	//
	Vector3d operator !() {
		if (data[0] == 0 && data[1] == 0 && data[2] == 0) return Vector3d(1, 1, 1);
		else return Vector3d(0, 0, 0);
	}
	

};


ostream& operator <<(ostream& os, const Vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}


bool test_all_operators() {
	Vector3d v1;
	Vector3d v2(5, 5, 5);
	Vector3d v3(1, 1, 1);
	Vector3d  v4 = v1 + v2, v5 = v3 - v2, v6 = v2 * 3, v7 = v2 / 5, v8 = -v2, v9 = !v3, v10 = !v1;
	if (v4.data[0] != 5 || v4.data[1] != 5 || v4.data[2] != 5)		{ cout << "Addition Error";		return false; }
	if (v5.data[0] != 4 || v5.data[1] != 4 || v5.data[2] != 4)		{ cout << "Substraction Error"; return false; }
	if (v6.data[0] != 15 || v6.data[1] != 15 || v6.data[2] != 15)	{ cout << "Multiplying Error";	return false; }
	if (v7.data[0] != 1 || v7.data[1] != 1 || v7.data[2] != 1)		{ cout << "Divising Error";		return false; }
	if (v8.data[0] != -5 || v8.data[1] != -5 || v8.data[2] != -5)	{ cout << "Inverting Error";	return false; }
	if (v9.data[0] != 0 || v3.data[1] != 0 || v9.data[2] != 0)		{ cout << "Boolean Converting Error";	return false; }
	if (v10.data[0] != 1 || v10.data[1] != 1 || v10.data[2] != 1)	{ cout << "Boolean Converting Error";	return false; }
	return true;
}



