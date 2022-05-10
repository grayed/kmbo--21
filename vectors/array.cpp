#include "array.h"
#include<iostream>

using namespace std;

// Написать шаблонные функции:
//   1. operator + (реализация внутри класса)
//   2. operator * (вектор на скаляр и скаляр на вектор; реализация вне класса)
//   3. Нахождение среднего для двух векторов (реализация вне класса)

ostream& operator <<(ostream& os, const Vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

int main() {
    Vector3d v(1, 1, 1), v1(4), v2 = v1+v, v3(-4, 2, 6);
    double n = 1.5;
    cout << v2 << " " << n * v2 << " " << -v3;
    cout << "\n";
    cout << !v;
    //Vector3d b(1, 1, 1), b1(1, 1, 1), otv(0, 0, 0);
    //cout << test_vector3d(b, b1, otv,  '-');
    cout << "\n";
    Vector3d c(1, 1, 1), otv1(0, 0, 0);
    int d = 5;
    //cout << test_vector3d(c, otv1, '!');
    //cout << v - v1;
	return 0;
}
