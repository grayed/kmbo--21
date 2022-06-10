#include "array.h"

using namespace std;

// Написать шаблонные функции:
//   1. operator + (реализация внутри класса)
//   2. operator * (вектор на скаляр и скаляр на вектор; реализация вне класса)
//   3. Нахождение среднего для двух векторов (реализация вне класса)

ostream& operator <<(ostream& os, const Vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

template<size_t Dimensions>
ostream& operator <<(ostream& os, const Vector<Dimensions>& v) {
    os << "{ " << v[0];
    for (size_t i = 1; i < Dimensions; i++)
        os << ", " << v[i];
    return os << " }";
}

template<size_t Dimensions>
Vector<Dimensions> Vector<Dimensions>::operator +(const Vector<Dimensions> v) const{
    Vector res_v;
    for (int i = 0; i < Dimensions; ++i) { res_v[i] = data[i] + v[i]; }
    return res_v;
}

template<size_t Dimensions>
Vector<Dimensions> operator *(const Vector<Dimensions> v, float n) {
    Vector<Dimensions> res_v;
    for (int i = 0; i < Dimensions; ++i) { res_v[i] = v[i] * n; }
    return res_v;
}

template<size_t Dimensions>
Vector<Dimensions> avg(const Vector<Dimensions> v1, const Vector<Dimensions> v2) {
    Vector<Dimensions> res_v;
    for (int i = 0; i < Dimensions; ++i) { res_v[i] = (v1[i] + v2[i]) / 2; }
    return res_v;
}

template<size_t Dimensions>
Vector<Dimensions> operator *(float n, const Vector<Dimensions> v) { return v * n; }

int main() {
    Vector<12> v1;
    v1[1] = v1[2] = 54;
    Vector<12> v2 = v1;
    v2[1] += 1;
    cout << v1 << endl;
    cout << v2 << endl;

    cout << v1 + v2 << endl;
    cout << v1 * 3 << endl;
    cout << 4 * v1 << endl;

    cout << avg(v1, v2);

	return 0;
}
