#pragma once
#include <iostream>
using namespace std;

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
    float  operator[] (int index) const { cerr << "const" << index << endl; return data[index]; }
    float& operator[] (int index) { cerr << "non-const" << index << endl; return data[index]; }

    Vector3d operator +(const Vector3d& these) { // оператор сложения 
        Vector3d result;
        for (int i = 0; i < 3; i++) {
            result[i] = this->data[i] + these.data[i];
        }
        return result;
    }

    Vector3d operator -(const Vector3d& these) { // оператор вычитания
        Vector3d result;
        for (int i = 0; i < 3; i++) {
            result[i] = this->data[i] - these.data[i];
        }
        return result;
    }



};

template<size_t Dimensions>
class Vector {
    float data[Dimensions];
public:
    Vector(float value = 0) { for (size_t i = 0; i < Dimensions; i++) data[i] = value; }
    float  operator[] (size_t index) const { return data[index]; }
    float& operator[] (size_t index) { return data[index]; }
};

// Написать шаблонные функции:
//   1. operator + (реализация внутри класса)
//   2. operator * (вектор на скаляр и скаляр на вектор; реализация вне класса)
//   3. Нахождение среднего для двух векторов (реализация вне класса)


Vector3d operator *(const Vector3d& pr_vect, const int numb) {  // оператор умножения на скаляр
    Vector3d result;
    for (int i = 0; i < 3; i++) {
        result[i] = pr_vect[i] * numb;
    }
    return result;
}

Vector3d operator *(const int numb, const Vector3d& pr_vect) {  // оператор умножения скаляра на вектор
    Vector3d result;
    for (int i = 0; i < 3; i++) {
        result[i] = numb * pr_vect[i];
    }
    return result;
}


Vector3d operator /(const Vector3d& pr_vect, const int numb) {  // оператор деления на скаляр
    Vector3d result;
    for (int i = 0; i < 3; i++) {
        result[i] = pr_vect[i] / numb;
    }
    return result;
}

Vector3d operator -(const Vector3d& pr_vect) {  // оператор деления на скаляр
    Vector3d result;
    for (int i = 0; i < 3; i++) {
        result[i] = -1 * (pr_vect[i]);
    }
    return result;
}

Vector3d operator &(const Vector3d& pr_vect1, const Vector3d& pr_vect2) {  // оператор взятия среднего двух векторов
    Vector3d result;
    for (int i = 0; i < 3; i++) {
        result[i] = (pr_vect1[i] + pr_vect2[i]) / 2;
    }
    return result;
}


bool test_vector3d(Vector3d v1, Vector3d v2, Vector3d vres, char oper) { // тест для сложения и вычитания
    bool check = true;
    switch (oper) {
    case '+':
        for (int i = 0; i < 3; i++) {
            if (v1[i] + v2[i] != vres[i]) check = false;           
        }
        return check;

    case '-':
        for (int i = 0; i < 3; i++) {
            if ((v1[i] - v2[i] != vres[i])) check = false;
        }
        return check;
    default:
        break;
    }  
}

bool test_vector3d(Vector3d v,int numb, Vector3d vres, char oper) { // тест для умножения и деления
    bool check = true;
    switch (oper) {
    case '*':
        for (int i = 0; i < 3; i++) {
            if (numb*v[i]!= vres[i]) check = false;
        }
        return check;

    case '/':
        for (int i = 0; i < 3; i++) {
            if ((v[i] /numb  != vres[i])) check = false;
        }
        return check;
    default:
        break;
    }
}

bool test_vector3d(Vector3d v, Vector3d vres, char oper) { // тест для унарного минуса
    bool check = true;
    switch (oper) {
    case '-':
        for (int i = 0; i < 3; i++) {
            if ((-1)*v[i] != vres[i]) check = false;
        }
        return check;

    
    default:
        break;
    }
}



