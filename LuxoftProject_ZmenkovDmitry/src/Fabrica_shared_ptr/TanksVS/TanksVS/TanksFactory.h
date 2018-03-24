#pragma once

#include"Factory.h"
#include"Tank.h"
class TanksFactory 
{
public:
	shared_ptr<MilitaryInstance> createMilitaryInstance( Rect& rect, bool isMain, Direction direction);
	
};
