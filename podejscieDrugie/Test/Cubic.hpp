#pragma once
#include <vector>
#include "glm/glm.hpp"
#include "PositionSwitch.hpp"


class Cubic
{
private:
	std::vector<Position> m_positions;
	std::vector<Position> m_initialPositions;
	glm::mat4 m_transformation;
	glm::mat4 m_initTransformation;
public:
	Cubic(std::vector<Position>, glm::mat4);
	glm::mat4 getTransformation() const;
	void addTransformation(glm::mat4 addedTransformation);
	void initiateTransformation(glm::mat4 addedTransformation);
	std::vector<Position>& getPosition();
	std::vector<Position>& getInitialPosition();


	PositionSwitch m_positionSwitch;

	glm::mat4 commonTransformation;

	void rotateOnAxis(float angle, glm::vec3 axis);
	double m_animationAngle;
	Rotation m_direction;

	void rotatePosition(std::vector<Position> rotation, int direction);
};