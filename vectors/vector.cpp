#include <iostream>
#include <locale.h>
using namespace std;

class vector3d {
	float data[3];
public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1; data[1] = a2; data[2] = a3; }

	float operator[] (int idx) const { return data[idx]; }
	float& operator[] (int idx) { return data[idx]; }
	vector3d operator +(const vector3d& other) {
		return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
	}

	vector3d operator-(const vector3d& other) {
		return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
	}

	vector3d operator*(const float value) {
		return vector3d(data[0] * value, data[1] * value, data[2] * value);
	}

	vector3d operator/(const float value) {
		return vector3d(data[0] / value, data[1] / value, data[2] / value);
	}

	vector3d operator-() { return vector3d(-data[0], -data[1], -data[2]); }

	vector3d operator!()
	{
		if ((data[0] == 0) && (data[1] == 0) && (data[2] == 0))
		{
			return vector3d(data[0] = 1, data[1] = 1, data[2] = 1);
		}
		else
			return vector3d(data[0] = 0, data[1] = 0, data[2] = 0);
	}
};
ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

bool test_vector3d() {
	vector3d v1;
	vector3d v2(3, 3, 3);
	vector3d v3(4, 4, 4);
	vector3d v4 = v2 + v3, v5 = v3 - v2, v6 = v2 * 4, v7 = v3 / 2, v8 = -v3, v9 = !v3, v10 = !v1;

	if ((v4[0] != 7) || (v4[1] != 7) || (v4[2] != 7)) {
		cerr << "ќпераци€ сложени€ векторов повела себ€ неверно с данными - v2(3,3,3), v3(4,4,4)";
		return false;
	}
	
	if ((v5[0] != 1) || (v5[1] != 1) || (v5[2] != 1)) {
		cerr << "ќпераци€ разности векторов повела себ€ неверно с данными - v3(4,4,4), v2(3,3,3)";
		return false;
	}
	
	if ((v6[0] != 12) || (v6[1] != 12) || (v6[2] != 12)) {
		cerr << "ќпераци€ умножени€ вектора на скал€р повела себ€ неверно с данными - v2(3,3,3), 4";
		return false;
	}
	
	if ((v7[0] != 2) || (v7[1] != 2) || (v7[2] != 2)) {
		cerr << "ќпераци€ делени€ вектора на скал€р повела себ€ неверно с данными - v3(4,4,4), 2";
		return false;
	}
	
	if ((v8[0] != -4) || (v8[1] != -4) || (v8[2] != -4)) {
		cerr << "ќпераци€ инвертировани€ знака повела себ€ неверно с данными  - v3(4,4,4)";
		return false;
	}
	
	if ((v9[0] != 0) || (v9[1] != 0) || (v9[2] != 0)) {
		cerr << "”нарный ! повел себ€ неверно с данными - v3(4,4,4)";
		return false;
	}
	
	if ((v10[0] != 1) || (v10[1] != 1) || (v10[2] != 1)) {
		cerr << "”нарный ! повел себ€ неверно с данными - v1(0,0,0)";
		return false;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "RUS");
	if (test_vector3d() == true)
	{
		return 0;
	}
	else 
	{
		return 1;
	};
}
