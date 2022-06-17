#pragma once

#include <iostream>
#include <typeinfo>

class vector3d {
    float data[3];

public:
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

    float& operator[](int idx) { return data[idx]; }
    float  operator[](int idx) const { return data[idx]; }

    vector3d operator+(vector3d other) {
        return vector3d((data[0] + other[0]), (data[1] + other[1]), (data[2] + other[2]));
    }

    vector3d operator-(vector3d other) {
        return vector3d((data[0] - other[0]), (data[1] - other[1]), (data[2] - other[2]));
    }

    vector3d operator*(float value) {
        return vector3d((data[0] * value), (data[1] * value), (data[2] * value));
    }

    vector3d operator/(float value) {
        if (value == 0) {
            std::cerr << "Indefinite division by zero" ;
        }
        else {
            return vector3d((data[0] / value), (data[1] / value), (data[2] / value));
        }
    }

    vector3d operator-() {
        return vector3d(-data[0], -data[1], -data[2]);
    }

    vector3d operator!() {
        if (data == 0) {
            return vector3d((data[0] = 1), (data[1] = 1), (data[2] = 1));
        }
        else {
            return vector3d((data[0] = 0), (data[1] = 0), (data[2] = 0));
        }
    }


    friend int main(int argc, char** argv);
};

bool vector3d_1(vector3d v1, vector3d v2) { /*Addition*/
    vector3d res = v1 + v2;
    if (fabs(res[0] - (-2.5f)) > 0.00001 || fabs(res[1] - 14.12f) > 0.00001 || fabs(res[2] - 6.2f) > 0.00001) {
        std::cout << "error" << std::endl;
        return false;
    }
    return true;
}

bool vector3d_2(vector3d v1, vector3d v2) { /*Substruction*/
    vector3d res = v1 - v2;
    if (fabs(res[0] - 7.5f) > 0.00001 || fabs(res[1] - 1.88f) > 0.00001 || fabs(res[2] - (-15.8f)) > 0.00001) {
        std::cerr << "error" << std::endl;
        return false;
    }
    return true;
}

bool vector3d_3(vector3d v1, float scal) {
    vector3d res = v1 * scal;
    if (fabs(res[0] - 3.75f) > 0.00001 || fabs(res[1] - 12) > 0.00001 || fabs(res[2] - (-7.2f)) > 0.00001) {
        std::cerr << "error" << std::endl;
        return false;
    }
    return true;
}

bool vector3d_4(vector3d v1, float scal) { /*Div*/
    vector3d res = v1 / scal;
    if (fabs(res[0] - 1.25f) > 0.00001 || fabs(res[1] - 4) > 0.00001 || fabs(res[2] - (-2.4f)) > 0.00001) {
        std::cerr << "error" << std::endl;
        return false;
    }
    return true;
}

bool vector3d_5(vector3d v) { /*Denial*/
    vector3d res = -v;
    if (fabs(res[0] + v[0]) > 0.00001 || fabs(res[1] + v[1]) > 0.00001 || fabs(res[2] + v[2]) > 0.00001) {
        std::cerr << "error" << std::endl;
        return false;
    }
    return true;
}

bool vector3d_6(vector3d v) { /*Bool*/
    vector3d res = !v;
    if ((res[0] == !v[0]) || (res[1] == !v[1]) || (res[2] == !v[2])) {
        std::cerr << "error" << std::endl;
        return false;
    }
    return true;
}

bool test_vector3d() {
    vector3d v_null, v_value1(2.5, 8, -4.8), v_value2(-5, 6.12, 11);
    bool res1, res2, res3, res4, res5, res6, res7, res8;
    res1 = vector3d_1(v_value1, v_value2);
    res2 = vector3d_2(v_value1, v_value2);
    res3 = vector3d_3(v_value1, 1.5);
    std::cout << "zero - ";
    res4 = vector3d_4(v_value1, 0);
    res5 = vector3d_4(v_value1, 2);
    res6 = vector3d_5(v_value1);
    res7 = vector3d_6(v_null);
    res8 = vector3d_6(v_value1);

    if (res1 && res2 && res3 && res4 && res5 && res6 && res7 && res8)
        return true;
    return false;
}

std::ostream& operator <<(std::ostream & os, const vector3d & v);
