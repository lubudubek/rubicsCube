#include "CubicTransformations.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <algorithm>
#include <corecrt_math_defines.h>

CubicTransformations::CubicTransformations(float translationX, float translationY, float translationZ)
	: m_translationX(translationX), m_translationY(translationY), m_translationZ(translationZ)
{
//CENTERS
	m_transformations.push_back(Cubic({ Position::BACK },   glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f,  0.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT },  glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f,  0.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::TOP },    glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f,  1.0f,  0.0f))));
	m_transformations.push_back(Cubic({ Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, -1.0f,  0.0f))));
	m_transformations.push_back(Cubic({ Position::RIGHT },  glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  0.0f,  0.0f))));
	m_transformations.push_back(Cubic({ Position::LEFT },   glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  0.0f,  0.0f))));

//EDGES
	m_transformations.push_back(Cubic({ Position::FRONT,  Position::RIGHT },  glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  0.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT,  Position::TOP },    glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f,  1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT,  Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, -1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT,  Position::LEFT },   glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  0.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,   Position::RIGHT },  glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  0.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,   Position::TOP },    glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f,  1.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,   Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, -1.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,   Position::LEFT },   glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  0.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BOTTOM, Position::RIGHT },  glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f, -1.0f,  0.0f))));
	m_transformations.push_back(Cubic({ Position::BOTTOM, Position::LEFT },   glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -1.0f,  0.0f))));
	m_transformations.push_back(Cubic({ Position::TOP,    Position::RIGHT },  glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  1.0f,  0.0f))));
	m_transformations.push_back(Cubic({ Position::TOP,    Position::LEFT },   glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  1.0f,  0.0f))));

//CORNERS
	m_transformations.push_back(Cubic({ Position::FRONT, Position::RIGHT, Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f, -1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT, Position::RIGHT, Position::TOP    }, glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT, Position::LEFT,  Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT, Position::LEFT,  Position::TOP    }, glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,  Position::RIGHT, Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f, -1.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,  Position::RIGHT, Position::TOP    }, glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  1.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,  Position::LEFT,  Position::BOTTOM }, glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -1.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,  Position::LEFT,  Position::TOP    }, glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  1.0f, -1.0f))));


	float m_fovy = 20.0f;
	float m_fovy1 = 2.0f;
	float m_fovy2 = 10.0f;
	glm::vec3 m_translationB(0.0f, 0.0f, -6.0f);

	glm::mat4 model1 = glm::translate(glm::mat4(1.0f), m_translationB);
	glm::mat4 proj = glm::perspective(m_fovy, float(4 / 3), m_fovy1, m_fovy2);

	glm::mat4 rotationx = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 commonTrnansformation = proj * model1 * rotationx;

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

void CubicTransformations::recalculatePosition(int direction)
{

}

void CubicTransformations::rotate(Rotation direction)
{
	for (auto& transform : m_transformations)
    	transform.startRotation(direction);
}

void CubicTransformations::update()
{
	for (auto& transform : m_transformations)
		transform.update();
}