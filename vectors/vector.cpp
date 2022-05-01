#include <iostream>
#include <cmath>

using namespace std;

class Vec{
public:
    float data[3];
    Vec() { data[2]=data[1]=data[0]=0;}
    Vec(float value) {data[2]=data[1]=data[0]=value;}
    Vec(float x, float y, float z) {data[0]=x; data[1]=y; data[2]=z;}
    float operator[](int idx) const { return data[idx];}
    float& operator[](int idx) {return data[idx];}
Vec operator +(const Vec& other) const {
    return Vec(data[0] + other[0], data[1]+other[1], data[2]+other[2]);
};
Vec operator -(const Vec &other) {
    return Vec(data[0]-other[0],data[1]-other[1], data[2]-other[2]);
};
Vec operator *(const float value ) {
    return Vec( data[0]*value, data[1]*value, data[2]*value);
};
Vec operator /(const float value) {
    return Vec(data[0]/value,data[1]/value,data[2]/value);
};
Vec operator-() {return Vec(-data[0],-data[1],-data[2]);
};
Vec operator !(){
    if ((data[0]==0) && (data[1]==0) && (data[2]==0))
        return Vec(data[0]==1,data[1]==1,data[2]==1);
    else
        return Vec(data[0]==0,data[1]==0,data[2]==0);
};
};

ostream& operator <<(ostream& os, const Vec3& v)
{
    return os << "{"<< v[0]<<","<<v[1]<<","<<v[2]<<"}";
}; 

bool test_Vec(){
    Vec v1;
    Vec v2(6,6,6);
    Vec v3(4,4,4);
    Vec v4 = v2+v3, v5 = v3-v2, v6=v2*5, v7 = v2/2, v8 = -v3, v9 = !v2, v10= !v1;
    if (v4.data[0] != 10 || v4.data[1] != 10 || v4.data[2] != 10){
        cerr<<"Ошибка в сложении"<<endl;
        return 1;
    }
    if (v5.data[0] != 2 || v5.data[1] != 2 || v5.data[2] != 2){
        cerr<<"Ошибка в вычитание"<<endl;
        return 1;
    }
    if (v6.data[0] != 30 || v6.data[1] != 30 || v6.data[2] != 30){
        cerr<<"Ошибка в умножении"<<endl;
        return 1;
    }
    if (v7.data[0] != 3 || v7.data[1] != 3 || v7.data[2] != 3){
        cerr<<"Ошибка в делении"<<endl;
        return 1;
    }
    if (v8.data[0] != -4 || v8.data[1] != -4 || v8.data[2] != -4){
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
