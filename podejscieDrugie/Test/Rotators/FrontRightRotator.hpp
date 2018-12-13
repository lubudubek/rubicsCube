#pragma once
#include "Rotator.hpp"

class FrontRightRotator : public Rotator
{
public:
	FrontRightRotator();
	~FrontRightRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};