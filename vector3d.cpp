#include <iostream>
#include "vector.h"
#include <cmath>

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

int main(int argc, char** argv) {
    vector3d v1, v2(12), v3(1, 3, 8);
    v1[2] = 54;
    //vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
    //cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;
    class Vec {
    public:
        float data[3];
        Vec() { data[2] = data[1] = data[0] = 0; }
        Vec(float value) { data[2] = data[1] = data[0] = value; }
        Vec(float x, float y, float z) { data[0] = x; data[1] = y; data[2] = z; }
        float operator[](int idx) const { return data[idx]; }
        float& operator[](int idx) { return data[idx]; }
        Vec operator +(const Vec& other) const {
            return Vec(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
        };
        Vec operator -(const Vec& other) {
            return Vec(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
        };
        Vec operator *(const float value) {
            return Vec(data[0] * value, data[1] * value, data[2] * value);
        };
        Vec operator /(const float value) {
            return Vec(data[0] / value, data[1] / value, data[2] / value);
        };
        Vec operator-() {
            return Vec(-data[0], -data[1], -data[2]);
        };
        Vec operator !() {
            if ((data[0] == 0) && (data[1] == 0) && (data[2] == 0))
                return Vec(data[0] == 1, data[1] == 1, data[2] == 1);
            else
                return Vec(data[0] == 0, data[1] == 0, data[2] == 0);
        };
    };

    printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
    printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
    printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
    printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
    printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
    printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
    printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));
    ostream& operator <<(ostream & os, const Vec3 & v);
    {
        return os << "{" << v[0] << "," << v[1] << "," << v[2] << "}";
    };

    return 0;
    bool test_Vec() {
        Vec v1;
        Vec v2(6, 6, 6);
        Vec v3(4, 4, 4);
        Vec v4 = v2 + v3, v5 = v3 - v2, v6 = v2 * 5, v7 = v2 / 2, v8 = -v3, v9 = !v2, v10 = !v1;
        if (v4.data[0] != 10 || v4.data[1] != 10 || v4.data[2] != 10) {
            cerr << "addition Error" << endl;
            return 1;
        }
        if (v5.data[0] != 2 || v5.data[1] != 2 || v5.data[2] != 2) {
            cerr << " subtraction Error" << endl;
            return 1;
        }
        if (v6.data[0] != 30 || v6.data[1] != 30 || v6.data[2] != 30) {
            cerr << "  multiplication Error" << endl;
            return 1;
        }
        if (v7.data[0] != 3 || v7.data[1] != 3 || v7.data[2] != 3) {
            cerr << "division Error" << endl;
            return 1;
        }
        if (v8.data[0] != -4 || v8.data[1] != -4 || v8.data[2] != -4) {
            cerr << "inversion Error" << endl;
            return 1;
        }
        if (v9.data[0] != 0 || v9.data[1] != 0 || v9.data[2] != 0) {
            cerr << "Logic Error" << endl;
            return 1;
        }
        if (v10.data[0] != 1 || v10.data[1] != 1 || v10.data[2] != 1) {
            cerr << "Logic Error" << endl;
            return 1;
        }
    }