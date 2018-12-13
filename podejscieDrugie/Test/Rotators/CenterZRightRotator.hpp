#pragma once
#include "Rotator.hpp"

class CenterZRightRotator : public Rotator
{
public:
	CenterZRightRotator();
	~CenterZRightRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_notRotatedPositions;
	int m_rotationCounter;
};