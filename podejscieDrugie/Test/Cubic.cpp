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
	  m_animationAngle(0.0),
	  m_direction(Rotation::UNSPECIFIED)
{
}

glm::mat4 Cubic::getTransformation() const
{
	return commonTransformation * m_transformation;
}

void Cubic::addTransformation(glm::mat4 addedTransformation)
{
	m_transformation = addedTransformation * glm::inverse(commonTransformation) * m_transformation;
	commonTransformation = addedTransformation;
}

void Cubic::initiateTransformation(glm::mat4 addedTransformation)
{
	commonTransformation = addedTransformation;
}

void Cubic::rotateOnAxis(float angle, glm::vec3 axis)
{
	m_transformation = glm::rotate(glm::mat4(1.0f), angle, axis) * m_transformation;
}

std::vector<Position>& Cubic::getPosition()
{
	return m_positions;
}

std::vector<Position>& Cubic::getInitialPosition()
{
	return m_initialPositions;
}

//void setRotation(std::shared_ptr<Rotator> m_rotator)
//{
//
//}

void Cubic::rotatePosition(std::vector<Position> rotation, int direction)
{
	for (auto& position : m_positions)
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