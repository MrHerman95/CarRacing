#ifndef TRACK_H
#define TRACK_H

#include "GameObject.h"

class Track : public GameObject
{
public:
	static const int leftBorderPosition_ = 17;
	static const int rightBorderPosition_ = 32;

	Track();

	void move();

	virtual vector<int> getPositionsXY() override;
};

#endif TRACK_H