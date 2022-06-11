#include <iostream>
#include <cmath>

using namespace std;

class Vector3d {
public:

    float data[3];

    Vector3d() { data[2] = data[1] = data[0] = 0; }
    Vector3d(float value) { data[2] = data[1] = data[0] = value; }
    Vector3d(float b1, float b2, float b3) { data[0] = b1; data[1] = b2; data[2] = b3; }

    float operator[](int idx) const { return data[idx]; }
    float& operator[](int idx) { return data[idx]; }

    Vector3d operator +(const Vector3d& v2) const {
        return Vector3d(data[0] + v2[0], data[1] + v2[1], data[2] + v2[2]);
    };
    Vector3d operator -(const Vector3d& v2) {
        return Vector3d(data[0] - v2[0], data[1] - v2[1], data[2] - v2[2]);
    };
    Vector3d operator *(const float k) {
        return Vector3d(data[0] * k, data[1] * k, data[2] * k);
    };
    Vector3d operator /(const float k) {
        return Vector3d(data[0] / k, data[1] / k, data[2] / k);
    };
    Vector3d operator-() {
        return Vector3d(-data[0], -data[1], -data[2]);
    };
    Vector3d operator !() {
        if ((data[0] == 0) && (data[1] == 0) && (data[2] == 0))
            return Vector3d(0);
        else
            return Vector3d(1);
    };
};

ostream& operator <<(ostream& os, const Vector3d& v) {
    return os << "{" << v[0] << "," << v[1] << "," << v[2] << "}";
};

bool test_Vector3d() {
    Vector3d v1;
    Vector3d v2(2, 4, 6);
    Vector3d v3(8, 5, 11);
    Vector3d v4 = v2 + v3, v5 = v3 - v2, v6 = v2 * 3, v7 = v2 / 2, v8 = -v3, v9 = !v1, v10 = !v2;
    if (v4.data[0] != v2.data[0]+ v3.data[0] || v4.data[1] != v2.data[1] + v3.data[1] || v4.data[2] != v2.data[2] + v3.data[2]) {
        cerr << "Сложение векторов выполнено неверно" << endl;
        return 1;
    }
    if (v5.data[0] != v3.data[0] - v2.data[0] || v5.data[1] != v3.data[1] - v2.data[1] || v5.data[2] != v3.data[2] - v2.data[2]) {
        cerr << "Вычитание векторов выполнено неверно" << endl;
        return 1;
    }
    if (v6.data[0] != v2.data[0]*3 || v6.data[1] != v2.data[1] * 3 || v6.data[2] != v2.data[2] * 3) {
        cerr << "Умножение на скаляр выполнено неверно" << endl;
        return 1;
    }
    if (v7.data[0] != v2.data[0] /2 || v7.data[1] != v2.data[1] / 2 || v7.data[2] != v2.data[2] / 2) {
        cerr << "Деление на скаляр выполнено неверно" << endl;
        return 1;
    }
    if (v8.data[0] != -v3.data[0] || v8.data[1] != -v3.data[1] || v8.data[2] != -v3.data[2]) {
        cerr << "Инвертирование знака выполнено неверно" << endl;
        return 1;
    }
    if (v9.data[0] != 1 || v9.data[1] != 1 || v9.data[2] != 1) {
        cerr << "Логическое отрицание выполнено неаверно" << endl;
        return 1;
    }
    if (v10.data[0] != 0 || v10.data[1] != 0 || v10.data[2] != 0) {
        cerr << "Логическое отрицание выполнено неаверно" << endl;
        return 1;
    }
    return 0;
}

