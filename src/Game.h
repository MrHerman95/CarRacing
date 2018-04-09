#ifndef GAME_H
#define GAME_H

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

#include "ConsoleApp.h"
#include "PlayerCar.h"
#include "ComputerCar.h"
#include "Track.h"

using namespace std;

class Game : public ConsoleApp
{
public:
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int LEFT_ARROW = 75;
	const int RIGHT_ARROW = 77;
	const int UP_ARROW = 72;
	const int DOWN_ARROW = 80;

	const int MIN_SPEED = 1;
	const int MAX_SPEED = 5;

	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}

	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	virtual void pressKey(int keyCode) override;
	virtual void updateFrame() override;
	virtual void run() override;
	void pause();

	void drawObject(GameObject& gameObj);
	void eraseObject(GameObject& gameObj);

	void speedUp();
	void speedDown();

	thread carGenerator();
	void generateCars();
	void generateNewCar();

	void checkCollision();

private:
	const char DISPLAY_CHAR = 2;

	Game();
	PlayerCar* playerCar_;
	Track* track_;
	ComputerCar* computerCar_;
	vector<ComputerCar*> cars_;

	vector<int> positionsXY_;

	thread generatorThread_;
	condition_variable conditionVar_;
	bool isPaused_ = false;

	int gameSpeed_ = 1;
};

#endif GAME_H