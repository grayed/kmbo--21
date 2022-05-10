#pragma once
#include <String>
#include <iostream>

class Vector3d {
    float data[3];
public:
    Vector3d() { data[2] = data[1] = data[0] = 0; }
    Vector3d(float value) { data[2] = data[1] = data[0] = value; }
    Vector3d(float value1, float value2, float value3) {
        data[0] = value1;
        data[1] = value2;
        data[2] = value3;
    }
    float  operator[] (int index) const { std::cerr << "const" << index << std::endl; return data[index]; }
    float& operator[] (int index)       { std::cerr << "non-const" << index << std::endl; return data[index]; }
    //бинарная операция +
    Vector3d operator +(Vector3d arr) {
        Vector3d rez;
        for (int i = 0; i < 3; ++i) {
            rez[i] = data[i] + arr[i];
        }
        return rez;
    }
    //бинарная операция -
    Vector3d operator -(Vector3d v1) {
        Vector3d rez;
        for (int i = 0; i < 3; ++i) {
            rez[i] = data[i] - v1[i];
        }
        return rez;
    }
    //унарная операция -
    Vector3d operator -() {
        Vector3d rez;
        for (int i = 0; i < 3; i++) {
            rez[i] = data[i] * (-1);
        }
        return rez;
    }
};

//бинарная операция умножения на скаляр
Vector3d operator *(Vector3d v1, float numb) {
    Vector3d rez;
    for (int i = 0; i < 3; i++) {
        rez[i] = v1[i] * numb;
    }
    return rez;
}

Vector3d operator *(float numb, Vector3d v1) {
    Vector3d rez;
    for (int i = 0; i < 3; i++) {
        rez[i] = numb * v1[i];
    }
    return rez;
}
//бинарная операция деление на скаляр
Vector3d operator /(Vector3d v1, float numb) {
    Vector3d rez;
    if (numb == 0) return v1;
    for (int i = 0; i < 3; i++) {
        rez[i] = v1[i] / numb;
    }
    return rez;
}

Vector3d operator /(float numb, Vector3d v1) {
    Vector3d rez;
    if (numb == 0) return v1;
    for (int i = 0; i < 3; i++) {
        rez[i] = v1[i] / numb;
    }
    return rez;
}

//унарная операция !
Vector3d operator !(Vector3d v) {
    Vector3d v0(0, 0, 0), v1(1, 1, 1);
    if ((v[0] == 0) && (v[1] == 0) && (v[2] == 0)) return v1;
    if ((v[0] == 1) && (v[1] == 1) && (v[2] == 1)) return v0;
}

//функции проверки
bool test_vector3d(Vector3d v1, Vector3d v2, Vector3d reply, char oper) {
    bool chec = true;
    switch (oper)
    {
    case  '+':
        for (int i = 0; i < 3; i++)
        {
            if ((v1[i] + v2[i]) != reply[i]) chec = false;
        }
        return chec;
    case '-':
        for (int i = 0; i < 3; i++)
        {
            if ((v1[i] - v2[i]) != reply[i]) chec = false;
        }
        return chec;
    default:
        break;
    }
}

bool test_vector3d(Vector3d v1, float numb, Vector3d reply, char oper) {
    bool chec = true;
    switch (oper)
    {
    case '*':
        for (int i = 0; i < 3; i++)
        {
            if ((v1[i] * numb) != reply[i]) chec = false;
        }
        return chec;
    case '/':
        for (int i = 0; i < 3; i++)
        {
            if ((v1[i] / numb) != reply[i]) chec = false;
        }
        return chec;
    default:
        break;
    }
}
bool test_vector3d(Vector3d v, Vector3d otv, char oper)
{
    if (oper == '!') {
        bool chec = true;
        Vector3d v1 = !v;
        for (int i = 0; i < 3; i++) {
            if (v1[i] != otv[i]) chec = false;
        }
        return chec;
    }
}
