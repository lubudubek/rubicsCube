#include "KeyHandler.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include "PositionTypes.hpp"

void KeyHandler::handleKey(CubicTransformations& cubicMvps)
{
	if (ImGui::IsKeyPressed(68)) // d
	{
		std::cout << "RIGHT_ROTATE_DOWN" << std::endl;
		cubicMvps.rotate(Rotation::RIGHT_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(83)) // s
	{
		std::cout << "CENTER_X_ROTATE_DOWN" << std::endl;
		cubicMvps.rotate(Rotation::CENTER_X_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(65)) // a
	{
		std::cout << "LEFT_ROTATE_DOWN" << std::endl;
		cubicMvps.rotate(Rotation::LEFT_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(69)) // e
	{
		std::cout << "RIGHT_ROTATE_UP" << std::endl;
		cubicMvps.rotate(Rotation::RIGHT_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(87)) //w
	{
		std::cout << "CENTER_X_ROTATE_UP" << std::endl;
		cubicMvps.rotate(Rotation::CENTER_X_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(81)) //q
	{
		std::cout << "LEFT_ROTATE_UP" << std::endl;
		cubicMvps.rotate(Rotation::LEFT_ROTATE_UP);
	}

	if (ImGui::IsKeyPressed(330)) // . (num)
	{
		std::cout << "FRONT_ROTATE_RIGHT" << std::endl;
		cubicMvps.rotate(Rotation::FRONT_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(320)) // 0 (num)
	{
		std::cout << "CENTER_Z_ROTATE_RIGHT" << std::endl;
		cubicMvps.rotate(Rotation::CENTER_Z_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(262)) // arrow right
	{
		std::cout << "BACK_ROTATE_RIGHT" << std::endl;
		cubicMvps.rotate(Rotation::BACK_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(323)) // 3 (num)
	{
		std::cout << "FRONT_ROTATE_LEFT" << std::endl;
		cubicMvps.rotate(Rotation::FRONT_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(322)) // 2 (num)
	{
		std::cout << "CENTER_Z_ROTATE_LEFT" << std::endl;
		cubicMvps.rotate(Rotation::CENTER_Z_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(321)) // 1 (num)
	{
		std::cout << "BACK_ROTATE_LEFT" << std::endl;
		cubicMvps.rotate(Rotation::BACK_ROTATE_LEFT);
	}

	if (ImGui::IsKeyPressed(326)) // 6 (num)
	{
		std::cout << "BOTTOM_ROTATE_RIGHT" << std::endl;
		cubicMvps.rotate(Rotation::BOTTOM_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(325)) // 5 (num)
	{
		std::cout << "BOTTOM_ROTATE_LEFT" << std::endl;
		cubicMvps.rotate(Rotation::BOTTOM_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(329)) // 9 (num)
	{
		std::cout << "CENTER_Y_ROTATE_RIGHT" << std::endl;
		cubicMvps.rotate(Rotation::CENTER_Y_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(328)) // 8 (num)
	{
		std::cout << "CENTER_Y_ROTATE_LEFT" << std::endl;
		cubicMvps.rotate(Rotation::CENTER_Y_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(332)) // * (num)
	{
		std::cout << "TOP_ROTATE_RIGHT" << std::endl;
		cubicMvps.rotate(Rotation::TOP_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(331)) // / (num)
	{
		std::cout << "TOP_ROTATE_LEFT" << std::endl;
		cubicMvps.rotate(Rotation::TOP_ROTATE_LEFT);
	}
	//for (int i = 0; i < 512; i++)
	//{
	//	if (ImGui::IsKeyPressed(i))
	//	{
	//		std::cout << "Pressed key:" << i <<std::endl;
	//	}
	//}
}