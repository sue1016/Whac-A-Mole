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
	bool isPasswordCorrect(std::string username, std::string passwordInput);//判断密码正确与否的函数 
	void renewTotalNum(std::string username);//让文件内的注册人数+1的函数 
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