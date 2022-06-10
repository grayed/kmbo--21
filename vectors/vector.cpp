#include <iostream>
#include "vector.h"

bool test_vector3d() {
	bool error = false;
	vector3d v1;
	vector3d v2(1);
	vector3d v3(1, 2, 3);
	vector3d v4 = v3 + v2;
	vector3d v5 = v3 - v2;
	vector3d v6 = v3 * 10;
	vector3d v7 = v3 / 10;
	vector3d v8 = -v2;
	vector3d v9 = !v1;
	if (v4[0] != v3[0] + v2[0] || v4[1] != v3[1] + v2[1] || v4[2] != v3[2] + v2[2]) { std::cerr << "+ Error\n"; error = true; }
	if (v5[0] != v3[0] - v2[0] || v5[1] != v3[1] - v2[1] || v5[2] != v3[2] - v2[2]) { std::cerr << "- Error\n"; error = true; }
	if (v6[0] != v3[0] * 10 || v6[1] != v3[1] * 10 || v6[2] != v3[2] * 10) { std::cerr << "* Error\n"; error = true; }
	if (v7[0] != v3[0] / 10 || v7[1] != v3[1] / 10 || v7[2] != v3[2] / 10) { std::cerr << "/ Error\n"; error = true; }
	if (v8[0] != -1 || v8[1] != -1 || v8[2] != -1) { std::cerr << "-() Error\n"; error = true; }
	if (v9[0] != 1 || v9[1] != 1 || v9[2] != 1) { std::cerr << "! Error\n"; error = true; }
	if (error)
		return false;
	return true;
}

int main() {
	return test_vector3d();
}