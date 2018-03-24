#include"stdafx.h"
#include "TanksFactory.h"
shared_ptr<MilitaryInstance> TanksFactory::createMilitaryInstance( Rect& rect, bool isMain, Direction direction)
{
	shared_ptr<Tank> tank(new Tank());
	Point coord;
	coord.x = rect.left;
	coord.y = rect.up;
	tank->setCoord(coord);
	tank->setDirection(direction);
	tank->setIsMain(isMain);
	return tank;
}