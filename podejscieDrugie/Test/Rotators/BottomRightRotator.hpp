#pragma once
#include "Rotator.hpp"

class BottomRightRotator : public Rotator
{
public:
	BottomRightRotator();
	~BottomRightRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};