#pragma once

#include <iostream>
#include <sstream>

class vector3 {
    float data[3]{};
public:
    vector3() { data[0] = data[1] = data[2] = 0; }
    vector3(float value) { data[0] = data[1] = data[2] = value; }
    vector3(float x, float y, float z) { data[0] = x, data[1] = y, data[2] = z; }

    float& operator[](int idx) {
        if (idx > 2 || idx < 0)
            throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds for type vector3");

        return data[idx];
    }
    float operator[](int idx) const {
        if (idx > 2 || idx < 0)
            throw std::out_of_range("Index " + std::to_string(idx) + " out of bounds for type vector3");

        return data[idx];
    }

    vector3 operator+ (const vector3 &v);
    vector3 operator- (const vector3 &v);

    vector3 operator* (const float &f);
    vector3 operator/ (const float &f);

    vector3 operator- ();
    vector3 operator! ();

    bool operator ==(const vector3 &v) const;
};

std::ostream& operator <<(std::ostream& os, const vector3& v) {
    return os << "{" << v[0] << ", " << v[1] << ", " << v[2] << "}";
}

vector3 vector3::operator+(const vector3 &v) {
    return { data[0] + v[0], data[1] + v[1], data[2] + v[2] };
}

vector3 vector3::operator-(const vector3 &v) {
    return { data[0] - v[0], data[1] - v[1], data[2] - v[2] };
}

vector3 vector3::operator*(const float &f) {
    return { data[0] * f, data[1] * f, data[2] * f };
}

vector3 vector3::operator/(const float &f) {
    return { data[0] / f, data[1] / f, data[2] / f };
}

vector3 vector3::operator-() {
    return { -data[0], -data[1], -data[2] };
}

vector3 vector3::operator!() {
    return { float(!data[0] && !data[1] && !data[2]) };
}

bool vector3::operator==(const vector3 &v) const {
    return data[0] == v[0] && data[1] == v[1] && data[2] == v[2];
}
