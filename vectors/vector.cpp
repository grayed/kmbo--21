#include <iostream>
#include "vector.h"

using namespace std;

ostream& operator <<(ostream& os, const vector3d& v) {
	return os << "{ " << v[0] << ", " << v[1] << ", " << v[2] << " }";
}
vector3d  vector3d::operator+(vector3d const &v){
	return vector3d(data[0]+v.data[0],data[1]+v.data[1],data[2]+v.data[2]);
}
vector3d  vector3d::operator-(vector3d const &v){
	return vector3d(data[0]-v.data[0],data[1]-v.data[1],data[2]-v.data[2]);
}
vector3d  operator*(vector3d const &v,float const &d){
	return vector3d(v.data[0]*d,v.data[1]*d,v.data[2]*d);
}
vector3d  operator/(vector3d const &v,float const &d){
	return vector3d(v.data[0]/d,v.data[1]/d,v.data[2]/d);
}
vector3d  operator*(float const &d,vector3d const &v){
	return vector3d(v.data[0]*d,v.data[1]*d,v.data[2]*d);
}
vector3d  vector3d::operator-(){
	return vector3d(-data[0],-data[1],-data[2]);
}
vector3d  vector3d::operator!(){
	return vector3d(!data[0],!data[1],!data[2]);
}
bool test_vector3d(vector3d v1,vector3d v2,float d) {
		bool res = true;
		if( ((v1+v2)[0] != v1[0] + v2[0]) || ((v1+v2)[1] != v1[1] + v2[1]) || ((v1+v2)[2] != v1[2] + v2[2]) ){
				res = false;
				cerr << "Сложение (+) выполнено неверно для:\n" << v1 << '\n' << v2 << '\n';
		}
		if( ((v1-v2)[0] != v1[0] - v2[0]) || ((v1-v2)[1] != v1[1] - v2[1]) || ((v1-v2)[2] != v1[2] - v2[2]) ){
				res = false;
				cerr << "Вычитание (-) выполнено неверно для:\n" << v1 << '\n' << v2 << '\n';
		}
		if( ((v1*d)[0] != v1[0]*d) || ((v1*d)[1] != v1[1]*d) || ((v1*d)[2] != v1[2]*d) ){
				res = false;
				cerr << "Умножение на скаляр (*) выполнено неверно для:\n" << v1 << '\n' << d <<'\n';
		}
		if( ((d*v1)[0] != v1[0]*d) || ((d*v1)[1] != v1[1]*d) || ((d*v1)[2] != v1[2]*d) ){
				res = false;
				cerr << "Умножение на скаляр (*) выполнено неверно для:\n" << v1 << '\n' << d <<'\n';
		}
		if( ((v2*d)[0] != v2[0]*d) || ((v2*d)[1] != v2[1]*d) || ((v2*d)[2] != v2[2]*d) ){
				res = false;
				cerr << "Умножение на скаляр (*) выполнено неверно для:\n" << v2 << '\n' << d <<'\n';
		}
		if( ((d*v2)[0] != v2[0]*d) || ((d*v2)[1] != v2[1]*d) || ((d*v2)[2] != v2[2]*d) ){
				res = false;
				cerr << "Умножение на скаляр (*) выполнено неверно для:\n" << v2 << '\n' << d <<'\n';
		}
		if( ((v1/d)[0] != v1[0]/d) || ((v1/d)[1] != v1[1]/d) || ((v1/d)[2] != v1[2]/d) ){
				res = false;
				cerr << "Деление на скаляр (/) выполнено неверно для:\n" << v1 << '\n' << d <<'\n';
		}
		if( ((v2/d)[0] != v2[0]/d) || ((v2/d)[1] != v2[1]/d) || ((v2/d)[2] != v2[2]/d) ){
				res = false;
				cerr << "Деление на скаляр (/) выполнено неверно для:\n" << v2 << '\n' << d <<'\n';
		}
		if( ((-v1)[0] != -v1[0]) || ((-v1)[1] != -v1[1]) || ((-v1)[2] != -v1[2]) ){
				res = false;
				cerr << "Взятие обратного знака (-) выполнено неверно для:\n" << v1 << '\n';
		}
		if( ((-v2)[0] != -v2[0]) || ((-v2)[1] != -v2[1]) || ((-v2)[2] != -v2[2]) ){
				res = false;
				cerr << "Взятие обратного знака (-) выполнено неверно для:\n" << v2 << '\n';
		}
		if( ((!v1)[0] != (!v1[0])) || ((!v1)[1] != (!v1[1])) || ((!v1)[2] != (!v1[2])) ){
				res = false;
				cerr << "Операция инверсии (!) выполнено неверно для:\n" << v1 << '\n';
		}
		if( ((!v2)[0] != !v2[0]) || ((!v2)[1] != !v2[1]) || ((!v2)[2] != !v2[2]) ){
				res = false;
				cerr << "Операция инверсии (!) выполнено неверно для:\n" << v2 << '\n';
		}

		return res;
}



int main(int argc, char** argv) {
	vector3d v1, v2(12), v3(1, 3, 8);
	//vector3d v4 = v1 + v2, v5 = v1 - v2, v6 = v1 * 0.5f;
	//cout << "v4: " << v4 << endl << "v5: " << v5 << endl << "v6: " << v6 << endl;

	/*
	printf("address of v1:             0x%p, size: %zu bytes\n", &v1, sizeof(v1));
	printf("address of v1.data:        0x%p, size: %zu bytes\n", &v1.data, sizeof(v1.data));
	printf("address of v1.data[-1]:    0x%p, size: %zu bytes\n", &v1.data[-1], sizeof(v1.data[-1]));
	printf("address of v1.data[0]:     0x%p, size: %zu bytes\n", &v1.data[0], sizeof(v1.data[0]));
	printf("address of v1.data[1]:     0x%p, size: %zu bytes\n", &v1.data[1], sizeof(v1.data[1]));
	printf("address of v1.data[2]:     0x%p, size: %zu bytes\n", &v1.data[2], sizeof(v1.data[2]));
	printf("address of v1.data[2000]:  0x%p, size: %zu bytes\n", &v1.data[2000], sizeof(v1.data[2000]));
	*/
	cout << "v3 = " << v3 << '\n';
	cout << "v2 = " << v2 << '\n';
	cout << "v1 = " << v1 << '\n' << '\n';
	vector3d v = v3 + v2;
	cout << "v3 + v2 : " << v << '\n';
	v = v3 - v2;
	cout << "v3 - v2 : " << v << '\n';
	cout << "v3*2    : " << v3*2 << '\n';
	cout << "2*v3    : " << 2*v3 << '\n';
	cout << "v3/2    : " << v3/2 << '\n';
	cout << "-v3     : " << -v3 << '\n';
	cout << "!v3     : " << !v3 << '\n';
	cout << "!v1     : " << !v1 << '\n';
	if(test_vector3d(v1,v2,8))	{ return 0;	}
	else {	return 1;	}
}
