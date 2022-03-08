#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

   
int main() {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v2 * 0.5f;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;
	cout << "v6: " << v6 << endl;
	return 0;
}


