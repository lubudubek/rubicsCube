#pragma once

#include "../Cubic.hpp"
#include <algorithm>
#include <vector>

class Rotator
{
public:
	virtual bool move(std::vector<Cubic>& cubic) = 0;
	virtual void animationMove(Cubic& cubic) {};
	virtual void lastMove(Cubic& cubic) {};
};