#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <map>
#include "Cubic.hpp"
#include "OnlineParams.hpp"
#include "Rotators/Rotation.hpp"

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
	CubicTransformations(OnlineParams& onlineParams);
	std::vector<glm::mat4> getTransformations();
	void initiateCommonTrnasformation(const glm::mat4& commonTrnansformation);
	void handleCamera();
	void setRotators(std::shared_ptr<IRotation>);
	std::vector<std::tuple<const std::vector<Position>&, const std::vector<Position>&>> getPositions();
	std::vector<Cubic>& getCubics();

	void moveLast();
	void stepMove();
private:
	std::vector<Cubic> m_transformations;
	glm::mat4 commonTrnansformation;
	
	OnlineParams& m_onlineParams;
	glm::mat4 prepareCommonTransformation();
};