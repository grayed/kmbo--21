#include "array.h"
<<<<<<< HEAD

template<size_t dim>
vector<dim> average(const vector<dim> a, const vector<dim> b) {
    vector<dim> temp;
    for (int i = 0; i < dim; ++i) temp[i] = (a[i] + b[i]) / 2;
    return temp;
=======

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
>>>>>>> 1d6eac8230aca4ab7bde98408de994c59fe11542
}

int main() {
    vector<5> vec_1;

    for (int i = 0; i < vec_1.size(); ++i) vec_1[i] = (float)i;

    vector<5> vec_2 = vec_1 * 3;
    vector<5> vec_3 = vec_1 * 4;

    std::cout << "vec_1 * 3: " << vec_2 << std::endl;
    std::cout << "vec_1 * 4: " << vec_3 << std::endl;
    std::cout << "average of vec_2 and vec_3: " << average(vec_2, vec_3) << std::endl;

    return 0;
}
