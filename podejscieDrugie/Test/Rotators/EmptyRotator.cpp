#include "EmptyRotator.hpp"
#include "corecrt_math_defines.h"
#include "../PositionSwitch.hpp"
#include <algorithm>

EmptyRotator::EmptyRotator()
{

}

EmptyRotator::~EmptyRotator()
{

}

bool EmptyRotator::move(std::vector<Cubic>& cubic)
{
	return false;
}