#include "KeyHandler.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include "PositionTypes.hpp"
#include "Rotators/IRotation.hpp"
#include "AvaliableRotatorsFactory.hpp"

KeyHandler::KeyHandler() : allRotations(AvaliableRotatorsFactory().createAvaliableRotators())
{
}

void KeyHandler::pushToEmptyQueue(std::queue<std::shared_ptr<IRotation>>& rotates,
								  Rotation1 rotation)
{
	std::queue<std::shared_ptr<IRotation>> empty;
	rotates.swap(empty);
	rotates.push(allRotations.at(rotation));
	std::cout << rotation << std::endl;
}

void KeyHandler::handleKey(std::queue<std::shared_ptr<IRotation>>& rotates)
{
	if (ImGui::IsKeyPressed(68)) // d
	{
		pushToEmptyQueue(rotates, Rotation1::RIGHT_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(83)) // s
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_X_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(65)) // a
	{
		pushToEmptyQueue(rotates, Rotation1::LEFT_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(69)) // e
	{
		pushToEmptyQueue(rotates, Rotation1::RIGHT_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(87)) //w
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_X_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(81)) //q
	{
		pushToEmptyQueue(rotates, Rotation1::LEFT_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(330)) // . (num)
	{
		pushToEmptyQueue(rotates, Rotation1::FRONT_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(320)) // 0 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_Z_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(262)) // arrow right
	{
		pushToEmptyQueue(rotates, Rotation1::BACK_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(323)) // 3 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::FRONT_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(322)) // 2 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_Z_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(321)) // 1 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::BACK_ROTATE_LEFT);
	}

	if (ImGui::IsKeyPressed(326)) // 6 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::BOTTOM_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(325)) // 5 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::BOTTOM_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(329)) // 9 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_Y_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(328)) // 8 (num)
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_Y_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(332)) // * (num)
	{
		pushToEmptyQueue(rotates, Rotation1::TOP_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(331)) // / (num)
	{
		pushToEmptyQueue(rotates, Rotation1::TOP_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(71)) // y
	{
		pushToEmptyQueue(rotates, Rotation1::CENTER_X_ROTATE_DOWN); // todo
		std::cout << "EMPTY_ROTATOR" << std::endl;
	}
	if (ImGui::IsKeyPressed(84)) // t
	{
		// todo? someSequence
	}
	for (int i = 0; i < 512; i++)
	{
		if (ImGui::IsKeyPressed(i))
		{
			std::cout << "Pressed key:" << i <<std::endl;
		}
	}
}