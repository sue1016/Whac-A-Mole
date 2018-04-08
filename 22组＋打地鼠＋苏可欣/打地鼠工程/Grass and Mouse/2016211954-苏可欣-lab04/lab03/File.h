#pragma once
#include<iostream>
#include<fstream>
#include<string> 
#include<time.h>
#include"graphics.h"




class File
{
	private:



public:
	bool isPasswordCorrect(std::string username, std::string passwordInput);//�ж�������ȷ���ĺ��� 
	void renewTotalNum(std::string username);//���ļ��ڵ�ע������+1�ĺ��� 
	int getRanking(std::string username, int score);
	void renewUser(std::string username, std::string password, int score);
	void renewRanking(std::string username, int score_);
	void renewDairy(std::string username, int score, std::string loginTime, std::string logoutTime);
	std::string getTime();
	

	bool isHigherScore(std::string username, int score);
	int getOldRank(std::string username);
	void rankingToRank();
	int getTotalNum();
	bool isUserHasExisted(std::string username);
};