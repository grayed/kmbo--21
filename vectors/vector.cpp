#include "vector.h"
#include <iostream>
using namespace std; 
int main() {
	Vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	Vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v2 * 0.5f, v7 = -v7,v8=!v8,v9= v2/2.f;
	cout << "v4: " << v4 << endl;
	cout << "v5: " << v5 << endl;
	cout << "v6: " << v6 << endl;
	cout << "v7: " << v7 << endl;
	cout << "v8: " << v8 << endl;
	cout << "v9: " << v9 << endl;
	
	return 0;
}


