#include "Bullet.hpp"
#include "Game.hpp"


 void Bullet::update(double dt) {
	
	afterpart.update(dt);

	switch (state)
	{

	case Ide:
	{

	}
	break;

	case Fire:
	{

	}
	break;

	default:
		break;
	}


	/*if () {
		rbx = 0.95;
		//onWallCollision();
	}
	else {
		rbx--;
		cellulex++;
	}*/
	/*while (rbx > 1) {
		if (isWallHitte(cellulex + 1, celluley)) {
			rbx = 0.95;
			//onWallCollision();
		}
		else {
			rbx--;
			cellulex++;
		}
	}*/

	/*while (rbx < 0) {
		if (isWallHitte(cellulex - 1, celluley)) {
			rbx = 0.05;
			//onWallCollision();
		}
		else {
			rbx++;
			cellulex--;
		}
	}*/

	/*if (isWallHitte(cellulex - 1, celluley)) {

	}

	if (isWallHitte(cellulex, celluley + 1)) {
		 
	}


	if (isWallHitte(cellulex, celluley - 1)) {
		
	}*/
	rbx += speedXBullet * dt / Char::GRID_SIZE;
	rby += speedYBullet * dt / Char::GRID_SIZE;

	speedXBullet *= frictionX;
	speedYBullet *= frictionY;
}

 void Bullet::draw(sf::RenderWindow& win) {
	 afterpart.draw(win);
 }

void Bullet::Spawn(Vector2f pos, Vector2f dir) {
	Particle p;
	p.x = pos.x * Char::GRID_SIZE;
	p.y = pos.y * Char::GRID_SIZE;
	p.life = 100;
	p.dx = dir.x *60 * 10;
	p.dy = dir.y * 60 * 10 ;

	p.bhv = [](Particle* p, float dt) {//= //& 
		if (p->life <= 10.0) {
			p->dx *= 0.98;
			p->dy *= 0.98;
		}

		if (p->life <= 20.0) {
			p->scaleX *= 0.95;
			p->scaleY *= 0.95;
		}

	};

	afterpart.add(p);

	cellulex = pos.x;
	celluley = pos.y;

	speedXBullet = dir.x ;
	speedYBullet = dir.y;
	cout << speedXBullet << "\n";
}

bool Bullet::isWallHitte(int cellulex, int celluley)
{
	return gam->isWall(cellulex, celluley);
}

void Bullet::setCellPosition(int cx, int cy) {
	rbx = 0.5;
	rby = 0.99;
	this->cellulex = cx;
	this->celluley = cy;
}

void Bullet::setPosition(int rpx, int rpy) {
	cellulex = rpx / Char::GRID_SIZE;
	rbx = rpx - (cellulex * Char::GRID_SIZE);

	celluley = rpy / Char::GRID_SIZE;
	rby = rpy - (celluley * Char::GRID_SIZE);
}

void Bullet::defaultFrictions() {
	frictionX = 0.87;
	frictionY = 0.87;
}