#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}


int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;

	//vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
	//cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;

	vector3d v = v2 + v3;
	cout << "v2 + v3 = " << v << endl;
	v = v2 - v3;
	cout << "v2 - v3 = " << v << endl;
	cout << "v3*10 = " << v3 * 10 << endl;
	cout << "v2/12 = " << v2 / 12 << endl;
	cout << "-v2 = " << -v2 << endl;
	v = (v2 / 12)*0;
	cout << "!v2 = " << !v << endl;
	cout << "!v3 = " << !v3 << endl;

	if (test(v2, v3, 5)) {
		return 0;
	}
	else {
		return 1;
	}
	/*
	printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
	printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
	printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
	printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
	printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
	printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
	printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));*/

}
