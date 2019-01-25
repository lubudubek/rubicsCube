#pragma once
#include <vector>
#include "Rotation.hpp"
#include "glm/fwd.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <corecrt_math_defines.h>
#include "RotatorHelpers.cpp"

Rotation::Rotation(glm::vec3 axis,
	           Direction direction,
	           std::vector<Position> rotationSequence,
			   Position rotatedPosition,
	           std::vector<Position> notRotatedPositions)
{
	float step = direction == Direction::FORWARD ? M_PI / 20.0 : -M_PI / 20;
	m_rotationMatrix = glm::rotate(glm::mat4(1.0f), step, axis);
	m_direction = direction;
	m_rotationSequence = rotationSequence;
	m_notRotatedPositions = notRotatedPositions;
	m_rotatedPosition = rotatedPosition;
}
void Rotation::performRotation(glm::mat4& transformation)
{
	transformation = m_rotationMatrix * transformation;
}
bool Rotation::isApplicable(const std::vector<Position>& cubicPos)
{
	if (m_notRotatedPositions.empty())
		return isCubicOnAxis(cubicPos, { m_rotatedPosition });
	return isCubicNotOnAxis(cubicPos, m_notRotatedPositions);
}
void Rotation::rotatePosition(std::vector<Position>& positions)
{
	for (auto& position : positions)
	{
		for (int i = 0; i < m_rotationSequence.size(); i++)
		{
			if (m_rotationSequence[i] == position)
			{
				position = m_rotationSequence[(i + (int)m_direction) % 4];
				break;
			}
		}
	}
}

// todo any_of instead of find_if
// todo move to rotation
bool Rotation::isCubicNotOnAxis(const std::vector<Position>& cubicPos, std::vector<Position> notRotatedPositions)
{
	return std::find_if(cubicPos.begin(), cubicPos.end(),
		[notRotatedPositions](auto& pos)
	{
		return std::find(notRotatedPositions.begin(),
			notRotatedPositions.end(),
			pos) != notRotatedPositions.end();
	}) == cubicPos.end();
}

bool Rotation::isCubicOnAxis(const std::vector<Position>& cubicPos, std::vector<Position> rotatedPositions)
{
	return std::find(cubicPos.begin(), cubicPos.end(), rotatedPositions[0]) != cubicPos.end();
}
