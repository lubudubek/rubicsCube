#pragma once
#include "Rotator.hpp"

class CenterXDownRotator : public Rotator
{
public:
	CenterXDownRotator();
	~CenterXDownRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_notRotatedPositions;
	int m_rotationCounter;
};