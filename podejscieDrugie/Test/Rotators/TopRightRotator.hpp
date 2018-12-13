#pragma once
#include "Rotator.hpp"

class TopRightRotator : public Rotator
{
public:
	TopRightRotator();
	~TopRightRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};