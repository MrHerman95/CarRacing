#ifndef CONSOLE_APP_H
#define CONSOLE_APP_H

#include <Windows.h>

class ConsoleApp
{
public:
	static const int X_SIZE = 50;
	static const int Y_SIZE = 25;

	ConsoleApp();
	virtual ~ConsoleApp();

	void setChar(int x, int y, char c);
	char getChar(int x, int y);

	virtual void updateFrame() = 0;
	virtual void pressKey(int keyCode) = 0;
	virtual void run() = 0;

protected:
	void render();

private:
	HANDLE writeHandle_;
	CHAR_INFO* consoleBuffer_;
	COORD bufferSize_;
	COORD charPosition_;
	SMALL_RECT writeArea_;
};

#endif CONSOLE_APP_H