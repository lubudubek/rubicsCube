#include "CubicTransformations.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <algorithm>
CubicTransformations::CubicTransformations()
{
	m_transformations.push_back(Cubic({ Position::BACK }, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT }, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::TOP }, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f))));
	m_transformations.push_back(Cubic({ Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f))));
	m_transformations.push_back(Cubic({ Position::RIGHT }, glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, 0.0f))));
	m_transformations.push_back(Cubic({ Position::LEFT }, glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f))));

	float m_fovy = 20.0f;
	float m_fovy1 = 2.0f;
	float m_fovy2 = 10.0f;
	glm::vec3 m_translationB(0.0f, 0.0f, -6.0f);
	glm::mat4 model1 = glm::translate(glm::mat4(1.0f), m_translationB);
	glm::mat4 proj = glm::perspective(m_fovy, float(4 / 3), m_fovy1, m_fovy2);

	glm::mat4 rotationx = glm::rotate(glm::mat4(1.0f), 0.8f, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 commonTrnansformation = proj * model1 * rotationx;
	//glm::mat4 transform1 = glm::inverse(transform);
	//addCommonTrnasformation(transform);
	//addCommonTrnasformation(transform1);
	//RotateCenterY(0.5f);
	//RotateCenterY(0.5f);
	//RotateCenterY(0.5f);

	addCommonTrnasformation(commonTrnansformation);

}

std::vector<glm::mat4> CubicTransformations::getTransformations()
{
	std::vector<glm::mat4> transformations;
	for (const auto& transform : m_transformations)
		transformations.push_back(transform.getTransformation());
	return transformations;
}

void CubicTransformations::addCommonTrnasformation(const glm::mat4& commonTrnansformation)
{
	for (auto& transform : m_transformations)
		transform.addTransformation(commonTrnansformation);
}

void CubicTransformations::RotateCenterY(float angle)
{
	for (auto& transform : m_transformations)
		transform.rotateY(angle);
	//m_transformations[CubicType::RIGHT] =
	//	glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[CubicType::RIGHT];
	//m_transformations[CubicType::LEFT] =
	//	glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[CubicType::LEFT];
	//m_transformations[CubicType::FRONT] =
	//	glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[CubicType::FRONT];
	//m_transformations[CubicType::BACK] =
	//	glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f)) * m_transformations[CubicType::BACK];

	//if (angle > 1.57f or angle <-1.57f)
	//{
	//	glm::mat4 temp = m_transformations[CubicType::RIGHT];
	//	m_transformations[CubicType::RIGHT] = m_transformations[CubicType::FRONT];
	//	m_transformations[CubicType::FRONT] = m_transformations[CubicType::LEFT];
	//	m_transformations[CubicType::LEFT] = m_transformations[CubicType::BACK];
	//	m_transformations[CubicType::BACK] = temp;
	//}


}

void CubicTransformations::RotateCenterX(float angle)
{
	for (auto& transform : m_transformations)
		transform.rotateX(angle);
	//m_transformations[CubicType::TOP] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * m_transformations[CubicType::TOP];
	//m_transformations[CubicType::BOTTOM] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * m_transformations[CubicType::BOTTOM];
	//m_transformations[CubicType::FRONT] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * m_transformations[CubicType::FRONT];
	//m_transformations[CubicType::BACK] = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 0.0f, 0.0f)) * m_transformations[CubicType::BACK];

	//if (angle > 1.57f or angle < -1.57f)
	//{
	//	glm::mat4 temp = m_transformations[CubicType::TOP];
	//	m_transformations[CubicType::TOP] = m_transformations[CubicType::FRONT];
	//	m_transformations[CubicType::FRONT] = m_transformations[CubicType::BOTTOM];
	//	m_transformations[CubicType::BOTTOM] = m_transformations[CubicType::BACK];
	//	m_transformations[CubicType::BACK] = temp;
	//}
}

void CubicTransformations::recalculatePosition(int direction)
{
	//for (auto& transform : m_transformations)
	//	transform.recalculatePosition(direction);
}