#pragma once

#include "../Cubic.hpp"
#include <algorithm>
#include "corecrt_math_defines.h"

bool isCubicNotOnAxis(std::vector<Position>& cubicPos, std::vector<Position> notRotatedPositions);
bool isCubicOnAxis(std::vector<Position>& cubicPos, std::vector<Position> rotatedPositions);
const float STEP = M_PI / 20.0;