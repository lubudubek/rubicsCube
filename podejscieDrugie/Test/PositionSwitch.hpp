#pragma once
#include <vector>
#include "PositionTypes.hpp"

class PositionSwitch
{
public:
	PositionSwitch();
	~PositionSwitch();

	void rotate(std::vector<Position>& positions, std::vector<Position> rotation, int direction);
	void rotateForwardX(std::vector<Position>& currentPosition);
	void rotateForwardY(std::vector<Position>& currentPosition);
	void rotateForwardZ(std::vector<Position>& currentPosition);

	void rotateBackwardX(std::vector<Position>& currentPosition);
	void rotateBackwardY(std::vector<Position>& currentPosition);
	void rotateBackwardZ(std::vector<Position>& currentPosition);
private:
	std::vector<Position> m_directionX;
	std::vector<Position> m_directionY;
	std::vector<Position> m_directionZ;
};