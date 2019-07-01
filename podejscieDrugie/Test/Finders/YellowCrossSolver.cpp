#include "YellowCrossSolver.h"
#include "../AvaliableRotatorsFactory.hpp"
#include <iostream>
#include <vector>

namespace
{
	std::map<std::vector<Position>, std::vector<Rotation1>> setInFrontMap =
	{
		{ {}, // ok 
			{ Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,
			  Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT,
			  Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,
			  Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::FRONT, Position::BACK, Position::RIGHT, Position::LEFT  }, // ok 
			{} },
		{ {Position::FRONT, Position::LEFT }, // ok 
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,
			 Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::BACK, Position::LEFT }, // ok 
			{Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,
			 Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::FRONT, Position::RIGHT }, // ok 
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,
			 Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::BACK, Position::RIGHT }, // ok 
			{Rotation1::TOP_ROTATE_LEFT,
			 Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT,
			 Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::LEFT }, // ok
			{Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
		{ {Position::FRONT, Position::BACK }, // ok
			{Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} },
	};
}

YellowCrossSolver::YellowCrossSolver(
	std::queue<std::shared_ptr<IRotation>>& p_rotates,
	std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
	CubicTransformations& p_cubicMvps,
	IFinder& solverContainer) :
	m_rotates(p_rotates), m_historyRrotates(p_historyRotates), m_cubicMvps(p_cubicMvps),
	allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
	m_solverContainer(solverContainer),
	m_rotationsMap(setInFrontMap)
{
}

std::vector<Position> YellowCrossSolver::findYellowTopPositions()
{
	std::vector<Position> result;
	std::vector<Cubic> withYellowEdges;

	auto cubics = m_cubicMvps.getCubics();
	std::copy_if(cubics.begin(), cubics.end(), std::back_inserter(withYellowEdges), [](auto cubic)
	{
		return cubic.getPosition().size() == 2 and
		cubic.getPositionOfInitial(Position::TOP) == Position::TOP;
	});
	std::transform(withYellowEdges.begin(), withYellowEdges.end(), std::back_inserter(result), [](auto cubic) {
		return *cubic.getPositionOtherThan(Position::TOP); });
	std::sort(result.begin(), result.end());
	return result;
}


void YellowCrossSolver::findRotations()
{
	std::vector<Position> yelowPos = findYellowTopPositions();
	for (auto& rotation : m_rotationsMap.at(yelowPos))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
	m_solverContainer.setNextState();
}


YellowCrossSolver::~YellowCrossSolver()
{
}
