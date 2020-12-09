#pragma once

#include "SFML/Graphics.hpp"
#include "Particle.hpp"
#include "ParticleMan.hpp"
#include "Char.hpp"

#include <iostream>

using namespace sf;
class Game;

enum Etat {
	Ide,
	Fire,
};

class Bullet;

class Bullet
{
public:
	float speedXBullet = 0.0;
	float speedYBullet = 0.0;

	int		cellulex = 0;
	int		celluley = 0;

	float	rbx = 0.0;
	float	rby = 0.0;

	float frictionX = 0.97;
	float frictionY = 0.97;

	float lateralSpeed = 1.0;
	float maxSpeed = 10.0;

	Etat state = Ide;

	static constexpr int t = 16;

	sf::RectangleShape	spr;

	sf::RenderWindow* win = nullptr;
	ParticleMan afterpart;

	Game* gam = nullptr;

	Bullet(Game* g = nullptr) {
		this->gam = g;
	}


	void update(double dt);
	bool isWallHitte(int cx, int cy);

	void Spawn(Vector2f pos, Vector2f dir);

	void draw(sf::RenderWindow& win);

	void setCellPosition(int cx, int cy);
	void setPosition(int rpx, int rpy);

	void defaultFrictions();
};


