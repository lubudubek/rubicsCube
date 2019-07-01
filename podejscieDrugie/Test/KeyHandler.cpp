#include "KeyHandler.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include "PositionTypes.hpp"
#include "Rotators/IRotation.hpp"
#include "AvaliableRotatorsFactory.hpp"

KeyHandler::KeyHandler(std::shared_ptr<IFinder>& finder,
	std::queue<std::shared_ptr<IRotation>>& rotates,
	std::stack<std::shared_ptr<IRotation>>& rotatesHistory) :
		allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
		m_realFinder(finder),
		m_rotates(rotates),
		m_rotatesHistory(rotatesHistory)
{
	m_realFinder->setInitialState();
}

void KeyHandler::pushToEmptyQueue(Rotation1 rotation)
{
	clearQueueAndAdjustHistory();
	m_rotates.push(allRotations.at(rotation));
	m_rotatesHistory.push(allRotations.at(opositeRotationsMap.at(rotation)));
	m_realFinder->setInitialState();
	std::cout << rotation << std::endl;
}
void KeyHandler::pushToEmptyQueue(std::vector<Rotation1> rotations)
{
	clearQueueAndAdjustHistory();
	for (auto rotation : rotations)
	{
		m_rotates.push(allRotations.at(rotation));
		m_rotatesHistory.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
	m_realFinder->setInitialState();
}

void KeyHandler::clearQueueAndAdjustHistory()
{
	for (int i = 0; i < m_rotates.size(); i++)
	{
		//std::cout << std::endl << "Pop from history" << std::endl;
		m_rotatesHistory.pop();
	}
	std::queue<std::shared_ptr<IRotation>> empty;
	m_rotates.swap(empty);
	//std::cout << "Empty regular queue" << std::endl;
}

void KeyHandler::makeRandomMoves()
{
	clearQueueAndAdjustHistory();

	for (int i = 0; i < 20; i++)
	{
		Rotation1 rotation =
			static_cast<Rotation1>(1 + (rand() % (static_cast<int>(Rotation1::CENTER_Y_ROTATE_LEFT))));
		m_rotates.push(allRotations.at(rotation));
		m_rotatesHistory.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
}

void KeyHandler::undo()
{
	if (not m_rotatesHistory.empty())
	{
		clearQueueAndAdjustHistory();
		m_rotates.push(m_rotatesHistory.top());
		m_rotatesHistory.pop();
		//std::cout << "Pop from history" << std::endl;
	}
}

void KeyHandler::handleKey()
{
	if (ImGui::IsKeyPressed(68)) // d
	{
		pushToEmptyQueue(Rotation1::RIGHT_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(83)) // s
	{
		pushToEmptyQueue(Rotation1::CENTER_X_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(65)) // a
	{
		pushToEmptyQueue(Rotation1::LEFT_ROTATE_DOWN);
	}
	if (ImGui::IsKeyPressed(69)) // e
	{
		pushToEmptyQueue(Rotation1::RIGHT_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(87)) //w
	{
		pushToEmptyQueue(Rotation1::CENTER_X_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(81)) //q
	{
		pushToEmptyQueue(Rotation1::LEFT_ROTATE_UP);
	}
	if (ImGui::IsKeyPressed(330)) // . (num)
	{
		pushToEmptyQueue(Rotation1::FRONT_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(320)) // 0 (num)
	{
		pushToEmptyQueue(Rotation1::CENTER_Z_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(262)) // arrow right
	{
		pushToEmptyQueue(Rotation1::BACK_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(323)) // 3 (num)
	{
		pushToEmptyQueue(Rotation1::FRONT_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(322)) // 2 (num)
	{
		pushToEmptyQueue(Rotation1::CENTER_Z_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(321)) // 1 (num)
	{
		pushToEmptyQueue(Rotation1::BACK_ROTATE_LEFT);
	}

	if (ImGui::IsKeyPressed(326)) // 6 (num)
	{
		pushToEmptyQueue(Rotation1::BOTTOM_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(325)) // 5 (num)
	{
		pushToEmptyQueue(Rotation1::BOTTOM_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(329)) // 9 (num)
	{
		pushToEmptyQueue(Rotation1::CENTER_Y_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(328)) // 8 (num)
	{
		pushToEmptyQueue(Rotation1::CENTER_Y_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(332)) // * (num)
	{
		pushToEmptyQueue(Rotation1::TOP_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(331)) // / (num)
	{
		pushToEmptyQueue(Rotation1::TOP_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(73)) // i
	{
		pushToEmptyQueue(Rotation1::Y_ROTATE_LEFT);
	}
	if (ImGui::IsKeyPressed(79)) // o
	{
		pushToEmptyQueue(Rotation1::Y_ROTATE_RIGHT);
	}
	if (ImGui::IsKeyPressed(71)) // g (?)
	{
		m_realFinder->setNextState();
		//pushToEmptyQueue(rotates, Rotation1::CENTER_X_ROTATE_DOWN); // todo
		std::cout << "START SOLVING" << std::endl;
	}
	if (ImGui::IsKeyPressed(84)) // t
	{
		makeRandomMoves();
		// todo? someSequence
	}
	if (ImGui::IsKeyPressed(80)) // p
	{
		pushToEmptyQueue({ Rotation1::CENTER_X_ROTATE_UP, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::CENTER_X_ROTATE_DOWN });
		// todo? someSequence
	}
	if (ImGui::IsKeyPressed(76)) // l
	{
		pushToEmptyQueue({ Rotation1::CENTER_X_ROTATE_UP, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::CENTER_X_ROTATE_DOWN });
		// todo? someSequence
	}
	if (ImGui::IsKeyPressed(59)) // ;
	{
		pushToEmptyQueue({ Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT});
		// todo? someSequence
	}
	if (ImGui::IsKeyPressed(91)) // [
	{
		pushToEmptyQueue({ Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP,
			Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN });
		// todo? someSequence
	}
	if (ImGui::IsKeyPressed(93)) // ]
	{
		pushToEmptyQueue({ Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP,
			Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN });
	}
	if (ImGui::IsKeyPressed(44)) // <
	{
		pushToEmptyQueue({ Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT,
			Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT,
			Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN });
		// todo? someSequence
	}
	if (ImGui::IsKeyPressed(46)) // >
	{
		pushToEmptyQueue({ Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN,
			Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN,
			Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT });
	}
	if (ImGui::IsKeyPressed(85)) // u
	{
		undo();
	}
	for (int i = 0; i < 512; i++)
	{
		if (ImGui::IsKeyPressed(i))
		{
			std::cout << "Pressed key:" << i <<std::endl;
		}
	}
}