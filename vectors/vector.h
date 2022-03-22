#pragma once
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	if (test_vector3d()) cout << " " << 0;
	else cout << " " << 1;
}