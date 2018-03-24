#include"stdafx.h"
#include "BulletsFactory.h"
//void BulletsFactory::createMilitaryInstance(const Game & game,
	//const Rect& rect, bool isMain, Direction direction)
shared_ptr<MilitaryInstance> BulletsFactory::createMilitaryInstance(  Rect& rect, bool isMain, Direction direction)
{
	shared_ptr<Bullet> mis(new Bullet(rect, isMain, direction));
	return mis;
}