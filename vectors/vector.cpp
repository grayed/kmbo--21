#pragma once

#include <ostream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class vector3d {
	float data[3];

public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	float& operator[](int idx) { return data[idx]; }
	float  operator[](int idx) const { return data[idx]; }
	vector3d operator+(vector3d v2) { 
		vector3d v3;
		v3[0] = data[0] + v2[0];
		v3[1] = data[1] + v2[1];
		v3[2] = data[2] + v2[2];
		return v3;
	}
	vector3d operator-(vector3d v2) {
		vector3d v3;
		v3[0] = data[0] - v2[0];
		v3[1] = data[1] - v2[1];
		v3[2] = data[2] - v2[2];
		return v3;
	}
	vector3d operator*(float c) {
		vector3d v3;
		v3[0] = data[0] * c;
		v3[1] = data[1] * c;
		v3[2] = data[2] * c;
		return v3;
	}
    vector3d operator/(float c) {
        vector3d v3;
        v3[0] = data[0] / c;
        v3[1] = data[1] / c;
        v3[2] = data[2] / c;
        return v3;
    }
	vector3d operator-() {
		vector3d v3;
		v3[0] = -data[0];
		v3[1] = -data[1];
		v3[2] = -data[2];
		return v3;
	}
	vector3d operator!() {
		vector3d v3;
		v3[0] = data[0] == 0 ? 1 : 0;
		v3[1] = data[1] == 0 ? 1 : 0;
		v3[2] = data[2] == 0 ? 1 : 0;
		return v3;
	}
	string about() const{
		stringstream ss;
	ss << "[" << data[0] << ", " << data[1] << ", " << data[2] << "]";
	return ss.str();
	}
};

inline ostream& operator<<(ostream& os, const vector3d& v) {
	return os << v.about();
}

bool test_vector3d(vector <vector3d> Vec, vector3d v1, vector3d v2, float v3) {
    bool check = true;
    for (int i = 0; i < Vec.size(); ++i) {
        switch (i)
        {
        case 0:
            if ((Vec[i][0] == (v1[0] + v2[0])) && (Vec[i][1] == (v1[1] + v2[1])) && (Vec[i][2] == (v1[2] + v2[2])))
                cerr << "Test 1: " << v1 << " + " << v2 << " - TRUE " << endl;
            else
            {
                cerr << "Test 1: " << v1 << " + " << v2 << " - FALSE " << endl;
                check = false;
            }
            break;

        case 1:
            if ((Vec[i][0] == (v1[0] - v2[0])) && (Vec[i][1] == (v1[1] - v2[1])) && (Vec[i][2] == (v1[2] - v2[2])))
                cerr << "Test 2: " << v1 << " - " << v2 << " - TRUE " << endl;
            else
            {
                cerr << "Test 2: " << v1 << " - " << v2 << " - FALSE " << endl;
                check = false;
            }
            break;
        case 2:
            if ((Vec[i][0] == (v1[0] * v3)) && (Vec[i][1] == (v1[1] * v3)) && (Vec[i][2] == (v1[2] * v3)))
                cerr << "Test 3: " << v1 << " * " << v3 << " - TRUE " << endl;
            else
            {
                check = false;
                cerr << "Test 3: " << v1 << " * " << v3 << " - FALSE " << endl;
            }
            break;
        case 3:
            if ((Vec[i][0] == (v1[0] / v3)) && (Vec[i][1] == (v1[1] / v3)) && (Vec[i][2] == (v1[2] / v3)))
                cerr << "Test 4: " << v1 << " / " << v3 << " - TRUE " << endl;
            else
            {
                check = false;
                cerr << "Test 4: " << v1 << " / " << v3 << " - FALSE " << endl;
            }
            break;
        case 4:
            if ((Vec[i][0] == (-v1[0])) && (Vec[i][1] == (-v1[1])) && (Vec[i][2] == (-v1[2])))
                cerr << "Test 5: " << "!" <<  v1 << " - TRUE " << endl;
            else
            {
                check = false;
                cerr << "Test 5: " << "!" << v1 << " - FALSE " << endl;
            }
            break;

        default:
            vector3d v;
            if (i == 5)
                v = v1;
            if (v[0] == 0 && v[1] == 0 && v[2] == 0) {
                if ((Vec[i][0] == 1) && (Vec[i][1] == 1) && (Vec[i][2] == 1)) {
                    cerr << "Test" << i + 1 << ": unary ! vector " << v << " - TRUE" << endl;
                }
                else {
                    check = false;
                    cerr << "Test" << i + 1 << ": unary ! vector " << v << " - FALSE" << endl;
                }
            }
            else {
                if ((Vec[i][0] == 0) && (Vec[i][1] == 0) && (Vec[i][2] == 0)) {
                    cerr << "Test" << i + 1 << ": unary ! vector " << v << " - TRUE" << endl;
                }
                else {
                    check = false;
                    cerr << "Test" << i + 1 << ": unary ! vector " << v << " - FALSE" << endl;
                }
            }
            break;
        }
    }
    return check;
}
int main() {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f, v7 = -v1, v8 = !v2;
    cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl << "v7: " << v7 << endl << "v8: " << v8 << endl;
    vector<vector3d> vv;
    vector3d vv1(3, 5, 9), vv2(-1, 5, 0);
    float c = 7.021;
    vv.push_back(vv1 + vv2);
    vv.push_back(vv1 - vv2);
    vv.push_back(vv1 * c);
    vv.push_back(vv1 / c);
    vv.push_back(-vv1);
    vv.push_back(!vv1);
    vv.push_back(!vv[5]);
    for (auto& element : vv) {
        cout << element << endl;
    }
    bool check = test_vector3d(vv, vv1, vv2, c);
    return check ? 1 : 0;
}
