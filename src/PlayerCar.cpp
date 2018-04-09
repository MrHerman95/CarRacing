#include "PlayerCar.h"
#include "Track.h"

PlayerCar::PlayerCar()
{
	positionX_ = 25;
	positionY_ = 20;
}



void PlayerCar::turnLeft()
{
	positionX_ -= 3;
	if (positionX_ < Track::leftBorderPosition_)
		positionX_ += 3;
}



void PlayerCar::turnRight()
{
	positionX_ += 3;
	if (positionX_ + CAR_WIDTH > Track::rightBorderPosition_)
		positionX_ -= 3;
}



vector<int> PlayerCar::getPositionsXY()
{
	positionsXY_.clear();

	for (int x = 0; x < CAR_WIDTH; x++) {
		for (int y = 0; y < CAR_HEIGHT; y++) {
			if (playerCar_[y][x] == 1) {
				positionsXY_.push_back(positionX_ + x);
				positionsXY_.push_back(positionY_ + y);
			}
		}
	}

	return positionsXY_;
}