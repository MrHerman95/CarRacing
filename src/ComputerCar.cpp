#include "ComputerCar.h"
#include "ConsoleApp.h"

ComputerCar::ComputerCar(int positionX, int positionY)
{
	positionX_ = positionX;
	positionY_ = positionY;
}



ComputerCar::~ComputerCar() {}



void ComputerCar::move()
{
	positionY_++;
}



vector<int> ComputerCar::getPositionsXY()
{
	positionsXY_.clear();

	for (int x = 0; x < CAR_WIDTH; x++) {
		for (int y = 0; y < CAR_HEIGHT; y++) {
			if (car_[y][x] == 1) {
				positionsXY_.push_back(positionX_ + x);
				positionsXY_.push_back(positionY_ + y);
			}
		}
	}

	return positionsXY_;
}
