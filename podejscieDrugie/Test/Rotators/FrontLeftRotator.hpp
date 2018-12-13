#pragma once
#include "Rotator.hpp"

class FrontLeftRotator : public Rotator
{
public:
	FrontLeftRotator();
	~FrontLeftRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};