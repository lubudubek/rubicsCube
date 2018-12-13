#pragma once
#include "Rotator.hpp"

class CenterZLeftRotator : public Rotator
{
public:
	CenterZLeftRotator();
	~CenterZLeftRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_notRotatedPositions;
	int m_rotationCounter;
};