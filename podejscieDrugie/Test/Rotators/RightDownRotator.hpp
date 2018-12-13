#pragma once
#include "Rotator.hpp"

class RightDownRotator : public Rotator
{
public:
	RightDownRotator();
	~RightDownRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};