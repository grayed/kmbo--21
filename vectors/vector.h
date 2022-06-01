#pragma once

#include <iostream>

class Vector3d
{
public:
    Vector3d();

    Vector3d(const float& value);

    Vector3d(const float& a1, const float& a2, const float& a3);

    float operator[](const int& index) const;

    float& operator[](const int& index);

    Vector3d operator+(const Vector3d& other);

    Vector3d operator-(const Vector3d& other);

    Vector3d operator*(const float& value);

    Vector3d operator/(const float& value);

    Vector3d operator-();

    Vector3d operator!();

private:
    float _data[3];
};

std::ostream& operator<<(std::ostream& os, const Vector3d& vector);