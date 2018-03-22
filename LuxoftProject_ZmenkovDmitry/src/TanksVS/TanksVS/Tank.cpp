#include "stdafx.h"
#include "Tank.h"
Tank::Tank() :
	isStricken_(false)
{

}
void Tank::setWidth(int width)
{
	width_ = width;
}
void Tank::setHeight(int height)
{
	height_ = height;
}
void Tank::setCoord(const Point& coord)
{
	coord_ = coord;
}
void Tank::setDirection(Direction direction)
{
	direction_ = direction;
}
Direction Tank::getDirection()
{
	return direction_;
}
void	Tank::moveTank()
{
	//isMain_ = false;
	lastCoord_ = coord_;
	int coeff = isMain_ ? 2 : 1;
	switch (direction_)
	{
	case leftMove: coord_.x -= coeff;
		break;
	case rightMove: coord_.x += coeff;
		break;
	case upMove: coord_.y += coeff;
		break;
	case bottomMove: coord_.y -= coeff;
	default:
		;
}
	
}
void Tank::drawTank(HDC dc)
{
	Rectangle(dc, coord_.x, coord_.y, coord_.x + width_, coord_.y + height_);
}
void 	Tank::setIsMain(bool isMain)
{
	isMain_ = isMain;
}
 Rect Tank::getRect() const
{
	 Rect rect;
	 rect.left = coord_.x;
	 rect.up = coord_.y;
	 rect.right = coord_.x + width_;
	 rect.bottom = coord_.y + height_;
	 return rect;
}
 Point Tank::getLastCoord() const
 {
	 return lastCoord_;
 }
 Point Tank::getCoord() const
 {
	 return coord_;

 }
 void Tank::shoot(Bullet& bullet  )
 {
	 Rect rect;
	 rect.left = coord_.x; rect.up = coord_.y; rect.bottom = rect.up + 5;
	 rect.right = rect.left + 5;
	 Direction direction = isMain_ ? direction_ :rightMove;
	 Bullet bullet1(rect, isMain_, direction);
	 bullet = bullet1;
}
 void Tank::decrementLife()
 {
	 life_--;
 }
 void Tank::setLife(int life)
 {
	 life_ = life;
 }
 bool Tank::getIsMain()
 {
	 return isMain_;
 }
 int Tank::getLife()
 {
	 return life_;
 }
 void  Tank::setIsStriken(bool isStricken)
 {
	 isStricken_ = isStricken;
 }
 bool Tank::getIsStricken()
 {
	 return isStricken_;
 }
