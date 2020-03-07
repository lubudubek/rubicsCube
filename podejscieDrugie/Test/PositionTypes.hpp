#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <iosfwd>

enum class Position
{
	FRONT,
	BACK,
	RIGHT,
	LEFT,
	BOTTOM,
	TOP
};
enum class Direction
{
	FORWARD = 1,
	BACKWARD = 3
};

enum class Rotation1
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
	CENTER_Y_ROTATE_LEFT,

	Y_ROTATE_LEFT,
	Y_ROTATE_RIGHT
};

extern std::map<Rotation1, Rotation1> opositeRotationsMap;

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
	//std::cout << temp.c_str();
	stream << temp.c_str();
	return stream;
}

inline std::ostream& operator<< (std::ostream& stream, const std::vector<Position>& position)
{
	stream << "[ ";
	for (auto& pos : position)
		stream << pos << " ";
	stream << " ]";
	return stream;
}

inline std::ostream& operator<< (std::ostream& stream, const Rotation1& rotation)
{
	std::string temp;
	switch (rotation)
	{
	    case Rotation1::UNSPECIFIED: temp = "UNSPECIFIED"; break;

		case Rotation1::FRONT_ROTATE_RIGHT: temp = "FRONT_ROTATE_RIGHT"; break;
		case Rotation1::FRONT_ROTATE_LEFT: temp = "FRONT_ROTATE_LEFT"; break;
		case Rotation1::BACK_ROTATE_RIGHT: temp = "BACK_ROTATE_RIGHT"; break;
		case Rotation1::BACK_ROTATE_LEFT: temp = "BACK_ROTATE_LEFT"; break;
		case Rotation1::CENTER_Z_ROTATE_RIGHT: temp = "CENTER_Z_ROTATE_RIGHT"; break;
		case Rotation1::CENTER_Z_ROTATE_LEFT: temp = "CENTER_Z_ROTATE_LEFT"; break;

		case Rotation1::LEFT_ROTATE_DOWN: temp = "LEFT_ROTATE_DOWN"; break;
		case Rotation1::LEFT_ROTATE_UP: temp = "LEFT_ROTATE_UP"; break;
		case Rotation1::RIGHT_ROTATE_DOWN: temp = "RIGHT_ROTATE_DOWN"; break;
		case Rotation1::RIGHT_ROTATE_UP: temp = "RIGHT_ROTATE_UP"; break;
		case Rotation1::CENTER_X_ROTATE_DOWN: temp = "CENTER_X_ROTATE_DOWN"; break;
		case Rotation1::CENTER_X_ROTATE_UP: temp = "CENTER_X_ROTATE_UP"; break;

		case Rotation1::BOTTOM_ROTATE_RIGHT: temp = "BOTTOM_ROTATE_RIGHT"; break;
		case Rotation1::BOTTOM_ROTATE_LEFT: temp = "BOTTOM_ROTATE_LEFT"; break;
		case Rotation1::TOP_ROTATE_RIGHT: temp = "TOP_ROTATE_RIGHT"; break;
		case Rotation1::TOP_ROTATE_LEFT: temp = "TOP_ROTATE_LEFT"; break;
		case Rotation1::CENTER_Y_ROTATE_RIGHT: temp = "CENTER_Y_ROTATE_RIGHT"; break;
		case Rotation1::CENTER_Y_ROTATE_LEFT: temp = "CENTER_Y_ROTATE_LEFT"; break;

		case Rotation1::Y_ROTATE_RIGHT: temp = "Y_ROTATE_RIGHT"; break;
		case Rotation1::Y_ROTATE_LEFT: temp = "Y_ROTATE_LEFT"; break;
		default: temp = (int)rotation;
	}
	stream << temp;
	return stream;
}