#include <iostream>
#include <iso646.h>

using namespace std;

class vector3d {
    float data[3];
public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
	// lvalue = rvalue
	float  operator[](int idx) const { return data[idx]; }
	float& operator[](int idx) { return data[idx]; }

};


ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

vector3d operator + (const vector3d& v1, const vector3d& v2) { return vector3d(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]); }
vector3d operator - (const vector3d& v1, const vector3d& v2) { return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]); }
vector3d operator * (const vector3d& v1, const float x) { return vector3d(v1[0] * x, v1[1] * x, v1[2] * x); }
vector3d operator / (const vector3d& v1, const float x) { return vector3d(v1[0] / x, v1[1] / x, v1[2] / x); }
const vector3d operator -(const vector3d& v1) { return vector3d(-v1[0], -v1[1], -v1[2]); }
const vector3d operator !(const vector3d& v1) {
	if (v1[0] == 0 and v1[1] == 0 and v1[2] == 0) { return vector3d(1, 1, 1); }
	else return vector3d(0, 0, 0);
}

bool test_vector3d() {
	vector3d v1(10, 85, 110);
	vector3d v2(20, 65, 90);

	cout << "v1: " << "10, 85, 110" << endl;
	cout << "v2: " << "20, 65, 90"  << endl;

	bool ERROR = false;

	cout << "v1 + v2 = " << v1 + v2 << endl;
	if ((v1 + v2)[0] != v1[0] + v2[0] or (v1 + v2)[1] != v1[1] + v2[1] or (v1 + v2)[2] != v1[2] + v2[2]) {
		cerr << "invalid, should be " << "{ " << v1[0] + v2[0] << " " << v1[1] + v2[1] << " " << v1[2] + v2[2] << " }" << endl;
		ERROR = true;
	}
	cout << "v1 - v2 = " << v1 - v2 << endl;
	if ((v1 - v2)[0] != v1[0] - v2[0] or (v1 - v2)[1] != v1[1] - v2[1] or (v1 - v2)[2] != v1[2] - v2[2]) {
		cerr << "invalid, should be " << "{ " << v1[0] - v2[0] << " " << v1[1] - v2[1] << " " << v1[2] - v2[2] << " }" << endl;
		ERROR = true;
	}
	cout << "v1 * 5 = " << v1 * 5 << endl;
	if ((v1 * 5)[0] != v1[0] * 5 or (v1 * 5)[1] != v1[1] * 5 or (v1 * 5)[2] != v1[2] * 5) {
		cerr << "invalid, should be " << "{ " << v1[0] * 5 << " " << v1[1] * 5 << " " << v1[2] * 5 << " }" << endl;
		ERROR = true;
	}
	cout << "v1 / 5 = " << v1 / 5 << endl;
	if ((v1 / 5)[0] != v1[0] / 5 || (v1 / 5)[1] != v1[1] / 5 || (v1 / 5)[2] != v1[2] / 5) {
		cerr << "invalid, should be " << "{ " << v1[0] / 5 << " " << v1[1] / 5 << " " << v1[2] / 5 << " }" << endl;
		ERROR = true;
	}
	return ERROR;
}

int main(int argc, char** argv) { return test_vector3d(); }
