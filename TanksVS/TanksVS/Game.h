#pragma once
#include <iostream>
#include "cstdlib"
#include "Tank.h"
#include "Bullet.h"
#include<vector>
using namespace std;
class Game 
{
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	HANDLE console_;
	SMALL_RECT  mLpWriteRegion;
	HWND handle_;
	HDC dc_;
	int widthBorder_;
	Rect	field_;
	std::vector<Tank> tanks_;
	Tank mainTank_;
	Tank tanks1_;
	int timeSleep_;
	std::vector<Rect> walls_;
	std::vector<Bullet> bullets_;
	int quantityWalls_;
	int quantityTanks_;
	int widthWalls_;
	bool isWin_;
	CHAR_INFO* mChiBuffer;
public:
	Game();
	void drawTanks();
	void createTanks();
	void	createWalls();
	bool isIntersectRects(const Rect& wall1, const Rect& wall2) const;
	void Run();
	void testMove();
	void KeyPressed(int btnCode);
	void createTank(Rect& rect, int width, int height);
	void Render();
	
	void SetChar(int x, int y, wchar_t c);
	wchar_t GetChar(int x, int y);
	Direction convertTo(int num);
	void clearScreen();
	void drawWalls();
	void clearRectangle(const Rect& rect);
	void testTanks();

};
