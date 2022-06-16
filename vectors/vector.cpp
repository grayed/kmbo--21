#include <iostream>
#include "vector.h"

bool test_vector3d()
{
	vector3d v1(2, 3, 1), v2(2, 4, 0), v3(0, 0, 0);

	if ((v1 + v2) != vector3d(4, 7, 1))
	{
		cerr << "Wrong operation binary + \n";
		return 0;
	}

	if ((v1 * 3) != vector3d(6, 9, 3))
	{
		cerr << "Wrong operation binary * on digit \n";
		return 0;
	}

	if ((v2 / 2) != vector3d(1, 2, 0))
	{
		cerr << "Wrong operation binary / on digit \n";
		return 0;
	}

	if (-v2 != vector3d(-2, -4, 0))
	{
		cerr << "Wrong operation unary - \n";
		return 0;
	}

	if (!(v3) != vector3d(1, 1, 1) && !v2 != vector3d(0, 0, 0))
	{
		cerr << "Wrong operation unary ! \n";
		return 0;
	}
	return 1;
}



int main(int argc, char** argv) {
	
	vector3d  v1(12), v2(1, 3, 8),v3(0,0,0);
	vector3d v4(v3);
	v2[1] = 5;//если по ссылке приходит, то присваиваем
	cout << v3 + v2;
	cout << v2 * 5;
	cout << v2 / 3;
	cout << v2 ;
	if (v2 != v1)
		cout << "correct != operator" << endl;
	if (test_vector3d()) 
		return 0;
	else
		return 1;



}