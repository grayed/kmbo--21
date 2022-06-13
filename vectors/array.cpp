#include <iostream>
#include "array.h"
using namespace std;



template<size_t Dimensions>
ostream& operator <<(ostream& os, const Vector<Dimensions>& v) {
    os << "{ " << v[0];
    for (size_t i = 1; i < Dimensions; i++)
        os << ", " << v[i];
    return os << " }";
}

ostream& operator <<(ostream& os, const Vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}




int main() {
    Vector3d v1(1, 2, 3), v2(1), v3 = v1 + v2, v4 = v2 * 6, v5 = v1 - v2, v6 = -v1;

    Vector3d srVect = v1 & v2;

    cout << v3 << endl;
    cout << v4 << endl;
    cout << v5 << endl;
    cout << v6 << endl;
    cout << srVect;
    bool a = test_vector3d(v3, v2, v5, '-');
    cout << a<<endl;
    bool b = test_vector3d(v2, 6, v4, '*');
    cout << b<<endl;
    bool c = test_vector3d(v1, v6, '-');
    cout << c << endl;

  









}

