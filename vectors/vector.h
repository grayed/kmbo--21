#pragma once

#include <iostream>
#include <typeinfo>

class vector3d {
	float data[3];

public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	float& operator[](int idx) { return data[idx]; }
	float  operator[](int idx) const { return data[idx]; }

	vector3d operator+(vector3d other) {
		return vector3d((data[0] + other[0]), (data[1] + other[1]), (data[2] + other[2]));
	}

	vector3d operator-(vector3d other) {
		return vector3d((data[0] - other[0]), (data[1] - other[1]), (data[2] - other[2]));
	}

	vector3d operator*(float value) {
		return vector3d((data[0] * value), (data[1] * value), (data[2] * value));
	}

	vector3d operator/(float value) {
		if (value == 0) {
			std::cerr << "Indefinite division by zero" ;
		}
		else {
			return vector3d((data[0] / value), (data[1] / value), (data[2] / value));
		}
	}

	vector3d operator-() {
		return vector3d(-data[0], -data[1], -data[2]);
	}

	vector3d operator!() {
		if (data == 0) {
			return vector3d((data[0] = 1), (data[1] = 1), (data[2] = 1));
		}
		else {
			return vector3d((data[0] = 0), (data[1] = 0), (data[2] = 0));
		}
	}


	friend int main(int argc, char** argv);
};

void vector3d_AdditionTest(vector3d v1, vector3d v2) {
	vector3d res = v1 + v2;
	if (fabs(res[0] - (-2.5f)) > 0.00001 || fabs(res[1] - 14.12f) > 0.00001 || fabs(res[2] - 6.2f) > 0.00001) {
		std::cout << "Addition error" << std::endl;
	}
}

void vector3d_SubstructionTest(vector3d v1, vector3d v2) {
	vector3d res = v1 - v2;
	if (fabs(res[0] - 7.5f) > 0.00001 || fabs(res[1] - 1.88f) > 0.00001 || fabs(res[2] - (-15.8f)) > 0.00001) {
		std::cerr << "Substraction error" << std::endl;
	}
}

void vector3d_MultiTest(vector3d v1, float scal) {
	vector3d res = v1 * scal;
	if (fabs(res[0] - 3.75f) > 0.00001 || fabs(res[1] - 12) > 0.00001 || fabs(res[2] - (-7.2f)) > 0.00001) {
		std::cerr << "Multiplication error" << std::endl;
	}
}

void vector3d_DivTest(vector3d v1, float scal) {
	vector3d res = v1 / scal;
	if (fabs(res[0] - 1.25f) > 0.00001 || fabs(res[1] - 4) > 0.00001 || fabs(res[2] - (-2.4f)) > 0.00001) {
		std::cerr << "Division error" << std::endl;
	}
}

void vector3d_DenialTest(vector3d v) {
	vector3d res = -v;
	if (fabs(res[0] + v[0]) > 0.00001 || fabs(res[1] + v[1]) > 0.00001 || fabs(res[2] + v[2]) > 0.00001) {
		std::cerr << "Deniel error" << std::endl;
	}
}

void vector3d_BoolTest(vector3d v) {
	vector3d res = !v;
	if ((res[0] == !v[0]) || (res[1] == !v[1]) || (res[2] == !v[2])) {
		std::cerr << "Bool error" << std::endl;
	}
}

void test_vector3d() {
	vector3d v_null, v_value1(2.5, 8, -4.8), v_value2(-5, 6.12, 11), res;

	vector3d_AdditionTest(v_value1, v_value2);
	vector3d_SubstructionTest(v_value1, v_value2);
	vector3d_MultiTest(v_value1, 1.5);
	std::cout << "Division by zero - ";
	vector3d_DivTest(v_value1, 0);
	vector3d_DivTest(v_value1, 2);
	vector3d_DenialTest(v_value1);
	vector3d_BoolTest(v_null);
	vector3d_BoolTest(v_value1);

}

	std::ostream& operator <<(std::ostream & os, const vector3d & v);
