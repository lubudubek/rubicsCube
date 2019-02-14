#pragma once
#include <vector>
#include "CubicTransformations.hpp"
#include <queue>

class RotationFinder
{
private:
	int state;
public:
	RotationFinder();

	std::vector<std::shared_ptr<IRotation>> findNextRotationSet(std::queue<std::shared_ptr<IRotation>>&, CubicTransformations&);
};