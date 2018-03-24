#pragma once
#include "Rectangle.h"
#include<cassert>
#include "MilitaryInstance.h"

class Bullet :public MilitaryInstance
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
 Rect getRect() const;
Direction getDirection();
int getCount();
bool getIsMain();
void setRect(const Rect rect);
void setDirection(Direction direction);
void setIsMain(bool isMain);

};

