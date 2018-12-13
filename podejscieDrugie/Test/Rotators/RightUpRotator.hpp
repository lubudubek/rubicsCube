#pragma once
#include "Rotator.hpp"

class RightUpRotator : public Rotator
{
public:
	RightUpRotator();
	~RightUpRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};