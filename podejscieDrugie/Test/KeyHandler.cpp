#include "KeyHandler.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include "PositionTypes.hpp"
#include "Rotators/CenterXUpRotator.hpp"

KeyHandler::KeyHandler(CubicTransformations& cubicMvps)
	: m_backLeftRotator(std::make_shared<BackLeftRotator>()),
      m_centerXUpRotator(std::make_shared<CenterXUpRotator>()),
      m_backRightRotator(std::make_shared<BackRightRotator>()),
      m_bottomLeftRotator(std::make_shared<BottomLeftRotator>()),
      m_bottomRightRotator(std::make_shared<BottomRightRotator>()),
      m_centerXDownRotator(std::make_shared<CenterXDownRotator>()),
      m_centerYLeftRotator(std::make_shared<CenterYLeftRotator>()),
      m_centerYRightRotator(std::make_shared<CenterYRightRotator>()),
      m_centerZLeftRotator(std::make_shared<CenterZLeftRotator>()),
      m_centerZRightRotator(std::make_shared<CenterZRightRotator>()),
      m_frontLeftRotator(std::make_shared<FrontLeftRotator>()),
      m_frontRightRotator(std::make_shared<FrontRightRotator>()),
      m_leftDownRotator(std::make_shared<LeftDownRotator>()),
      m_leftUpRotator(std::make_shared<LeftUpRotator>()),
      m_rightDownRotator(std::make_shared<RightDownRotator>()),
      m_rightUpRotator(std::make_shared<RightUpRotator>()),
      m_topLeftRotator(std::make_shared<TopLeftRotator>()),
      m_topRightRotator(std::make_shared<TopRightRotator>()),
	  m_emptyRotator(std::make_shared<EmptyRotator>()),
	  m_cubicMvps(cubicMvps)
{
}

void KeyHandler::handleKey(std::queue<std::shared_ptr<Rotator>>& rotators)
{
	std::queue<std::shared_ptr<Rotator>> empty;
	if (ImGui::IsKeyPressed(68)) // d
	{
		rotators.swap(empty);

		rotators.push(m_rightDownRotator);
		std::cout << "RIGHT_ROTATE_DOWN" << std::endl;
	}
	if (ImGui::IsKeyPressed(83)) // s
	{
		rotators.swap(empty);
		rotators.push(m_centerXDownRotator);

		std::cout << "CENTER_X_ROTATE_DOWN" << std::endl;
	}
	if (ImGui::IsKeyPressed(65)) // a
	{
		rotators.swap(empty);
		rotators.push(m_leftDownRotator);
		std::cout << "LEFT_ROTATE_DOWN" << std::endl;
	}
	if (ImGui::IsKeyPressed(69)) // e
	{
		rotators.swap(empty);
		rotators.push(m_rightUpRotator);
		std::cout << "RIGHT_ROTATE_UP" << std::endl;
	}
	if (ImGui::IsKeyPressed(87)) //w
	{
		rotators.swap(empty);
		rotators.push(m_centerXUpRotator);
		std::cout << "CENTER_X_ROTATE_UP" << std::endl;
	}
	if (ImGui::IsKeyPressed(81)) //q
	{
		rotators.swap(empty);
		rotators.push(m_leftUpRotator);
		std::cout << "LEFT_ROTATE_UP" << std::endl;
	}
	if (ImGui::IsKeyPressed(330)) // . (num)
	{
		rotators.swap(empty);
		rotators.push(m_frontRightRotator);
		std::cout << "FRONT_ROTATE_RIGHT" << std::endl;
	}
	if (ImGui::IsKeyPressed(320)) // 0 (num)
	{
		rotators.swap(empty);
		rotators.push(m_centerZRightRotator);
		std::cout << "CENTER_Z_ROTATE_RIGHT" << std::endl;
	}
	if (ImGui::IsKeyPressed(262)) // arrow right
	{
		rotators.swap(empty);
		rotators.push(m_backRightRotator);
		std::cout << "BACK_ROTATE_RIGHT" << std::endl;
	}
	if (ImGui::IsKeyPressed(323)) // 3 (num)
	{
		rotators.swap(empty);
		rotators.push(m_frontLeftRotator);
		std::cout << "FRONT_ROTATE_LEFT" << std::endl;
	}
	if (ImGui::IsKeyPressed(322)) // 2 (num)
	{
		rotators.swap(empty);
		rotators.push(m_centerZLeftRotator);
		std::cout << "CENTER_Z_ROTATE_LEFT" << std::endl;
	}
	if (ImGui::IsKeyPressed(321)) // 1 (num)
	{
		rotators.swap(empty);
		rotators.push(m_backLeftRotator);
		std::cout << "BACK_ROTATE_LEFT" << std::endl;
	}

	if (ImGui::IsKeyPressed(326)) // 6 (num)
	{
		rotators.swap(empty);
		rotators.push(m_bottomRightRotator);
		std::cout << "BOTTOM_ROTATE_RIGHT" << std::endl;
	}
	if (ImGui::IsKeyPressed(325)) // 5 (num)
	{
		rotators.swap(empty);
		rotators.push(m_bottomLeftRotator);
		std::cout << "BOTTOM_ROTATE_LEFT" << std::endl;
	}
	if (ImGui::IsKeyPressed(329)) // 9 (num)
	{
		rotators.swap(empty);
		rotators.push(m_centerYRightRotator);
		std::cout << "CENTER_Y_ROTATE_RIGHT" << std::endl;
	}
	if (ImGui::IsKeyPressed(328)) // 8 (num)
	{
		rotators.swap(empty);
		rotators.push(m_centerYLeftRotator);
		std::cout << "CENTER_Y_ROTATE_LEFT" << std::endl;
	}
	if (ImGui::IsKeyPressed(332)) // * (num)
	{
		rotators.swap(empty);
		rotators.push(m_topRightRotator);
		std::cout << "TOP_ROTATE_RIGHT" << std::endl;
	}
	if (ImGui::IsKeyPressed(331)) // / (num)
	{
		rotators.swap(empty);
		rotators.push(m_topLeftRotator);
		std::cout << "TOP_ROTATE_LEFT" << std::endl;
	}
	if (ImGui::IsKeyPressed(71)) // / (num)
	{
		rotators.swap(empty);
		rotators.push(m_emptyRotator);
		std::cout << "EMPTY_ROTATOR" << std::endl;
	}
	if (ImGui::IsKeyPressed(84)) // / (num)
	{
		rotators.swap(empty);
		
		rotators.push(m_topLeftRotator);
		rotators.push(m_centerXDownRotator);
		rotators.push(m_leftDownRotator);
		rotators.push(m_frontLeftRotator);
		rotators.push(m_topLeftRotator);
		rotators.push(m_centerXUpRotator);
		rotators.push(m_rightDownRotator);
		rotators.push(m_rightDownRotator);
		rotators.push(m_centerZLeftRotator);
		rotators.push(m_frontRightRotator);
		rotators.push(m_centerXDownRotator);
		rotators.push(m_leftUpRotator);
		rotators.push(m_frontLeftRotator);
		rotators.push(m_backRightRotator);
		rotators.push(m_centerZLeftRotator);
		rotators.push(m_frontRightRotator);
		rotators.push(m_bottomLeftRotator);
		rotators.push(m_topLeftRotator);
		rotators.push(m_frontRightRotator);
		rotators.push(m_rightDownRotator);
		rotators.push(m_topLeftRotator);
		rotators.push(m_topLeftRotator);
		rotators.push(m_centerXUpRotator);
		rotators.push(m_backRightRotator);
		rotators.push(m_leftDownRotator);
		rotators.push(m_leftDownRotator);
		rotators.push(m_leftUpRotator);
		rotators.push(m_leftUpRotator);
		rotators.push(m_topLeftRotator);
		rotators.push(m_centerYRightRotator);
		rotators.push(m_topLeftRotator);

		std::cout << "TOP_ROTATE_LEFT" << std::endl;
	}
	for (int i = 0; i < 512; i++)
	{
		if (ImGui::IsKeyPressed(i))
		{
			std::cout << "Pressed key:" << i <<std::endl;
		}
	}
}