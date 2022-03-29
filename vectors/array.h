#pragma once
#include < iostream>
using namespace std;

class Vector3d {
    float data[3];
public:
    Vector3d() { data[2] = data[1] = data[0] = 0; }
    Vector3d(float value) { data[2] = data[1] = data[0] = value; }
    float  operator[] (int index) const { cerr << "const" << index << endl; return data[index]; }
    float& operator[] (int index) { cerr << "non-const" << index << endl; return data[index]; }
};

template<size_t Dimensions>
class Vector {
    float data[Dimensions];
public:
    Vector(float value = 0) { for (size_t i = 0; i < Dimensions; i++) data[i] = value; }
    float  operator[] (size_t index) const { return data[index]; }
    float& operator[] (size_t index) { return data[index]; }

template<size_t Dimensions>
Vector operator +(Vector vec) {
    Vector vector;
    for (size_t i = 0; i < Dimensions;i++) {
        vector[i] = vec[i] + Vector.data[i];
    }
    return vector;
}
};

template<size_t Dimensions>
Vector<Dimensions> operator *(Vector<Dimensions> vec, float value) {
    Vector<Dimensions> vector;
    for (size_t i = 0;i < Dimensions;i++) {
        vector[i] = vec[i] * value;
    }
    return vector;
}

//   3. Нахождение среднего для двух векторов (реализация вне класса)

ostream& operator <<(ostream& os, const Vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

template<size_t Dimensions>
ostream& operator <<(ostream& os, const Vector<Dimensions>& v) {
    os << "{ " << v[0];
    for (size_t i = 1; i < Dimensions; i++)
        os << ", " << v[i];
    return os << " }";
}