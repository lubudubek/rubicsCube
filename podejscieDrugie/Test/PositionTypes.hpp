#pragma once
#include <string>
enum class Position
{
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	BOTTOM,
	TOP
};

enum class Rotation
{
	UNSPECIFIED,

	FRONT_ROTATE_RIGHT,
	FRONT_ROTATE_LEFT,
	BACK_ROTATE_RIGHT,
	BACK_ROTATE_LEFT,
	CENTER_Z_ROTATE_RIGHT,
	CENTER_Z_ROTATE_LEFT,

	LEFT_ROTATE_DOWN,
	LEFT_ROTATE_UP,
	RIGHT_ROTATE_DOWN,
	RIGHT_ROTATE_UP,
	CENTER_X_ROTATE_DOWN,
	CENTER_X_ROTATE_UP,

	BOTTOM_ROTATE_RIGHT,
	BOTTOM_ROTATE_LEFT,
	TOP_ROTATE_RIGHT,
	TOP_ROTATE_LEFT,
	CENTER_Y_ROTATE_RIGHT,
	CENTER_Y_ROTATE_LEFT
};

inline std::ostream& operator<< (std::ostream& stream, const Position& position)
{
	std::string temp;
	switch (position)
	{
		case Position::FRONT: temp = "FRONT"; break;
		case Position::BACK: temp = "BACK"; break;
		case Position::LEFT: temp = "LEFT"; break;
		case Position::RIGHT: temp = "RIGHT"; break;
		case Position::BOTTOM: temp = "BOTTOM"; break;
		case Position::TOP: temp = "TOP"; break;
	}
	stream << temp;
	return stream;
}

inline std::ostream& operator<< (std::ostream& stream, const Rotation& rotation)
{
	std::string temp;
	switch (rotation)
	{
	    case Rotation::UNSPECIFIED: temp = "UNSPECIFIED"; break;

		case Rotation::FRONT_ROTATE_RIGHT: temp = "FRONT_ROTATE_RIGHT"; break;
		case Rotation::FRONT_ROTATE_LEFT: temp = "FRONT_ROTATE_LEFT"; break;
		case Rotation::BACK_ROTATE_RIGHT: temp = "BACK_ROTATE_RIGHT"; break;
		case Rotation::BACK_ROTATE_LEFT: temp = "BACK_ROTATE_LEFT"; break;
		case Rotation::CENTER_Z_ROTATE_RIGHT: temp = "CENTER_Z_ROTATE_RIGHT"; break;
		case Rotation::CENTER_Z_ROTATE_LEFT: temp = "CENTER_Z_ROTATE_LEFT"; break;

		case Rotation::LEFT_ROTATE_DOWN: temp = "LEFT_ROTATE_DOWN"; break;
		case Rotation::LEFT_ROTATE_UP: temp = "LEFT_ROTATE_UP"; break;
		case Rotation::RIGHT_ROTATE_DOWN: temp = "RIGHT_ROTATE_DOWN"; break;
		case Rotation::RIGHT_ROTATE_UP: temp = "RIGHT_ROTATE_UP"; break;
		case Rotation::CENTER_X_ROTATE_DOWN: temp = "CENTER_X_ROTATE_DOWN"; break;
		case Rotation::CENTER_X_ROTATE_UP: temp = "CENTER_X_ROTATE_UP"; break;

		case Rotation::BOTTOM_ROTATE_RIGHT: temp = "BOTTOM_ROTATE_RIGHT"; break;
		case Rotation::BOTTOM_ROTATE_LEFT: temp = "BOTTOM_ROTATE_LEFT"; break;
		case Rotation::TOP_ROTATE_RIGHT: temp = "TOP_ROTATE_RIGHT"; break;
		case Rotation::TOP_ROTATE_LEFT: temp = "TOP_ROTATE_LEFT"; break;
		case Rotation::CENTER_Y_ROTATE_RIGHT: temp = "CENTER_Y_ROTATE_RIGHT"; break;
		case Rotation::CENTER_Y_ROTATE_LEFT: temp = "CENTER_Y_ROTATE_LEFT"; break;
	}
	stream << temp;
	return stream;
}