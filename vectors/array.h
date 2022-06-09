#pragma once

#include <iostream>

class Vector3d {
    float data[3];
public:
    Vector3d() { data[2] = data[1] = data[0] = 0; }
    Vector3d(float value) { data[2] = data[1] = data[0] = value; }
    float  operator[] (int index) const { std::cerr << "const" << index << std::endl; return data[index]; }
    float& operator[] (int index)       { std::cerr << "non-const" << index << std::endl; return data[index]; }
};

template<size_t Dimensions>
class Vector {
    float data[Dimensions];
public:
    Vector(float value = 0) { for (size_t i = 0; i < Dimensions; i++) data[i] = value;  }
    float  operator[] (size_t index) const { return data[index]; }
    float& operator[] (size_t index)       { return data[index]; }

    Vector operator +(const Vector v) const;
};

template<size_t Dimensions>
Vector<Dimensions> operator *(const Vector<Dimensions> v, float n);

template<size_t Dimensions>
Vector<Dimensions> avg(const Vector<Dimensions> v1, const Vector<Dimensions> v2);