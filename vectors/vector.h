#pragma once

#include <ostream>

class vector3d {
	float data[3];

public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	float& operator[](int idx)       { return data[idx]; }
	float  operator[](int idx) const { return data[idx]; }

	friend int main(int argc, char** argv);
};

std::ostream& operator <<(std::ostream& os, const vector3d& v);


vector3d operator-(const vector3d& v);

vector3d operator +(const vector3d& v1, const vector3d& v2);

vector3d operator -(const vector3d& v1, const vector3d& v2);

vector3d operator *(const vector3d& v, float n);

vector3d operator * (float n, const vector3d& v);

vector3d operator /(const vector3d& v, float n);

vector3d operator /(float n, const vector3d& v);

vector3d operator !(const vector3d& v);

bool test_vector3d();
