#pragma once
#include "Rotator.hpp"

class CenterYRightRotator : public Rotator
{
public:
	CenterYRightRotator();
	~CenterYRightRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_notRotatedPositions;
	int m_rotationCounter;
};