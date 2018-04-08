#include"main.h"
#include"stdio.h"
#include<fstream>

User logOrSign(File file);

void showStory(int n);
int main()
{
	
	File file;
	initgraph(960, 520);
	//setbkcolor(WHITE);
	//string login = file.getTime();
	//string logout = file.getTime();
	//file.renewDairy("zoe", 100, login, logout);
		//void File::renewDairy(std::string username, int score, std::string loginTime, std::string logoutTime)
	User user =	logOrSign(file);
	string loginTime=file.getTime();
	showStory(0);
    Grass* pGrass0 = new Grass(0);
	pGrass0->makeMiceOut();
	

	showStory(1);
	Grass* pGrass1 = new Grass(1);
	pGrass1->makeMiceOut();

	showStory(2);
	Grass* pGrass2 = new Grass(2);
    pGrass2->makeMiceOut();
    pGrass2->showEndImg();
	
	string logoutTime = file.getTime();

	setfont(50, 0, "��Բ");
	setcolor(BLACK);
	user.setScore(pGrass0->getScoresCanGet() + pGrass1->getScoresCanGet() + pGrass2->getScoresCanGet());
	user.getScore();
	xyprintf(300, 192,user.getUserName().c_str());

	char s1[30];
	_itoa_s(user.getScore(), s1, 10);
	xyprintf(678, 262, s1);

	
	char s2[30];
	_itoa_s(file.getRanking(user.getUserName(), user.getScore()), s2, 10);
	xyprintf(540, 330, s2);
	
	
	char s3[30];
	_itoa_s(file.getTotalNum(), s3, 10);
	xyprintf(270, 400, s3);


	file.renewRanking(user.getUserName(), user.getScore());
	file.renewTotalNum(user.getUserName());
	file.renewUser(user.getUserName(), user.getPassword(), user.getScore());
	file.renewDairy(user.getUserName(), user.getScore(), loginTime, logoutTime);
	
	
	
	//file.getRanking(user.getUserName(), user.getScore());
	//file.getTotalNum();
	
  //  delay_ms(4000);
	delete pGrass0;
	delete pGrass1;
	delete pGrass2;
	
	getch();

	//system("pause");
	closegraph();
	
	//file.usersHasSignedUpNumPlusOne();
	//char str[30];
	//_itoa_s(file.getTotalNum(), str, 10, 10);
	//file.getPercent("123", 80);
	//xyprintf(20,60,str);
	//int getTotalNum();
	//file.renewUser("sue", "19971016", 200);
	//file.renewRanking("sue", 180);
	
    //system( "pause");
	//closegraph();

	return 0;
}
User logOrSign(File file)//�Ƿ�Ҫ����һ��������û��� �򷵻��ַ��������Ա㴴����Ӧ�Ķ���
{
	char username[100];
	char userPassword[100];
	char newName[100];
	char newPassword[100];

	initgraph(960, 520);
	PIMAGE img[2];
	img[0] = newimage(960, 520);
	img[1] = newimage(960, 520);
	getimage(img[0], "INITIAL.jpg");
	getimage(img[1], "LOGIN&REGISTER.jpg");
	PIMAGE  login_f;
	login_f = newimage(960, 520);
	getimage(login_f, "login_f.jpg");
	PIMAGE nameNotExist;
	nameNotExist=newimage(960,520);
	getimage(nameNotExist, "nameNotExist.jpg");
	PIMAGE  regi[2];
	regi[0] = newimage(960, 520);
	regi[1] = newimage(960, 520);
	getimage(regi[0],"regi_f.jpg");
	getimage(regi[1], "regi_t.jpg");
	putimage(0, 0, img[0]);
	//�ȴ������   if�����  �������Ϸ����ʾ��¼����
	mouse_msg msg = { 0 };
	for (bool is_initrun = true; is_initrun; delay_fps(60))
	{   
		while (mousemsg())
		{
			msg = getmouse();
		}
		//�ȴ������   if�����  �������Ϸ����ʾ��¼����
   		if (msg.is_left())
		{
			
			putimage(0, 0, img[1]);
		}
		//�����½ҳ��     	
		if (msg.is_left() && (354< msg.x) && (msg.x < 447) && (229 < msg.y) && (msg.y < 271))
		{
			inputbox_getline("      ", "�������û������س�ȷ�ϣ�", username, 100);//�����û���			
			inputbox_getline("      ", "���������루�س�ȷ�ϣ�", userPassword, 100);//��������
			//problem
			//if (username== "passerby")
			//{
			//	break;
			//}
			//else {
				//�����ļ������  ������������break  ������ʾ����ҳ��
				if (file.isUserHasExisted(username))
				{
					if (file.isPasswordCorrect(username, userPassword))
					{
						return User(username, userPassword);

					}
					else
					{
						//showErrorImg;
						putimage(0, 0, login_f);
						delay_ms(500);
						//xyprintf(100, 100, "Wrong");
					}
				}
				else
				{
					putimage(0, 0, nameNotExist);
				}
			//}
		}
		//����ע��ҳ��
		if (msg.is_left() && (507< msg.x) && (msg.x < 601) && (229< msg.y) && (msg.y < 271))
		{
			inputbox_getline("      ", "�������û������س�ȷ�ϣ�", newName, 100);//�����û���
			inputbox_getline("      ", "���������루�س�ȷ�ϣ�", newPassword, 100);//��������
																		//д���ļ�  ��õ����ļ������  ��������д�벢��ʾע��ɹ�
			if (file.isUserHasExisted(newName))//���� ����1
			{
				putimage(0, 0, regi[0]);
				//delay_ms(500);
			}
			else//������  ����0  ����ע��
			{
				putimage(0, 0, regi[1]);
				//file.usersHasSignedUpNumPlusOne();
				//delay_ms(500);
				return User(newName, newPassword);
			}
			//return User(newName, newPassword);
		}
	}
}

void showStory(int n)
{
	PIMAGE story0[3];
	PIMAGE story1[3];
	PIMAGE story2[3];
	story0[0] = newimage(960, 520);
	story0[1] = newimage(960, 520);
	story0[2] = newimage(960, 520);
	story1[0] = newimage(960, 520);
	story1[1] = newimage(960, 520);
	story1[2] = newimage(960, 520);
	story2[0] = newimage(960, 520);
	story2[1] = newimage(960, 520);
	story2[2] = newimage(960, 520);

	getimage(story0[0], "first0.jpg");
	getimage(story0[1], "first1.jpg");
	getimage(story0[2], "first2.jpg");
	getimage(story1[0], "second0.jpg");
	getimage(story1[1], "second1.jpg");
	getimage(story1[2], "second2.jpg");
	getimage(story2[0], "third0.jpg");
	getimage(story2[1], "third1.jpg");
	getimage(story2[2], "third2.jpg");
	switch (n)
	{
	case 0:
		putimage(0, 0, story0[0]);
		delay_ms(1800);
		putimage(0, 0, story0[1]);
		delay_ms(1800);
		putimage(0, 0, story0[2]);
		delay_ms(1800);
		break;
	case 1:
		putimage(0, 0, story1[0]);
		delay_ms(2700);
		putimage(0, 0, story1[1]);
		delay_ms(2700);
		putimage(0, 0, story1[2]);
		delay_ms(2700);
		break;
	case 2:
		putimage(0, 0, story2[0]);
		delay_ms(2700);
		putimage(0, 0, story2[1]);
		delay_ms(2700);
		putimage(0, 0, story2[2]);
		delay_ms(2700);
		break;
	default:
		break;
	}
}
