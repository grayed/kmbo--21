#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

int main(int argc, char** argv) {
	vector3d v1, v2(12.45), v3(1, 3.2, 8);
	v1[2] = 54;
	vector3d res1 = v1 + v2, res2 = v3 - v1, res3 = v3 * 1.2, res4 = v2 / 2.5, res5 = -v3, res6 = !v1;

	cout << "res1 = " << res1 << '\n' << "res2 = " << res2 << '\n' << "res3 = " << res3 << '\n'
		<< "res4 = " << res4 << '\n' << "res5 = " << res5 << '\n' << "res6 = " << res6 << '\n';
 
	test_vector3d();
	

	

	return 0;
}
