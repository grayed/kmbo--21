#include <iostream>


class vector3d {
    float data[3];

    public:
        vector3d() { data[0] = data[1] = data[2] = 0; }
        vector3d(float value) { data[0] = data[1] = data[2] = value; }
        vector3d(float x, float y, float z) { data[0] = x; data[1] = y; data[2] = z; }

        float operator[](int ind) const {

            if (ind > 2 || ind < 0) throw std::out_of_range("index out of bounds");

            return data[ind]; 
        }

        float& operator[](int ind) {

            if (ind > 2 || ind < 0) throw std::out_of_range("index out of bounds");

            return data[ind]; 
        }

        vector3d operator +(const vector3d& other) { return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
        vector3d operator -(const vector3d& other) { return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
        vector3d operator *(const float value) { return vector3d(data[0] * value, data[1] * value, data[2] * value); }
        vector3d operator /(const float value) { return vector3d(data[0] / value, data[1] / value, data[2] / value); }
        vector3d operator -() { return vector3d(-data[0], -data[1], -data[2]); }
        vector3d operator !() {
            if (data[0] != 0 ||  data[1] != 0 || data[2] != 0) {
                return vector3d(0);
            } else {
                return vector3d(1);
            }
        } 
};

std::ostream& operator <<(std::ostream& os, const vector3d& v) {
    return os << "{" << v[0] << ", " << v[1] << ", " << v[2] << "}";
}

bool vectorsEquals(vector3d v1, vector3d v2) {
    return v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2];
}

bool checkPlus() {
    vector3d v1(1), v2(1, 2, 3), exp(2, 3 ,4);
    if (!vectorsEquals(v1 + v2, exp)) {
        std::cerr << "plus works wrong! expected: " << exp << " but got: " << v1 + v2 << std::endl;
        return false;
    }

    return true;
}

bool checkMinus() {
    vector3d v1(4, 5, 6), v2(1, 2, 3), exp(3);
    if (!vectorsEquals(v1 - v2, exp)) {
        std::cerr << "minus works wrong! expected: " << exp << " but got: " << v1 - v2 << std::endl;
        return false;
    }

    return true;
}

bool checkMul() {
    vector3d v1(1, 2, 3), exp(4, 8, 12);
    if (!vectorsEquals(v1 * 4, exp)) {
        std::cerr << "mul works wrong! expected: " << exp << " but got: " << v1 * 4 << std::endl;
        return false;
    }

    return true;
}

bool checkDiv() {
    vector3d v1(4, 2, 12), exp(1, 0.5, 3);
    if (!vectorsEquals(v1 / 4, exp)) {
        std::cerr << "div works wrong! expected: " << exp << " but got: " << v1 / 4 << std::endl;
        return false;
    }

    return true;
}

bool checkUnaryMinus() {
    vector3d v1(4, 2, 12), exp(-4, -2, -12);
    if (!vectorsEquals(-v1, exp)) {
        std::cerr << "unary minus works wrong! expected: " << exp << " but got: " << -v1 << std::endl;
        return false;
    }

    return true;
}

bool checkInv() {
    vector3d v1(4, 2, 12), exp1;
    if (!vectorsEquals(!v1, exp1)) {
        std::cerr << "inv works wrong! expected: " << exp1 << " but got: " << !v1 << std::endl;
        return false;
    }

    vector3d v2(0), exp2(1);
    if (!vectorsEquals(!v2, exp2)) {
        std::cerr << "inv works wrong! expected: " << exp2 << " but got: " << !v2 << std::endl;
        return false;
    }

    return true;
}

bool test_vector3d() {
    return checkPlus() && checkMinus() && checkMul() && checkDiv() && checkUnaryMinus() && checkInv();
}

int main() {
    bool testResult = test_vector3d();
    std::cout << "Everything works " << (testResult ? "fine" : "terrible") << "!" << std::endl;
    return testResult ? 1 : 0;
}