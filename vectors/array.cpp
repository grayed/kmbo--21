#include "array.h"

using namespace std;

// Написать шаблонные функции:
//   1. operator + (реализация внутри класса)
//   2. operator * (вектор на скаляр и скаляр на вектор; реализация вне класса)
//   3. Нахождение среднего для двух векторов (реализация вне класса)

template<size_t Dimensions>
Vector<Dimensions> middle(Vector<Dimensions> vector_1, Vector<Dimensions> vector_2) {
    Vector<Dimensions> vector;
    for (int i = 0; i < Dimensions; ++i) vector[i] = (vector_1[i] + vector_2[i]) / 2;
    return vector;
}

template<size_t Dimensions>
ostream& operator <<(ostream& os, const Vector<Dimensions>& v) {
    os << "{ " << v[0];
    for (size_t i = 1; i < Dimensions; i++)
        os << ", " << v[i];
    return os << " }";
}

int main() {
    Vector<7> vector_1 = Vector<7>(7);
    Vector<7> vector_2 = Vector<7>(3);
    Vector<7> vector_3 = Vector<7>(2);
    
    cout << "vector_1 + vector_2 = " << vector_1 + vector_2 << endl; 
    cout << "vector_3 * 5 = " << vector_3 * 5 << endl; 
    cout << "middle of vector_1, vector_2 = " << middle(vector_1, vector_2) << endl; 

	return 0;
}
