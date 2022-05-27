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

	vector3d operator+ (vector3d vector) {
		return vector3d(data[0] + vector[0], data[1] + vector[1], data[2] + vector[2]);
	}
	vector3d operator- (vector3d vector) {
		return vector3d(data[0] - vector[0], data[1] - vector[1], data[2] - vector[2]);
	}
	vector3d operator* (float scalar) {
		return vector3d(data[0] * scalar, data[1] * scalar, data[2] * scalar);
	}
	vector3d operator/ (float scalar) {
		return vector3d(data[0] / scalar, data[1] / scalar, data[2] / scalar);
	}
	vector3d operator- () {
		return vector3d(-data[0], -data[1], -data[2]);
	}
	vector3d operator! () {
		return vector3d(!data[0] && !data[1] && !data[2]);
	}
	bool operator== (vector3d vector) {
    	return data[0] == vector[0] && data[1] == vector[1] && data[2] == vector[2];
	}
};

std::ostream& operator <<(std::ostream& os, const vector3d& v);
