#include "RotatorHelpers.hpp"
#include <algorithm>

bool isCubicNotOnAxis(std::vector<Position>& cubicPos, std::vector<Position> notRotatedPositions)
{
	return std::find_if(cubicPos.begin(), cubicPos.end(),
		[notRotatedPositions](auto& pos)
	{
		return std::find(notRotatedPositions.begin(),
			 			 notRotatedPositions.end(),
			   			 pos) != notRotatedPositions.end();
	}) == cubicPos.end();
}

bool isCubicOnAxis(std::vector<Position>& cubicPos, std::vector<Position> rotatedPositions)
{
	return std::find(cubicPos.begin(), cubicPos.end(), rotatedPositions[0]) != cubicPos.end();
}