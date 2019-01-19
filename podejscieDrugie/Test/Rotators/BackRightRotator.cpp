#include "BackRightRotator.hpp"
#include "corecrt_math_defines.h"
#include "../PositionSwitch.hpp"
#include <iostream>
#include <algorithm>
#include "RotatorHelpers.hpp"

BackRightRotator::BackRightRotator()
	: m_rotatedPositions({ Position::BACK }),
	m_rotationCounter(10)
{

}

BackRightRotator::~BackRightRotator()
{

}

bool BackRightRotator::move(std::vector<Cubic>& cubics)
{
	for (auto& cubic : cubics)
	{
		if (isCubicOnAxis(cubic.getPosition(), m_rotatedPositions))
		{
			cubic.rotateOnAxis(-STEP, glm::vec3(0.0f, 0.0f, 1.0f));
			if (m_rotationCounter == 1)
			{
				cubic.rotatePosition(PositionSwitch().getDirectionZ(), 3);
			}
		}
	}
	m_rotationCounter--;
	if (m_rotationCounter == 0)
	{
		m_rotationCounter = 10;
		return false;
	}

	return true;
}

void BackRightRotator::animationMove(Cubic& cubic)
{
	if (isCubicOnAxis(cubic.getPosition(), m_rotatedPositions))
	{
		//std::cout << "back right rotator - animationMove on axis" << std::endl;
		cubic.rotateOnAxis(-STEP, glm::vec3(0.0f, 0.0f, 1.0f));
	}
}

void BackRightRotator::lastMove(Cubic& cubic)
{
	if (isCubicOnAxis(cubic.getPosition(), m_rotatedPositions))
	{
		//std::cout << "back right rotator - last Move on axis" << std::endl;
		cubic.rotatePosition(PositionSwitch().getDirectionZ(), 3);
	}
}