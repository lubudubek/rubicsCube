#pragma once
#include <vector>
#include "glm/glm.hpp"

enum class Position
{
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	BOTTOM,
	TOP
};

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
	//void recalculatePosition(int direction);

	glm::mat4 commonTransformation;
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	float oldAngleX;
	float oldAngleY;
	float oldAngleZ;

	short countX;
	short countY;
	short coutnZ;

	//void resetMatrix();
};