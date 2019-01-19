#include <iostream>
#include <algorithm>
#include "RotationFinder.hpp"
#include "Rotators/LeftUpRotator.hpp"
RotationFinder::RotationFinder()
{
}

std::vector<Rotation> RotationFinder::findNextRotationSet(std::queue<std::shared_ptr<Rotator>>& rotators,
													      CubicTransformations& cubicTransformations)
{
	auto currentPositions = cubicTransformations.getPositions();
	//std::cout << "cubic" << std::get<0>(currentPositions[10]) << std::endl;
	std::vector<std::vector<Position>> whitePositions{};
	//std::cout << std::endl <<std::endl << std::endl;
	for (auto& position : currentPositions)
	{
		//std::cout << "cubic" << std::get<0>(position) << std::endl;
		if (std::get<0>(position).size() == 2)
		{
		    //std::cout << "cubic with size 2" << std::get<0>(position) << std::endl;
			auto foundwhiteposition = std::find(begin(std::get<0>(position)),
												end(std::get<0>(position)),
												Position::BOTTOM);
			if (foundwhiteposition != end(std::get<0>(position)))
			{
				whitePositions.push_back(std::ref(std::get<1>(position)));
			}
		}
	}

	//std::cout << std::endl << "pozycje bialych bokow: " << whitePositions.size();
	//for (auto& cube : whitePositions)
	//{
	//	std::cout << cube << std::endl;
	//}
	auto whiteCubeToMove = std::find_if(begin(whitePositions), end(whitePositions),
		[](const auto& pos) {return pos[0] != Position::BOTTOM;});
	if (whiteCubeToMove == end(whitePositions))
	{
		std::cout << "WHITE CROSS SOLVED" <<std::endl;
	}
	else
	{
		//if ((*whiteCubeToMove)[0] == Position::TOP and (*whiteCubeToMove)[1] == Position::LEFT)
		//{
		//	rotators.push(std::make_shared<LeftUpRotator>());
		//	rotators.push(std::make_shared<LeftUpRotator>());
		//}
		std::cout << "WHITE CROSS NOT SOLVED" << std::endl;
	}
	return {};
}