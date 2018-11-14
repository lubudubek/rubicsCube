#include "PositionSwitch.hpp"
#include <iostream>

PositionSwitch::PositionSwitch()
	: m_directionX { Position::TOP, Position::FRONT, Position::BOTTOM, Position::BACK },
	  m_directionY { Position::FRONT, Position::LEFT, Position::BACK, Position::RIGHT },
	  m_directionZ { Position::TOP, Position::RIGHT, Position::BOTTOM, Position::LEFT }
{
}

PositionSwitch::~PositionSwitch()
{

}

void PositionSwitch::rotateBackwardX(std::vector<Position>& currentPosition)
{
	rotate(currentPosition, m_directionX, 1);
}


void PositionSwitch::rotateForwardX(std::vector<Position>& currentPosition)
{
	rotate(currentPosition, m_directionX, 3);
}

void PositionSwitch::rotateForwardY(std::vector<Position>& currentPosition)
{
	rotate(currentPosition, m_directionY, 3);
}

void PositionSwitch::rotateForwardZ(std::vector<Position>& currentPosition)
{
	rotate(currentPosition, m_directionZ, 3);
}


void PositionSwitch::rotateBackwardY(std::vector<Position>& currentPosition)
{
	rotate(currentPosition, m_directionY, 1);
}

void PositionSwitch::rotateBackwardZ(std::vector<Position>& currentPosition)
{
	rotate(currentPosition, m_directionZ, 1);
}

void PositionSwitch::rotate(std::vector<Position>& positions, std::vector<Position> rotation, int direction)
{
	for (auto& position : positions)
	{
		//Position temp;
		//std::cout << "old position: " << position << std::endl;
		for (int i = 0; i < rotation.size(); i++)
		{
			//std::cout << "loop rotation at" << i <<": " << rotation[i] << std::endl;
			if (rotation[i] == position)
			{
				position = rotation[(i + direction) % 4];
				//std::cout << "changed to " << position << "which is at rotation [" <<
				//	(i + direction) % 4 << "] (should be equal " << rotation[(i + direction) % 4] << ")" << std::endl;
				break;
			}
			//std::cout << std::endl;
		}
	}
}