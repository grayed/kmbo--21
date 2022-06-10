#include <iostream>
//#include "vector.h"
using namespace std;

class vector3d {
    float data[3];
public:
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
    float  operator[](int idx) const { return data[idx]; }
    float& operator[](int idx)       { return data[idx]; }
};
vector3d operator + (const vector3d& v1, const vector3d& v2) { return vector3d(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]); }
vector3d operator - (const vector3d& v1, const vector3d& v2) { return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]); }
vector3d operator * (const vector3d& v1, const float x)      { return vector3d(v1[0] * x, v1[1] * x, v1[2] * x); }
vector3d operator * (const float x, const vector3d& v1)      { return vector3d(v1[0] * x, v1[1] * x, v1[2] * x); }
vector3d operator / (const vector3d& v1, const float x)      { return vector3d(v1[0] / x, v1[1] / x, v1[2] / x); }
vector3d operator -(const vector3d& v1)                      { return vector3d(-v1[0], -v1[1], -v1[2]); }
vector3d operator !(const vector3d& v1) {
    if (v1[0] == 0 && v1[1] == 0 && v1[2] == 0)              { return vector3d(1, 1, 1); }
    else                                                     { return vector3d(0, 0, 0); }
}


ostream& operator <<(ostream& os, const vector3d& v)         
{ 
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }"; 
}
bool operator ==(vector3d& first, vector3d& second)
{
    if ((first[0] == second[0]) && (first[1] == second[1]) && (first[2] == second[2]))
    { return 1; }
    else 
    { return 0; }
};

void testBVA(vector3d firstTester, vector3d secondTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] + secondTester[0]);
    ans[1] = (firstTester[1] + secondTester[1]);
    ans[2] = (firstTester[2] + secondTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester + secondTester;
    cerr << test << " - Vector obtained from + operator." << endl;

    if (ans == test) {
        cerr << "Testing of Binary Vector Addition went successful." << endl << endl;
    } else { cerr << "ERROR in Binary Vector Addition: something went wrong." << endl << endl; flag = 0; }
}

void testBVS(vector3d firstTester, vector3d secondTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] - secondTester[0]);
    ans[1] = (firstTester[1] - secondTester[1]);
    ans[2] = (firstTester[2] - secondTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester - secondTester;
    cerr << test << " - Vector obtained from - operator." << endl;

    if (ans == test) {
        cerr << "Testing of Binary Vector Subtraction went successful." << endl << endl;
    } else { cerr << "ERROR in Binary Vector Subtraction: something went wrong." << endl << endl; flag = 0; }
}

void testLeftVSM(float floatTester, vector3d secondTester, bool flag) {
    vector3d ans;
    ans[0] = (floatTester * secondTester[0]);
    ans[1] = (floatTester * secondTester[1]);
    ans[2] = (floatTester * secondTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = floatTester * secondTester;
    cerr << test << " - Vector obtained from * operator (left)." << endl;

    if (ans == test) {
        cerr << "Testing of Vector Scalar Multiple (left) went successful." << endl << endl;
    } else { cerr << "ERROR in Vector Scalar Multiple (left): something went wrong." << endl << endl; flag = 0; }
}

void testRightVSM(vector3d firstTester, float floatTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] * floatTester);
    ans[1] = (firstTester[1] * floatTester);
    ans[2] = (firstTester[2] * floatTester);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester * floatTester;
    cerr << test << " - Vector obtained from * operator (right)." << endl;

    if (ans == test) {
        cerr << "Testing of Vector Scalar Multiple (right) went successful." << endl << endl;
    } else { cerr << "ERROR in Vector Scalar Multiple (right): something went wrong." << endl << endl; flag = 0; }
}

void testVSD(vector3d firstTester, float floatTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] / floatTester);
    ans[1] = (firstTester[1] / floatTester);
    ans[2] = (firstTester[2] / floatTester);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester / floatTester;
    cerr << test << " - Vector obtained from / operator." << endl;

    if (ans == test) {
        cerr << "Testing of Vector Scalar Division went successful." << endl << endl;
    } else { cerr << "ERROR in Vector Scalar Division: something went wrong." << endl << endl; flag = 0; }
}

void testCV(vector3d firstTester, bool flag) {
    vector3d ans;
    ans[0] = (-firstTester[0]);
    ans[1] = (-firstTester[1]);
    ans[2] = (-firstTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = -firstTester;
    cerr << test << " - Vector obtained from - operator." << endl;

    if (ans == test) {
        cerr << "Testing of Converse Vector went successful." << endl << endl;
    } else { cerr << "ERROR in Converse Vector: something went wrong." << endl << endl; flag = 0; }
}

void testLDV(vector3d firstTester, bool flag) {
    vector3d ans;
    if (!(firstTester[0] || firstTester[0] || firstTester[0])) { ans[0] = ans[1] = ans[2] = 1; }

    cerr << ans << " - Vector with answers." << endl;

    vector3d test = !firstTester;
    cerr << test << " - Vector obtained from ! operator." << endl;

    if (ans == test) {
        cerr << "Testing of Logical Denial of Vector went successful." << endl << endl;
    } else { cerr << "ERROR in Logical Denial of Vector: something went wrong." << endl << endl; flag = 0; }
}


bool test_vector3d(vector3d v1, vector3d v2) {
    bool flag = 1;
    testBVA(v1, v2, flag);
    testBVS(v1, v2, flag);
    testLeftVSM(3, v2, flag);
    testRightVSM(v1, 3, flag);
    testVSD(v1, -1.7, flag);
    testCV(v2, flag);
    testLDV(v2, flag);
    if (flag) { cout << "Tests passed successfully!" << endl; }
    else { cout << "GREAT ERROR!!!" << endl; }
    return true;
}


int main(int argc, char** argv) {
    vector3d v1(2, 2, 2), v2(4, 4, 4);
    test_vector3d(v1, v2);
}