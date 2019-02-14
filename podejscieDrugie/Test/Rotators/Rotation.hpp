#pragma once
#include <vector>
#include "../PositionTypes.hpp"
//#include "glm/detail/type_mat4x4.inl"
#include "IRotation.hpp"

class Rotation : public IRotation
{
public:
	Rotation(Direction direction,
		     std::pair<std::vector<Position>, glm::vec3> rotationSequence,
		     Position rotatedPosition,
		     std::vector<Position> m_notRotatedPositions);
	virtual void performRotation(glm::mat4& transformation) override;
	virtual bool isApplicable(const std::vector<Position>& cubicPos) override;
	virtual void rotatePosition(std::vector<Position>& positions) override;

private:
	bool isCubicNotOnAxis(const std::vector<Position>& cubicPos, std::vector<Position> notRotatedPositions);
	bool isCubicOnAxis(const std::vector<Position>& cubicPos, std::vector<Position> rotatedPositions);

	Direction m_direction;
	glm::mat4 m_rotationMatrix;
	std::vector<Position> m_rotationSequence;
	std::vector<Position> m_notRotatedPositions;
	Position m_rotatedPosition;
};