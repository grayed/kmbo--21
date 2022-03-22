#include <iostream>

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
    Vector3d operator*(const float value) {
        return Vector3d(data[0] * value, data[1] * value, data[2] * value);
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

bool test_vector3d() {
    Vector3d vec1(2), vec2(1.5);
    bool error = false;

    cout << vec1 << "; " << vec2 << endl;

    cout << vec1 + vec2 << endl;
    if (vec1[0] + vec2[0] != (vec1 + vec2)[0] || vec1[1] + vec2[1] != (vec1 + vec2)[1] || vec1[2] + vec2[2] != (vec1 + vec2)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] + vec2[0] << ", " << vec1[1] + vec2[1] << ", " << vec1[2] + vec2[2] << " }" << endl; 
        error = true;
    }

    cout << vec1 - vec2 << endl;
    if (vec1[0] - vec2[0] != (vec1 - vec2)[0] || vec1[1] - vec2[1] != (vec1 - vec2)[1] || vec1[2] - vec2[2] != (vec1 - vec2)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] - vec2[0] << ", " << vec1[1] - vec2[1] << ", " << vec1[2] - vec2[2] << " }" << endl; 
        error = true;
    }

    cout << vec1 * 4 << endl;
    if (vec1[0] * 4 != (vec1 * 4)[0] || vec1[1] * 4 != (vec1 * 4)[1] || vec1[2] * 4 != (vec1 * 4)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] * 4 << ", " << vec1[1] * 4 << ", " << vec1[2] * 4 << " }" << endl; 
        error = true;
    }

    cout << vec1 / 5 << endl;
    if (vec1[0] / 5 != (vec1 / 5)[0] || vec1[1] / 5 != (vec1 / 5)[1] || vec1[2] / 5 != (vec1 / 5)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] / 5 << ", " << vec1[1] / 5 << ", " << vec1[2] / 5 << " }" << endl; 
        error = true;
    }

    cout << -vec1 << endl;
    if (-vec1[0] != (-vec1)[0] || -vec1[1] != (-vec1)[1] || -vec1[2] != (-vec1)[2]) {
        cerr << "Должно быть: " << "{ " << -vec1[0] << ", " << -vec1[1] << ", " << -vec1[2] << " }" << endl; 
        error = true;
    }

    cout << !vec1 << endl;
    if (!vec1[0] != (!vec1)[0] || !vec1[1] != (!vec1)[1] || !vec1[2] != (!vec1)[2]) {
        cerr << "Должно быть: " << "{ " << !vec1[0] << ", " << !vec1[1] << ", " << !vec1[2] << " }" << endl; 
        error = true;
    }

    return error;
}

int main() {
    cout << test_vector3d() << endl;
}