#pragma once
#include <vector>
#include <glm/glm.hpp>

class CubicTransformations
{
public:
	CubicTransformations();
	std::vector<glm::mat4> getTransformations();
	void addCommonTrnasformation(const glm::mat4& commonTrnansformation);
	void RotateCenterX(float angle);
	//void RotateCenterY();

private:
	std::vector<glm::mat4> m_transformations;
};