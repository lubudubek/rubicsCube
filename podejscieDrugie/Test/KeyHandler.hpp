#pragma once
#include <queue>
#include "Rotators/IRotation.hpp"
#include <map>
#include "Finders/IFinder.h"
#include "Finders/RealRotationFinder.h"
#include <stack>
#include "imgui/imgui.h"

class KeyHandler
{

public:
	KeyHandler(std::shared_ptr<IFinder>& finder,
		std::queue<std::shared_ptr<IRotation>>& rotates,
		std::stack<std::shared_ptr<IRotation>>& rotatesHistory);
	void handleKey();
	ImVec2 vecMouse5;
private:
	std::map<Rotation1, std::shared_ptr<IRotation>> allRotations;
	void pushToEmptyQueue(Rotation1);
	void pushToEmptyQueue(std::vector<Rotation1> rotation);

	void makeRandomMoves();
	void undo();
	void clearQueueAndAdjustHistory();

	std::shared_ptr<IFinder>& m_realFinder;
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	std::stack<std::shared_ptr<IRotation>>& m_rotatesHistory;
	
};