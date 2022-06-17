#include "array.h"


std::ostream& operator <<(std::ostream& os, const Vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}

template<size_t Dimensions>
std::ostream& operator <<(std::ostream& os, const Vector<Dimensions>& v) {
    os << "{ " << v[0];
    for (size_t i = 1; i < Dimensions; i++)
        os << ", " << v[i];
    return os << " }";
}

int main() {
    Vector<12> v1;
    v1[1] = v1[2] = 54;
    Vector<12> v2 = v1;
    std::cout << v2 << std::endl;
    return 0;
}