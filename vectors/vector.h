#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Vector3d {
private:
    float data[3];
public:
    Vector3d() {
        data[2] = data[1] = data[0] = 0;
    }
    Vector3d(float value) {
        data[2] = data[1] = data[0] = value;
    }
    Vector3d(float a1, float a2, float a3) {
        data[0] = a1;
        data[1] = a2;
        data[2] = a3;
    }
    float operator[](int index) const {return data[index];}
    float& operator[](int index)  {return data[index];}
    Vector3d operator+(const Vector3d& other) {
        return Vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
    }
    Vector3d operator-(const Vector3d& other) {
        return Vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
    }
    Vector3d operator/(const float value) {
        return Vector3d(data[0] / value, data[1] / value, data[2] / value);
    }

    Vector3d operator-() {
        return Vector3d(-data[0], -data[1], -data[2]);
    }
    Vector3d operator!() {
        return Vector3d(!data[0], !data[1], !data[2]);
    }
};

ostream& operator<<(ostream& os, const Vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

Vector3d average(Vector3d v1, Vector3d v2) {
    Vector3d v;
    for (int i = 0; i < 3; i++) v[i] = (v1[i] + v2[i]) / 2;
    return v;
}

Vector3d operator*(Vector3d vec, float value) {
    Vector3d temp;
    for (int i = 0; i < 3; i++) temp[i] = vec[i] * value;
    return temp;
}
Vector3d operator*(float value, Vector3d vec) {
    return vec * value;
}