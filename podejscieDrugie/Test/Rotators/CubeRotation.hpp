#pragma once
#include <vector>
#include "../PositionTypes.hpp"
//#include "glm/detail/type_mat4x4.inl"
#include "IRotation.hpp"

class CubeRotation : public IRotation
{
public:
	CubeRotation(Direction direction,
		std::pair<std::vector<Position>, glm::vec3> rotationSequence,
		Position rotatedPosition,
		std::vector<Position> m_notRotatedPositions);
	virtual void performRotation(glm::mat4& transformation) override;
	virtual bool isApplicable(const std::vector<Position>& cubicPos) override;
	virtual void rotatePosition(std::vector<Position>& positions) override;
	virtual void rotateInitPosition(std::vector<Position>& positions) override;

private:
	Direction m_direction;
	glm::mat4 m_rotationMatrix;
	std::vector<Position> m_rotationSequence;
	std::vector<Position> m_notRotatedPositions;
	Position m_rotatedPosition;
};