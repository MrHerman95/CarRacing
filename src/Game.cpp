#include <conio.h>
#include <ctime>

#include "Game.h"
#include "PerformanceCounter.h"

Game::Game()
{
	playerCar_ = new PlayerCar();
	track_ = new Track();
}



void Game::pressKey(int keyCode)
{
	eraseObject(*playerCar_);

	if (keyCode == LEFT_ARROW)
		playerCar_->turnLeft();
	else if (keyCode == RIGHT_ARROW)
		playerCar_->turnRight();
	else if (keyCode == UP_ARROW)
		speedUp();
	else if (keyCode == DOWN_ARROW)
		speedDown();
	else if (keyCode == ENTER)
		pause();
	else if (keyCode == ESCAPE)
		exit(1);
}



void Game::updateFrame()
{
	eraseObject(*playerCar_);

	for (int i = 0; i < size(cars_); i++) {
		eraseObject(*cars_[i]);
		cars_[i]->move();
		drawObject(*cars_[i]);
		if (cars_[i]->getPositionY() > ConsoleApp::Y_SIZE) {
			cars_.erase(cars_.begin() + i);
		}
	}

	checkCollision();
	
	drawObject(*playerCar_);

	eraseObject(*track_);
	track_->move();
	drawObject(*track_);
}



void Game::run()
{
	Counter timer;
	srand(time(0));

	generatorThread_ = carGenerator();
	generatorThread_.detach();

	double deltaTime = 0.0;
	while (true)
	{
		timer.start();

		if (_kbhit())
			pressKey(_getch());

		updateFrame();
		render();

		while (true)
		{
			deltaTime = timer.getTime();
			if (deltaTime > (150 / gameSpeed_))
				break;
		}
	}
}



void Game::pause()
{
	isPaused_ = true;
	while (true) {
		if (_getch() == ENTER) {
			conditionVar_.notify_one();
			isPaused_ = false;
			break;
		}
	}
}



void Game::drawObject(GameObject& gameObj)
{
	positionsXY_ = gameObj.getPositionsXY();

	for (int i = 0; i < positionsXY_.size(); i += 2) {
		if (positionsXY_[i + 1] > 0 && positionsXY_[i + 1] < ConsoleApp::Y_SIZE )
			setChar(positionsXY_[i], positionsXY_[i + 1], DISPLAY_CHAR);
	}
}



void Game::eraseObject(GameObject& gameObj)
{
	positionsXY_ = gameObj.getPositionsXY();

	for (int i = 0; i < positionsXY_.size(); i += 2) {
		if (positionsXY_[i + 1] > 0 && positionsXY_[i + 1] < ConsoleApp::Y_SIZE)
			setChar(positionsXY_[i], positionsXY_[i + 1], ' ');
	}
}



void Game::speedUp()
{
	gameSpeed_++;
	if (gameSpeed_ > MAX_SPEED)
		gameSpeed_ = 5;
}



void Game::speedDown()
{
	gameSpeed_--;
	if (gameSpeed_ < MIN_SPEED)
		gameSpeed_ = 1;
}



thread Game::carGenerator()
{
	return thread([=] { generateCars(); });
}



void Game::generateCars()
{
	mutex m;
	unique_lock<mutex> lock(m);
	int frequency;

	while (true) {
		if (isPaused_ == true) {
			conditionVar_.wait(lock);
		}
	
		generateNewCar();

		switch (gameSpeed_) {
			case 1 :
				frequency = 1000 + rand() % 800;
				break;

			case 2:
				frequency = 700 + rand() % 400;
				break;

			case 3:
				frequency = 500 + rand() % 300;
				break;

			case 4:
				frequency = 300 + rand() % 200;
				break;

			case 5:
				frequency = 200 + rand() % 200;
				break;
		}

		this_thread::sleep_for(chrono::milliseconds(frequency));
	}
}



void Game::generateNewCar()
{
	int carPosition;
	
	carPosition = rand() % 4 + 1;
	switch (carPosition) {
		case 1 :
			computerCar_ = new ComputerCar(19, -3);
			break;

		case 2 :
			computerCar_ = new ComputerCar(22, -3);
			break;

		case 3 :
			computerCar_ = new ComputerCar(25, -3);
			break;

		case 4 :
			computerCar_ = new ComputerCar(28, -3);
			break;
	}
	cars_.push_back(computerCar_);
}



void Game::checkCollision()
{
	positionsXY_ = playerCar_->getPositionsXY();

	for (int i = 0; i < positionsXY_.size(); i += 2) {
		if (getChar(positionsXY_[i], positionsXY_[i + 1]) == DISPLAY_CHAR) {
			this_thread::sleep_for(chrono::milliseconds(2000));
			exit(1);
		}
	}
}