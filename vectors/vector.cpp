#include <iostream>
#include <cmath>

using namespace std;

class vector3d {
public:
	float data[3];
public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	float  operator [](int index) const { return data[index]; }
	float& operator [](int index)       { return data[index]; }

};

vector3d operator+ (const vector3d& v1, const vector3d& v2) {
	return vector3d((v1.data[0] + v2.data[0]), (v1.data[1] + v2.data[1]), (v1.data[2] + v2.data[2]));
}
vector3d operator- (const vector3d& v1, const vector3d& v2) {
	return vector3d((v1.data[0] - v2.data[0]), (v1.data[1] - v2.data[1]), (v1.data[2] - v2.data[2]));
}
float operator* (const vector3d& v, float a) {
	float sum = v.data[0] + v.data[1] + v.data[2];
	return sqrt(sum) * a;
}

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v2 * 0.5f;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;
	cout << "v6: " << v6 << endl;
	return 0;
}


