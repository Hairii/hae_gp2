#pragma once

#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

//#include "Particle.hpp"
#include "ParticleMan.hpp"
#include "Char.hpp"
#include "Char2.hpp"
#include "Bullet.hpp"

using namespace sf;

class HotReloadShader;
class Game {
public:
	sf::RenderWindow*	win = nullptr;


	/*HotReloadShader *	bgShader = nullptr;
	HotReloadShader *	doubleShader = nullptr;
	HotReloadShader *	displaceShader = nullptr;*/

	sf::Texture			tex;
	sf::Texture			tex2;
	sf::Texture			displaceMap;

	sf::RectangleShape	displace;

	Char				player1;
	Char2				player2;
	Bullet				tire;

	bool				closing = false;


	float JoystickPosX1;//joystick gauche
	float JoystickPosY1;

	float JoystickPosX2;
	float JoystickPosY2;


	float JoystickDPosX1;//joystick droite
	float JoystickDPosY1;

	float JoystickDPosX2;
	float JoystickDPosY2;

	bool mannette1 = false;
	bool mannette2 = false;


	
	std::vector<sf::Vector2i>		walls;
	std::vector<sf::RectangleShape> wallSprites;

	ParticleMan beforeParts;
	//ParticleMan afterParts;
	

	Game(sf::RenderWindow * win);

	void cacheWalls();

	void processInput(sf::Event ev);
	bool wasPressed = false;
	void pollInput(double dt);
	void onSpacePressed();

	void update(double dt);

	void draw(sf::RenderWindow& win);

	void onFileTick();
	bool isWall(int cx, int cy);

	void spawnBullet(Vector2f pos, Vector2f dir);
};