#ifndef PLAYER_CAR_H
#define PLAYER_CAR_H

#include "GameObject.h"

class PlayerCar : public GameObject
{
public:
	PlayerCar();

	void turnLeft();
	void turnRight();

	virtual vector<int> getPositionsXY() override;

private:
	static const int CAR_WIDTH = 3;
	static const int CAR_HEIGHT = 4;
	int playerCar_[CAR_HEIGHT][CAR_WIDTH] = {
		{ 0, 1, 0 },
		{ 1, 1, 1 },
		{ 0, 1, 0 },
		{ 1, 0, 1 }
	};
};

#endif PLAYER_CAR_H