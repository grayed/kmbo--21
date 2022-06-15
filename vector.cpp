using namespace std;
#include "vector.h"

bool test_vector3d()
{
	vector3d v1(20, 45, 160);
	vector3d v2(25, 80, 30);

	cout << "v1: "
		 << "20, 45, 160" << endl;
	cout << "v2: "
		 << "25, 80, 30" << endl;

	bool ERROR = false;

	cout << "v1 + v2 = " << v1 + v2 << endl;
	if ((v1 + v2)[0] != v1[0] + v2[0] or (v1 + v2)[1] != v1[1] + v2[1] or (v1 + v2)[2] != v1[2] + v2[2])
	{
		cerr << "invalid, should be "
			 << "{ " << v1[0] + v2[0] << " " << v1[1] + v2[1] << " " << v1[2] + v2[2] << " }" << endl;
		ERROR = true;
	}
	cout << "v1 - v2 = " << v1 - v2 << endl;
	if ((v1 - v2)[0] != v1[0] - v2[0] or (v1 - v2)[1] != v1[1] - v2[1] or (v1 - v2)[2] != v1[2] - v2[2])
	{
		cerr << "invalid, should be "
			 << "{ " << v1[0] - v2[0] << " " << v1[1] - v2[1] << " " << v1[2] - v2[2] << " }" << endl;
		ERROR = true;
	}
	cout << "v1 * 5 = " << v1 * 5 << endl;
	if ((v1 * 5)[0] != v1[0] * 5 or (v1 * 5)[1] != v1[1] * 5 or (v1 * 5)[2] != v1[2] * 5)
	{
		cerr << "invalid, should be "
			 << "{ " << v1[0] * 5 << " " << v1[1] * 5 << " " << v1[2] * 5 << " }" << endl;
		ERROR = true;
	}
	cout << "v1 / 5 = " << v1 / 5 << endl;
	if ((v1 / 5)[0] != v1[0] / 5 || (v1 / 5)[1] != v1[1] / 5 || (v1 / 5)[2] != v1[2] / 5)
	{
		cerr << "invalid, should be "
			 << "{ " << v1[0] / 5 << " " << v1[1] / 5 << " " << v1[2] / 5 << " }" << endl;
		ERROR = true;
	}
	return ERROR;
}

int main(int argc, char **argv)
{
	return test_vector3d();
}