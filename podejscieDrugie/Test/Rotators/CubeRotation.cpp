#include "CubeRotation.hpp"
#pragma once
#include <vector>
//#include "Rotation.hpp"
#include "glm/fwd.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <corecrt_math_defines.h>
#include <algorithm>

CubeRotation::CubeRotation(Direction direction,
	std::pair<std::vector<Position>, glm::vec3> rotationSequence,
	Position rotatedPosition,
	std::vector<Position> notRotatedPositions)
{
	float step = direction == Direction::FORWARD ? M_PI / 20.0 : -M_PI / 20;
	m_rotationMatrix = glm::rotate(glm::mat4(1.0f), step, rotationSequence.second);
	m_direction = direction;
	m_rotationSequence = rotationSequence.first;
	m_notRotatedPositions = notRotatedPositions;
	m_rotatedPosition = rotatedPosition;
}
void CubeRotation::performRotation(glm::mat4& transformation)
{
	transformation = m_rotationMatrix * transformation;
}
bool CubeRotation::isApplicable(const std::vector<Position>& cubicPos)
{
	return true;
}
void CubeRotation::rotatePosition(std::vector<Position>& positions)
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

void CubeRotation::rotateInitPosition(std::vector<Position>& positions)
{
	rotatePosition(positions);
}

// todo any_of instead of find_if
// todo move to rotation
