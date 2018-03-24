#pragma once
#include <stdlib.h>
#include"Rectangle.h"
#include<conio.h>
#include <ctime>
//#include<Windows.h>
#include <stdio.h>
#include <iostream>
//#include <memory>
//#include "Bullet.h"

//#include "BulletsFactory.h"
#include "MilitaryInstance.h"
using namespace std;
//#include"Game.h"


class Tank  : public MilitaryInstance
{
	Point coord_;
	Point lastCoord_;
	int width_;
	int height_;
	int life_;
	Direction direction_;
	
	bool isStricken_;
	bool isMain_;
public :
	Tank();
	void setWidth(int width);
	void setHeight(int height);
	void setCoord(const Point& coord);
	void 	setDirection(Direction direction);
	Direction getDirection();
	void	moveTank();
	void drawTank(HDC dc);
	void 	setIsMain(bool isMain);
	 Rect getRect() const;
	 Point getLastCoord() const;
	 Point getCoord() const;
	void  shoot (Rect& rect, bool& isMain, Direction &direction);
	void decrementLife();
	void setLife(int life);
	bool getIsMain();
	int getLife();
	void setIsStriken(bool isStricken);
	bool getIsStricken();
};