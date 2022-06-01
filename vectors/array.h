#pragma once

#include <iostream>

template<size_t Dimensions>
class Vector {
    float data[Dimensions];
public:
    Vector(float value = 0) { for (size_t i = 0; i < Dimensions; i++) data[i] = value;  }
    float  operator[] (size_t index) const { return data[index]; }
    float& operator[] (size_t index)       { return data[index]; }

    Vector operator+ (Vector<Dimensions> vector_1) {
    Vector<Dimensions> vector;
    for (size_t i = 0; i < Dimensions; i++) vector[i] = vector_1[i] + data[i]; 
    return vector;
    }
};

template<size_t Dimensions>
Vector<Dimensions> operator* (Vector<Dimensions> vector_1, float scalar) {
    Vector<Dimensions> vector;
    for (size_t i = 0; i < Dimensions; i++) vector[i] = vector_1[i] * scalar; 
    return vector;
}

template<size_t Dimensions>
Vector<Dimensions> operator* (float scalar, Vector<Dimensions> vector_1) {
    Vector<Dimensions> vector;
    for (size_t i = 0; i < Dimensions; i++) vector[i] = vector_1[i] * scalar; 
    return vector;
}