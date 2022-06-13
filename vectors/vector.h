#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class vector3d {
    float data[3];
    float data[3];

public:
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
    vector3d() { data[2] = data[1] = data[0] = 0; }
    vector3d(float value) { data[2] = data[1] = data[0] = value; }
    vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

    float& operator[](int idx) { return data[idx]; }
    float  operator[](int idx) const { return data[idx]; }
    float& operator[](int idx) { return data[idx]; }
    float  operator[](int idx) const { return data[idx]; }

    friend int main(int argc, char** argv);
    friend int main(int argc, char** argv);
};

std::ostream& operator <<(std::ostream& os, const vector3d& v);

vector3d operator + (const vector3d& v1, const vector3d& v2) { return vector3d(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]); }
vector3d operator - (const vector3d& v1, const vector3d& v2) { return vector3d(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]); }
vector3d operator * (const vector3d& v1, const float x) { return vector3d(v1[0] * x, v1[1] * x, v1[2] * x); }
vector3d operator * (const float x, const vector3d& v1) { return vector3d(v1[0] * x, v1[1] * x, v1[2] * x); }
vector3d operator / (const vector3d& v1, const float x) { return vector3d(v1[0] / x, v1[1] / x, v1[2] / x); }
vector3d operator -(const vector3d& v1) { return vector3d(-v1[0], -v1[1], -v1[2]); }
vector3d operator !(const vector3d& v1) {
    if (v1[0] == 0 && v1[1] == 0 && v1[2] == 0) { return vector3d(1, 1, 1); }
    else { return vector3d(0, 0, 0); }
}


ostream& operator <<(ostream& os, const vector3d& v)
{
    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}
bool operator ==(vector3d& first, vector3d& second)
{
    if ((first[0] == second[0]) && (first[1] == second[1]) && (first[2] == second[2]))
        return true;
    else
        return false;
};

void testAddition(vector3d firstTester, vector3d secondTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] + secondTester[0]);
    ans[1] = (firstTester[1] + secondTester[1]);
    ans[2] = (firstTester[2] + secondTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester + secondTester;
    cerr << test << " - Vector obtained from + operator." << endl;

    if (ans == test) {
        cerr << "Testing of Addition vector went successful." << endl << endl;
    }
    else { cerr << "ERROR in Addition vector." << endl << endl; flag = 0; }
}

void testSubtraction(vector3d firstTester, vector3d secondTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] - secondTester[0]);
    ans[1] = (firstTester[1] - secondTester[1]);
    ans[2] = (firstTester[2] - secondTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester - secondTester;
    cerr << test << " - Vector obtained from - operator." << endl;

    if (ans == test) {
        cerr << "Testing of Subtraction vector went successful." << endl << endl;
    }
    else { cerr << "ERROR in Subtraction vector." << endl << endl; flag = 0; }
}

void testLMultipl(float floatTester, vector3d secondTester, bool flag) {
    vector3d ans;
    ans[0] = (floatTester * secondTester[0]);
    ans[1] = (floatTester * secondTester[1]);
    ans[2] = (floatTester * secondTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = floatTester * secondTester;
    cerr << test << " - Vector obtained from * operator (left)." << endl;

    if (ans == test) {
        cerr << "Testing of Multiple vector (left) went successful." << endl << endl;
    }
    else { cerr << "ERROR in Multiple vector (left)." << endl << endl; flag = 0; }
}

void testRMultipl(vector3d firstTester, float floatTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] * floatTester);
    ans[1] = (firstTester[1] * floatTester);
    ans[2] = (firstTester[2] * floatTester);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester * floatTester;
    cerr << test << " - Vector obtained from * operator (right)." << endl;

    if (ans == test) {
        cerr << "Testing of Multiple vector (right) went successful." << endl << endl;
    }
    else { cerr << "ERROR in Multiple vector (right)." << endl << endl; flag = 0; }
}

void testDivision(vector3d firstTester, float floatTester, bool flag) {
    vector3d ans;
    ans[0] = (firstTester[0] / floatTester);
    ans[1] = (firstTester[1] / floatTester);
    ans[2] = (firstTester[2] / floatTester);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = firstTester / floatTester;
    cerr << test << " - Vector obtained from / operator." << endl;

    if (ans == test) {
        cerr << "Testing of Division vector went successful." << endl << endl;
    }
    else { cerr << "ERROR in Division vector." << endl << endl; flag = 0; }
}

void testN(vector3d firstTester, bool flag) {
    vector3d ans;
    ans[0] = (-firstTester[0]);
    ans[1] = (-firstTester[1]);
    ans[2] = (-firstTester[2]);
    cerr << ans << " - Vector with answers." << endl;

    vector3d test = -firstTester;
    cerr << test << " - Vector obtained from - operator." << endl;

    if (ans == test) {
        cerr << "Testing of Conversion vector went successful." << endl << endl;
    }
    else { cerr << "ERROR in Conversion vector." << endl << endl; flag = 0; }
}

void testOtr(vector3d firstTester, bool flag) {
    vector3d ans;
    if (!(firstTester[0] || firstTester[0] || firstTester[0])) { ans[0] = ans[1] = ans[2] = 1; }

    cerr << ans << " - Vector with answers." << endl;

    vector3d test = !firstTester;
    cerr << test << " - Vector obtained from ! operator." << endl;

    if (ans == test) {
        cerr << "Testing of  Denial vector went successful." << endl << endl;
    }
    else { cerr << "ERROR in Denial vector: something went wrong." << endl << endl; flag = 0; }
}


bool test_vector3d(vector3d v1, vector3d v2) {
    bool flag = 1;
    testAddition(v1, v2, flag);
    testSubtraction(v1, v2, flag);
    testLMultipl(3, v2, flag);
    testRMultipl(v1, 3, flag);
    testDivision(v1, -1.7, flag);
    testN(v2, flag);
    testOtr(v2, flag);
    if (flag) { cout << "Tests passed successfully!" << endl; }
    else { cout << "GREAT ERROR!!!" << endl; }
    return true;
}
