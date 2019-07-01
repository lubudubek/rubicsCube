#pragma once
#include <string>
#include <vector>
#include <map>
#include "PositionTypes.hpp"

std::map<Rotation1, Rotation1> opositeRotationsMap
{
	{Rotation1::FRONT_ROTATE_RIGHT,     Rotation1::FRONT_ROTATE_LEFT	 },
	{Rotation1::FRONT_ROTATE_LEFT,		Rotation1::FRONT_ROTATE_RIGHT	 },
	{Rotation1::BACK_ROTATE_RIGHT,		Rotation1::BACK_ROTATE_LEFT	 },
	{Rotation1::BACK_ROTATE_LEFT,		Rotation1::BACK_ROTATE_RIGHT		 },
	{Rotation1::CENTER_Z_ROTATE_RIGHT,	Rotation1::CENTER_Z_ROTATE_LEFT },
	{Rotation1::CENTER_Z_ROTATE_LEFT,	Rotation1::CENTER_Z_ROTATE_RIGHT	 },

	{Rotation1::LEFT_ROTATE_DOWN,		Rotation1::LEFT_ROTATE_UP		 },
	{Rotation1::LEFT_ROTATE_UP,			Rotation1::LEFT_ROTATE_DOWN		 },
	{Rotation1::RIGHT_ROTATE_DOWN,		Rotation1::RIGHT_ROTATE_UP	 },
	{Rotation1::RIGHT_ROTATE_UP,		Rotation1::RIGHT_ROTATE_DOWN		 },
	{Rotation1::CENTER_X_ROTATE_DOWN,	Rotation1::CENTER_X_ROTATE_UP	 },
	{Rotation1::CENTER_X_ROTATE_UP,		Rotation1::CENTER_X_ROTATE_DOWN	 },

	{Rotation1::BOTTOM_ROTATE_RIGHT,	Rotation1::BOTTOM_ROTATE_LEFT	 },
	{Rotation1::BOTTOM_ROTATE_LEFT,		Rotation1::BOTTOM_ROTATE_RIGHT	 },
	{Rotation1::TOP_ROTATE_RIGHT,		Rotation1::TOP_ROTATE_LEFT 	 },
	{Rotation1::TOP_ROTATE_LEFT,		Rotation1::TOP_ROTATE_RIGHT 		 },
	{Rotation1::CENTER_Y_ROTATE_RIGHT,	Rotation1::CENTER_Y_ROTATE_LEFT },
	{Rotation1::CENTER_Y_ROTATE_LEFT,	Rotation1::CENTER_Y_ROTATE_RIGHT	 },

	{Rotation1::Y_ROTATE_LEFT,	Rotation1::Y_ROTATE_RIGHT	 },
	{Rotation1::Y_ROTATE_RIGHT,	Rotation1::Y_ROTATE_LEFT	 },

};
