#include "PositionSwitch.hpp"
#include <iostream>

PositionSwitch::PositionSwitch()
	: m_directionX { Position::TOP, Position::FRONT, Position::BOTTOM, Position::BACK },
	  m_directionY { Position::FRONT, Position::RIGHT, Position::BACK, Position::LEFT },
	  m_directionZ { Position::TOP, Position::LEFT, Position::BOTTOM, Position::RIGHT }
{
}

PositionSwitch::~PositionSwitch()
{

}

std::vector<Position> PositionSwitch::getDirectionX()
{
	return m_directionX;
}

std::vector<Position> PositionSwitch::getDirectionY()
{
	return m_directionY;
}

std::vector<Position> PositionSwitch::getDirectionZ()
{
	return m_directionZ;
}