#include "RotatorHelpers.hpp"
#include <algorithm>

// todo any_of instead of find_if
// todo move to rotation
//bool isCubicNotOnAxis(const std::vector<Position>& cubicPos, std::vector<Position> notRotatedPositions)
//{
//	return false;
////	return std::find_if(cubicPos.begin(), cubicPos.end(),
////		[notRotatedPositions](auto& pos)
////	{
////		return std::find(notRotatedPositions.begin(),
////			 			 notRotatedPositions.end(),
////			   			 pos) != notRotatedPositions.end();
////	}) == cubicPos.end();
//}
////
//bool isCubicOnAxis(const std::vector<Position>& cubicPos, std::vector<Position> rotatedPositions)
//{
//	return false;
////	return std::find(cubicPos.begin(), cubicPos.end(), rotatedPositions[0]) != cubicPos.end();
//}