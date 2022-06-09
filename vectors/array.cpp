#include "array.h"

template<size_t dim>
vector<dim> average(const vector<dim> a, const vector<dim> b) {
    vector<dim> temp;
    for (int i = 0; i < dim; ++i) temp[i] = (a[i] + b[i]) / 2;
    return temp;
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
