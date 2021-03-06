#include "stdafx.h"
#include "Game.h"

Game::Game() :
	widthBorder_(10),
	timeSleep_(50),
	quantityWalls_(2),
	widthWalls_(10),
	quantityTanks_(3),
	isWin_(false)
{
	field_.left = 10;
	field_.right = 500;
	field_.bottom = 200;
	field_.up = 30;
	 handle_ = FindWindowA("ConsoleWindowClass", NULL);
	 dc_ = GetDC(handle_);

	 COORD windowBufSize = { 50, 50 };
	 mDwBufferSize.X = 100 + 1;
	 mDwBufferSize.Y = 80 + 1;		// ������ ������ ������

	 mDwBufferCoord.X = 0;
	 mDwBufferCoord.Y = 0;				// ���������� ������

	 mLpWriteRegion.Left = 0;
	 mLpWriteRegion.Top = 0;
	 mLpWriteRegion.Right = 100 + 1;
	 mLpWriteRegion.Bottom = 80 + 1;
	 mChiBuffer = (CHAR_INFO*)malloc((100 + 1)*(80 + 1) * sizeof(CHAR_INFO));
	 console_ = GetStdHandle(STD_OUTPUT_HANDLE);
	 if (!SetConsoleScreenBufferSize(console_, windowBufSize))
	 {
		 cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << endl;
	 }
	 CONSOLE_CURSOR_INFO cursorInfo;
	 GetConsoleCursorInfo(console_, &cursorInfo);
	 cursorInfo.bVisible = FALSE;
	 cursorInfo.dwSize = 1;
	 SetConsoleCursorInfo(console_, &cursorInfo);
	 SMALL_RECT windowSize = { 0,0,150,150 };
	 SetConsoleWindowInfo(console_, TRUE, &windowSize);
	 Rect rect;
	Rectangle(dc_, field_.left, field_.up, field_.left + widthBorder_, field_.bottom);
	rect = { field_.left, field_.up, field_.left + widthBorder_, field_.bottom };
	walls_.push_back(rect);
	Rectangle(dc_, field_.left, field_.up, field_.right, field_.up + widthBorder_);
	rect = { field_.left, field_.up, field_.right, field_.up + widthBorder_ };
	walls_.push_back(rect);
	Rectangle(dc_, field_.right, field_.up, field_.right + widthBorder_, field_.bottom);
	rect = { field_.right, field_.up, field_.right + widthBorder_, field_.bottom };
	walls_.push_back(rect);
	Rectangle(dc_, field_.left, field_.bottom + widthBorder_, field_.right + widthBorder_, 
		field_.bottom);
	rect = { field_.left, field_.bottom  , field_.right + widthBorder_,
		field_.bottom + widthBorder_ };
	walls_.push_back(rect);
	createWalls();
	createTanks();
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 80; j++)
			SetChar(i,j,L' ');
	
}
void Game::drawTanks()
{
	for (int i = 0; i < tanks_.size(); i++)
		tanks_[i].drawTank(dc_);
	mainTank_.drawTank(dc_);
}
void Game::createTanks()
{
	Point coord;
	Rect rect;
	createTank(rect,10,10);
	coord.x = rect.left;
	coord.y = rect.up;
	mainTank_.setCoord(coord);
	mainTank_.setWidth(10);
	mainTank_.setHeight(10);
	mainTank_.drawTank(dc_);
	mainTank_.setDirection(rightMove);
	mainTank_.setIsMain(true);
	mainTank_.setLife(3);
for (int k = 0; k < quantityTanks_; k++)
	{
	Tank tank;
	createTank(rect, 15, 15);
	coord.x = rect.left;
	coord.y = rect.up;
	tank.setCoord(coord);
	tank.setWidth(15);
	tank.setHeight(15);
	tank.drawTank(dc_);
	tank.setDirection(rightMove);
	tank.setIsMain(false);
	tank.setLife(1);
	tanks_.push_back(tank);
}
	

}
void Game::Run()
{
	while (true)
	{
		//drawWalls();
		if (_kbhit())
		{
			KeyPressed(_getch());
		}
		mainTank_.moveTank();
		Rect rect;
		Point coordLast = mainTank_.getLastCoord();
		Point coord = mainTank_.getCoord();
		Direction direction = mainTank_.getDirection();
		switch (direction)
		{
		case leftMove:
		{
			rect.left = coord.x + 10; rect.right = coordLast.x + 10;
			rect.up = coord.y; rect.bottom = coord.y + 10; break; 
		}
		case rightMove:
		{
			rect.left = coordLast.x; rect.right = coord.x;
			rect.up = coord.y ; rect.bottom = coord.y + 10; break;
		}
		case bottomMove:
		{
			rect.left = coord.x; rect.right = coord.x + 10;
			rect.up = coord.y + 10 ; rect.bottom = coordLast.y + 10 ;
			break;
        }
		case upMove:
		{
			rect.left = coord.x; rect.right = coord.x + 10;
			rect.up = coordLast.y; rect.bottom = coord.y;
			break;
		}
		default:
			;
	}
		clearRectangle(rect);
		for (int i = 0; i < tanks_.size(); i++)
			tanks_[i].moveTank();
          testMove();
		drawTanks();
		for (auto it = bullets_.begin();it!= bullets_.end();++it)
		{
			
			it ->move();
			Rect rect = it->getRect();
			Rectangle(dc_, rect.left, rect.up, rect.right, rect.bottom);
			bool flag = false;
			for (int j = 0; j < walls_.size(); j++)
				if (isIntersectRects(walls_[j], it->getRect()))
				{
					flag = true;	bullets_.erase(it); break;
				}
			
			/*switch (bullets_[i].getDirection())
			{
			case leftMove: 
			{
				rect1.left = coord.x - bullets_[i].getCount()*4; 
				rect1.right = rect1.left + 4;
				rect1.up = coord.y; rect1.bottom = coord.y + 5; break;
		    }
			case rightMove:
			{
				rect1.left = coord.x - 5 ; rect1.right = coord.x;
				rect1.up = coord.y; rect1.bottom = coord.y + 5; break;
			}
			case bottomMove:
			{
				rect1.left = coord.x; rect1.right = coord.x + 5;
				rect1.up = coord.y + 5; rect1.bottom = coord.y + 5;
				break;
			}
			case upMove:
			{
				rect.left = coord.x; rect.right = coord.x + 5;
				rect.up = coordLast.y; rect.bottom = coord.y;
				break;
			}
			default:
				;
			}
			clearRectangle(rect1);*/
			if (flag) break;
		}
		testTanks();
		//isWin_ = true;
		//for(int i = 0;i < tanks_.size(); i++)
		//if (tanks_[i].getLife() != 0) { isWin_ = false; break; }
		if (tanks_.size() == 0) {
			isWin_ = true; break;
		}
      Sleep(timeSleep_);
	 // if (isWin_) break;
		//clearScreen();
		
    }
	clearScreen();
	if (isWin_) std::cout << "WIN" << endl;
	Sleep(2000);

	
}
void	Game::createWalls()
{
	int heightField = field_.bottom - field_.up;
	int widthField = field_.right - field_.left;
	bool isVertical = false;
	Rect rect;
	for (int i = 0; i < quantityWalls_; i++)
	{
int width, height;
rect.left = rand() % (widthField - widthWalls_) + field_.left;
width = field_.right - rect.left;
rect.up = rand() % (heightField - widthWalls_) + field_.up;
height = field_.bottom - rect.up;
while (true) {
	if (isVertical)
	{
		rect.bottom = rand() % height + field_.up;
		rect.right = rect.left + widthWalls_;
	}
	else
	{
		rect.right = rand() % width + rect.left;
		rect.bottom = rect.up + widthWalls_;
	}
	bool isIntersect = false;
	for(int j = 0;j < walls_.size();j++)
		if (isIntersectRects(walls_[j], rect)) { isIntersect = true; break; }
	if (!isIntersect) break;
	//cout << "i =" << i << endl;
}
Rectangle(dc_, rect.left, rect.up, rect.right, rect.bottom);
		isVertical = rand() % 2;
		walls_.push_back(rect);
	}

}
	bool Game::isIntersectRects(const Rect& rect1, const Rect& rect2) const
	{
		//if ((wall1.left > wall2.left) && (wall1.left < wall2.right)) return true;
		int maxHorizontal, minHorizontal,maxVertical, minVertical;
		maxHorizontal = (rect1.right > rect2.right) ? rect1.right : rect2.right;
		minHorizontal = (rect1.left < rect2.left) ? rect1.left : rect2.left;
		maxVertical = (rect1.bottom > rect2.bottom) ? rect1.bottom : rect2.bottom;
		minVertical = (rect1.up < rect2.up) ? rect1.up : rect2.up;
		bool isVerticalIntersect = ((maxVertical - minVertical) < (abs(rect1.bottom - rect1.up)
			+ abs(rect2.bottom - rect2.up)));
		
		
		bool isHorizontalIntersect = ((maxHorizontal - minHorizontal) < (abs(rect1.right -rect1.left) +
			abs(rect2.right - rect2.left)));
		return (isHorizontalIntersect&&isVerticalIntersect);
		
		//return false;
}
	void Game::testMove()
	{
		for (int j = 0; j < tanks_.size(); j++)
		{
			for (int k = 0; k < tanks_.size(); k++)
			{
				if ((k!=j)&&(isIntersectRects(tanks_[j].getRect(), tanks_[k].getRect())))

				{
					tanks_[j].setCoord(tanks_[j].getLastCoord());
					tanks_[j].setDirection(convertTo(rand() % 4)); break;
				}
			}
			for (int k = 0; k <walls_.size(); k++)
				if (isIntersectRects(tanks_[j].getRect(), walls_[k]))
				{
					tanks_[j].setCoord(tanks_[j].getLastCoord()); tanks_[j].setDirection(convertTo(rand() % 4)); break;
				}
			if (isIntersectRects(tanks_[j].getRect(), mainTank_.getRect()))
			{
				tanks_[j].setCoord(tanks_[j].getLastCoord()); tanks_[j].setDirection(convertTo(rand() % 4));
			}
		}
		
		
		for(int j = 0;j < walls_.size();j++)
		if(isIntersectRects(mainTank_.getRect(), walls_[j]))
		{
			mainTank_.setCoord(mainTank_.getLastCoord()); mainTank_.setDirection(neutralMove);
			return;
        }
       
	}
	void Game:: KeyPressed(int btnCode)
	{
		if (btnCode == 80) //
			mainTank_.setDirection(upMove); //mObj1Y++;
		else
			if (btnCode == 75) //
			{
				mainTank_.setDirection(leftMove);	//mObj1X--; if ((getCountPress() != 20) && (mObj1Y > 5)) mObj1Y--;
			}
			else
				if (btnCode == 77) //
				{
					mainTank_.setDirection(rightMove);
					//mObj1X++;
					//if ((getCountPress() != 20) && (mObj1Y > 5)) mObj1Y--;
				}
				else
					if(btnCode == 72)
						mainTank_.setDirection(bottomMove);
					if ((char)btnCode == ' ')
					{
						
						Bullet bullet;
						mainTank_.shoot(bullet);
						bullets_.push_back(bullet);
						//Rotate(); flagRotate = true;
					}
	}
	void  Game::createTank(Rect& rect, int width, int height) 
	{
		int heightField = field_.bottom - field_.up;
		int widthField = field_.right - field_.left;
		for (int i = 0; i < walls_.size(); i++)
		{
			while (true) {
				rect.left = rand() % (widthField - 10 - widthBorder_) + field_.left + widthBorder_;
				rect.up = rand() % (heightField - 10 - widthBorder_) + field_.up + widthBorder_; rect.right = rect.left + width;
				rect.bottom = rect.up + height ;
				bool isIntersect = false;
				for (int j = 0; j < walls_.size(); j++)
					if (isIntersectRects(walls_[j], rect)) { isIntersect = true; break; }
				//if(isIntersectRects(walls_[j], rect)
				if (!isIntersect) break;
			}

		}
	}
	wchar_t Game::GetChar(int x, int y)
	{
		return mChiBuffer[x + (100 + 1)*y].Char.AsciiChar;
	}
	void Game::Render()
	{
		if (!WriteConsoleOutput(console_, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion))
		{
			printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
		}
	}
	void Game::SetChar(int x, int y, wchar_t c)
	{
		mChiBuffer[x + (100 + 1)*y].Char.UnicodeChar = c;
		mChiBuffer[x + (100 + 1)*y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;

	}
	Direction Game::convertTo(int num)
	{
		switch (num)
		{
		case 0: return leftMove;
			break;
		case 1: return rightMove;
			break;
		case 2: return upMove;
			break;
		case 3: return bottomMove;
			break;
		case 4: return upMove;
			break;
		default:
			;
		}

		}
	void Game::clearScreen()
	{
		/*COORD c;
		c.X = 0;
		c.Y = 0;
		CONSOLE_SCREEN_BUFFER_INFO bi;
		DWORD written;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
		FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
			bi.dwSize.X*bi.dwSize.Y, c, &written);
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
			FOREGROUND_GREEN, bi.dwSize.X*bi.dwSize.Y, c, &written); 
		//SetPixel(dc_, 0, 0, RGB(0xff, 0, 0));*/
		for(int i =0;i < field_.bottom - field_.up;i++)
			for(int j = 0;j < field_.right - field_.left; j++)

		SetPixel(dc_,  field_.left + j , field_.up + i, 0);
	}
	void Game::drawWalls()
	{
		for (int i = 0; i < walls_.size(); i++)
			Rectangle(dc_, walls_[i].left, walls_[i].up, walls_[i].right, walls_[i].bottom);
	}
	void Game::clearRectangle(const Rect& rect)
	{
       for(int i =0;i < rect.bottom - rect.up;i++ )
		   for(int j =0;j < rect.right - rect.left; j++)
			   SetPixel(dc_, rect.left + j, rect.up + i, 0);
	}
	void Game::testTanks()
	{
		std::vector<Tank>::iterator it1;
		std::vector<Bullet>::iterator it2;
		bool flag = false;
		for (auto it = tanks_.begin(); it!= tanks_.end(); ++it)
			for (auto it0 = bullets_.begin(); it0 != bullets_.end(); ++it0) 
			{
				if ((it0->getIsMain()) &&
					(isIntersectRects(it0->getRect(), it->getRect())))
				{
					it->incrementLife();
					if (it->getLife() == 0) 
					{
						it1 = it; it2 = it0; //it->setIsStriken(true);
						flag = true; break;
					} 
					if (flag) break;
				}
			}
		if (flag) {
			tanks_.erase(it1); 
			bullets_.erase(it2);
		}
	}
	