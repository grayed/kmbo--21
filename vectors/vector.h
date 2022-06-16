#pragma once

#include <ostream>
using namespace std;

class vector3d {
	float data[3];

public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float value) { data[2] = data[1] = data[0] = value; }
	vector3d(float a1, float a2, float a3) { data[0] = a1;  data[1] = a2; data[2] = a3; }

	vector3d operator+(const vector3d& other) {

		return vector3d(data[0] + other.data[0],data[1] + other.data[1],data[2] + other.data[2]);
	}

	vector3d operator*(const float digit)
	{
		return vector3d(data[0] * digit,data[1] * digit,data[2] * digit);
	}
	
	vector3d operator/(const float digit)
	{
		return vector3d(data[0] / digit,data[1] / digit,data[2] / digit);
	}
	vector3d operator-()
	{
		return vector3d(-data[0], -data[1], -data[2]);
	}
	vector3d operator!()
	{
		if (data[0] == data[1] == data[2] == 0)
			return vector3d(1, 1, 1);
		return vector3d(0, 0, 0);
	}
	bool operator!=(const vector3d& v)
	{
		if (data[0] != v.data[0] || data[1] != v.data[1] || data[2] != v.data[2])
			return 1;
		return 0;
	}

	vector3d(const vector3d& v);
	
	friend int main(int argc, char** argv);
	friend ostream&operator<<(ostream& os, const vector3d& v);

	float& operator[](int idx) { return data[idx]; }// по ссылке понятно, что изменится сам объект
	float  operator[](int idx) const { return data[idx]; } // а тут возвращается просто число, которое соотвествует этому индексу, никак не меняет объект, поэтому const в конце=фу-я ничего не меняет

	
};
ostream &operator<<(ostream& os, const vector3d& v)
{
	os  <<"{"<<v.data[0]<<"," << v.data[1] <<"," << v.data[2] << "}\n";
	return os;
	
}

vector3d::vector3d(const vector3d& v)
{
	data[0] = v.data[0];
	data[1] = v.data[1];
	data[2] = v.data[2];
	cout << "constructor copy\n";
}






