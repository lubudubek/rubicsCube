#pragma once
#include "Rotator.hpp"

class BottomLeftRotator : public Rotator
{
public:
	BottomLeftRotator();
	~BottomLeftRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;
	
private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};