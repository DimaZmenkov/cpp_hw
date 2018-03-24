#pragma once
#include <memory>
#include<cassert>
using namespace std;
enum Direction
{
	leftMove = 0, rightMove, upMove, bottomMove, neutralMove
};
struct Point
{
	int  x;
	int y;
};
struct Rect 
{
	int left;
	int up;
	int right;
	int bottom;
};