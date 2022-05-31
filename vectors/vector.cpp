#pragma once

#include <iostream>
#include "vectors.h"

using namespace std;



template<size_t Dimensions>
ostream& operator <<(ostream& os, const Vector<Dimensions>& v) {
    os << "{ " << v[0];
    for (size_t i = 1; i < Dimensions; i++)
        os << ", " << v[i];
    return os << " }";
}


template<size_t Dimensions>
bool test_vector(Vector<Dimensions>(&Arr)[5], Vector<Dimensions> v1, Vector<Dimensions> v2, float n)
{   
    bool Res = 0;
    bool t = true;

    cout << v1 << endl;
    cout << v2 << endl;


    for (int i = 0; i < 5; i++)
    {
            switch (i) {
                case 0:
                    for (size_t j = 0; j < Dimensions; j++)
                    {
                        if (Arr[i][j] != v1[j] + v2[j])
                        {
                            t = false;
                        }

                    }

                    if (t)
                    {
                        cerr << "Сумма: верно" << endl;
                    }
                    else {
                        cerr << "Сумма: неверно" << endl;
                        Res = 1;
                    }
                    break;

                case 1:
                    for (size_t j = 0; j < Dimensions; j++)
                    {
                        if (Arr[i][j] != v1[j] - v2[j])
                        {
                            t = false;
                        }

                    }

                    if (t)
                    {
                        cerr << "Рзаность: верно" << endl;
                    }
                    else {
                        cerr << "Разность: неверно" << endl;
                        Res = 1;
                    }
                    break;

                case 2:
                    for (size_t j = 0; j < Dimensions; j++)
                    {
                        if (Arr[i][j] != v1[j] * n)
                        {
                            t = false;
                        }

                    }

                    if (t)
                    {
                        cerr << "Умножение на скалаяр: верно" << endl;
                    }
                    else {
                        cerr << "Умножение на скалаяр: верно" << endl;
                        Res = 1;
                    }
                    break;

                case 3:
                    for (size_t j = 0; j < Dimensions; j++)
                    {
                        if (Arr[i][j] != v1[j] / n)
                        {
                            t = false;
                        }

                    }

                    if (t)
                    {
                        cerr << "Деление на скалаяр: верно" << endl;
                    }
                    else {
                        cerr << "Деление на скалаяр: неверно" << endl;
                        Res = 1;
                    }
                    break;

                case 4:
                    for (size_t j = 0; j < Dimensions; j++)
                    {
                        if (Arr[i][j] != -v1[j])
                        {
                            t = false;
                        }

                    }

                    if (t)
                    {
                        cerr << "Инвертирование знака: верно" << endl;
                    }
                    else {
                        cerr << "Инвертирование знака: неверно" << endl;
                        Res = 1;
                    }
                    break;

            }

    }
    return Res;
}
    



int main() {
    Vector<5> v1(6);
    Vector<5> v2(2);
    Vector<5> Arr[5];
    Vector<6> v3;

    cout << v1 + v2 << endl;
    Arr[0] = v1 + v2;

    cout << v1 - v2 << endl;
    Arr[1] = v1 - v2;

    cout << v1 * 3 << endl;
    Arr[2] = v1 * 3;

    cout << 4 * v2 << endl;

    cout << v1 / 3 << endl;
    Arr[3] = v1 / 3;

    cout << 8 / v2 << endl;

    cout << -v2 << endl;
    Arr[4] = -v1;
    
    cout << !v3 << endl;

    cout << !v2 << endl;

    Vector<5> v4;
    v4 = average_value(v1, v2);
    cout << v4 << endl;

    bool res = test_vector(Arr, v1, v2, 3);

    cout << res;

    return 0;
}