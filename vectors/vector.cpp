#include <iostream>
#include <vector>
using namespace std;

class vector3d {
    float data[3];
public:
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
    float  operator[](int idx) const { return data[idx]; }
    float& operator[](int idx) { return data[idx]; }
};
ostream& operator <<(ostream& os, const vector3d& v) {
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}
vector3d operator + (const vector3d& v1, const vector3d& v2) {
    return vector3d(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}
vector3d operator - (const vector3d& v1, const vector3d& v2) {
    return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}
vector3d operator * (const vector3d& v1, const float x) {
    return vector3d(v1[0] * x, v1[1] * x, v1[2] * x);
}
vector3d operator / (const vector3d& v1, const float x) {
    return vector3d(v1[0] / x, v1[1] / x, v1[2] / x);
}
const vector3d operator -(const vector3d& v1) {
    return vector3d(-v1[0], -v1[1], -v1[2]);
}
const vector3d operator !(const vector3d& v1) {
    if (v1[0] == 0 && v1[1] == 0 && v1[2] == 0) {
        return vector3d(1, 1, 1);
    }
    else
        return vector3d(0, 0, 0);
}
bool test_vector_addition(vector3d& v1, vector3d& v2) {
    bool flag = true;
    vector3d v3 = v1 + v2;
    for (int i = 0; i < 3; ++i) {
        if((v3[0] == (v1[0]+v2[0])) && (v3[1] == (v1[1]+v2[1])) && (v3[2] == (v1[2]+v2[2])))
            cerr << "Test 1 binary vector addition " << v1 << " and " << v2 << " - Correct " << endl;
        else {
            cerr << "Test binary vector addition " << v1 << " and " << v2 << " - Incorrect" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool test_vector_difference(vector3d& v1, vector3d& v2) {
    bool flag = true;
    vector3d v3 = v1 - v2;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] - v2[0])) && (v3[1] == (v1[1] - v2[1])) && (v3[2] == (v1[2] - v2[2])))
            cerr << "Test 2 binary difference of vectors " << v1 << " and " << v2 << " - Correct" << endl;
        else {
            cerr << "Test 2 binary difference of vectors " << v1 << " and " << v2 << " - Incorrect" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool test_vector_multiplying(vector3d& v1, float& c1) {
    bool flag = true;
    vector3d v3 = v1 * c1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] * c1 )) && (v3[1] == (v1[1] * c1)) && (v3[2] == (v1[2] *c1)))
            cerr << "Test 3 binary operation of multiplying a vector by a scolar " << v1 << " на " << c1 << " - Correct" << endl;
        else {
            cerr << "Test 3 binary operation of multiplying a vector by a scolar " << v1 << " на " << c1 << " - Incorrect" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}


bool test_vector_dividing(vector3d& v1, float& c1) {
    bool flag = true;
    vector3d v3 = v1 / c1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == (v1[0] / c1)) && (v3[1] == (v1[1] / c1)) && (v3[2] == (v1[2] / c1)))
            cerr << "Test 4 binary operation of dividing a vector by a scolar " << v1 << " на " << c1 << " - Correct" << endl;
        else {
            cerr << "Test 4 binary operation of dividing a vector by a scolar " << v1 << " на " << c1 << " - Incorrect" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}

bool test_vector_inverting(vector3d& v1) {
    bool flag = true;
    vector3d v3 = - v1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == -v1[0]) && (v3[1] == -v1[1]) && (v3[2] == -v1[2]))
            cerr << "Test 5 unary operation of inverting the vector sign  " << v1 << " - Correct" << endl;
        else {
            cerr << "Test 5 unary operation of inverting the vector sign  " << v1 << " - Incorrect" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}
bool test_vector_denial() {
    bool flag = true;
    vector3d v1 = (0, 0, 0);
    vector3d v3 = !v1;
    for (int i = 0; i < 3; ++i) {
        if ((v3[0] == 1) && (v3[1] == 1) && (v3[2] == 1))
            cerr << "Test" << i + 1 << ": unary ! vector " << v1 << " - Correct" << endl;
        else {
            cerr << "Test" << i + 1 << ": unary ! vector " << v1 << " - Incorrect" << endl;
            flag = false;
        }
        break;
    }
    return flag;
}


bool test_vector3d(vector3d v1, vector3d v2, float c1) {
    bool flag = true;
    test_vector_addition(v1, v2);
    test_vector_difference(v1, v2);
    test_vector_multiplying(v1, c1);
    test_vector_dividing(v1, c1);
    test_vector_inverting(v1);
    test_vector_denial();
    return flag;
}

int main(int x, char** y) {
    vector3d v1(12), v2(4, -3, 7), v4, v5, v6, v7, v8, v9, v10;
    vector <vector3d> Vect;
    float v3 = 0.5;
    v4 = v1 + v2; Vect.push_back(v4);
    v5 = v1 - v2; Vect.push_back(v5);
    v6 = v1 * v3; Vect.push_back(v6);
    v7 = v1 / v3; Vect.push_back(v7);
    v8 = -v1; Vect.push_back(v8);
    v9 = !v1; Vect.push_back(v9);
    v10 = !v9; Vect.push_back(v10);
    cout << " First : " << v4 << " Second : " << v5 << " Third : " << v6 << " Fourth : " << v7 << " Fifth : " << v8 << " Sixth : " << v9 << " Seventh : " << v10 << endl;
    bool Check = test_vector3d(v1, v2, v3);
    return 0;
}
