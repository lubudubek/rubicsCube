#pragma once
#include <map>
#include <vector>
#include "Test/PositionTypes.hpp"
#include <algorithm>
#include <iostream>

namespace test
{
	enum class Direction2d
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};

	std::ostream& operator<<(std::ostream& os, Direction2d dir);

	struct MouseRotationKey
	{
		MouseRotationKey(const std::vector<Position>& position,
			Position surface,
			Direction2d direction);

		std::vector<Position> positions;
		Position surface;
		Direction2d direction;

		bool operator<(const MouseRotationKey& l) const;
		bool operator==(const MouseRotationKey& l) const;

	};

	extern std::map<MouseRotationKey, Rotation1> mouseRotationsMap;
	extern std::map<MouseRotationKey, Rotation1> mouseCtrlRotationsMap;
}