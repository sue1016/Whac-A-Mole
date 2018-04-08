#include "Mouse.h"

//Mouse::Mouse( int bloodsNum, int scoresCanGet, int tag, bool isAlive)
Mouse::Mouse()
{
	pRes_ = new Res;
	state_ = 0;
	tag_ = -1;
	isMouse_ = true;
	position_ = 0;
	alpha_ = 0;
	x_ = 0;
	y_ = 0;
}

Mouse::~Mouse()
{
	//delete pRes_;

}
void Mouse::setX(int tag)
{
	int x;
	int point[8][2] =
	{
		178, 140,
		400, 160,
		670, 160,
		790, 240,

		80, 350,
		260, 280,
		530, 320,
		720, 370,//最后一个洞 first改图
	};

	x = point[tag][0];
	x_ = x;
}

void Mouse::setY(int tag)
{
	int y;

	int point[8][2] =
	{
	
		178, 140,
		400, 160,
		670, 160,
		790, 240,

		80, 350,
		260, 280,
		530, 320,
		720, 370,//最后一个洞 first改图
	};

	y = point[tag][1];
	y_ = y;

}
int  Mouse::getX()
{
	return x_;
}

int  Mouse::getY()
{
	return y_;
}

bool Mouse::getIsMouse()
{
	return isMouse_;
}

void Mouse::setIsMouse(bool isMouse)
{
	isMouse_ = isMouse;
}

int Mouse::getTag()
{
	return tag_;
}

void Mouse::setTag(int tag)
{
	tag_ = tag;
}


void Mouse::goOneStepUp()
{
	
	switch (position_)
	{
	case 0:
		alpha_ = 0;
		break;
	case 1:
		alpha_ = 100;
		break;
	case 2:
		alpha_ = 200;
		break;
	case 3:
		alpha_ = 250;
		break;
	default:
		alpha_ = 255;
		break;
	}
	position_++;
	PIMAGE gameBgImg;
	PIMAGE mouseOrCatImg;
	gameBgImg = pRes_->getGameBgImg(gameLevel_);
	mouseOrCatImg = pRes_->getMouseOrCatImg(isMouse_);
	//putimage(0, 0, gameBgImg);
    putimage_alphatransparent(nullptr, mouseOrCatImg, x_, y_ - 5*position_, BLACK, (unsigned char)alpha_);
	
}
void Mouse::keepUpStatic()
{

    alpha_ = 255;

	PIMAGE gameBgImg;
	PIMAGE mouseOrCatImg;
	gameBgImg = pRes_->getGameBgImg(gameLevel_);
	mouseOrCatImg = pRes_->getMouseOrCatImg(isMouse_);
	//putimage(0, 0, gameBgImg);
	putimage_alphatransparent(nullptr, mouseOrCatImg, x_, y_ - 5 * position_, BLACK, (unsigned char)alpha_);

}


void Mouse::goOneStepDown()
{
	position_--;
	
	switch (position_)
	{
	case 0:
		alpha_ = 0;
		break;
	case 1:
		alpha_ = 100;
		break;
	case 2:
		alpha_ = 200;
		break;
	case 3:
		alpha_ = 250;
		break;
	default:
		alpha_ = 255;
		break;
	}
	
	PIMAGE gameBgImg;
	PIMAGE mouseOrCatImg;
	gameBgImg = pRes_->getGameBgImg(gameLevel_);
	mouseOrCatImg = pRes_->getMouseOrCatImg(isMouse_);
	//putimage(0, 0, gameBgImg);
	putimage_alphatransparent(nullptr, mouseOrCatImg, x_, y_ -5*position_, BLACK, (unsigned char)alpha_);

	
}

int Mouse::getPosition()
{
	return position_;
}
void Mouse::setPosition(int position)
{
	position_ = position;
}

int Mouse::getGameLevel()
{
	return gameLevel_;
}

void Mouse::setGameLevel(int gameLevel)
{
	gameLevel_ = gameLevel;
}



int Mouse::getState()
{
	return state_;
}

void Mouse::setState(int state)
{
	state_ = state;
}

