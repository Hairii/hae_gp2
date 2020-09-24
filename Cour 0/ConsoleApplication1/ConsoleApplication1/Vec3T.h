#pragma once
template<typename T>
class Vec3T
{
public:

	T x;
	T y;
	T z;

	Vec3T<T>() {
		x = {};
		y = {};
		z = {};
	};
	Vec3T<T>(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3T<T> add(Vec3T<T> v) {
		Vec3T res;
		res.x = this ->x + v.x;
		res.y = this->y + v.y;
		res.z = this->z + v.z;
		return res;
	}
};

