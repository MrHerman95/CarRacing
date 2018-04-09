#ifndef COMPUTER_CAR_H
#define COMPUTER_CAR_H

#include "GameObject.h"

class ComputerCar : public GameObject
{
public:
	ComputerCar(int positionX, int positionY);
	~ComputerCar();

	void move();

	virtual vector<int> getPositionsXY() override;

private:
	static const int CAR_WIDTH = 3;
	static const int CAR_HEIGHT = 4;
	int car_[CAR_HEIGHT][CAR_WIDTH] = {
		{ 1, 0, 1 },
		{ 0, 1, 0 },
		{ 1, 1, 1 },
		{ 0, 1, 0 }
	};
};

#endif COMPUTER_CAR_H