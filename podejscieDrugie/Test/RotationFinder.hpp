#pragma once
#include <vector>
#include "Rotators/Rotator.hpp"
#include "CubicTransformations.hpp"
#include <queue>

class RotationFinder
{
private:
	int state;
public:
	RotationFinder();

	std::vector<Rotation> findNextRotationSet(std::queue<std::shared_ptr<Rotator>>&, CubicTransformations&);
};