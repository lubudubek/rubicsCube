#pragma once
#include "Rotator.hpp"

class BackLeftRotator : public Rotator
{
public:
	BackLeftRotator();
	~BackLeftRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;
	
private:
	std::vector<Position> m_rotatedPositions;
	int m_rotationCounter;
};