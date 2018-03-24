#pragma once
#include "Factory.h"
#include"Bullet.h"

class BulletsFactory : public Factory
{
public:
//virtual	void createMilitaryInstance(const Game & game,
		//const Rect& rect, bool isMain, Direction direction);
	shared_ptr<MilitaryInstance> createMilitaryInstance(   Rect& rect, bool isMain, Direction direction);
	
	


};