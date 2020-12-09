#include "Char2.hpp"
#include "Game.hpp"

void Char2::setCellPosition(int cx, int cy) {
	rx = 0.5;
	ry = 0.99;
	this->cx = cx;
	this->cy = cy;
}

void Char2::setPosition(int rpx, int rpy) {
	cx = rpx / GRID_SIZE;
	rx = rpx - (cx * GRID_SIZE);

	cy = rpy / GRID_SIZE;
	ry = rpy - (cy * GRID_SIZE);
}

/*void Char::onWallCollision() {
	if (state == WalkTo) stop();
}*/

void Char2::update(double dt) {

	rx += speedX * dt;
	ry += speedY * dt;



	while (rx > 1) {
		if (isWallHit(cx + 1, cy)) {
			rx = 0.95;
			//onWallCollision();
		}
		else {
			rx--;
			cx++;
		}
	}

	while (rx < 0) {
		if (isWallHit(cx - 1, cy)) {
			rx = 0.05;
			//onWallCollision();
		}
		else {
			rx++;
			cx--;
		}
	}

	while (ry > 1) {
		if (isWallHit(cx, cy + 1)) {
			ry = 0.95;
			//onWallCollision();
		}
		else {
			ry--;
			cy++;
		}
	}

	while (ry < 0) {
		if (isWallHit(cx, cy - 1)) {
			ry = 0.05;
			//onWallCollision();
		}
		else {
			ry++;
			cy--;
		}
	}

	/*switch (state)
	{
	case WalkTo:*/
	/*{
		if ( (((int)destX) == cx) && (((int)destY) == cy)) {
			speedX = 0.0;
			speedY = 0.0;
			setState(Idle);
		}
	}
	break;
case Idle:
	if (
		isWallHit(cx, cy - 1)
		|| isWallHit(cx, cy + 1)
		|| isWallHit(cx - 1, cy)
		|| isWallHit(cx + 1, cy)
		) {
		setState(Cover);
	}
	break;
case Cover:
	break;
case Walking:
	if ((abs(speedX) < 0.01) && (abs(speedY) < 0.01)) {
		speedX = 0.0;
		speedY = 0.0;
		setState(Idle);
	}
	break;
case Running:
	if ((abs(speedX) < 0.01) && (abs(speedY) < 0.01)) {
		speedX = 0.0;
		speedY = 0.0;
		setState(Idle);
	}
	break;
default:
	break;
}*/

	speedX *= frictX;
	speedY *= frictY;

	player.setPosition(getPositionPixel());
}

void Char2::stop() {
	speedX = 0.0;
	speedY = 0.0;
}

void Char2::defaultFriction() {
	frictX = 0.87;
	frictY = 0.87;
}

bool Char2::isWallHit(int cx, int cy)
{
	return game->isWall(cx, cy);
}