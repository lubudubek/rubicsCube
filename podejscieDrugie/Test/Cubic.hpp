#pragma once
#include <vector>
#include "glm/glm.hpp"
#include "PositionSwitch.hpp"


class Cubic
{
private:
	std::vector<Position> m_positions;
	glm::mat4 m_transformation;
	glm::mat4 m_initTransformation;
public:
	Cubic(std::vector<Position>, glm::mat4);
	glm::mat4 getTransformation() const;
	void addTransformation(glm::mat4 addedTransformation);
	void initiateTransformation(glm::mat4 addedTransformation);

	PositionSwitch m_positionSwitch;

	glm::mat4 commonTransformation;
	void rotateCenterX(float angle);
	void rotateRightX(float angle);
	void rotateLeftX(float angle);

	void rotateCenterY(float angle);
	void rotateTopY(float angle);
	void rotateBottomY(float angle);

	void rotateCenterZ(float angle);
	void rotateFrontZ(float angle);
	void rotateBackZ(float angle);

	short countX;
	short countY;
	short coutnZ;

	void startRotation(Rotation direction);
	void rotateOnAxis(float angle, glm::vec3 axis);
	double m_animationAngle;
	Rotation m_direction;
	void update();
	bool isCubicOnAxis(Position rotatedPositions);
	bool isCubicNotOnAxis(std::vector<Position> notRotatedPositions);
};