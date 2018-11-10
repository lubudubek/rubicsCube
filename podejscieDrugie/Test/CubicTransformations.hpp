#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <map>
#include "Cubic.hpp"

enum class CubicType
{
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	BOTTOM,
	TOP,

	FRONT_RIGHT,
	FRONT_LEFT,
	BACK_RIGHT,
	BACK_LEFT,
	TOP_RIGHT,
	TOP_LEFT,
	BOTTOM_RIGHT,
	BOTTOM_LEFT,

	TOP_FRONT_RIGHT,
	TOP_FRONT_LEFT,
	TOP_BACK_RIGHT,
	TOP_BACK_LEFT,
	BOTTOM_BACK_RIGHT,
	BOTTOM_BACK_LEFT,
	BOTTOM_FRONT_RIGHT,
	BOTTOM_FRONT_LEFT,
};

class CubicTransformations
{
public:
	CubicTransformations();
	std::vector<glm::mat4> getTransformations();
	void addCommonTrnasformation(const glm::mat4& commonTrnansformation);
	void RotateCenterY(float angle);
	void RotateCenterX(float angle);
	void recalculatePosition(int direction);

private:
	std::vector<Cubic> m_transformations;
	glm::mat4 commonTrnansformation;
};