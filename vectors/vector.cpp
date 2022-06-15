#include <iostream>
#include "vector.h"
#include <cmath>

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}
class Vector3d{
public:
    float data[3];
    Vector3d() { data[2]=data[1]=data[0]=0;}
    Vector3d(float value) {data[2]=data[1]=data[0]=value;}
    Vector3d(float x, float y, float z) {data[0]=x; data[1]=y; data[2]=z;}
    float operator[](int idx) const { return data[idx];}
    float& operator[](int idx) {return data[idx];}
Vector3d operator +(const Vector3d& other) const {
    return Vector3d(data[0] + other[0], data[1]+other[1], data[2]+other[2]);
};
Vector3d operator -(const Vector3d &other) {
    return Vector3d(data[0]-other[0],data[1]-other[1], data[2]-other[2]);
};
Vector3d operator *(const float value ) {
    return Vector3d( data[0]*value, data[1]*value, data[2]*value);
};
Vector3d operator /(const float value) {
    return Vector3d(data[0]/value,data[1]/value,data[2]/value);
};
Vector3d operator-() {return Vector3d(-data[0],-data[1],-data[2]);
};
Vector3d operator !(){
    if ((data[0]==0) && (data[1]==0) && (data[2]==0))
        return Vector3d(data[0]==1,data[1]==1,data[2]==1);
    else
        return Vector3d(data[0]==0,data[1]==0,data[2]==0);
};
};

int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
	v1[2] = 54;
	//vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
	//cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;
ostream& operator <<(ostream& os, const Vector3d& v){
    return os << "{"<< v[0]<<","<<v[1]<<","<<v[2]<<"}";
}; 

	printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
	printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
	printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
	printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
	printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
	printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
	printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));

	return 0;
}
bool test_Vector3d(){
    Vector3d v1;
    Vector3d v2(5,5,5);
    Vector3d v3(7,7,7);
    Vector3d v4 = v2+v3, v5 = v3-v2, v6=v2*3, v7 = v2/5, v8 = -v3, v9 = !v2, v10= !v1;
    if (v4.data[0] != 12 || v4.data[1] != 12 || v4.data[2] != 12){
        cerr<<"Ошибка в сложении"<<endl;
        return 1;
    }
    if (v5.data[0] != 2 || v5.data[1] != 2 || v5.data[2] != 2){
        cerr<<"Ошибка в вычитании"<<endl;
        return 1;
    }
    if (v6.data[0] != 15 || v6.data[1] != 15 || v6.data[2]!=15){
        cerr<<"Ошибка в умножении"<<endl;
        return 1;
    }
    if (v7.data[0] != 1 || v7.data[1] != 1 || v7.data[2] != 1){
        cerr<<"Ошибка в делении"<<endl;
        return 1;
    }
    if (v8.data[0] != -7 || v8.data[1] != -7 || v8.data[2] != -7){
        cerr<<"Ошибка в инверсии знака"<<endl;
        return 1;
    }
    if (v9.data[0] != 0 || v9.data[1] != 0 || v9.data[2] != 0){
        cerr<<"Ошибка в логическом преобразовании"<<endl;
        return 1;
    }
    if (v10.data[0] != 1 || v10.data[1] != 1 || v10.data[2] != 1){
        cerr<<"Ошибка в логическом преобразовании"<<endl;
        return 1;
    }
} 
