#pragma once

#include <ostream>

class vector3d {
	float data[3];

public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	vector3d operator+(const vector3d& other) { return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
	vector3d operator-(const vector3d& other) { return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
	vector3d operator/(const float val) { return vector3d(data[0] / val, data[1] / val, data[2] / val); }

	vector3d operator-() { return vector3d(-data[0], -data[1], -data[2]); }
	vector3d operator!() {
		if ((data[0] == 0) && (data[1] == 0) && (data[2] == 0))
		{
			return vector3d(!data[0], !data[1], !data[2]);
		}
		else {
			return vector3d(data[0] * 0, data[1] * 0, data[2] * 0);
		}
	}

	float& operator[](int idx) { return data[idx]; }
	float  operator[](int idx) const { return data[idx]; }

	friend int main(int argc, char** argv);
	friend vector3d operator*(const vector3d& other, const float num);
	friend vector3d operator*(const float num, const vector3d& other);
};


vector3d operator*(const vector3d& other, const float num) { return vector3d(other.data[0] * num, other.data[1] * num, other.data[2] * num); }
vector3d operator*(const float num, const vector3d& other) { return vector3d(other.data[0] * num, other.data[1] * num, other.data[2] * num); }


std::ostream& operator <<(std::ostream& os, const vector3d& v);

bool test(vector3d v1, vector3d v2, float num) {
	bool nomistakes = true;

	if (((v1 + v2)[0] != v1[0] + v2[0]) || ((v1 + v2)[1] != v1[1] + v2[1]) || ((v1 + v2)[2] != v1[2] + v2[2]))
	{
		nomistakes = false;
		std::cerr << "Addition is incorrect";
	}

	if (((v1 - v2)[0] != v1[0] - v2[0]) || ((v1 - v2)[1] != v1[1] - v2[1]) || ((v1 - v2)[2] != v1[2] - v2[2]))
	{
		nomistakes = false;
		std::cerr << "Subtraction is incorrect";
	}

	if (((v1 * num)[0] != v1[0] * num) || ((v1 * num)[1] != v1[1] * num) || ((v1 * num)[2] != v1[2] * num))
	{
		nomistakes = false;
		std::cerr << "Multiplication by num is incorrect";
	}

	if (((num * v1)[0] != v1[0] * num) || ((num * v1)[1] != v1[1] * num) || ((num * v1)[2] != v1[2] * num))
	{
		nomistakes = false;
		std::cerr << "Multiplication by num is incorrect";
	}

	if (((v1 / num)[0] != v1[0] / num) || ((v1 / num)[1] != v1[1] / num) || ((v1 / num)[2] != v1[2] / num))
	{
		nomistakes = false;
		std::cerr << "Division by num is incorrect";
	}

	if (((-v1)[0] != -v1[0]) || ((-v1)[1] != -v1[1]) || ((-v1)[2] != -v1[2]))
	{
		nomistakes = false;
		std::cerr << "Negative coords are incorrect";
	}

	if (((!v1)[0] != !v1[0]) || ((!v1)[1] != !v1[1]) || ((!v1)[2] != !v1[2]))
	{
		nomistakes = false;
		std:: cerr << "Inversion is incorrect";
	}

	return nomistakes;
}
