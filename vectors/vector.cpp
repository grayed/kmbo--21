#include <iostream>
#include "vector.h"

using namespace std;

class Vector3d {
private:
	double data[3];

public:
	Vector3d() { data[2] = data[1] = data[0] = 0; }
	Vector3d(double value) { data[2] = data[1] = data[0] = value; }
	Vector3d(double a1, double a2, double a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	double  operator[](int idx) const { return data[idx]; }
	double& operator[](int idx)       { return data[idx]; }

	Vector3d operator - () const {
		return Vector3d(-data[0], -data[1], -data[2]);
	}

	Vector3d operator ! () const {
		if (data[0] == data[1] == data[2] == 0) {
			return Vector3d(1, 1, 1);
		}
		else {
			return Vector3d(0, 0, 0);
		}
	}

	Vector3d operator + (const Vector3d other) const {
		return Vector3d(data[0] + other.data[0], data[1] + other.data[1], data[2] + other.data[2]);
	}

	Vector3d operator * (double n) const {
		return Vector3d(data[0] * n, data[1] * n, data[2] * n);
	}

	Vector3d operator / (double n) const {
		return Vector3d(data[0] / n, data[1] / n, data[2] / n);
	}
	

	friend ostream& operator << (ostream& os, const Vector3d& v);
};

Vector3d operator - (const Vector3d first, const Vector3d second) {
	return first + (-second);
}

ostream& operator << (ostream& os, const Vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

bool test_vector3d() {
	Vector3d v1 = Vector3d(62, 88, 71);
	Vector3d v2 = Vector3d(66, 52, 43);

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	bool error = false;

	cout << "v1 + v2 = " << v1 + v2 << endl;
	if((v1 + v2)[0] != v1[0] + v2[0] || (v1 + v2)[1] != v1[1] + v2[1] || (v1 + v2)[2] != v1[2] + v2[2]) {
		cerr << "invalid, should be " << "{ " << v1[0] + v2[0] << " " << v1[1] + v2[1] << " " << v1[2] + v2[2] << " }" << endl;
		error = true;
	}

	cout << "v1 - v2 = " << v1 - v2 << endl;
	if((v1 - v2)[0] != v1[0] - v2[0] || (v1 - v2)[1] != v1[1] - v2[1] || (v1 - v2)[2] != v1[2] - v2[2]) {
		cerr << "invalid, should be " << "{ " << v1[0] - v2[0] << " " << v1[1] - v2[1] << " " << v1[2] - v2[2] << " }" << endl;
		error = true;
	}

	cout << "v1 * 3 = " << v1 * 3 << endl;
	if((v1 * 3)[0] != v1[0] * 3 || (v1 * 3)[1] != v1[1] * 3 || (v1 * 3)[2] != v1[2] * 3) {
		cerr << "invalid, should be " << "{ " << v1[0] * 3 << " " << v1[1] * 3 << " " << v1[2] * 3 << " }" << endl;
		error = true;
	}

	cout << "v1 / 3 = " << v1 / 3 << endl;
	if((v1 / 3)[0] != v1[0] / 3 || (v1 / 3)[1] != v1[1] / 3 || (v1 / 3)[2] != v1[2] / 3) {
		cerr << "invalid, should be " << "{ " << v1[0] / 3 << " " << v1[1] / 3 << " " << v1[2] / 3 << " }" << endl;
		error = true;
	}

	return error;
}

int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	//vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
	//cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;

	printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
	printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
	printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
	printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
	printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
	printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
	printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));

	return 0;
}
