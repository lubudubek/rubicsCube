#pragma once
#include "Rotator.hpp"

class CenterYLeftRotator : public Rotator
{
public:
	CenterYLeftRotator();
	~CenterYLeftRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};