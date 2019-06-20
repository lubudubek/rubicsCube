#include "WhiteGreenEdgeSolver.h"
#include <iostream>
#include "../AvaliableRotatorsFactory.hpp"
#include <algorithm>
#include <stack>

namespace {
	std::map<Rotation1, Rotation1> opositeRotationMap
	{
		{Rotation1::FRONT_ROTATE_RIGHT,     Rotation1::FRONT_ROTATE_LEFT	 },
		{Rotation1::FRONT_ROTATE_LEFT,		Rotation1::FRONT_ROTATE_RIGHT	 },
		{Rotation1::BACK_ROTATE_RIGHT,		Rotation1::BACK_ROTATE_LEFT	 },
		{Rotation1::BACK_ROTATE_LEFT,		Rotation1::BACK_ROTATE_RIGHT		 },
		{Rotation1::CENTER_Z_ROTATE_RIGHT,	Rotation1::CENTER_Z_ROTATE_LEFT },
		{Rotation1::CENTER_Z_ROTATE_LEFT,	Rotation1::CENTER_Z_ROTATE_RIGHT	 },

		{Rotation1::LEFT_ROTATE_DOWN,		Rotation1::LEFT_ROTATE_UP		 },
		{Rotation1::LEFT_ROTATE_UP,			Rotation1::LEFT_ROTATE_DOWN		 },
		{Rotation1::RIGHT_ROTATE_DOWN,		Rotation1::RIGHT_ROTATE_UP	 },
		{Rotation1::RIGHT_ROTATE_UP,		Rotation1::RIGHT_ROTATE_DOWN		 },
		{Rotation1::CENTER_X_ROTATE_DOWN,	Rotation1::CENTER_X_ROTATE_UP	 },
		{Rotation1::CENTER_X_ROTATE_UP,		Rotation1::CENTER_X_ROTATE_DOWN	 },

		{Rotation1::BOTTOM_ROTATE_RIGHT,	Rotation1::BOTTOM_ROTATE_LEFT	 },
		{Rotation1::BOTTOM_ROTATE_LEFT,		Rotation1::BOTTOM_ROTATE_RIGHT	 },
		{Rotation1::TOP_ROTATE_RIGHT,		Rotation1::TOP_ROTATE_LEFT 	 },
		{Rotation1::TOP_ROTATE_LEFT,		Rotation1::TOP_ROTATE_RIGHT 		 },
		{Rotation1::CENTER_Y_ROTATE_RIGHT,	Rotation1::CENTER_Y_ROTATE_LEFT },
		{Rotation1::CENTER_Y_ROTATE_LEFT,	Rotation1::CENTER_Y_ROTATE_RIGHT	 }
	};
}

WhiteGreenEdgeSolver::WhiteGreenEdgeSolver(std::queue<std::shared_ptr<IRotation>>& p_rotates,
										   std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
										   CubicTransformations& p_cubicMvps,
										   IFinder& solverContainer,
										   std::vector<Position> positions,
										   std::map<std::vector<Position>, std::vector<Rotation1>> rotationsMap)
	: m_rotates(p_rotates), m_historyRrotates(p_historyRotates), m_cubicMvps(p_cubicMvps), m_solverContainer(solverContainer),
	  allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
	  m_positions(positions),
	  m_rotationsMap(rotationsMap)
{
}

void WhiteGreenEdgeSolver::moveByPosition(Cubic& cubic)
{
	std::vector<Position> l_tempPos = m_positions;
	std::transform(l_tempPos.begin(), l_tempPos.end(), l_tempPos.begin(),
		[&cubic](auto& pos) {return cubic.getPositionOfInitial(pos); });
	for (auto& rotation : m_rotationsMap.at(l_tempPos))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationMap.at(rotation)));
	}
}

bool WhiteGreenEdgeSolver::doesCubicMatch(Cubic& cube)
{
	auto initPositions = cube.getInitialPosition();
	auto expectedPositions = m_positions;
	std::sort(initPositions.begin(), initPositions.end());
	std::sort(expectedPositions.begin(), expectedPositions.end());
	return initPositions == expectedPositions;
}

void WhiteGreenEdgeSolver::findRotations()
{
	std::cout << "Start solving - WhiteGreenEdge" << std::endl;
	for (auto& cube : m_cubicMvps.getCubics())
	{
		cube.setOpacity(1.0f);
		if (doesCubicMatch(cube))
		{
			std::cout << "Cubic BOTTOM FRONT chosen" << std::endl;
			cube.setOpacity(1.0f);
			moveByPosition(cube);
			m_solverContainer.setNextState();
		}
	}
}


WhiteGreenEdgeSolver::~WhiteGreenEdgeSolver()
{
}