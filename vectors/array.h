<<<<<<< HEAD
#include <iostream>

template<size_t dim>
class vector {
    float data[dim] {};
public:
    vector(float value = 0) { for (auto &d: data) d = value; }

    constexpr size_t size() { return dim; }

    float operator[] (int idx) const { return data[idx]; }
    float& operator[] (int idx) { return data[idx]; }

    vector operator+ (const vector<dim> &v) const {
        vector<dim> temp;
        for (int i = 0; i < dim; ++i) temp[i] = data[i] + v[i];
        return temp;
    }
};

template<size_t dim>
vector<dim> operator* (vector<dim> v, float f) {
    vector<dim> temp;
    for (int i = 0; i < dim; ++i) temp[i] = v[i] * f;
    return temp;
}

template<size_t dim>
vector<dim> operator* (float f, vector<dim> v) {
    return v * f;
}

template<size_t dim>
std::ostream& operator <<(std::ostream &os, const vector<dim> &v) {
    os << "{" << v[0];
    for (int i = 1; i < dim; ++i) os << ", " << v[i];
    return os << "}";
}
=======
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
};
>>>>>>> 1d6eac8230aca4ab7bde98408de994c59fe11542
