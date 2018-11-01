#include "CubicTransformations.hpp"
#include "glm/gtc/matrix_transform.hpp"

CubicTransformations::CubicTransformations()
{
	m_transformations.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f)));
	m_transformations.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f)));
	m_transformations.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f)));
	m_transformations.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f)));
	m_transformations.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	m_transformations.push_back(glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)));
}

std::vector<glm::mat4> CubicTransformations::getTransformations()
{
	return m_transformations;
}

void CubicTransformations::addCommonTrnasformation(const glm::mat4& commonTrnansformation)
{
	for (auto& transform : m_transformations)
	{
		transform = commonTrnansformation * transform;
	}
}

void CubicTransformations::RotateCenterX(float angle)
{
	m_transformations[0] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[0];
	m_transformations[1] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[1];
	m_transformations[4] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[4];
	m_transformations[5] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[5];
}