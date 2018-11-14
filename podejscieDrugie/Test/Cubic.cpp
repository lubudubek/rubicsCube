#include "Cubic.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>
#include <algorithm>
#include <corecrt_math_defines.h>

Cubic::Cubic(std::vector<Position> points, glm::mat4 initTransformation)
	: m_positions(points),
	  m_transformation(initTransformation),
	  m_initTransformation(initTransformation),
	  countX(0),
	  countY(0),
	  m_positionSwitch(),
	  m_animationAngle(0.0),
	  m_direction(Rotation::UNSPECIFIED)
{
}

glm::mat4 Cubic::getTransformation() const
{
	return m_transformation;
}

void Cubic::addTransformation(glm::mat4 addedTransformation)
{
	commonTransformation = addedTransformation;
	m_transformation = addedTransformation * m_transformation;
}

void Cubic::rotateCenterX(float angle)
{
	rotateOnAxis(angle, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Cubic::rotateRightX(float angle)
{
	rotateOnAxis(angle, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Cubic::rotateLeftX(float angle)
{
	rotateOnAxis(angle, glm::vec3(1.0f, 0.0f, 0.0f));
}

void Cubic::rotateCenterY(float angle)
{
	rotateOnAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Cubic::rotateTopY(float angle)
{
	rotateOnAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Cubic::rotateBottomY(float angle)
{
	rotateOnAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Cubic::rotateCenterZ(float angle)
{
	rotateOnAxis(angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Cubic::rotateFrontZ(float angle)
{
	rotateOnAxis(angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Cubic::rotateBackZ(float angle)
{
	rotateOnAxis(angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Cubic::rotateOnAxis(float angle, glm::vec3 axis)
{
	m_transformation = commonTransformation *
		glm::rotate(glm::mat4(1.0f), angle, axis) * glm::inverse(commonTransformation) * m_transformation;
}

void Cubic::startRotation(Rotation direction)
{
	if (m_animationAngle < M_PI / 20)
	{
		m_animationAngle = M_PI / 2.0;
		m_direction = direction;
	}
}

bool Cubic::isCubicOnAxis(Position rotatedPositions)
{
	return std::find(m_positions.begin(), m_positions.end(), rotatedPositions) != m_positions.end();
}

bool Cubic::isCubicNotOnAxis(std::vector<Position> notRotatedPositions)
{
	return std::find_if(m_positions.begin(), m_positions.end(),
						[notRotatedPositions](auto& pos)
						{
							return std::find(notRotatedPositions.begin(),
											 notRotatedPositions.end(),
											 pos) != notRotatedPositions.end();
						}) == m_positions.end();
}

void Cubic::update()
{
	if (m_animationAngle > 0)
	{
		switch (m_direction)
		{
		case Rotation::CENTER_X_ROTATE_UP:
			if (isCubicNotOnAxis({Position::RIGHT, Position::LEFT}))
			{
				rotateCenterX(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_X_ROTATE_UP: before: ( ";
					for (auto& pos : m_positions) { std::cout << pos << " "; }
					m_positionSwitch.rotateForwardX(m_positions);
					std::cout << "), after: ";
					for (auto& pos : m_positions) { std::cout << pos << " "; }
					std::cout << std::endl;
				}
				
			}
			break;
		case Rotation::CENTER_X_ROTATE_DOWN:
			if (isCubicNotOnAxis({ Position::RIGHT, Position::LEFT }))
			{
				rotateCenterX(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_X_ROTATE_DOWN: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardX(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}
				
			}
			break;
		case Rotation::CENTER_Y_ROTATE_LEFT:
			if (isCubicNotOnAxis({ Position::TOP, Position::BOTTOM }))
			{
				rotateCenterY(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_Y_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardY(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}
				
			}
			break;
		case Rotation::CENTER_Y_ROTATE_RIGHT:
			if (isCubicNotOnAxis({ Position::TOP, Position::BOTTOM }))
			{
				rotateCenterY(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_Y_ROTATE_RIGHT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardY(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}
				
			}
			break;
		case Rotation::CENTER_Z_ROTATE_LEFT:
			if (isCubicNotOnAxis({ Position::FRONT, Position::BACK }))
			{
				rotateCenterZ(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_Z_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardZ(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}
				
			}
			break;
		case Rotation::CENTER_Z_ROTATE_RIGHT:
			if (isCubicNotOnAxis({ Position::FRONT, Position::BACK }))
			{
				rotateCenterZ(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_Z_ROTATE_RIGHT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardZ(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}
				
			}
			break;
		case Rotation::RIGHT_ROTATE_UP:
			if (isCubicOnAxis( Position::RIGHT ))
			{
				rotateCenterX(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "RIGHT_ROTATE_DOWN: before: ( ";
					for (auto& pos : m_positions) { std::cout << pos << " "; };
					m_positionSwitch.rotateForwardX(m_positions);
					std::cout << "), after: ";
					for (auto& pos : m_positions) { std::cout << pos << " "; }
					std::cout << std::endl;
				}

			}
			break;
		case Rotation::RIGHT_ROTATE_DOWN:
			if (isCubicOnAxis( Position::RIGHT ))
			{
				rotateCenterX(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "RIGHT_ROTATE_DOWN: before: ( ";
					for (auto& pos : m_positions) { std::cout << pos << " "; };
					m_positionSwitch.rotateBackwardX(m_positions);
					std::cout << "), after: ";
					for (auto& pos : m_positions) { std::cout << pos << " "; }
					std::cout << std::endl;
				}

			}
			break;
		case Rotation::LEFT_ROTATE_UP:
			if (isCubicOnAxis( Position::LEFT ))
			{
				rotateCenterX(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "LEFT_ROTATE_UP: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardX(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::LEFT_ROTATE_DOWN:
			if (isCubicOnAxis( Position::LEFT ))
			{
				rotateCenterX(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "LEFT_ROTATE_DOWN: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardX(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::TOP_ROTATE_LEFT:
			if (isCubicOnAxis( Position::TOP ))
			{
				rotateCenterY(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "TOP_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardY(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::TOP_ROTATE_RIGHT:
			if (isCubicOnAxis( Position::TOP ))
			{
				rotateCenterY(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "TOP_ROTATE_RIGHT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardY(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::BOTTOM_ROTATE_LEFT:
			if (isCubicOnAxis( Position::BOTTOM))
			{
				rotateCenterY(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "BOTTOM_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardY(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::BOTTOM_ROTATE_RIGHT:
			if (isCubicOnAxis( Position::BOTTOM ))
			{
				rotateCenterY(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "BOTTOM_ROTATE_RIGHT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardY(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::FRONT_ROTATE_LEFT:
			if (isCubicOnAxis( Position::FRONT ))
			{
				rotateCenterZ(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "FRONT_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardZ(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::FRONT_ROTATE_RIGHT:
			if (isCubicOnAxis( Position::FRONT ))
			{
				rotateCenterZ(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "CENTER_Y_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardZ(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::BACK_ROTATE_LEFT:
			if (isCubicOnAxis( Position::BACK ))
			{
				rotateCenterZ(M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "BACK_ROTATE_LEFT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateForwardZ(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		case Rotation::BACK_ROTATE_RIGHT:
			if (isCubicOnAxis( Position::BACK ))
			{
				rotateCenterZ(-M_PI / 20);
				if (m_animationAngle == (M_PI / 20))
				{
					std::cout << "BACK_ROTATE_RIGHT: before: ( ";
					for (auto& pos : m_positions) { std::cout << *m_positions.begin() << " "; }
					m_positionSwitch.rotateBackwardZ(m_positions);
					std::cout << "), after: " << *m_positions.begin() << std::endl;
				}

			}
			break;
		}

	}

	m_animationAngle -= (M_PI / 20);
}