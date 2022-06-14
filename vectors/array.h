#include <iostream>

using namespace std;

class Vector3d {
    float data[3];
public:
    Vector3d() { data[2] = data[1] = data[0] = 0; }

    Vector3d(float value) { data[2] = data[1] = data[0] = value; }

    Vector3d(float a1, float a2, float a3) {
        data[0] = a1;
        data[1] = a2;
        data[2] = a3;
    }

    float operator[](int index) const {
        cerr << "const" << index << endl;
        return data[index];
    }

    float &operator[](int index) {
        cerr << "non-const" << index << endl;
        return data[index];
    }

    Vector3d operator+(const Vector3d &v2) {
        Vector3d v3;
        v3[0] = data[0] + v2[0];
        v3[1] = data[1] + v2[1];
        v3[2] = data[2] + v2[1];
        return v3;
    }

    Vector3d operator*(const float value) {
        Vector3d v3;
        v3[0] = data[0] * value;
        v3[1] = data[1] * value;
        v3[2] = data[2] * value;
        return v3;
    }

    Vector3d operator-(const Vector3d &v2) {
        Vector3d v3;
        v3[0] = data[0] - v2[0];
        v3[1] = data[1] - v2[1];
        v3[2] = data[2] - v2[2];
        return v3;
    }

    Vector3d operator/(const float value) {
        if (value == 0) {
            cout << "Value is not correct\n";
            return 0;
        }
        Vector3d v3;
        v3[0] = data[0] / value;
        v3[1] = data[1] / value;
        v3[2] = data[2] / value;
        return v3;
    }

    Vector3d operator-() { return Vector3d(-data[0], -data[1], -data[2]); }

    Vector3d operator!() {
        if (data[0] == data[1] == data[2] == 0) {
            return Vector3d(1, 1, 1);
        }
        return Vector3d(0, 0, 0);
    }
};

ostream &operator<<(ostream &os, const Vector3d &v) {
    return os << "{  " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

bool test_vector3d() {
    Vector3d v1(4, 4, 4);
    Vector3d v2(1, 1, 1);
    Vector3d v3;
    Vector3d v4(0, 0, 0);
    v3 = v1 + v2;
    if ((v3[0] != 5) || (v3[1] != 5) || (v3[2] != 5)) {
        cerr << "The addition operation does not work correctly with data - v1(4,4,4), v2(1,1,1)";
        return false;
    }
    v3 = v1 - v2;
    if ((v3[0] != 3) || (v3[1] != 3) || (v3[2] != 3)) {
        cerr << "The subtract operation does not work correctly with data - v1(4,4,4), v2(1,1,1)";
        return false;
    }
    v3 = v1 * 3;
    if ((v3[0] != 12) || (v3[1] != 12) || (v3[2] != 12)) {
        cerr << "The operation of multiplying by a number does not work correctly with data - v1(4,4,4), 3";
        return false;
    }
    v3 = v1 / 4;
    if ((v3[0] != 1) || (v3[1] != 1) || (v3[2] != 1)) {
        cerr << "The operation of division by a number does not work correctly with data - v1(5,5,5), 4";
        return false;
    }
    v3 = -v1;
    if ((v3[0] != -4) || (v3[1] != -4) || (v3[2] != -4)) {
        cerr << "Unary minus does not work correctly with data - v1(5,5,5)";
        return false;
    }
    v3 = !v1;
    if ((v3[0] != 0) || (v3[1] != 0) || (v3[2] != 0)) {
        cerr << "Unary ! works incorrectly with data - v4(0,0,0)";
        return false;
    }
    v3 = !v4;
    if ((v3[0] != 1) || (v3[1] != 1) || (v3[2] != 1)) {
        cerr << "Unary ! works incorrectly with data - v1(1,1,1)";
        return false;
    }
    return true;
}

int main() {
    if (test_vector3d()) {
        return 0;
    } else {
        return 1;
    }
}