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

void Cubic::rotate()
{
	//std::cout << "rotate in cubic" << std::endl;
	m_rotator->performRotation(m_transformation);
	//m_transformation = m_rotator->getRotationMatrix * m_transformation;
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
}
//	for (auto& position : m_positions)
//	{
//		for (int i = 0; i < rotation.size(); i++)
//		{
//			if (rotation[i] == position)
//			{
//				position = rotation[(i + direction) % 4];
//				break;
//			}
//		}
//	}
//}

//void Cubic::rotatePosition()
//{
//	auto rotation = m_rotator->getPositionSequence;
//	auto direction = m_rotator->getDirection;
//	for (auto& position : m_positions)
//	{
//		for (int i = 0; i < rotation.size(); i++)
//		{
//			if (rotation[i] == position)
//			{
//				position = rotation[(i + direction) % 4];
//				break;
//			}
//		}
//	}
//}
