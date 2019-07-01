#pragma once
#include <map>
#include <vector>
#include "../PositionTypes.hpp"

namespace Solution
{
	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteGreenRedCornerSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT, Position::LEFT }, // ok 
			{} },
		{ {Position::FRONT, Position::LEFT, Position::BOTTOM }, // ok
			{Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::LEFT, Position::BOTTOM, Position::FRONT }, // ok
			{Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },

		{ {Position::BOTTOM, Position::RIGHT, Position::FRONT },   // ok
			{} }, // here is solved another cubic
		{ {Position::RIGHT, Position::FRONT, Position::BOTTOM },   // ok
			{} }, // here is solved another cubic
		{ {Position::FRONT, Position::BOTTOM, Position::RIGHT },   // ok
			{} }, // here is solved another cubic

		{ {Position::BOTTOM, Position::BACK, Position::RIGHT },   // ok
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::BACK, Position::RIGHT, Position::BOTTOM },   // ok
			{Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::RIGHT, Position::BOTTOM, Position::BACK },   // ok
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },

		{ {Position::BOTTOM, Position::LEFT, Position::BACK },  // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::LEFT, Position::BACK, Position::BOTTOM },  // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::BACK, Position::BOTTOM, Position::LEFT },  // ok
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },

		{ {Position::FRONT, Position::TOP, Position::LEFT },  // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::LEFT, Position::FRONT, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::TOP, Position::LEFT, Position::FRONT },
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::RIGHT, Position::TOP, Position::FRONT }, // ok
			{Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::FRONT, Position::RIGHT, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::TOP, Position::FRONT, Position::RIGHT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },

		{ {Position::BACK, Position::TOP, Position::RIGHT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::RIGHT, Position::BACK, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::TOP, Position::RIGHT, Position::BACK }, // ok
			{Rotation1::FRONT_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::LEFT, Position::TOP, Position::BACK }, //ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::BACK, Position::LEFT, Position::TOP }, // ok
			{Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::TOP, Position::BACK, Position::LEFT }, // ok
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT} },

	};

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteGreenOrangeCornerSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT, Position::RIGHT }, {} },
		{ {Position::FRONT, Position::RIGHT, Position::BOTTOM },
			{Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT,Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::RIGHT, Position::BOTTOM, Position::FRONT },
			{Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT,Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::BOTTOM, Position::LEFT, Position::FRONT },
			{Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT,Rotation1::LEFT_ROTATE_DOWN, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::LEFT, Position::FRONT, Position::BOTTOM },
			{Rotation1::RIGHT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT,Rotation1::RIGHT_ROTATE_DOWN, Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::FRONT, Position::BOTTOM, Position::LEFT },
			{Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::FRONT_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::BOTTOM, Position::BACK, Position::LEFT },
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::BACK, Position::LEFT, Position::BOTTOM },
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP,Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::LEFT, Position::BOTTOM, Position::BACK },
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP} },

		{ {Position::BOTTOM, Position::RIGHT, Position::BACK },
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::BACK, Position::BOTTOM },
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::BACK, Position::BOTTOM, Position::RIGHT },
			{Rotation1::BACK_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT} },

		{ {Position::RIGHT, Position::FRONT, Position::TOP },
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT,} },
		{ {Position::FRONT, Position::TOP, Position::RIGHT },
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT,Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::TOP, Position::RIGHT, Position::FRONT },
			{Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN} },

		{ {Position::FRONT, Position::LEFT, Position::TOP },
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT,} },
	 	{ {Position::LEFT, Position::TOP, Position::FRONT },
	 		{Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT,Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::TOP, Position::FRONT, Position::LEFT },
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN} },

		{ {Position::LEFT, Position::BACK, Position::TOP },
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT,} },
		{ {Position::BACK, Position::TOP, Position::LEFT },
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT,Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::TOP, Position::LEFT, Position::BACK },
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN} },

		{ {Position::BACK, Position::RIGHT, Position::TOP },
			{Rotation1::FRONT_ROTATE_LEFT,Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT,} },
		{ {Position::RIGHT, Position::TOP, Position::BACK },
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT,Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::TOP, Position::BACK, Position::RIGHT },
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT,Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN} },
	};

	// -------------------------------------------------------
	// -------------------------------------------------------
	// -------------------------------------------------------
	// ---------------WhiteBlueOrangeCornerSolvMap------------
	// -------------------------------------------------------
	// -------------------------------------------------------

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteBlueOrangeCornerSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT, Position::LEFT }, // ok 
			{} },
		{ {Position::FRONT, Position::LEFT, Position::BOTTOM }, // ok
			{} },
		{ {Position::LEFT, Position::BOTTOM, Position::FRONT }, // ok
			{} },

		{ {Position::BOTTOM, Position::RIGHT, Position::FRONT },   // ok
			{} }, // here is solved another cubic
		{ {Position::RIGHT, Position::FRONT, Position::BOTTOM },   // ok
			{} }, // here is solved another cubic
		{ {Position::FRONT, Position::BOTTOM, Position::RIGHT },   // ok
			{} }, // here is solved another cubic

		{ {Position::BOTTOM, Position::BACK, Position::RIGHT },   // ok
			{} },
		{ {Position::BACK, Position::RIGHT, Position::BOTTOM },   // ok
			{Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::RIGHT, Position::BOTTOM, Position::BACK },   // ok
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },

		{ {Position::BOTTOM, Position::LEFT, Position::BACK },  // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::LEFT, Position::BACK, Position::BOTTOM },  // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP } },
		{ {Position::BACK, Position::BOTTOM, Position::LEFT },  // ok
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },

		{ {Position::FRONT, Position::TOP, Position::LEFT },  // ok
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::LEFT, Position::FRONT, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::TOP, Position::LEFT, Position::FRONT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },

		{ {Position::RIGHT, Position::TOP, Position::FRONT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::FRONT, Position::RIGHT, Position::TOP }, // ok
			{Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::TOP, Position::FRONT, Position::RIGHT }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },
	// above checked
		{ {Position::BACK, Position::TOP, Position::RIGHT }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::RIGHT, Position::BACK, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::TOP, Position::RIGHT, Position::BACK }, // ok
			{Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },

		{ {Position::LEFT, Position::TOP, Position::BACK }, // ok
			{Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::BACK, Position::LEFT, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::TOP, Position::BACK, Position::LEFT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },
	};

	// -------------------------------------------------------
	// -------------------------------------------------------
	// -------------------------------------------------------
	// ---------------WhiteBlueOrangeCornerSolvMap------------
	// -------------------------------------------------------
	// -------------------------------------------------------

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteBlueRedCornerSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT, Position::LEFT }, // ok 
			{} },
		{ {Position::FRONT, Position::LEFT, Position::BOTTOM }, // ok
			{} },
		{ {Position::LEFT, Position::BOTTOM, Position::FRONT }, // ok
			{} },

		{ {Position::BOTTOM, Position::RIGHT, Position::FRONT },   // ok
			{} }, // here is solved another cubic
		{ {Position::RIGHT, Position::FRONT, Position::BOTTOM },   // ok
			{} }, // here is solved another cubic
		{ {Position::FRONT, Position::BOTTOM, Position::RIGHT },   // ok
			{} }, // here is solved another cubic

		{ {Position::BOTTOM, Position::BACK, Position::RIGHT },   // ok
			{} },
		{ {Position::BACK, Position::RIGHT, Position::BOTTOM },   // ok
			{} },
		{ {Position::RIGHT, Position::BOTTOM, Position::BACK },   // ok
			{} },

		{ {Position::BOTTOM, Position::LEFT, Position::BACK },  // ok
			{} },
		{ {Position::LEFT, Position::BACK, Position::BOTTOM },  // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::BACK, Position::BOTTOM, Position::LEFT },  // ok
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP} },

		{ {Position::FRONT, Position::TOP, Position::LEFT },  // ok
			{Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::LEFT, Position::FRONT, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP } },
		{ {Position::TOP, Position::LEFT, Position::FRONT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },

		{ {Position::RIGHT, Position::TOP, Position::FRONT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::FRONT, Position::RIGHT, Position::TOP }, // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP} },
		{ {Position::TOP, Position::FRONT, Position::RIGHT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },

		{ {Position::BACK, Position::TOP, Position::RIGHT }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::BACK, Position::TOP }, // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP} },
		{ {Position::TOP, Position::RIGHT, Position::BACK }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },

		{ {Position::LEFT, Position::TOP, Position::BACK }, // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP} },
		{ {Position::BACK, Position::LEFT, Position::TOP }, // ok
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP} },
		{ {Position::TOP, Position::BACK, Position::LEFT }, // ok
			{Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT} },
	};

}