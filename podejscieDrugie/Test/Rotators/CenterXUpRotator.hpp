#pragma once
#include "Rotator.hpp"

class CenterXUpRotator : public Rotator
{
public:
	CenterXUpRotator();
	~CenterXUpRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_notRotatedPositions;
	int m_rotationCounter;
};