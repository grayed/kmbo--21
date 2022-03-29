#include <iostream>
#include "vector.h"

using namespace std;

class vector3d {
	float data[3];
public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
	// lvalue = rvalue
	float  operator[] (int idx) const { return data[idx]; }
	float& operator[] (int idx)       { return data[idx]; } // подразумевает изменение
	vector3d operator +(const vector3d& other) const { 
		return vector3d(data[0] + other.data[0], data[1] + other.data[1], other.data[2] + data[2]);
	}
	//friend ostream& operator <<(ostream& os, const vector3d& v);
};

vector3d operator -(const vector3d& v1, const vector3d& v2) {
	return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
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
