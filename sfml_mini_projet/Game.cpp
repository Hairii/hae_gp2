#include "Char.hpp"
#include "Game.hpp"
#include "HotReloadShader.hpp"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

static int cols = 1280 / Char::GRID_SIZE;
static int lastLine = 720 / Char::GRID_SIZE - 1;

Game::Game(sf::RenderWindow * win) {
	this->win = win;
	displace = sf::RectangleShape(Vector2f(1280,720));

	/*bool isOk = tex.loadFromFile("res/bg.jpg");
	if (!isOk) {
		printf("ERR : LOAD FAILED\n");
	}

	isOk = tex2.loadFromFile("res/bg2.jpg");
	if (!isOk)  printf("ERR : LOAD FAILED\n");
	
	isOk = displaceMap.loadFromFile("res/nm.png");
	if (!isOk)  printf("ERR : LOAD FAILED\n");
	

	displace.setTexture(&tex);

	bgShader = new HotReloadShader("res/bg.vert", "res/bg_time.frag");
	doubleShader = new HotReloadShader("res/bg.vert", "res/double.frag");
	displaceShader = new HotReloadShader("res/bg.vert", "res/displace.frag");*/

	if (sf::Joystick::isConnected(1))
	{
		// le joystick est connecté au 1er port du pc
		mannette1 = true;
		cout << "mannette 1 connecter" << "\n";
	}
	if (sf::Joystick::isConnected(2))
	{
		// le joystick est connecté au 1er port du pc
		cout << "mannette 2 connecter" << "\n";
		mannette2 = true;
	}
	else {
		cout << "aucune mannette connecter" << "\n";
		mannette1 = false;
		mannette2 = false;
	}
	
	for (int i = 0; i < 1280 / Char::GRID_SIZE; ++i) {
		walls.push_back( Vector2i(i, 0) );
		walls.push_back( Vector2i(i, lastLine) );

		walls.push_back( Vector2i(0, i) );
		walls.push_back( Vector2i(cols-1, i) );
	}

	
	cacheWalls();

	player1 = Char(this);
	player1.setCellPosition(cols>>1, lastLine-1);

	player2 = Char2(this);
	player2.setCellPosition(cols >> 3, lastLine - 1);

}

void Game::cacheWalls()
{
	wallSprites.clear();
	for (Vector2i & w : walls) {
		sf::RectangleShape rect(Vector2f(16,16));
		rect.setPosition(w.x * Char::GRID_SIZE, w.y * Char::GRID_SIZE);
		rect.setFillColor(sf::Color(0x50ff0ff));
		wallSprites.push_back(rect);
	}
}

void Game::processInput(sf::Event ev) {
	if (ev.type == sf::Event::Closed) {
		win->close();
		closing = true;
		return;
	}
	if (ev.type == sf::Event::KeyReleased) {

		if (ev.key.code == sf::Keyboard::Key::R) {
			player1.setCellPosition(cols >> 1, lastLine-1);
		}
	}

	//add walls on click
	if (ev.type == sf::Event::MouseButtonPressed ) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			int wx = ev.mouseButton.x / Char::GRID_SIZE;
			int wy = ev.mouseButton.y / Char::GRID_SIZE;
			for (auto iter = walls.begin(); iter != walls.end(); iter++) {
				auto& w = *iter;
				if (w.x == wx && w.y == wy) {
					iter = walls.erase(iter);
					cacheWalls();
					return;
				}
			}
			walls.emplace_back(wx, wy);
			cacheWalls();
		}
	}
}


static float g_time = 0.0;
static float g_tickTimer = 0.0;
void Game::update(double dt) {
	pollInput(dt);

	g_time += dt;
	/*if (bgShader) bgShader->update(dt);
	if (doubleShader) doubleShader->update(dt);
	if (displaceShader) displaceShader->update(dt);*/

	//beforeParts.update(dt);

	player1.update(dt);
	player2.update(dt);
	tire.update(dt);


	g_tickTimer -= dt;
	if (g_tickTimer <= 0.0) {
		onFileTick();
		g_tickTimer = 0.1;
	}
}

 void Game::draw(sf::RenderWindow & win) {
	if (closing) return;

	//beforeParts.draw(win);

	for (sf::RectangleShape & r : wallSprites)
		win.draw(r);

	player1.draw(win);
	player2.draw(win);
	tire.draw(win);

}

void Game::pollInput(double dt) {

	float lateralSpeed = 1.0;
	float maxSpeed = 10.0;

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
		mario.setState(Running);
	}*/

	/*if (mario.state == Running) {
		lateralSpeed *= 2.0;
		maxSpeed *= 10.0;
	}*/

	bool moved = false;

	JoystickDPosX1 = sf::Joystick::getAxisPosition(1, sf::Joystick::Z);//Joystick::R axe X de joystick droit pour manette PS4
	JoystickDPosY1 = sf::Joystick::getAxisPosition(1, sf::Joystick::R); //Joystick::R axe Y de joystick droit  pour manette PS4

	

	if (mannette1) {

		JoystickPosY1 = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);//JoystickPosY negatif joystick en haut
		JoystickPosX1 = sf::Joystick::getAxisPosition(1, sf::Joystick::X);//JoystickPosX negatif joystick en gauche

		if (JoystickPosX1 > 10) {
			player1.speedX += lateralSpeed;
			if (player1.speedX > maxSpeed)
				player1.speedX = maxSpeed;
			moved = true;
		}
		if (JoystickPosX1 < -10) {
			player1.speedX -= lateralSpeed;
			if (player1.speedX < -maxSpeed)
				player1.speedX = -maxSpeed;
			moved = true;
		}
		if (JoystickPosY1 < -10) {
			player1.speedY -= lateralSpeed;
			if (player1.speedY < -maxSpeed)
				player1.speedY = -maxSpeed;
			moved = true;
		}
		if (JoystickPosY1 > 10) {
			player1.speedY += lateralSpeed;
			if (player1.speedY > maxSpeed)
				player1.speedY = maxSpeed;
			moved = true;
		}


		if (sf::Joystick::isButtonPressed(1, 1))//bouton B de la mannette XBoX
											//bouton X de la mannette PS4
		{
			float destRx = 1.0  / Char::GRID_SIZE;
			float destRy = 1.0  / Char::GRID_SIZE;

			float MarioPosX = player1.cx + player1.rx;
			float MarioPosY = player1.cy + player1.ry;

			if (!wasPressed) {
				Vector2f dir(destRx - MarioPosX, destRy - MarioPosY);
				Vector2f pos(MarioPosX, MarioPosY);

				Vector2f ndir = dir;
				double len = sqrt(ndir.x * ndir.x + ndir.y * ndir.y);
				if (len <= 0.0)
					len = 1.0;
				ndir.x /= len;
				ndir.y /= len;
				tire.Spawn(pos, ndir);
				wasPressed = true;
			}
			else {
				wasPressed = false;
			}
		}

	}



	JoystickDPosX2 = sf::Joystick::getAxisPosition(2, sf::Joystick::U);//Joystick::R axe X de joystick droit pour manette XBoX
	JoystickDPosY2 = sf::Joystick::getAxisPosition(2, sf::Joystick::V);//Joystick::R axe Y de joystick droit pour manette XBoX

	if (mannette2) {

		JoystickPosY2 = sf::Joystick::getAxisPosition(2, sf::Joystick::Y);//JoystickPosY negatif joystick en haut
		JoystickPosX2 = sf::Joystick::getAxisPosition(2, sf::Joystick::X);//JoystickPosX negatif joystick en gauche

		if (JoystickPosX2 > 10) {
			player2.speedX += lateralSpeed;
			if (player2.speedX > maxSpeed)
				player2.speedX = maxSpeed;
			moved = true;
		}
		if (JoystickPosX2 < -10) {
			player2.speedX -= lateralSpeed;
			if (player2.speedX < -maxSpeed)
				player2.speedX = -maxSpeed;
			moved = true;
		}
		if (JoystickPosY2 < -10) {
			player2.speedY -= lateralSpeed;
			if (player2.speedY < -maxSpeed)
				player2.speedY = -maxSpeed;
			moved = true;
		}
		if (JoystickPosY2 > 10) {
			player2.speedY += lateralSpeed;
			if (player2.speedY > maxSpeed)
				player2.speedY = maxSpeed;
			moved = true;
		}
	}
	/*if (moved) {
		if (mario.state == Cover)
			mario.setState(Walking);
		//walkin  nope 
		//running nope
		if (mario.state == Idle)
			mario.setState(Walking);

	}*/
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		if (!wasPressed) {
			onSpacePressed();
			wasPressed = true;
		}
	}
	else {
		wasPressed = false;
	}

}

void Game::onSpacePressed() {
	
}

void Game::onFileTick() {
	
}

bool Game::isWall(int cx, int cy)
{
	for (Vector2i & w : walls) {
		if (w.x == cx && w.y == cy)
			return true;
	}
	return false;
}

