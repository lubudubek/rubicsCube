#include "Cubic.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>
#include <algorithm>
#include <corecrt_math_defines.h>

Cubic::Cubic(std::vector<Position> points, glm::mat4 initTransformation)
	: m_positions(points),
	  m_transformation(initTransformation),
	  m_initTransformation(initTransformation),
	  oldAngleX(0.0f),
	  oldAngleY(0.0f),
	  oldAngleZ(0.0f),
	  countX(0),
	  countY(0)
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

void Cubic::rotateX(float angle)
{
	if(std::find_if(m_positions.begin(), m_positions.end(),
		[](auto& pos) {return pos == Position::TOP
								or pos == Position::BOTTOM
								or pos == Position::FRONT
								or pos == Position::BACK;}) != m_positions.end())
	{
		m_transformation = commonTransformation *
			glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::inverse(commonTransformation) * m_transformation;
	}

	if (angle < M_PI / 20 and oldAngleX > M_PI / 20)
	{
		Position temp = *m_positions.begin();
		if (temp == Position::TOP)
			std::replace(m_positions.begin(), m_positions.end(), Position::TOP, Position::FRONT);
		if (temp == Position::FRONT)
			std::replace(m_positions.begin(), m_positions.end(), Position::FRONT, Position::BOTTOM);
		if (temp == Position::BOTTOM)
			std::replace(m_positions.begin(), m_positions.end(), Position::BOTTOM, Position::BACK);
		if (temp == Position::BACK)
			std::replace(m_positions.begin(), m_positions.end(), Position::BACK, Position::TOP);
		std::cout << " + change position X !!!" << std::endl;

		countX++;
	}

	if (angle > - M_PI / 20 and oldAngleX < - M_PI / 20)
	{
		Position temp = *m_positions.begin();
		if (temp == Position::TOP)
			std::replace(m_positions.begin(), m_positions.end(), Position::TOP, Position::BACK);
		if (temp == Position::BACK)
			std::replace(m_positions.begin(), m_positions.end(), Position::BACK, Position::BOTTOM);
		if (temp == Position::BOTTOM)
			std::replace(m_positions.begin(), m_positions.end(), Position::BOTTOM, Position::FRONT);
		if (temp == Position::FRONT)
			std::replace(m_positions.begin(), m_positions.end(), Position::FRONT, Position::TOP);
		std::cout << " - change position X !!!" << std::endl;

		countX--;
	}
	//std::cout << "angle: " << angle << ", old angle X: " << oldAngleX;
	oldAngleX = angle;


}

void Cubic::rotateY(float angle)
{
	if (std::find_if(m_positions.begin(), m_positions.end(),
		[](auto& pos) {return pos == Position::RIGHT
					or pos == Position::LEFT
					or pos == Position::FRONT
					or pos == Position::BACK;}) != m_positions.end())
	{
		m_transformation = commonTransformation *
			glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::inverse(commonTransformation) * m_transformation;

		if (angle < M_PI / 20 and oldAngleY > M_PI / 20)
		{
			Position temp = *m_positions.begin();
			if (temp == Position::RIGHT)
				std::replace(m_positions.begin(), m_positions.end(), Position::RIGHT, Position::FRONT);
			if (temp == Position::FRONT)
				std::replace(m_positions.begin(), m_positions.end(), Position::FRONT, Position::LEFT);
			if (temp == Position::LEFT)
				std::replace(m_positions.begin(), m_positions.end(), Position::LEFT, Position::BACK);
			if (temp == Position::BACK)
				std::replace(m_positions.begin(), m_positions.end(), Position::BACK, Position::RIGHT);
			std::cout << "change Position Y !!!" << std::endl;

			countY++;
		}

		if ((angle > - M_PI / 20) and (oldAngleY < - M_PI / 20))
		{
			Position temp = *m_positions.begin();
			if (temp == Position::RIGHT)
				std::replace(m_positions.begin(), m_positions.end(), Position::RIGHT, Position::BACK);
			if (temp == Position::BACK)
				std::replace(m_positions.begin(), m_positions.end(), Position::BACK, Position::LEFT);
			if (temp == Position::LEFT)
				std::replace(m_positions.begin(), m_positions.end(), Position::LEFT, Position::FRONT);
			if (temp == Position::FRONT)
				std::replace(m_positions.begin(), m_positions.end(), Position::FRONT, Position::RIGHT);
			std::cout << "change Position Y !!!" << std::endl;

			countY--;
		}
		oldAngleY = angle;
		if (countY == -4 or countY == 4)
		{
			countY = 0;
		}
		if (countX == -4 or countX == 4)
		{
			countX = 0;
		}
	}
}

void Cubic::rotateZ(float angle)
{

}