#include <iostream>
#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) 
{
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

int main(int argc, char** argv)
{
    vector3d v1, v2(12), v3(1, 3, 8);
    v1[2] = 54;
    //vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
    //cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;

    printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
    printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
    printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
    printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
    printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
    printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
    printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));

    return 0;
}

class Vector3d 
{
    float data[3];
public:
    Vector3d() { data[2] = data[1] = data[0] = 0; }
    Vector3d(float value) { data[2] = data[1] = data[0] = value; }
    Vector3d(float a1, float a2, float a3) { data[0] = a1; data[1] = a2; data[2] = a3; }
    float operator[](int idx) { return data[idx]; }
    float& operator[](int idx) const { return data[idx]; }
    friend int main(int argc, char** argv);
}

vector3d operator + (const vector3d & v1, const vector3d & v2) 
{
    return vector3d(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

vector3d operator - (const vector3d & v1, const vector3d & v2) 
{
    return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

vector3d operator * (const vector3d & v1, const float x) 
{
    return vector3d(v1[0] * x, v1[1] * x, v1[2] * x);
}

vector3d operator / (const vector3d & v1, const float x) 
{
    return vector3d(v1[0] / x, v1[1] / x, v1[2] / x);
}

const vector3d operator -(const vector3d & v1) 
{
    return vector3d(-v1[0], -v1[1], -v1[2]);
}

const vector3d operator !(const vector3d & v1) 
{
    if (v1[0] == 0 && v1[1] == 0 && v1[2] == 0) 
    {
        return vector3d(1, 1, 1);
    }
    else
        return vector3d(0, 0, 0);
}

bool sum_test(vector3d& v1, vector3d& v2)
{
    bool flag = true;
    vector3d v3 = v1 + v2;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] + v2[0])) && (v3[1] == (v1[1] + v2[1])) && (v3[2] == (v1[2] + v2[2])))
            cerr << "Сложение векторов сделано верно " << endl;
        else {
            cerr << "Сложение векторов сделано неверно" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool sub_test(vector3d& v1, vector3d& v2) 
{
    bool flag = true;
    vector3d v3 = v1 - v2;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] - v2[0])) && (v3[1] == (v1[1] - v2[1])) && (v3[2] == (v1[2] - v2[2])))
            cerr << "Вычитание векторов сделано верно" << endl;
        else {
            cerr << "Вычитание векторов сделано неверно" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool mult_test(vector3d& v1, float& c1) 
{
    bool flag = true;
    vector3d v3 = v1 * c1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] * c1)) && (v3[1] == (v1[1] * c1)) && (v3[2] == (v1[2] * c1)))
            cerr << "Умножение вектора на скаляр выполнено верно" << endl;
        else {
            cerr << "Умножение вектора на скаляр выполнено неверно" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool div_test(vector3d& v1, float& c1) 
{
    bool flag = true;
    vector3d v3 = v1 / c1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] / c1)) && (v3[1] == (v1[1] / c1)) && (v3[2] == (v1[2] / c1)))
            cerr << "Деление вектора на число выполнено верно" << endl;
        else {
            cerr << "Деление вектора на число выполнено неверно" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool minus_test(vector3d& v1) 
{
    bool flag = true;
    vector3d v3 = -v1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == -v1[0]) && (v3[1] == -v1[1]) && (v3[2] == -v1[2]))
            cerr << "Инвертирование знака выполнено верно" << endl;
        else {
            cerr << "Инвертирование знака выполнено неверно" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool unar!_test() 
{
    bool flag = true;
    vector3d v1 = (0, 0, 0);
    vector3d v3 = !v1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == 1) && (v3[1] == 1) && (v3[2] == 1))
            cerr << "Логическое отрицание выполнено верно" << endl;
        else {
            cerr << "Логическое отрицание выполнено неверно" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool test_vector3d(vector3d v1, vector3d v2, float c1)
{
    bool flag = true;
    sum_test(v1, v2);
    sub_test(v1, v2);
    mult_test(v1, c1);
    div_test(v1, c1);
    minus_test(v1);
    unar!_test();
    return flag;
}
