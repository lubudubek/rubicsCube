#pragma once
#include "Rotator.hpp"

class LeftUpRotator : public Rotator
{
public:
	LeftUpRotator();
	~LeftUpRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};