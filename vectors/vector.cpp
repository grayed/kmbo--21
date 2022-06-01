#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

bool test_vector3d() {
	bool test_plus, test_minus, test_multiply, test_divide, test_unary_minus, test_negate_1, test_negate_2;
	vector3d vector_1 = vector3d(1, 2, 3);
	vector3d vector_2 = vector3d(4, 5, 6);
	vector3d vector_3 = vector3d(0);
	test_plus = (vector_1 + vector_2) == vector3d (5, 7, 9);
	test_minus = (vector_1 - vector_2) == vector3d (-3);
	test_multiply = (vector_1 * 3) == vector3d (3, 6, 9);
	test_divide = (vector_2 / 2) == vector3d (2, 2.5, 3);
	test_unary_minus = (-vector_1) == vector3d (-1, -2, -3);
	test_negate_1 = (!vector_1) == vector3d (0);
	test_negate_2 = (!vector_3) == vector3d (1);
	if (!test_plus) cerr << "Not correct value operator+, vector_1: " << vector_1 << ", vector_2: " << vector_2 << endl;
	if (!test_minus) cerr << "Not correct value operator-, vector_1: " << vector_1 << ", vector_2: " << vector_2 << endl;
	if (!test_multiply) cerr << "Not correct value operator*, vector_1: " << vector_1 << ", scalar: 3 " << endl;
	if (!test_divide) cerr << "Not correct value operator/, vector_1: " << vector_1 << " scalar: 2 " << endl;
	if (!test_unary_minus) cerr << "Not correct value operator-, vector_1: " << vector_1 << endl;
	if (!test_negate_1) cerr << "Not correct value operator!, vector_1: " << vector_1 << endl;
	if (!test_negate_2) cerr << "Not correct value operator!, vector_3: " << vector_3 << endl;
	return false;
}

int main(int argc, char** argv) {
	return !test_vector3d();
}
