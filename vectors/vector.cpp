#include "vector.h"

bool test_vector3d() {
    Vector3d vec1(2), vec2(1.5);
    bool error = false;

    cout << vec1 << "; " << vec2 << endl;

    cout << vec1 + vec2 << endl;
    if (vec1[0] + vec2[0] != (vec1 + vec2)[0] || vec1[1] + vec2[1] != (vec1 + vec2)[1] || vec1[2] + vec2[2] != (vec1 + vec2)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] + vec2[0] << ", " << vec1[1] + vec2[1] << ", " << vec1[2] + vec2[2] << " }" << endl; 
        error = true;
    }

    cout << vec1 - vec2 << endl;
    if (vec1[0] - vec2[0] != (vec1 - vec2)[0] || vec1[1] - vec2[1] != (vec1 - vec2)[1] || vec1[2] - vec2[2] != (vec1 - vec2)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] - vec2[0] << ", " << vec1[1] - vec2[1] << ", " << vec1[2] - vec2[2] << " }" << endl; 
        error = true;
    }

    cout << vec1 * 4 << endl;
    if (vec1[0] * 4 != (vec1 * 4)[0] || vec1[1] * 4 != (vec1 * 4)[1] || vec1[2] * 4 != (vec1 * 4)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] * 4 << ", " << vec1[1] * 4 << ", " << vec1[2] * 4 << " }" << endl; 
        error = true;
    }

    cout << 3 * vec1 << endl;
    if (3 * vec1[0] != (3 * vec1)[0] || 3 * vec1[1] != (3 * vec1)[1] || 3 * vec1[2] != (3 * vec1)[2]) {
        cerr << "Должно быть: " << "{ " << 3 * vec1[0] << ", " << 3 * vec1[1] << ", " << 3 * vec1[2] << " }" << endl; 
        error = true;
    }

    cout << vec1 / 5 << endl;
    if (vec1[0] / 5 != (vec1 / 5)[0] || vec1[1] / 5 != (vec1 / 5)[1] || vec1[2] / 5 != (vec1 / 5)[2]) {
        cerr << "Должно быть: " << "{ " << vec1[0] / 5 << ", " << vec1[1] / 5 << ", " << vec1[2] / 5 << " }" << endl; 
        error = true;
    }

    cout << -vec1 << endl;
    if (-vec1[0] != (-vec1)[0] || -vec1[1] != (-vec1)[1] || -vec1[2] != (-vec1)[2]) {
        cerr << "Должно быть: " << "{ " << -vec1[0] << ", " << -vec1[1] << ", " << -vec1[2] << " }" << endl; 
        error = true;
    }

    cout << !vec1 << endl;
    if (!vec1[0] != (!vec1)[0] || !vec1[1] != (!vec1)[1] || !vec1[2] != (!vec1)[2]) {
        cerr << "Должно быть: " << "{ " << !vec1[0] << ", " << !vec1[1] << ", " << !vec1[2] << " }" << endl; 
        error = true;
    }

    return error;
}

int main() {
    cout << test_vector3d() << endl;

    Vector3d v1(3), v2(4);
    cout << average(v1, v2);

    if (test_vector3d()) 
        return 0;
    else    
        return 1;
}