#include "Cubic.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>
#include <algorithm>
#include <corecrt_math_defines.h>

Cubic::Cubic(std::vector<Position> positions, glm::mat4 initTransformation)
	: m_positions(positions),
	  m_initialPositions(positions),
	  m_transformation(initTransformation),
	  commonTransformation(initTransformation),
	  m_positionSwitch(),
	  m_animationAngle(0.0)
{
}

glm::mat4 Cubic::getTransformation() const
{
	return commonTransformation * m_transformation;
}

float Cubic::getOpacity()
{
	return m_opacity;
}

void Cubic::setOpacity(float opacity)
{
	m_opacity = opacity;
}

void Cubic::initiateTransformation(glm::mat4 addedTransformation)
{
	commonTransformation = addedTransformation;
}

void Cubic::rotateOnAxis(float angle, glm::vec3 axis)
{
	m_transformation = glm::rotate(glm::mat4(1.0f), angle, axis) * m_transformation;
}

void Cubic::rotate()
{
	m_rotator->performRotation(m_transformation);
}

std::vector<Position>& Cubic::getPosition()
{
	return m_positions;
}

std::vector<Position>& Cubic::getInitialPosition()
{
	return m_initialPositions;
}

void Cubic::applyRotator(std::shared_ptr<IRotation> rotator)
{
	if(rotator->isApplicable(m_positions))
		m_rotator = rotator;
}

void Cubic::rotatePosition()
{
	m_rotator->rotatePosition(m_positions);
	m_rotator->rotateInitPosition(m_initialPositions);
}

std::optional<Position> Cubic::getPositionOfInitial(Position initialPosition)
{
	auto foundPosition = std::find(m_initialPositions.begin(), m_initialPositions.end(), initialPosition);
	if (foundPosition == m_initialPositions.end())
		return std::nullopt;
	return m_positions[std::distance(m_initialPositions.begin(), foundPosition)];
}

std::optional<Position> Cubic::getInitialPositionOf(Position currentPosition)
{
	auto foundPosition = std::find(m_positions.begin(),	m_positions.end(), currentPosition);
	if (foundPosition == m_positions.end())
		return std::nullopt;
	return m_initialPositions[std::distance(m_positions.begin(), foundPosition)];
}

std::optional<Position> Cubic::getPositionOtherThan(Position currentPosition)
{
	auto foundPosition = std::find_if_not(m_positions.begin(), m_positions.end(), [&](auto pos) {return pos == currentPosition; });
	if (foundPosition == m_positions.end())
		return std::nullopt;
	return m_positions[std::distance(m_positions.begin(), foundPosition)];

}

std::optional<Position> Cubic::getInitPositionOtherThan(Position currentPosition)
{
	auto foundPosition = std::find_if_not(m_initialPositions.begin(), m_initialPositions.end(), [&](auto pos) {return pos == currentPosition; });
	if (foundPosition == m_initialPositions.end())
		return std::nullopt;
	return m_initialPositions[std::distance(m_initialPositions.begin(), foundPosition)];

}
