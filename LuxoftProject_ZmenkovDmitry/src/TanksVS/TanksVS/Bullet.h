#pragma once
#include "Rectangle.h"
#include<cassert>
enum Direction
{
	leftMove = 0, rightMove, upMove, bottomMove, neutralMove
};
class Bullet
{
	int speed_;
	Direction direction_;
	Rect rect_;
bool isMain_;
int count_;
public :
	Bullet(const Rect& rect, bool isMain, Direction direction);
	Bullet();
void	move();
const Rect& getRect();
Direction getDirection();
int getCount();
bool getIsMain();

};

