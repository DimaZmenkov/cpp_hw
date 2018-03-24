#pragma once
#include"Rectangle.h"
#include<Windows.h>
//#include"Game.h"
class MilitaryInstance
{
	
public:
	//Direction direction_;
	//Rect rect_;
	//bool isMain_;
	~MilitaryInstance() {}
	virtual	void	move() {}
	//virtual	const Rect& getRect() {}
	virtual	Direction getDirection() { 
		Direction direction = rightMove;
	return direction;
	}
	virtual	int getCount() 
	{ 
		return 0; 
	}
	virtual	bool getIsMain() 
	{
		return false;
	}
	virtual void setWidth(int width) 
	{

	}
	virtual	void setHeight(int height) 
	{
	}
	virtual	void setCoord(const Point& coord) 
	{
	}
	virtual	void 	setDirection(Direction direction) 
	{

	}
	
	virtual	void	moveTank() 
	{
	}
	virtual	void drawTank(HDC dc) 
	{
	}
	virtual	void 	setIsMain(bool isMain) 
	{
	}
	virtual	Rect getRect() const 
	{
		Rect rect = { 0,0,0,0 };
		return rect;
	}
	virtual	Point getLastCoord() const 
	{
		Point point = { 0, 0 };
		return point;
	}
	virtual	Point getCoord() const
	{
		Point point = { 0, 0 };
		return point;
		
	}
	virtual	void  shoot(Rect& rect, bool& isMain, Direction & direction) {}
	virtual	void decrementLife() {}
	virtual	void setLife(int life) {}
	
	virtual	int getLife() 
	{
		return 0;
	}
	virtual	void setIsStriken(bool isStricken) 
	{

	}
	virtual	bool getIsStricken() 
	{
		return false;
	}
	virtual void setRect(const Rect rect) {}
	

};