#include"User.h"
#include<windows.h>
#include "mmsystem.h"//导入声音头文件 
#pragma comment(lib,"winmm.lib")//导入声音头文件库 
#include<stdio.h>

int User::idOfLastUser_(-1);

User::User() {
	userName_ = "Karry";
	password_ = "00000000";
	score_ = 0;
	idOfLastUser_++;
	
}

User::User(string userName, string password) {
	userName_ = userName;
	password_ = password;
	score_ = 0;
	idOfLastUser_++;
}
string User::getUserName() {
	return userName_;
}
string User::getPassword() {
	return password_;
}
int User::getScore() {
	return score_;
}

int User::getIdOfLastUser() {
	return idOfLastUser_;
}

void User::setUserName(string userName) {
	userName_ = userName;
}
void User::setPassword(string password) {
	password_ = password;
}
void User::setScore(int score) {
	score_ = score;
}



