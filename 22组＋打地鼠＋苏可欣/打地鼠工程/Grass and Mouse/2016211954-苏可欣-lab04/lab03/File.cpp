#include"File.h"

bool File::isPasswordCorrect(std::string usernameInput, std::string passwordInput)//如果返回值是FALSE，有两种情况：1.该用户没有注册.2注册过，登陆的时候，密码不对。
{
	std::ifstream input(usernameInput.c_str());

	//如果该用户名对应的TXT存在，则能打开，反之不能打开
	if (!input.fail())
	{
		//读出文件中该用户名的最高分数，用户名和密码；
		int highestScoreSaved;
		char usernameSaved[20];
		char passwordSaved[20];
		input >> highestScoreSaved >> usernameSaved >> passwordSaved;
		input.close();//关闭TXT
		return passwordInput == passwordSaved;
	}
	else
		return false;
}


void File::renewTotalNum(std::string username)
{
	int totalNum;
	std::ifstream input("totalNum.txt");
	input >> totalNum;
	input.close();
	if (!isUserHasExisted(username))
	{
		totalNum++;
		std::ofstream output("totalNum.txt");
		output << totalNum;
		output.close();
	}
}

bool File::isHigherScore(std::string username, int score)
{
	int oldScore;
	std::ifstream input(username.c_str());
	input >> oldScore;
	input.close();
	return (oldScore > score);
}


int File::getRanking(std::string username, int score)
{
	std::ifstream input("ranking.txt");
	int totalNum = getTotalNum();
	int rivalPoint;
	char user[20];
	int i = 0;
	input >> rivalPoint >> user;
	i++;
	while ((i<totalNum) && (rivalPoint > score))
	{
		i++;
		input >> rivalPoint >> user;
	}
	if (i==totalNum)
	{
		if (rivalPoint > score)
			i++;
	}
	input.close();
	if (isUserHasExisted(username))
	{
		if (isHigherScore(username, score))
			i--;
	}
	input.close();
	return i;
}

int File::getTotalNum()
{
	std::ifstream input("totalNum.txt");
	int totalNum;
	input >> totalNum;
	input.close();
	return totalNum;
}

bool File::isUserHasExisted(std::string username)
{
	std::ifstream input(username.c_str());
	return !input.fail();
}

void File::renewUser(std::string username, std::string password, int score)
{
	if (!isUserHasExisted(username))
	{
		std::ofstream output(username.c_str());
		output << score << std::endl;
		output << username << std::endl;
		output << password << std::endl;
		output.close();
	}
	else
	{
		if (!isHigherScore(username, score))
		{
			std::ofstream output(username.c_str());
			
		    output << score << std::endl;
			output << username << std::endl;
			output << password << std::endl;
			output.close();
		}
	}
}


void File::rankingToRank()
{
	std::ofstream output("Rank.txt");
	std::ifstream input("ranking.txt");
	int score;
	int totalNum = getTotalNum();
	char user[20];
	for (int i = 0;i<totalNum;i++)
	{
		input >> score >> user;
		output << score << std::endl;
		output << user << std::endl;
	}
}

int File::getOldRank(std::string username)
{
	int i = 0;
	int score;
	char user[20];
	std::ifstream input("ranking.txt");
	input >> score >> user;
	i++;
	while (user != username)
	{
		input >> score >> user;
		i++;
	}
	return i;
}


void File::renewRanking(std::string username, int score_)
{
	int ranking = getRanking(username, score_);
	int totalNum = getTotalNum();
	int j = 0;
	rankingToRank();
	std::ifstream input("Rank.txt");
	std::ofstream output("ranking.txt");
	int point;
	char user[20];
	if (ranking == 1)
	{
		output << score_ << std::endl;
		output << username << std::endl;
	}
	else
	{
		for (int i = 1;i < ranking;i++)
		{
			j++;
			input >> point >> user;
			output << point << std::endl;
			output << user << std::endl;
			//	cout << "output:" << point << " " << user << endl;
		}
		output << score_ << std::endl;
		output << username << std::endl;
		//cout << "output:" << point << " " << user << endl;
	}
	//cout << "user存在吗："<<isUserExist(username) << endl;
	if (isUserHasExisted(username))
	{
		if (!isHigherScore(username, score_))
		{
			int oldRanking = getOldRank(username);
			//	cout << "oldRanking:" << oldRanking << endl;
			for (int i = oldRanking - ranking;i > 0;i--)
			{
				j++;
				input >> point >> user;
				output << point << std::endl;
				output << user << std::endl;
				//	cout << "output:" << point << " " << user << endl;

			}
			input >> point >> user;
			j++;
			while (j != totalNum)
			{
				j++;
				input >> point >> user;
				output << point << std::endl;
				output << user << std::endl;
			}
		}
	}
	else
	{
		while (j != totalNum)
		{
			j++;
			input >> point >> user;
			output << point << std::endl;
			output << user << std::endl;
		}
	}
	input.close();
	output.close();
}


void File::renewDairy(std::string username, int score, std::string loginTime, std::string logoutTime)
{
	std::ofstream output("dairy.txt", std::ios::app);
	output << username << " " << score << " " << "LogIn:" << loginTime << " " << "LogOut:" << logoutTime << std::endl;
}

std::string File::getTime()
{
	time_t nowtime;
	nowtime = time(NULL);
	struct tm* local, *gm;
	local = localtime(&nowtime);
	std::ofstream output("time.txt");
	output << local->tm_year + 1900 << "." << local->tm_mon + 1 << "." << local->tm_mday << "/" << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec;
	output.close();
	std::ifstream input("time.txt");
	char time[30];
	while (!input.eof())
	{
		input >> time;
	}
	std::string Time = time;
	return Time;
	//char year[5];
	//char month[5];
	//char day[5];
	//char hour[5];
	//char min[5];
	//char sec[5];
	//_itoa_s(local->tm_year + 1900, year, 10, 10);
	//_itoa_s(local->tm_mon + 1, month, 10, 10);
	//_itoa_s(local->tm_mday, day, 10, 10);
	//_itoa_s(local->tm_hour, hour, 10, 10);
	//_itoa_s(local->tm_min, min, 10, 10);
	//_itoa_s(local->tm_sec, sec, 10, 10);
	//std::string Year = year;
	//std::string Month = month;
	//std::string Day = day;
	//std::string Hour = hour;
	//std::string Min = min;
	//std::string Sec = sec;
	//std::string time= Year + "." + Month + "." + Day + "  " + Hour + ":" + Min + ":" + Sec;
	//return time;
}
