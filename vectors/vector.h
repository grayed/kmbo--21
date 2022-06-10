#pragma once


class vector3d {
private:
	float data[3];
public:
	vector3d() { data[2] = data[1] = data[0] = 0; }
	vector3d(float k) { data[2] = data[1] = data[0] = k; }
	vector3d(float x, float y, float z) { data[0] = x;  data[1] = y; data[2] = z; }
	float  operator [](int i) const { return data[i]; }
	vector3d operator +(vector3d& Vector2) { return vector3d(data[0] + Vector2[0], data[1] + Vector2[1], data[2] + Vector2[2]); } //Vector3d& Vector2
	vector3d operator -(vector3d& Vector2) { return vector3d(data[0] - Vector2[0], data[1] - Vector2[1], data[2] - Vector2[2]); }
	vector3d operator *(float k) { return vector3d(data[0] * k, data[1] * k, data[2] * k); }
	vector3d operator /(float k) {
		if (k != 0)
			return vector3d(data[0] / k, data[1] / k, data[2] / k);
		else std::cout << "Division by zero";
	}
	vector3d operator -() { return vector3d(-data[0], -data[1], -data[2]); }
	vector3d operator !() {
		if (data[0] == 0 && data[1] == 0 && data[2] == 0) return vector3d(1, 1, 1);
		else return vector3d(0, 0, 0);
	}
};

std::ostream& operator <<(std::ostream& os, vector3d& v) {
	return os << "(" << v[0] << " " << v[1] << " " << v[2] << ")";
}
