#pragma once
#include"Rectangle.h"
#include"MilitaryInstance.h"

class Factory
{
public:
	//virtual void createMilitaryInstance(const Game & game, const Rect& rect, bool isMain, Direction direction) = 0;
	virtual shared_ptr<MilitaryInstance> createMilitaryInstance(Rect& rect, bool isMain, Direction direction) { return NULL; };
	
	
	
	virtual ~Factory() {}

};