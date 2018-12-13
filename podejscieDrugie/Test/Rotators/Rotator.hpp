#pragma once

#include "../Cubic.hpp"
#include <algorithm>

class Rotator
{
public:
	virtual bool move(std::vector<Cubic>& cubic) = 0;
};