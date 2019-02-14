#include "AvaliableRotatorsFactory.hpp"
#include "PositionTypes.hpp"
#include "Rotators/Rotation.hpp"
#include "PositionSwitch.hpp"

std::map<Rotation1, std::shared_ptr<IRotation>> AvaliableRotatorsFactory::createAvaliableRotators()
{
	return
	{
		{ Rotation1::FRONT_ROTATE_RIGHT, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionZ(), Position::FRONT, std::vector<Position>{ }) },
		{ Rotation1::FRONT_ROTATE_LEFT, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionZ(), Position::FRONT, std::vector<Position>{ }) },
		{ Rotation1::BACK_ROTATE_RIGHT, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionZ(), Position::BACK, std::vector<Position>{ }) },
		{ Rotation1::BACK_ROTATE_LEFT, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionZ(), Position::BACK, std::vector<Position>{ }) },
		{ Rotation1::CENTER_Z_ROTATE_RIGHT, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionZ(), Position::BACK, std::vector<Position>{ Position::FRONT, Position::BACK }) },
		{ Rotation1::CENTER_Z_ROTATE_LEFT, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionZ(), Position::BACK, std::vector<Position>{ Position::FRONT, Position::BACK }) },

		{ Rotation1::LEFT_ROTATE_DOWN, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionX(), Position::LEFT, std::vector<Position>{ }) },
		{ Rotation1::LEFT_ROTATE_UP, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionX(), Position::LEFT, std::vector<Position>{ }) },
		{ Rotation1::RIGHT_ROTATE_DOWN, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionX(), Position::RIGHT, std::vector<Position>{ }) },
		{ Rotation1::RIGHT_ROTATE_UP, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionX(), Position::RIGHT, std::vector<Position>{ }) },
		{ Rotation1::CENTER_X_ROTATE_DOWN, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionX(), Position::BACK, std::vector<Position>{ Position::LEFT, Position::RIGHT }) },
		{ Rotation1::CENTER_X_ROTATE_UP, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionX(), Position::BACK, std::vector<Position>{ Position::LEFT, Position::RIGHT }) },

		{ Rotation1::BOTTOM_ROTATE_RIGHT, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionY(), Position::BOTTOM, std::vector<Position>{ }) },
		{ Rotation1::BOTTOM_ROTATE_LEFT, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionY(), Position::BOTTOM, std::vector<Position>{ }) },
		{ Rotation1::TOP_ROTATE_RIGHT, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionY(), Position::TOP, std::vector<Position>{ }) },
		{ Rotation1::TOP_ROTATE_LEFT, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionY(), Position::TOP, std::vector<Position>{ }) },
		{ Rotation1::CENTER_Y_ROTATE_RIGHT, std::make_shared<Rotation>(Direction::BACKWARD, PositionSwitch().getDirectionY(), Position::BACK, std::vector<Position>{ Position::TOP, Position::BOTTOM }) },
		{ Rotation1::CENTER_Y_ROTATE_LEFT, std::make_shared<Rotation>(Direction::FORWARD, PositionSwitch().getDirectionY(), Position::BACK, std::vector<Position>{ Position::TOP, Position::BOTTOM }) }
	};
}