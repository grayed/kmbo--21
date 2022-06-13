#include "vector.h"

bool test_vector3() {
    auto vec_1 = vector3(1, 2, 3);
    auto vec_2 = vector3(3, 2, 1);

    bool check_1 = (vec_1 + vec_2) == vector3(4);
    bool check_2 = (vec_2 - vec_1) == vector3(2, 0, -2);

    auto vec_3 = vector3(3);

    bool check_3 = (vec_3 * 3) == vector3(9);
    bool check_4 = (vec_3 / 3) == vector3(1);
    bool check_5 = -vec_3 == vector3(-3);

    auto vec_4 = vector3(0);

    bool check_6 = !vec_4 == vector3(1);
    bool check_7 = !vec_1 == vector3(0);

    if (!check_1)
        std::cerr << "Invalid result of the operator+ (vector3 lhs, vector3 rhs), lhs value: " << vec_1 << ", rhs value: " << vec_2 << std::endl;
    if (!check_2)
        std::cerr << "Invalid result of the operator- (vector3 lhs, vector3 rhs), lhs value: " << vec_2 << ", rhs value: " << vec_1 << std::endl;
    if (!check_3)
        std::cerr << "Invalid result of the operator* (vector3 lhs, float rhs), lhs value: " << vec_3 << ", rhs value: " << 3 << std::endl;
    if (!check_4)
        std::cerr << "Invalid result of the operator/ (vector3 lhs, float rhs), lhs value: " << vec_3 << ", rhs value: " << 3 << std::endl;
    if (!check_5)
        std::cerr << "Invalid result of the operator- (vector3 v), v value: " << vec_3 << std::endl;
    if (!check_6)
        std::cerr << "Invalid result of the operator! (vector3 v), v value: " << vec_4 << std::endl;
    if (!check_7)
        std::cerr << "Invalid result of the operator! (vector3 v), v value: " << vec_1 << std::endl;

    return check_1 && check_2 && check_3 && check_4 && check_5 && check_6 && check_7;
}

int main() {
    return !test_vector3()
