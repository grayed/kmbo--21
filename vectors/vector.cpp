#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

vector3d operator-(const vector3d& v) {
	vector3d res_v;

	for (int i = 0; i < 3; ++i) {
		res_v[i] = -v[i];
	}

	return res_v;
}

vector3d operator +(const vector3d& v1, const vector3d& v2) {
	vector3d res_v;

	for (int i = 0; i < 3; ++i) {
		res_v[i] = v1[i] + v2[i];
	}

	return res_v;
}

vector3d operator -(const vector3d& v1, const vector3d& v2) { return v1 + (-v2); }

vector3d operator *(const vector3d& v, float n) {
	vector3d res_v;

	for (int i = 0; i < 3; ++i) {
		res_v[i] = v[i] * n;
	}

	return res_v;
}

vector3d operator * (float n, const vector3d& v) { return v * n; }

vector3d operator /(const vector3d& v, float n) { return v * (1/n); }

vector3d operator /(float n, const vector3d& v) { return v / n; }

vector3d operator !(const vector3d& v) {
	return (v[0] == v[1] && v[1] == v[2] && v[2] == 0 ? vector3d(1, 1, 1) : vector3d(0, 0, 0));
}

bool operator !=(const vector3d& v1, const vector3d& v2) {
	bool flag = false;

	for (int i = 0; i < 3; ++i) {
		if (v1[i] != v2[i]) {
			flag = true;
			break;
		}
	}

	return flag;
}

bool test_vector3d() {
	vector3d v1 = vector3d(71, 0, 71);
	vector3d v2 = vector3d(74, 37, 5);

	bool flag = false;
	vector3d right;

	right[0] = 71 + 74;
	right[1] = 0 + 37;
	right[2] = 71 + 5;
	if ((v1 + v2) != right) {
		flag = true;
		cerr << "v1 + v2 = " << v1 + v2 << ", should be " << right << endl;
	}

	right[0] = 71 - 74;
	right[1] = 0 - 37;
	right[2] = 71 - 5;
	if ((v1 - v2) != right) {
		flag = true;
		cerr << "v1 - v2 = " << v1 - v2 << ", should be " << right << endl;
	}

	right[0] = 71 * 2.2;
	right[1] = 0 * 2.2;
	right[2] = 71 * 2.2;
	if (v1 * 2.2 != right) {
		flag = true;
		cerr << "v1 * 2.2 = " << v1 * 2.2 << ", should be " << right << endl;
	}

	right[0] = 71 / 2.2;
	right[1] = 0 / 2.2;
	right[2] = 71 / 2.2;
	if (v1 / 2.2 != right) {
		flag = true;
		cerr << "v1 / 2.2 = " << v1 / 2.2 << ", should be " << right << endl;
	}

	right[0] = -71;
	right[1] = -0;
	right[2] = -71;
	if (-v1 != right) {
		flag = true;
		cerr << "-v1 = " << -v1 << ", should be " << right << endl;
	}

	right[0] = 0;
	right[1] = 0;
	right[2] = 0;
	if (!v1 != right) {
		flag = true;
		cerr << "!v1 = " << !v1 << ", should be " << right << endl;
	}

	return !flag;
}

int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f, v7 = v1 / 0.5f, v8 = -v3, v9 = !v3;
	cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl << "v7: " << v7 << endl << "v8: " << v8 << endl << "v9: " << v9 << endl;

	printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
	printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
	printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
	printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
	printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
	printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
	printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));

	return !test_vector3d();
}
