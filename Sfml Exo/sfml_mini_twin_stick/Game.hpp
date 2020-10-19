#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace sf;
using namespace std;

class Game {
public:

	sf::RenderWindow* win = nullptr;
	sf::RectangleShape player;
	sf::CircleShape projectile;
	sf::Vector2f positionPlayer;
	sf::Vector2f positionDir;

	Game(sf::RenderWindow * win) {
		this->win = win;
		player = sf::RectangleShape(Vector2f(64, 64));
		player.setFillColor(sf::Color(0xF57F5Dff));
		player.setOutlineColor(sf::Color(0x59EB7Fff));
		player.setOutlineThickness(2);
		player.setPosition(50, 50);
		player.setOrigin(25, 25);
		
	}

	void processInput(sf::Event ev) {
		if (ev.type == sf::Event::Closed)
			win->close();
		if (ev.type == sf::Event::KeyReleased) {

		}
	}

	void shoot(sf::Event ev) {

		sf::Vector2f posMouse;
		
			projectile = sf::CircleShape(20.0f);
			projectile.setFillColor(sf::Color(0x0021FAff));
			positionPlayer = player.getPosition();
			projectile.setPosition(player.getPosition());
			posMouse.x = ev.mouseButton.x - projectile.getRadius();
			posMouse.y = ev.mouseButton.y - projectile.getRadius();
			positionDir.x = posMouse.x - positionPlayer.x;
			positionDir.y = posMouse.y - positionPlayer.y;


	}

	void move() {
		projectile.setPosition(projectile.getPosition() + (positionDir * 0.01f));
		//projectile.setPosition(positionPlayer);
	}

	void destroys() {
		sf::RenderWindow sizeMAx;
		sizeMAx.getSize();
		
		sf::Vector2f pixel;
		pixel = projectile.getPosition();
		pixel = { static_cast<float>(pixel.x), static_cast<float>(pixel.y) };
		


		if (pixel.x> (1280)|| pixel.y > 720) {
			

		}
	}

	void pollInput() {
		sf::Vector2f ppos = player.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) 
			ppos.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
			ppos.x--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			ppos.y++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			ppos.x++;
		player.setPosition(ppos);
	}
	void update() {
		pollInput();
		move();
	}

	void draw(sf::RenderWindow& win) {
		win.draw(player);
		win.draw(projectile);
	}
};