#pragma once
#include <iostream>
#include "vector.h"

using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	if (test_vector3d()) cout << " " << 1;
	else cout << " " << 0;
	test_vector3d();
}