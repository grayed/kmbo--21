#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class vector3d
{
public:
    float data[3];

public:
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3)
    {
        data[0] = a1;
        data[1] = a2;
        data[2] = a3;
    }

    float operator[](int index) const { return data[index]; }
    float& operator[](int index) { return data[index]; }

    vector3d operator+(const vector3d& other) { return vector3d(data[0] + other[0], data[1] + other[1], data[2] + other[2]); }
    vector3d operator-(const vector3d& other) { return vector3d(data[0] - other[0], data[1] - other[1], data[2] - other[2]); }
    vector3d operator*(const float value) { return vector3d(data[0] * value, data[1] * value, data[2] * value); }
    vector3d operator/(const float value) { return vector3d(data[0] / value, data[1] / value, data[2] / value); }
    vector3d operator-() { return vector3d(-data[0], -data[1], -data[2]); }
    vector3d operator!()
    {
        if ((data[0] == 0) && (data[1] == 0) && (data[2] == 0))
        {
            return vector3d(data[0] = 1, data[1] = 1, data[2] = 1);
        }
        else
            return vector3d(data[0] = 0, data[1] = 0, data[2] = 0);
    }
};
ostream& operator<<(ostream& os, const vector3d& v)
{
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

bool test_vector3d()
{
    vector3d v1;
    vector3d v2(4, 4, 4);
    vector3d v3(2, 2, 2);
    vector3d v4 = v3 + v2, v5 = v2 - v3, v6 = v2 * 5, v7 = v2 / 2, v8 = -v3, v9 = !v3, v10 = !v1;
    if (v4.data[0] != 6 || v4.data[1] != 6 || v4.data[2] != 6)
    {
        cerr << "Ошибка в операции сложения векторов";
        return 1;
    }
    if (v5.data[0] != 2 || v5.data[1] != 2 || v5.data[2] != 2)
    {
        cerr << "Ошибка в операции разности векторов";
        return 1;
    }
    if (v6.data[0] != 20 || v6.data[1] != 20 || v6.data[2] != 20)
    {
        cerr << "Ошибка в операции умножения вектора на скаляр";
        return 1;
    }
    if (v7.data[0] != 2 || v7.data[1] != 2 || v7.data[2] != 2)
    {
        cerr << "Ошибка в операции деления вектора на скаляр";
        return 1;
    }
    if (v8.data[0] != -2 || v8.data[1] != -2 || v8.data[2] != -2)
    {
        cerr << "Ошибка в операции инвертирования знака вектора";
        return 1;
    }
    if (v9.data[0] != 0 || v9.data[1] != 0 || v9.data[2] != 0)
    {
        cerr << "Ошибка в логическом преобразовании";
        return 1;
    }
    if (v10.data[0] != 1 || v10.data[1] != 1 || v10.data[2] != 1)
    {
        cerr << "Ошибка в логическом преобразовании";
        return 1;
    }
    return 0;
}