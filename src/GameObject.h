#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>

using std::vector;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	void setPositionX(int x);
	void setPositionY(int y);

	int getPositionX();
	int getPositionY();

	virtual vector<int> getPositionsXY() = 0;

protected:
	int positionX_;
	int positionY_;
	vector<int> positionsXY_;
};

#endif GAME_OBJECT_H