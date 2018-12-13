#pragma once
#include "Rotator.hpp"

class TopLeftRotator : public Rotator
{
public:
	TopLeftRotator();
	~TopLeftRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;

private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};