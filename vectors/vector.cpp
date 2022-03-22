#include <iostream>
using namespace std;

class vector3d {
    float data[3];
public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }
    // lvalue = rvalue
    virtual float  operator[] (int index) const { return data[index]; }
    float& operator[] (int index)       { return data[index]; }
    //vector3d operator +(const vector3d& other) const { return vector3d(data[0] + other.data[0], /* ... */); }
    //friend ostream& operator <<(ostream& os, const vector3d& v);
    friend int main(int argc, char **argv);
};

int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
    v1[2] = 54;

    printf("Address of v1:            %p, size is %zu bytes\n", &v1, sizeof(v1));
    printf("Address of v1.data:       %p, size is %zu bytes\n", &v1.data, sizeof(v1.data));
    printf("Address of v1.data[-1]:   %p, size is %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
    printf("Address of v1.data[0]:    %p, size is %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
    printf("Address of v1.data[1]:    %p, size is %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
    printf("Address of v1.data[2]:    %p, size is %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
    printf("Address of v1.data[2000]: %p, size is %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));

    printf("v1.data[-1]   = %f\n", v1.data[-1]);
    printf("v1.data[2000] = %f\n", v1.data[2000]);

    //vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
    //cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;
	return 0;
}

//vector3d operator - (const vector3d& v1, const vector3d& v2) {
//    return vector3d(v1[0] - v2[0], /* ... */);
//}

//ostream& operator <<(ostream& os, const vector3d& v) {
//    return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
//}
