#pragma once
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
