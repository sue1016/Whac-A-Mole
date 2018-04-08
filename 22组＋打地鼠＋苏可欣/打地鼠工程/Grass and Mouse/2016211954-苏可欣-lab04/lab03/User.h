#pragma once
#include<string>
#include"Mouse.h"
#include"Grass.h"

using namespace std;
class User {
private:
	string userName_;
	string password_;
	int score_;
	static int idOfLastUser_;
public:
	User();
	User(string userName, string password);

	string getUserName();
	void setUserName(string userName);

	int getScore();
	void setScore(int score);
	
	void setPassword(string password);
	string getPassword();
	

	static int getIdOfLastUser();
	
};
