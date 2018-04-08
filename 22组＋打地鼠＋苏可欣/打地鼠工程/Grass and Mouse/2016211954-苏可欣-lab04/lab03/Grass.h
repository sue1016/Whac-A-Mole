#pragma once
#include<iostream>
#include"graphics.h"
#include"Mouse.h"
#include <windows.h> 
#include"time.h"
#include"Res.h"
class Mouse;
class Res;
class Grass
{
private:


	int outRatio_;//How possible each loop each hole can make a mouse out. 
	int mouseRatio_;
	int downRatio_;
	bool isMakingMiceOut_;
	int scoresCanGet_;//Each grass
	Mouse* pMouse_;
	Res* pRes_;
	int tagClicked_;
	int  interval_;//each loop delay 100ms
	int timeInAll_;//how many seconds(round) the grass in all
	int gameLevel_;
	

public:

	Grass(int gameLevel);// 0,1,2
	~Grass();


	void makeMiceOut();
	void waitForClick();
	void showBgImg();
	void showHammerImg();
	void showEndImg();
	void showProgressBar(int coordinateX, int coordinateY, int lengthOfAll, int width);
	int getClickedMouseTag();
	int getScoresCanGet();
	int getGameLevel();
	
};