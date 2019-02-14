#pragma once
#include <vector>
#include "PositionTypes.hpp"
#include "glm/glm.hpp"

class PositionSwitch
{
public:
	PositionSwitch();
	~PositionSwitch();

	std::pair<std::vector<Position>, glm::vec3> getDirectionX();
	std::pair<std::vector<Position>, glm::vec3> getDirectionY();
	std::pair<std::vector<Position>, glm::vec3> getDirectionZ();
private:
	std::vector<Position> m_directionX;
	std::vector<Position> m_directionY;
	std::vector<Position> m_directionZ;

	glm::vec3 m_xAxisVector;
	glm::vec3 m_yAxisVector;
	glm::vec3 m_zAxisVector;

};