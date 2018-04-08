#pragma once
#include<iostream>
#include"Grass.h"
#include"Mouse.h"
#include <time.h>  
#include<windows.h>
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
#include<stdio.h>
#include"graphics.h"
#include<string>

class Res
{

private:

 static PIMAGE gameBgImg_[3];
 static PIMAGE mouseOrCatImg_[2];
 static PIMAGE hammerImg_[2];
 static PIMAGE scoresRecorderImg_;
 static PIMAGE endImg_;
public:

	Res();
	void playBgm(int gameLevel);
	void playEmptySound();
	void playHitMouseSound();
	void playHitCatSound();
	void playEscapeSound();
	PIMAGE getGameBgImg(int i);
	PIMAGE getScoresRecorderImg();
	PIMAGE getMouseOrCatImg(bool isMouse);
	PIMAGE getHammerClickedOrNot(bool isClicked);
	PIMAGE getEndImg();
	~Res();

};
