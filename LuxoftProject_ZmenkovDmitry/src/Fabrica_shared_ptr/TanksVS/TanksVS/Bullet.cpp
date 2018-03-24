#include"stdafx.h"
#include"Bullet.h"
Bullet::Bullet(const Rect& rect, bool isMain, Direction direction) :
	//rect_(rect),
	//isMain_(isMain),
	speed_(5)
	//direction_(direction)
{
	direction_ = direction;
isMain_ = isMain;
rect_ = rect;
}
void	Bullet::move()
{
	
	switch (direction_)
	{
	case  leftMove:
	{  //assert(false);
		rect_.left -= speed_;  rect_.right -= speed_; break;
	}
	case rightMove:

	{  
		
		rect_.left += speed_;  rect_.right += speed_; break;                      }

	case upMove:
	{  rect_.up += speed_;  rect_.bottom += speed_; break;                      }


	case bottomMove:
	{  rect_.up -= speed_;  rect_.bottom -= speed_; break;                      }
	
	default:
		;
		

}
	count_++;
}
Bullet::Bullet()
	:count_(0)
{}
 Rect Bullet::getRect()const
{
	
	 return rect_;
}
Direction Bullet::getDirection()
{
	return direction_;
}
int Bullet::getCount()
{
	return count_;
}
bool Bullet::getIsMain()
{
	return isMain_;
}
void Bullet::setRect(const Rect rect)
{
	rect_ = rect;
}
void Bullet::setDirection(Direction direction)
{
	direction_ = direction;
}
void Bullet::setIsMain(bool isMain)
{
	isMain_ = isMain;
}