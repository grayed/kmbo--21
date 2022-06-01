#include "vector.h"

Vector3d::Vector3d()
{
    _data[2] = _data[1] = _data[0] = 0;
}

Vector3d::Vector3d(const float& value)
{
    _data[2] = _data[1] = _data[0] = value;
}

Vector3d::Vector3d(const float& a1, const float& a2, const float& a3)
{
    _data[0] = a1;
    _data[1] = a2;
    _data[2] = a3;
}

float Vector3d::operator[](const int& index) const
{
    return _data[index];
}

float& Vector3d::operator[](const int& index)
{
    return _data[index];
}

Vector3d Vector3d::operator+(const Vector3d& other)
{
    return {_data[0] + other[0], _data[1] + other[1], _data[2] + other[2]};
}

Vector3d Vector3d::operator-(const Vector3d& other)
{
    return {_data[0] - other[0], _data[1] - other[1], _data[2] - other[2]};
}

Vector3d Vector3d::operator*(const float& value)
{
    return {_data[0] * value, _data[1] * value, _data[2] * value};
}

Vector3d Vector3d::operator/(const float& value)
{
    return {_data[0] / value, _data[1] / value, _data[2] / value};
}

Vector3d Vector3d::operator-()
{
    return {-_data[0], -_data[1], -_data[2]};
}

Vector3d Vector3d::operator!()
{
    if (_data[0] == _data[1] && _data[1] == _data[2])
        if (_data[0] == 0)
            return {1, 1, 1};
    return {0, 0, 0};
}

std::ostream& operator<<(std::ostream& out, const Vector3d& vector)
{
    return out << "{ " << vector[0] << ", " << vector[1] << ", " << vector[2] << " }";
}


bool test_vector3d()
{

    struct vec
    {
        float x, y, z;
    };

    vec a = {1, 2, 3}, b = {4, 5, 6};

    Vector3d vec1(a.x, a.y, a.z), vec2(b.x, b.y, b.z);

    bool error = false;

    if (vec1[0] + vec2[0] != a.x + b.x ||
        vec1[1] + vec2[1] != a.y + b.y ||
        vec1[2] + vec2[2] != a.z + b.z) {
        std::cerr << "Vector3d + Vector3d: "
                  << "{ " << vec1[0] + vec2[0] << ", " << vec1[1] + vec2[1] << ", " << vec1[2] + vec2[2] << " } != "
                  << "{ " << a.x + b.x << ", " << a.y + b.y << ", " << a.z + b.z << " }\n";
        error = true;
    }

    if (vec1[0] - vec2[0] != (vec1 - vec2)[0] ||
        vec1[1] - vec2[1] != (vec1 - vec2)[1] ||
        vec1[2] - vec2[2] != (vec1 - vec2)[2]) {
        std::cerr << "Vector3d - Vector3d: "
                  << "{ " << vec1[0] - vec2[0] << ", " << vec1[1] - vec2[1] << ", " << vec1[2] - vec2[2] << " } != "
                  << "{ " << a.x - b.x << ", " << a.y - b.y << ", " << a.z - b.z << " }\n";
        error = true;
    }

    if (vec1[0] * 4 != a.x * 4 ||
        vec1[1] * 4 != a.y * 4 ||
        vec1[2] * 4 != a.z * 4) {
        std::cerr << "Vector3d * const: "
                  << "{ " << vec1[0] * 4 << ", " << vec1[1] * 4 << ", " << vec1[2] * 4 << " } != "
                  << "{ " << a.x * 4 << ", " << a.y * 4 << ", " << a.z * 4 << " }\n";
        error = true;
    }

    if (vec1[0] / 4 != a.x / 4 ||
        vec1[1] / 4 != a.y / 4 ||
        vec1[2] / 4 != a.z / 4) {
        std::cerr << "Vector3d / const: "
                  << "{ " << vec1[0] / 4 << ", " << vec1[1] / 4 << ", " << vec1[2] / 4 << " } != "
                  << "{ " << a.x / 4 << ", " << a.y / 4 << ", " << a.z / 4 << " }\n";
        error = true;
    }

    if ((-vec1)[0] != -a.x ||
        (-vec1)[1] != -a.y ||
        (-vec1)[2] != -a.z) {
        std::cerr << "-Vector3d: "
                  << "{ " << -vec1[0] << ", " << -vec1[1] << ", " << -vec1[2] << " } != "
                  << "{ " << -a.x << ", " << -a.y << ", " << -a.z << " }\n";
        error = true;
    }

    if (a.x == a.y && a.y == a.z && a.x == 0) {
        Vector3d v = !vec1;
        if (v[0] != v[1] || v[1] != v[2] || v[0] != 1) {
            std::cerr << "!Vector3d:"
                      << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " } != "
                      << "{ " << 1 << ", " << 1 << ", " << 1 << " }\n";
            error = true;
        }
        else if (v[0] != v[1] || v[1] != v[2] || v[0] != 1) {
            std::cerr << "!Vector3d:"
                      << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " } != "
                      << "{ " << 0 << ", " << 0 << ", " << 0 << " }\n";
            error = true;
        }
    }

    return error;
}

int main()
{
    std::cout << test_vector3d << std::endl;
    return EXIT_SUCCESS;
}