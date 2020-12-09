#pragma once
#include "SFML/Graphics.hpp"
#include <functional>

using namespace sf;

class Game;

class Char2;

class Char2
{
public:
	static constexpr int GRID_SIZE = 16;

	sf::RectangleShape	player;


	Game* game = nullptr;

	Char2(Game* g = nullptr) {
		player = RectangleShape(Vector2f(48, 16 * 3));
		player.setFillColor(sf::Color(0xE6B03Eff));
		player.setOrigin(8, 16 * 2.5);
		this->game = g;
	}

	float speedX = 0.0;//rx par secondes
	float speedY = 0.0;//rx par secondes



	int		cx = 0;
	float	rx = 0.0;

	int		cy = 0;
	float	ry = 0.0;

	float frictX = 0.97;
	float frictY = 0.97;

	float destX = 0;
	float destY = 0;

	void setCellPosition(int cx, int cy);
	void setPosition(int rpx, int rpy);



	Vector2f getPositionPixel() {
		return Vector2f(cx * GRID_SIZE + rx * GRID_SIZE, cy * GRID_SIZE + ry * GRID_SIZE);
	}

	void update(double dt);

	void stop();

	void draw(sf::RenderWindow& win) {
		win.draw(player);
	}

	void defaultFriction();
	bool isWallHit(int cx, int cy);
};

