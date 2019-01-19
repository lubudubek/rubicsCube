#pragma once
#include "Rotator.hpp"

class BackRightRotator : public Rotator
{
public:
	BackRightRotator();
	~BackRightRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;
	virtual void animationMove(Cubic& cubic) override;
	virtual void lastMove(Cubic& cubic) override;
private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};