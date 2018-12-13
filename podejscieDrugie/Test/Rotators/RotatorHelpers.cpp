#include "RotatorHelpers.hpp"
#include <algorithm>

bool isCubicNotOnAxis(std::vector<Position>& cubicPos, std::vector<Position> notRotatedPositions)
{
	//auto temp = m_notRotatedPositions;
	//std::cout << "temp: " << temp << std::endl;
	//std::cout << "notRotPos: " << m_notRotatedPositions << std::endl;
	//std::cout << "in: " << cubic.getPosition() << std::endl;
	//auto temp2 = cubic.getPosition();
	return std::find_if(cubicPos.begin(), cubicPos.end(),
		[notRotatedPositions](auto& pos)
	{
		return std::find(notRotatedPositions.begin(),
			 			 notRotatedPositions.end(),
			   			 pos) != notRotatedPositions.end();
	}) == cubicPos.end();

	//std::cout << "result: " << res << std::endl;
	//return res;
}

bool isCubicOnAxis(std::vector<Position>& cubicPos, std::vector<Position> rotatedPositions)
{
	return std::find(cubicPos.begin(), cubicPos.end(), rotatedPositions[0]) != cubicPos.end();
}