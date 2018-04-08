#include "Grass.h"

Grass::Grass(int gameLevel)
{
	gameLevel_ = gameLevel;
	pRes_ = new Res;
	pMouse_ = new Mouse[8];
	for (int i = 0; i < 8; i++)
	{                                        		
		pMouse_[i].setTag(i);
		pMouse_[i].setGameLevel(gameLevel_);
		pMouse_[i].setX(i);
		pMouse_[i].setY(i);
	}
	//set default nine mice

	isMakingMiceOut_ = false;
	switch (gameLevel_)
	{
	case 0:
	outRatio_ = 5;
	 mouseRatio_ = 80;
	 downRatio_ = 40;
	 break;
	case 1:
		outRatio_ = 20;
		mouseRatio_ = 50;
		downRatio_ = 50;
		break;
	case 2:
		outRatio_ = 65;
		mouseRatio_ = 30;
		downRatio_ = 70;
		break;
	}
	 
     scoresCanGet_ = 0;
	 tagClicked_ = -1;
	 interval_ = 200;//each loop delay 1000ms
	 timeInAll_ = 30;
	 showBgImg();
	 pRes_->playBgm(getGameLevel());
}
Grass::~Grass()
{
	delete[] pMouse_;
//	delete pRes_;
}


void Grass::waitForClick()
{

	clock_t cstart, cends;
	int interval = 0;
	cstart = clock();
	while (interval < interval_)
	{
		char str2[10];
	
		showProgressBar(300, 480, 400, 20);

		setbkmode(TRANSPARENT);
		setcolor(WHITE);
			_itoa_s(scoresCanGet_, str2, 10, 10);
			setfont(30, 0, "幼圆");
		 xyprintf(525, 60, str2);

		

		char str[10];
		cends = clock();
		interval = cends - cstart;
		bool hasExist = false;
		int tagClicked = getClickedMouseTag();
		if (tagClicked != -1 && !hasExist )
		{
		
			tagClicked_ = tagClicked;
			_itoa_s(tagClicked_, str, 10, 10);
			switch(pMouse_[tagClicked_].getState())
			{
			case 0:
			//	xyprintf(60, 60, "Hole:");
			//	xyprintf(100, 60,str);
			//	xyprintf(120, 60,"State:0" );
			//	xyprintf(20, 80, "Clicked, but it is not out");
				break;
				
			case 1:
				//xyprintf(60, 60, "Hole:");
			//	xyprintf(100, 60, str);
			//	xyprintf(120, 60, "State:1");
			//	xyprintf(20, 80, "Clicked, it is going up");
				break;
			case 2:
			//	xyprintf(60, 60, "Hole:");
			//	xyprintf(100, 60, str);
			//	xyprintf(120, 60, "State:2");
			//	xyprintf(20, 100, "Clicked, it is up static");
				break;
			case 3:
			//	xyprintf(60, 60, "Hole:");
			//	xyprintf(100, 60, str);
			//	xyprintf(120, 60, "State:3");
			//	xyprintf(20, 120, "Clicked, it is going down");
				break;
			}
			
			hasExist = true;
		}
	}

}

int Grass::getClickedMouseTag()
{
	PIMAGE hammerNotClick = pRes_->getHammerClickedOrNot(0);
	PIMAGE hammerClicked = pRes_->getHammerClickedOrNot(1);
	int mouse_x, mouse_y;
	mousepos(&mouse_x, &mouse_y);

	mouse_msg msg;
	int op = 1;
	while (op)
	{
		msg = getmouse();

		if (msg.is_left() && msg.is_down() && msg.x >= 177 && msg.x <= 300 && msg.y >= 120 && msg.y <= 228)
		{
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 0;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 400 && msg.x <= 520 && msg.y >= 140 && msg.y <= 260) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 1;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 670 && msg.x <= 790 && msg.y >= 130 && msg.y <= 250) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 2;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 790 && msg.x <= 910 && msg.y >= 220 && msg.y <= 340) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 3;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 80 && msg.x <= 200 && msg.y >= 330 && msg.y <= 450) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 4;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 260 && msg.x <= 380 && msg.y >= 260 && msg.y <= 380) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 5;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 530 && msg.x <= 650 && msg.y >= 300 && msg.y <= 400) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 6;
		}
		else if (msg.is_left() && msg.is_down() && msg.x >= 720 && msg.x <= 840 && msg.y >= 350 && msg.y <= 470) {
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return 7;
		}
		else if (msg.is_left() && msg.is_down())
		{
			//xyprintf(20, 40, "click out of hole!");
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			return -1;//unsure
		}
		else {
			//xyprintf(20, 20, "unclicked");
			
			return -1;

		}
	}
	return -1;


}

void Grass::makeMiceOut()
{
	

	int count = 0;
	const int maxPosition = 5;//!!!!!!!!!!!!!!!!!!!!!!!!!can change
	isMakingMiceOut_ = true;	
	while (isMakingMiceOut_)
	{
		switch (gameLevel_)
		{
		case 0:
			setbkmode(TRANSPARENT);
			setcolor(BLACK);
		setfont(15, 0, "幼圆");
		xyprintf(460, 460, "剩余时间");
		break;
		case 1:
			setbkmode(TRANSPARENT);
			setfont(15, 0, "幼圆");
			setcolor(BLACK);
			xyprintf(460, 460, "剩余时间");
			break;
		case 2:
			setbkmode(TRANSPARENT);
			setfont(15, 0, "幼圆");
			setcolor(WHITE);
			xyprintf(460, 460, "剩余时间");
		}
		setbkmode(TRANSPARENT);
		setfont(12, 0, "幼圆");
		setcolor(BLACK);
		xyprintf(700, 30, "静止鼠标游戏暂停，移动鼠标游戏继续。");
	                            
		int x, y, z;
		tagClicked_ = -1;
		waitForClick();//wait for interval_ ms,and set tagClicked_,if never,keep tagClicked_ = -1;
		showBgImg();
		for (int i = 0; i < 8; i++)//suppose there are 8 holes.
		{
			 x = random(100);//out
			 y = random(100);//bad
			 z = random(100);//down

			switch (pMouse_[i].getState())
			{
			case 0:
				
				if (x < outRatio_)
				{
					//will out
					if (y < mouseRatio_)
					{
						//out a mouse
						pMouse_[i].setIsMouse(true);
					}
					else
					{
						//out a cat
						pMouse_[i].setIsMouse(false);
					}

					pMouse_[i].setState(1);//change into is going up
					pMouse_[i].goOneStepUp();// go 1 step up
					showHammerImg();
				}
				else
				{
					//will not out
					pMouse_[i].setPosition(0);
					pMouse_[i].setState(0);
				}
				break;




			case 1:

				if (pMouse_[i].getPosition() != maxPosition)
				{
					pMouse_[i].setState(1);
					pMouse_[i].goOneStepUp();
				}
				else
				{
					pMouse_[i].keepUpStatic();
					showHammerImg();
					pMouse_[i].setState(2);
					pMouse_[i].setPosition(maxPosition);
				
				}
				break;


			case 2:
				
				if (z < downRatio_)
				{

					//will down
					pMouse_[i].setState(3);
					pMouse_[i].goOneStepDown();
				}
				else
				{ //not down
					pMouse_[i].keepUpStatic();
					showHammerImg();
					pMouse_[i].setPosition(maxPosition);
					pMouse_[i].setState(2);
				}

				break;
			case 3:
				if (pMouse_[i].getPosition() != 0)
				{
					pMouse_[i].goOneStepDown();
					showHammerImg();
				}
				else
				{	
					
				//	pRes_->playEscapeSound();
					pMouse_[i].setState(0);
					pMouse_[i].setPosition(0);
					//play meidazhao music
				
				}
				break;
			default:
				xyprintf(200, 100, "Wrong State");
			}

			if (i == tagClicked_)
			{
				if (pMouse_[i].getState() == 0)
				{
					
					pRes_->playEmptySound();

				}
				else
				{
					if (pMouse_[i].getIsMouse())
					{	
						
						pRes_->playHitMouseSound();


						scoresCanGet_++;
						pMouse_[i].setState(0);
						pMouse_[i].setPosition(0);
					}
					else
					{
						pRes_->playHitCatSound();

						scoresCanGet_--;
						pMouse_[i].setState(0);
						pMouse_[i].setPosition(0);
					}
					
				
				}
			}

			
			



		}
	

			count++;
			if (count == 3)
			{
				timeInAll_--;
				count = 0;
	//one second has passed
			}
			if (timeInAll_ == 0)
			{
				isMakingMiceOut_ = false;
				
			}
		
	}
	
}

void Grass::showProgressBar( int coordinateX, int coordinateY, int lengthOfAll, int width) {


	int lengthOfProgress = lengthOfAll *(30 - timeInAll_) / 30;
	setfillcolor(BLUE);
	bar(coordinateX, coordinateY, coordinateX + lengthOfAll, coordinateY + width);
	setfillcolor(WHITE);
	bar(coordinateX, coordinateY, coordinateX + lengthOfProgress, coordinateY + width);
}

void Grass::showBgImg() 
{
	PIMAGE gameBgImg = pRes_->getGameBgImg(gameLevel_);
	PIMAGE	scoresRecorderImg = pRes_->getScoresRecorderImg();
	putimage(0, 0, gameBgImg);
	putimage_alphatransparent(nullptr, scoresRecorderImg, 320, 50, BLACK, (unsigned char)200);
	
}
void Grass::showHammerImg()
{
	PIMAGE hammerNotClick=pRes_->getHammerClickedOrNot(false);
	PIMAGE hammerClicked=pRes_->getHammerClickedOrNot(true);
	int mouse_x, mouse_y;
	mousepos(&mouse_x, &mouse_y);
	while (1) {
		mouse_msg msg;
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_left() && msg.is_down())
		{
			putimage_alphatransparent(nullptr, hammerClicked, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			//delay_fps(10);
			break;
		}
		else
		{
			putimage_alphatransparent(nullptr, hammerNotClick, mouse_x - 100, mouse_y - 100, BLACK, (unsigned char)255);
			//delay_fps(10);
			break;
		}
	}
}
void Grass::showEndImg()
{
	PIMAGE endImg = pRes_->getEndImg();
	putimage(0, 0, endImg);
	setbkmode(TRANSPARENT);
	setfont(20, 0, "幼圆");
	setcolor(BLACK);
	xyprintf(270, 500, "输入任意键退出游戏，您的账号记录会自动存档");

}
int Grass::getScoresCanGet()
{
	return scoresCanGet_;
}
int Grass::getGameLevel() {
	return gameLevel_;
}