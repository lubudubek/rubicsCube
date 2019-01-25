#include "CubicTransformations.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <algorithm>
#include <corecrt_math_defines.h>
#include <iostream>
#include "Rotators/EmptyRotator.hpp"

CubicTransformations::CubicTransformations(OnlineParams& onlineParams)
	: m_onlineParams(onlineParams),
	  m_rotator(std::make_shared<EmptyRotator>())
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
	m_transformations.push_back(Cubic({ Position::BOTTOM, Position::FRONT },  glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, -1.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::FRONT,  Position::LEFT },   glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,  0.0f,  1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,   Position::RIGHT },  glm::translate(glm::mat4(1.0f), glm::vec3( 1.0f,  0.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BACK,   Position::TOP },    glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f,  1.0f, -1.0f))));
	m_transformations.push_back(Cubic({ Position::BOTTOM, Position::BACK },   glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, -1.0f, -1.0f))));
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
	glm::mat4 m_proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
	glm::vec3 m_translationB(0.0f, 0.0f, -6.0f);

	glm::mat4 model1 = glm::translate(glm::mat4(1.0f), m_translationB);
	glm::mat4 proj = glm::perspective(m_fovy, float(4 / 3), m_fovy1, m_fovy2);

	glm::mat4 rotationx = glm::rotate(glm::mat4(1.0f), 0.3f, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotationy = glm::rotate(glm::mat4(1.0f), 0.5f, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 commonTrnansformation = m_proj * proj * model1 * rotationx * rotationy;

	initiateCommonTrnasformation(glm::mat4(1.0f));
}

void CubicTransformations::setRotator(std::shared_ptr<Rotator> rotator)
{
}

void CubicTransformations::setRotators(std::shared_ptr<IRotation> rotator)
{
	for (auto& cubic : m_transformations)
	{
		cubic.applyRotator(rotator);
	}
}

std::vector<glm::mat4> CubicTransformations::getTransformations()
{
	std::vector<glm::mat4> transformations;
	for (const auto& transform : m_transformations)
		transformations.push_back(transform.getTransformation());
	return transformations;
}

std::vector<std::tuple<const std::vector<Position>&, const std::vector<Position>&>> CubicTransformations::getPositions()
{
	std::vector<std::tuple<const std::vector<Position>&, const std::vector<Position>&>> result;
	for (auto& cubic : m_transformations)
		result.push_back(std::make_tuple(
			std::ref(cubic.getInitialPosition()), std::ref(cubic.getPosition())));
	return result;
}

void CubicTransformations::initiateCommonTrnasformation(const glm::mat4& commonTrnansformation)
{
	for (auto& transform : m_transformations)
		transform.initiateTransformation(commonTrnansformation);
}

void CubicTransformations::handleCamera()
{
	initiateCommonTrnasformation(prepareCommonTransformation());
}

void CubicTransformations::stepMove()
{
	for (auto& cubic : m_transformations)
	{
		cubic.rotate();
	}
}

void CubicTransformations::moveLast()
{
	for (auto& cubic : m_transformations)
	{
		cubic.rotatePosition();
	}
}

glm::mat4 CubicTransformations::prepareCommonTransformation()
{
	glm::vec3 m_translationB(0.0f, 0.0f, m_onlineParams.transformZ);

	glm::mat4 model1 = glm::translate(glm::mat4(1.0f), m_translationB);
	glm::mat4 proj = glm::perspective(m_onlineParams.fovy, float(4 / 3), m_onlineParams.near, m_onlineParams.far);

	//glm::mat4 m_proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f, 2.8f, 2.0f));
	glm::mat4 transX = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.0f, 0.0f));
	glm::mat4 rotationx = glm::rotate(glm::mat4(1.0f), m_onlineParams.rotateX, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotationy = glm::rotate(glm::mat4(1.0f), m_onlineParams.rotateY, glm::vec3(0.0f, 1.0f, 0.0f));
	return transX * proj * model1 *  rotationx * rotationy *scale;

}