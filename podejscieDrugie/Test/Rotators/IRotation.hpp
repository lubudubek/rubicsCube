#pragma once
#include <vector>
#include "../PositionTypes.hpp"
#include "glm/glm.hpp"
//#include "res/glm/detail/type_mat4x4.inl"
//enum Position;
//namespace glm
//{
//	class mat4;
//}

class IRotation
{
public:
	virtual bool isApplicable(const std::vector<Position>& cubicPos) = 0;
	virtual void performRotation(glm::mat4& transformation) = 0;
	virtual void rotatePosition(std::vector<Position>& position) = 0;
	virtual void rotateInitPosition(std::vector<Position>& position) = 0;

};