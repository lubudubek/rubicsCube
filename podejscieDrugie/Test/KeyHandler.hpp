#pragma once
#include <queue>
#include "Rotators/IRotation.hpp"
#include <map>

class KeyHandler
{

public:
	KeyHandler();
	void handleKey(std::queue<std::shared_ptr<IRotation>>& rotates);
private:
	std::map<Rotation1, std::shared_ptr<IRotation>> allRotations;
	void pushToEmptyQueue(std::queue<std::shared_ptr<IRotation>>& rotates, Rotation1);
};