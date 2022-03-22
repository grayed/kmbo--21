#include "vector.h"
#include <iostream>
using namespace std; 
int main() {
	Vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	Vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v2 * 0.5f, v7 = -v7,v8=!v8,v9= v2/2.f;
	cout << "v4: " << v4 << "\n";
	cout << "v5: " << v5 << "\n";
	cout << "v6: " << v6 << "\n";
	cout << "v7: " << v7 << "\n";
	cout << "v8: " << v8 << "\n";
	cout << "v9: " << v9 << "\n";
	cout << test_all_operators()<<"\n";
	
	return 0;
}


