#pragma once
#include <iostream>
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

	vector3d operator +(const vector3d& other) { return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
	vector3d operator -(const vector3d& other) { return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
	vector3d operator *(const float value) { return vector3d(data[0] * value, data[1] * value, data[2] * value); }
	vector3d operator /(const float value) { return vector3d(data[0] / value, data[1] / value, data[2] / value); }
	vector3d operator -() { return vector3d(-data[0], -data[1], -data[2]); }
	vector3d operator !()
	{
		if ((data[0] == 0) && (data[1] == 0) && (data[2] == 0))
		{
			return vector3d(data[0] = 1, data[1] = 1, data[2] = 1);
		}
		else return vector3d(data[0] = 0, data[1] = 0, data[2] = 0);
	}
};

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}
bool test_vector3d()
{
	vector3d v1(5, 5, 5);
	vector3d v2(1, 1, 1);
	vector3d v3;
	vector3d v4(0, 0, 0);
	v3 = v1 + v2;
	if ((v3.data[0] != 6) || (v3.data[1] != 6) || (v3.data[2] != 6)) { cout << "The addition operation does not work. Check Data v1(5,5,5), v2(1,1,1)"; return 1; }
	v3 = v1 - v2;
	if ((v3.data[0] != 4) || (v3.data[1] != 4) || (v3.data[2] != 4)) { cout << "The subtraction operation does not work. Check Data v1(5,5,5), v2(1,1,1)"; return 1; }
	v3 = v1 * 3;
	if ((v3.data[0] != 15) || (v3.data[1] != 15) || (v3.data[2] != 15)) { cout << "The multiplication operation does not work. Check Data v1(5,5,5), 3"; return 1; }
	v3 = v1 / 5;
	if ((v3.data[0] != 1) || (v3.data[1] != 1) || (v3.data[2] != 1)) { cout << "The division operation by a scalar does not work. Check Data v1(5,5,5), 5"; return 1; }
	v3 = -v1;
	if ((v3.data[0] != -5) || (v3.data[1] != -5) || (v3.data[2] != -5)) { cout << "The invert operation does not work. Check Data v1(5,5,5)"; return 1; }
	v3 = !v1;
	if ((v3.data[0] != 0) || (v3.data[1] != 0) || (v3.data[2] != 0)) { cout << "Operation ! does not work. Check Data v4(0,0,0)"; return 1; }
	v3 = !v4;
	if ((v3.data[0] != 1) || (v3.data[1] != 1) || (v3.data[2] != 1)) { cout << "Operation ! does not work. Check Data v1(1,1,1)"; return 1; }
	return 0;
}

