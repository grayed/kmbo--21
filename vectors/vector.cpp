#include <iostream>
#include "vector.h"

class vector3d {
    float data[3];

    public:
        vector3d() { data[0] = data[1] = data[2] = 0; }
        vector3d(float value) { data[0] = data[1] = data[2] = value; }
        vector3d(float x, float y, float z) { data[0] = x; data[1] = y; data[2] = z; }

        float operator[](int ind) const {

            if (ind > 2 || ind < 0) throw std::overflow_error("index out of bounds");

            return data[ind]; 
        }

        float& operator[](int ind) {

            if (ind > 2 || ind < 0) throw std::overflow_error("index out of bounds");

            return data[ind]; 
        }

        vector3d operator +(const vector3d& other) { return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
        vector3d operator -(const vector3d& other) { return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
        vector3d operator *(const float value) { return vector3d(data[0] * value, data[1] * value, data[2] * value); }
};

std::ostream& operator <<(std::ostream& os, const vector3d& v) {
    return os << "{" << v[0] << ", " << v[1] << ", " << v[2] << "}";
}

int main() {
    vector3d v1, v2(12), v3(1, 3, 8);
    v1[2] = 54;
    vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << "v5: " << v5 << std::endl;
    std::cout << "v6: " << v6 << std::endl;
}