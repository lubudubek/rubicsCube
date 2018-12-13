#pragma once
#include "Rotator.hpp"

class LeftDownRotator : public Rotator
{
public:
	LeftDownRotator();
	~LeftDownRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};