#include "CenterYRightRotator.hpp"
#include "corecrt_math_defines.h"
#include "../PositionSwitch.hpp"
#include <iostream>
#include <algorithm>
#include "RotatorHelpers.hpp"

CenterYRightRotator::CenterYRightRotator()
	: m_notRotatedPositions({ Position::TOP, Position::BOTTOM }),
	m_rotationCounter(10)
{

}

CenterYRightRotator::~CenterYRightRotator()
{

}

bool CenterYRightRotator::move(std::vector<Cubic>& cubics)
{
	for (auto& cubic : cubics)
	{
		if (isCubicNotOnAxis(cubic.getPosition(), m_notRotatedPositions))
		{
			cubic.rotateOnAxis(STEP, glm::vec3(0.0f, 1.0f, 0.0f));
			//rotateCenterX(-M_PI / 20);
			//std::cout << "rotate on Axis" << std::endl;
			if (m_rotationCounter == 1)
			{
				//std::cout << "Rotate Position";
				//m_positionSwitch.rotateForwardX(m_positions);
				//m_directionX{ Position::TOP, Position::FRONT, Position::BOTTOM, Position::BACK }
				cubic.rotatePosition(PositionSwitch().getDirectionY(), 1);
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