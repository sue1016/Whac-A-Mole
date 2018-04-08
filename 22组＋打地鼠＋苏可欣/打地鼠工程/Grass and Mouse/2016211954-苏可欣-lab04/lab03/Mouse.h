#pragma once
#include<iostream>
#include"graphics.h"
#include"Res.h"
class Res;
class Mouse
{
private:
	
	int tag_;
	bool isMouse_;
	int state_; //mode_ = 0.state:ownStatic; =1 , goUp;=2,upstatic;=3,go down;
	int position_;
	int alpha_;
	int gameLevel_;
	int x_;
	int y_;//Coordinate on the map
	Res* pRes_;

public:

	//Mouse( int bloodsNum, int scoresCanGet, int tag, bool isAlive);
	Mouse();
	~Mouse();
	bool getIsMouse();
	void setIsMouse(bool isMouse);

	int getTag();
	void setTag(int tag);

	int getGameLevel();
	void setGameLevel(int gameLevel);


    int getPosition();
	void setPosition(int position);

	int getState();
	void setState(int state);


	void goOneStepUp();
	void goOneStepDown();
	void keepUpStatic();

	void  setX(int tag);
	void  setY(int tag);
	
	int  getX();
	int  getY();
};		