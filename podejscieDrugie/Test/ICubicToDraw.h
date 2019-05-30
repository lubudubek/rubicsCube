#pragma once
#include "glm/fwd.hpp"

class ICubicToDraw
{
	virtual glm::mat4 getTransformation() const = 0;
};