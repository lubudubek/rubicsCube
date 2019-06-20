#include "WhiteCorners.h"
#include <iostream>
#include "../AvaliableRotatorsFactory.hpp"
#include <algorithm>

WhiteCornersSolver::WhiteCornersSolver(std::queue<std::shared_ptr<IRotation>>& p_rotates,
										   CubicTransformations& p_cubicMvps,
										   IFinder& solverContainer,
										   std::vector<Position> positions,
										   std::map<std::vector<Position>, std::vector<Rotation1>> rotationsMap)
	: m_rotates(p_rotates), m_cubicMvps(p_cubicMvps), m_solverContainer(solverContainer),
	  allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
	  m_positions(positions),
	  m_rotationsMap(rotationsMap)
{
}

void WhiteCornersSolver::moveByPosition(Cubic& cubic)
{
	std::vector<Position> l_tempPos = m_positions;
	std::transform(l_tempPos.begin(), l_tempPos.end(), l_tempPos.begin(),
		[&cubic](auto& pos) {return cubic.getPositionOfInitial(pos); });
	std::sort(l_tempPos.begin(), l_tempPos.end());
	for(auto& rotation : m_rotationsMap.at(l_tempPos))
		m_rotates.push(allRotations.at(rotation));
}

bool WhiteCornersSolver::doesCubicMatch(Cubic& cube)
{
	auto initPositions = cube.getInitialPosition();
	auto expectedPositions = m_positions;
	std::sort(initPositions.begin(), initPositions.end());
	std::sort(expectedPositions.begin(), expectedPositions.end());
	return initPositions == expectedPositions;
}

void WhiteCornersSolver::findRotations()
{
	std::cout << "Start solving - WhiteGreenEdge" << std::endl;
	for (auto& cube : m_cubicMvps.getCubics())
	{
		//cube.setOpacity(0.1f);
		if (doesCubicMatch(cube))
		{
			std::cout << "Cubic BOTTOM FRONT chosen" << std::endl;
			cube.setOpacity(1.0f);
			moveByPosition(cube);
			m_solverContainer.setNextState();
		}
	}
}


WhiteCornersSolver::~WhiteCornersSolver()
{
}