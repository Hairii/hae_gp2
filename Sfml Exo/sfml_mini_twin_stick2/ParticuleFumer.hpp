#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class ParticuleFumer {
public:
	;
	float			x = 0.0f;
	float			y = 0.0f;

	float			dx = 0.0f;
	float			dy = 0.0f;

	float			life = 1.0f;
	float			random = 1.0f;

	float			scaleX = 1.0f;
	float			scaleY = 1.0f;

	bool			destroyed = false;

	CircleShape fumer;

	ParticuleFumer() {



		fumer.setRadius(10);
		fumer.setOrigin(4, 4);
		fumer.setFillColor(sf::Color(0xADABAAff));

		random = rand() / RAND_MAX;
		life = random * 6.0 + 2.0 * 6.0;
	}


	void update(float dt) {
		x += dx * dt;
		y += dy * dt;

		fumer.setPosition(x, y);
		fumer.rotate(dt * 3.0);
		fumer.setScale(scaleX, scaleY);

		life -= dt;

		if (life <= 10.0) {
			dx *= 0.98;
			dy *= 0.98;
		}

		if (life <= 20.0) {
			scaleX *= 0.95;
			scaleY *= 0.95;
		}

		if (fumer.getScale().x <= 0.1 || fumer.getScale().x <= 0.1) {
			destroyed = true;
		}
	}
};

