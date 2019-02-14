#include "PositionSwitch.hpp"
#include <iostream>

PositionSwitch::PositionSwitch()
	: m_directionX { Position::TOP, Position::FRONT, Position::BOTTOM, Position::BACK },
	  m_directionY { Position::FRONT, Position::RIGHT, Position::BACK, Position::LEFT },
	  m_directionZ { Position::TOP, Position::LEFT, Position::BOTTOM, Position::RIGHT },
	  m_xAxisVector { glm::vec3(1.0f, 0.0f, 0.0f) },
	  m_yAxisVector { glm::vec3(0.0f, 1.0f, 0.0f) },
	  m_zAxisVector { glm::vec3(0.0f, 0.0f, 1.0f) }
{
}

PositionSwitch::~PositionSwitch()
{

}

std::pair<std::vector<Position>, glm::vec3> PositionSwitch::getDirectionX()
{
	return { m_directionX, m_xAxisVector };
}

std::pair<std::vector<Position>, glm::vec3> PositionSwitch::getDirectionY()
{
	return { m_directionY, m_yAxisVector };
}

std::pair<std::vector<Position>, glm::vec3> PositionSwitch::getDirectionZ()
{
	return { m_directionZ, m_zAxisVector };
}