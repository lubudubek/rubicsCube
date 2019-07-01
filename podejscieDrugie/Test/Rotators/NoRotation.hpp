#pragma once

#include "IRotation.hpp"

class NoRotation : public IRotation
{
	virtual bool isApplicable(const std::vector<Position>& cubicPos) override;
	virtual void performRotation(glm::mat4& transformation) override;
	virtual void rotatePosition(std::vector<Position>& position) override;
	virtual void rotateInitPosition(std::vector<Position>& position) override;

};