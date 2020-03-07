#include "SecondLayerEdgeFinalSolver.hpp"
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../AvaliableRotatorsFactory.hpp"

SecondLayerEdgeFinalSolver::SecondLayerEdgeFinalSolver(
	std::queue<std::shared_ptr<IRotation>>& p_rotates,
	std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
	CubicTransformations& p_cubicMvps,
	IFinder& solverContainer,
	std::map<std::vector<Position>, std::vector<Rotation1>> rotationsMap) :
		m_rotates(p_rotates), m_historyRrotates(p_historyRotates), m_cubicMvps(p_cubicMvps),
		allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
		m_solverContainer(solverContainer),
		m_rotationsMap(rotationsMap)
{
}

namespace
{
std::map<Position, std::vector<Rotation1>> topFixer =
{
	{ {Position::RIGHT }, // ok 
		{Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT} },
	{ {Position::LEFT }, // ok
		{Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT} }
};


std::function<bool(Cubic&)> findNotYellowOnTop = [](Cubic& cube) ->bool
{
	auto currentPositions = cube.getPosition();
	if (currentPositions.size() == 2 and
		std::any_of(currentPositions.begin(), currentPositions.end(), [](auto& pos) {return pos == Position::TOP; }))
	{
		auto initialPositions = cube.getInitialPosition();
		if (std::none_of(initialPositions.begin(), initialPositions.end(), [](auto& pos) {return pos == Position::TOP; }))
		{
			return true;
		}
	}
	return false;
};
}

bool SecondLayerEdgeFinalSolver::wholeMiddleLayerSolved(std::vector<Cubic>& cubics)
{
	std::vector<Cubic> middleEdges;
	std::copy_if(cubics.begin(), cubics.end(), std::back_inserter(middleEdges), [](auto positions) {
		return positions.getPosition().size() == 2 and
			not positions.getInitialPositionOf(Position::BOTTOM) and
			not positions.getInitialPositionOf(Position::TOP); });
	return all_of(middleEdges.begin(), middleEdges.end(), [](auto positions) { return positions.getPosition() == positions.getInitialPosition(); });
}

void SecondLayerEdgeFinalSolver::findRotations()
{
	auto cubics = m_cubicMvps.getCubics();
	auto cubicOnRight = std::find_if(cubics.begin(), cubics.end(), [&](auto cube)
	{
		return cube.getPosition() == std::vector{Position::RIGHT};
	});


	std::vector<Position> positionsToSearch = { Position::FRONT, Position::TOP };
	auto cubic = std::find_if(cubics.begin(), cubics.end(), [&](auto cube)
	{
		std::cout << cube.getPosition();
		
		return std::is_permutation(cube.getPosition().begin(), cube.getPosition().end(), positionsToSearch.begin(), positionsToSearch.end());
	});

	auto initAtTopInFront = cubic->getInitialPositionOf( Position::TOP);
	auto chosenDir = initAtTopInFront == cubicOnRight->getInitialPositionOf(Position::RIGHT) ? Position::RIGHT : Position::LEFT;
	for (auto& rotation : topFixer.at({ chosenDir }))//*cubic->getInitialPositionOf(Position::TOP) }))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}

	comeBackToDefaultCubePosition();

	if (wholeMiddleLayerSolved(cubics))
	{
		std::cout << std::endl << "MIDDLE LAYER SOLVED";
		//m_solverContainer.setInitialState();
		m_solverContainer.setNextState();
	}
	else
	{
		std::cout << std::endl << "MIDDLE LAYER NOT SOLVED YET";
		//m_solverContainer.setInitialState();
		m_solverContainer.setPreviousState();
	}
	
}

std::map<Position, std::vector<Rotation1>> backFrontToDefault =
{
	{ {Position::FRONT }, // ok 
		{} },
	{ {Position::LEFT }, // ok
		{Rotation1::Y_ROTATE_RIGHT} },
	{ {Position::BACK }, // ok
		{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
	{ {Position::RIGHT }, // ok
		{Rotation1::Y_ROTATE_LEFT} }
};

void SecondLayerEdgeFinalSolver::comeBackToDefaultCubePosition()
{
	auto cubics = m_cubicMvps.getCubics();
	auto cubicInFront = std::find_if(cubics.begin(), cubics.end(), [&](auto cube)
	{
		return cube.getPosition() == std::vector{ Position::FRONT };
	});

	std::cout << "initial position in front: " << *cubicInFront->getInitialPositionOf(Position::FRONT) << ", from map: (size: " << backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT)).size() << ") ";
	for(int i = 0; i < backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT)).size(); i++)
		std::cout << backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT))[0] << std::endl;
	for (auto& rotation : backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT)))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
}

	SecondLayerEdgeFinalSolver::~SecondLayerEdgeFinalSolver()
{
}
