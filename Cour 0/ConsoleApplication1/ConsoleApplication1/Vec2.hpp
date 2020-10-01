#pragma once
#include <string>
#include <iostream>

using namespace std;

class Vec2 {
public:

	float x = 0.0f;
	float y = 0.0;

	Vec2(float x = 0.0f,float y = 0.0f) {
		this->x = x;
		this->y = y;
	}

	Vec2 add(Vec2 v) {
		Vec2 xy;

		xy = this->x + v.x;
		xy = this->y + v.y;

	}

	void incr(Vec2 * v) {
		(*v).x += this->x;
	}

	/*void incr(Vec2 & v) {
		v->x += this->x;
	}*/


	~Vec2() {
		cout << "supprimer " << to_string(x) << endl;
	}
};
