#pragma once
#include <map>
#include <vector>
#include "../PositionTypes.hpp"

namespace Solution
{
	std::map<std::vector<Position>, std::vector<Rotation1>> GreenWallSolvMap =
	{
		{ {Position::RIGHT},  {Rotation1::CENTER_Y_ROTATE_RIGHT} },
		{ {Position::LEFT},   {Rotation1::CENTER_Y_ROTATE_LEFT} },
		{ {Position::FRONT},  {} },
		{ {Position::BACK},   {Rotation1::CENTER_Y_ROTATE_LEFT, Rotation1::CENTER_Y_ROTATE_LEFT} }
	};

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteYellowWallSolvMap =
	{
		{ {Position::BOTTOM}, {} },
		{ {Position::TOP},    {Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::CENTER_X_ROTATE_DOWN} },
		{ {Position::RIGHT},  {Rotation1::CENTER_Z_ROTATE_RIGHT} },
		{ {Position::LEFT},   {Rotation1::CENTER_Z_ROTATE_LEFT} },
		{ {Position::FRONT},  {Rotation1::CENTER_X_ROTATE_DOWN} },
		{ {Position::BACK},   {Rotation1::CENTER_X_ROTATE_UP} }
	};

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteGreenEdgeSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT}, {} },
		{ {Position::BOTTOM, Position::BACK},  {Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_RIGHT} },
		{ {Position::BOTTOM, Position::RIGHT}, {Rotation1::BOTTOM_ROTATE_RIGHT} },
		{ {Position::BOTTOM, Position::LEFT},  {Rotation1::BOTTOM_ROTATE_LEFT} },

		{ {Position::TOP, Position::FRONT}, {Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::TOP, Position::BACK},  {Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::TOP, Position::RIGHT}, {Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::TOP, Position::LEFT},  {Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::RIGHT, Position::FRONT},  {Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::RIGHT, Position::BACK},   {Rotation1::BACK_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_RIGHT} },
		{ {Position::RIGHT, Position::TOP},    {Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::RIGHT, Position::BOTTOM}, {Rotation1::RIGHT_ROTATE_UP, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::LEFT, Position::FRONT},  {Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::LEFT, Position::BACK},   {Rotation1::BACK_ROTATE_LEFT, Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_RIGHT} },
		{ {Position::LEFT, Position::TOP},    {Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::LEFT, Position::BOTTOM}, {Rotation1::LEFT_ROTATE_UP, Rotation1::FRONT_ROTATE_LEFT} },

		{ {Position::FRONT, Position::TOP},    {Rotation1::BACK_ROTATE_RIGHT,  Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::FRONT, Position::BOTTOM}, {Rotation1::FRONT_ROTATE_LEFT,  Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::LEFT},   {Rotation1::LEFT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::FRONT, Position::RIGHT},  {Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_RIGHT} },

		{ {Position::BACK, Position::TOP},    {Rotation1::FRONT_ROTATE_RIGHT,  Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::BACK, Position::BOTTOM}, {Rotation1::BACK_ROTATE_LEFT,  Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::BACK, Position::LEFT},   {Rotation1::LEFT_ROTATE_UP, Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::BACK, Position::RIGHT},  {Rotation1::RIGHT_ROTATE_UP, Rotation1::BOTTOM_ROTATE_RIGHT} }
	};

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteOrangeEdgeSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT}, {} }, // already fixed another cubic - error!
		{ {Position::BOTTOM, Position::BACK},  {Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP } },
		{ {Position::BOTTOM, Position::RIGHT}, {} },
		{ {Position::BOTTOM, Position::LEFT},  {Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP } },

		{ {Position::TOP, Position::FRONT}, {Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::TOP, Position::BACK},  {Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::TOP, Position::RIGHT}, {Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::TOP, Position::LEFT},  {Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP} },

		{ {Position::RIGHT, Position::FRONT},  {Rotation1::FRONT_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::BACK},   {Rotation1::BACK_ROTATE_LEFT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::RIGHT, Position::TOP},    {Rotation1::RIGHT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::BOTTOM}, {Rotation1::RIGHT_ROTATE_UP, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },

		{ {Position::LEFT, Position::FRONT},  {Rotation1::FRONT_ROTATE_LEFT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT } },
		{ {Position::LEFT, Position::BACK},   {Rotation1::BACK_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::LEFT, Position::TOP},    {Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::LEFT, Position::BOTTOM}, {Rotation1::LEFT_ROTATE_UP, Rotation1::FRONT_ROTATE_LEFT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::FRONT, Position::TOP},    {Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::FRONT, Position::BOTTOM}, {} }, // error!
		{ {Position::FRONT, Position::LEFT},   {Rotation1::FRONT_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::RIGHT},  {Rotation1::RIGHT_ROTATE_DOWN} },

		{ {Position::BACK, Position::TOP},    {Rotation1::BACK_ROTATE_RIGHT,  Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::BACK, Position::BOTTOM}, {Rotation1::BACK_ROTATE_LEFT,  Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::BACK, Position::LEFT},   {Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP} },
		{ {Position::BACK, Position::RIGHT},  {Rotation1::RIGHT_ROTATE_UP} }
	};

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteBlueEdgeSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT}, {} }, // already fixed another cubic - error!
		{ {Position::BOTTOM, Position::BACK},  {} },
		{ {Position::BOTTOM, Position::RIGHT}, {} }, // already fixed another cubic - error!
		{ {Position::BOTTOM, Position::LEFT},  {Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT } },

		{ {Position::TOP, Position::FRONT}, { Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::TOP, Position::BACK},  { Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT } },
		{ {Position::TOP, Position::RIGHT}, { Rotation1::TOP_ROTATE_LEFT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::TOP, Position::LEFT},  { Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT} },

		{ {Position::RIGHT, Position::FRONT},  {Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::BACK},   {Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::RIGHT, Position::TOP},    {Rotation1::RIGHT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN} },
		{ {Position::RIGHT, Position::BOTTOM}, {} },
		// check from here
		{ {Position::LEFT, Position::FRONT},  {Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_LEFT } },
		{ {Position::LEFT, Position::BACK},   {Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::LEFT, Position::TOP},    {Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::LEFT, Position::BOTTOM}, {Rotation1::LEFT_ROTATE_DOWN, Rotation1::BACK_ROTATE_LEFT} },

		{ {Position::FRONT, Position::TOP},    {Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::FRONT, Position::BOTTOM}, {} }, // error!
		{ {Position::FRONT, Position::LEFT},   {Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::BACK_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT} },
		{ {Position::FRONT, Position::RIGHT},  {Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::BOTTOM_ROTATE_LEFT} },

		{ {Position::BACK, Position::TOP},    {Rotation1::BACK_ROTATE_RIGHT,  Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP,  Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::BACK, Position::BOTTOM}, {Rotation1::BACK_ROTATE_LEFT,  Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP,  Rotation1::BOTTOM_ROTATE_LEFT} },
		{ {Position::BACK, Position::LEFT},   {Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BOTTOM_ROTATE_RIGHT} },
		{ {Position::BACK, Position::RIGHT},  {Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP,  Rotation1::BOTTOM_ROTATE_LEFT} }
	};

	std::map<std::vector<Position>, std::vector<Rotation1>> WhiteRedEdgeSolvMap =
	{
		{ {Position::BOTTOM, Position::FRONT}, {} }, // already fixed another cubic - error!
		{ {Position::BOTTOM, Position::BACK},  {} }, // already fixed another cubic - error!
		{ {Position::BOTTOM, Position::RIGHT}, {} }, // already fixed another cubic - error!
		{ {Position::BOTTOM, Position::LEFT},  { } },

		{ {Position::TOP, Position::FRONT}, { Rotation1::BOTTOM_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP} },
		{ {Position::TOP, Position::BACK},  { Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP } },
		{ {Position::TOP, Position::RIGHT}, { Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::BOTTOM_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP } },
		{ {Position::TOP, Position::LEFT},  {  Rotation1::LEFT_ROTATE_UP, Rotation1::LEFT_ROTATE_UP} },

		{ {Position::RIGHT, Position::FRONT},  {Rotation1::CENTER_Y_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::CENTER_Y_ROTATE_LEFT } },
		{ {Position::RIGHT, Position::BACK},   {Rotation1::CENTER_Y_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::CENTER_Y_ROTATE_RIGHT} },
		{ {Position::RIGHT, Position::TOP},    {Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_RIGHT } },
		{ {Position::RIGHT, Position::BOTTOM}, {} }, // already fixed another cubic - error!
		// check from here
		{ {Position::LEFT, Position::FRONT},  { Rotation1::CENTER_Y_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::CENTER_Y_ROTATE_LEFT } },
		{ {Position::LEFT, Position::BACK},   { Rotation1::CENTER_Y_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::CENTER_Y_ROTATE_RIGHT} },
		{ {Position::LEFT, Position::TOP},    { Rotation1::LEFT_ROTATE_UP, Rotation1::CENTER_Y_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::CENTER_Y_ROTATE_RIGHT } },
		{ {Position::LEFT, Position::BOTTOM}, { Rotation1::LEFT_ROTATE_UP, Rotation1::CENTER_Y_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_UP, Rotation1::CENTER_Y_ROTATE_LEFT } },

		{ {Position::FRONT, Position::TOP},    {Rotation1::FRONT_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::BOTTOM}, {} }, // already fixed another cubic - error!
		{ {Position::FRONT, Position::LEFT},   {Rotation1::LEFT_ROTATE_DOWN} },
		{ {Position::FRONT, Position::RIGHT},  {Rotation1::FRONT_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT} },

		{ {Position::BACK, Position::TOP},    {Rotation1::BACK_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT} },
		{ {Position::BACK, Position::BOTTOM}, {} }, // already fixed another cubic - error!
		{ {Position::BACK, Position::LEFT},   {Rotation1::LEFT_ROTATE_UP} },
		{ {Position::BACK, Position::RIGHT},  {Rotation1::BACK_ROTATE_LEFT, Rotation1::BACK_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::BACK_ROTATE_RIGHT, Rotation1::BACK_ROTATE_RIGHT} }
	};
}