#include"Res.h"
PIMAGE Res::gameBgImg_[3] = { 0,0 ,0 };
PIMAGE Res::mouseOrCatImg_[2] = { 0 ,0 };
PIMAGE Res::hammerImg_[2] = { 0 ,0 };
PIMAGE Res::scoresRecorderImg_ = { 0 };
PIMAGE Res::endImg_ = { 0 };

Res::Res()
{
	gameBgImg_[0] = newimage();
	gameBgImg_[1] = newimage();
	gameBgImg_[2] = newimage();
	mouseOrCatImg_[0] = newimage();
	mouseOrCatImg_[1] = newimage();
	hammerImg_[0] = newimage();
	hammerImg_[1] = newimage();
	scoresRecorderImg_ = newimage();
	endImg_ = newimage();

	getimage(gameBgImg_[0], 0, 0, 90, 60);
	getimage(gameBgImg_[1], 0, 0, 90, 60);
	getimage(gameBgImg_[2], 0, 0, 90, 60);
	getimage(mouseOrCatImg_[0], 0, 0, 90, 60);
	getimage(mouseOrCatImg_[1], 0, 0, 90, 60);
	getimage(hammerImg_[0], 0, 0, 90, 90);
	getimage(hammerImg_[1], 0, 0, 90, 90);
	getimage(scoresRecorderImg_, 0, 0, 90, 90);
	getimage(endImg_, 0, 0, 90, 60);

	getimage(gameBgImg_[0], "first.jpg");
	getimage(gameBgImg_[1], "second.jpg");
	getimage(gameBgImg_[2], "third.jpg");
	getimage(mouseOrCatImg_[0], "bad.png");
	getimage(mouseOrCatImg_[1], "good.png");
	getimage(hammerImg_[0], "hammer1.png");
	getimage(hammerImg_[1], "hammer2.png");
	getimage(scoresRecorderImg_, "scoresRecorder.png");
	getimage(endImg_, "end.jpg");
}

void Res::playBgm(int gameLevel)
{
	char buf[128];
	char str[128] = { 0 };
	int i = 0;
	//use mciSendCommand
	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;
	//SetWindowText(NULL,"12345");
	mciOpen.lpstrDeviceType = "mpegvideo";
	switch (gameLevel) {
	case 0:
        mciOpen.lpstrElementName = "第一关背景音乐 (clip) (clip).wav";
		break;
	case 1:
			mciOpen.lpstrElementName = "第三关背景音乐.wav";
		break;
	case 2:
	mciOpen.lpstrElementName = "第二关背景音乐 (clip) (clip).wav";
		break;
	}
		
	
	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)&mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}

}

void Res::playEmptySound()
{
	/*char buf[128];
	char str[128] = { 0 };
	//int i = 0;
	//use mciSendCommand
	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;
	//SetWindowText(NULL,"12345");
	mciOpen.lpstrDeviceType = "mpegvideo";
	mciOpen.lpstrElementName = "C:\\Users\\tf\\Music\\打空.wav";
	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)&mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}*/
	PlaySound("打空.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void Res::playHitMouseSound()
{
	int x = random(1);

	/*char buf[128];
	char str[128] = { 0 };

	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;

	mciOpen.lpstrDeviceType = "mpegvideo";
	if (x == 0) {
		mciOpen.lpstrElementName = "C:\\Users\\tf\\Music\\打中坏鼠1.wav";
	}
	
	else if (x == 1) {
		mciOpen.lpstrElementName = "C:\\Users\\tf\\Music\\打中坏鼠3.wav";
	}


	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)&mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}*/
	if (x == 0) {
		PlaySound("打中坏鼠1.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	else if (x == 1) {
		PlaySound("打中坏鼠3.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
}

void Res::playHitCatSound() {
	PlaySound("可怜猫叫.wav", NULL, SND_FILENAME | SND_ASYNC);
}


void Res::playEscapeSound() {
	/*char buf[128];
	char str[128] = { 0 };

	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;
	
	mciOpen.lpstrDeviceType = "mpegvideo";
	mciOpen.lpstrElementName = "C:\\Users\\tf\\Music\\没打着.wav";
	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)&mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}*/
	PlaySound("没打着.wav", NULL, SND_FILENAME | SND_ASYNC);
}

PIMAGE Res::getGameBgImg(int i)
{
	return gameBgImg_[i];
}
PIMAGE Res::getScoresRecorderImg()
{
	return scoresRecorderImg_;
}
PIMAGE Res::getMouseOrCatImg(bool isMouse)
{
	if (isMouse)
	{
		return mouseOrCatImg_[0];
	}
	else
	{
		return mouseOrCatImg_[1];
	}
}
PIMAGE Res::getHammerClickedOrNot(bool isClicked)
{
	if (!isClicked)
	{
		return hammerImg_[0];
	}
	else
	{
		return hammerImg_[1];
	}
}
PIMAGE Res::getEndImg()
{
	return endImg_;
}
Res::~Res()
{
	delimage(gameBgImg_[0]);
	delimage(gameBgImg_[1]);
	delimage(gameBgImg_[2]);
	delimage(mouseOrCatImg_[0]);
	delimage(mouseOrCatImg_[1]);
}