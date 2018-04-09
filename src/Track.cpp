#include "Track.h"
#include "ConsoleApp.h";

Track::Track()
{
	positionY_ = -1;
}



void Track::move()
{
	positionY_++;
	if (positionY_ == 2)
		positionY_ = 0;
}



vector<int> Track::getPositionsXY()
{
	positionsXY_.clear();

	for (int y = 0; y <= ConsoleApp::Y_SIZE; y++)
	{
		if (y % 3 != 0) {
			positionsXY_.push_back(leftBorderPosition_);
			positionsXY_.push_back(positionY_ + y);
		}
	}
	for (int y = 0; y <= ConsoleApp::Y_SIZE; y++)
	{
		if (y % 3 != 0) {
			positionsXY_.push_back(rightBorderPosition_);
			positionsXY_.push_back(positionY_ + y);
		}
	}

	return positionsXY_;
}