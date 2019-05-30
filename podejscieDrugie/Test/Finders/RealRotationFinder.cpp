#include "RealRotationFinder.h"
#include "EmptySolver.h"
#include "WhiteGreenEdgeSolver.h"
#include <iostream>
#include "SolutionsFactory.h"

RealRotationFinder::RealRotationFinder(std::queue<std::shared_ptr<IRotation>>& p_rotates,
									   CubicTransformations& p_cubicMvps)
{
	SolutionsFactory solutionFactory(p_rotates, p_cubicMvps, *this);
	std::vector<Position> l_temp = { Position::BOTTOM, Position::FRONT };
	m_solvers.reserve(10);
	m_solvers.emplace_back(solutionFactory.createEmptySolution());
	m_solvers.emplace_back(solutionFactory.createWhiteYellowWallSolution());
	m_solvers.emplace_back(solutionFactory.createGrboWallsSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteGreenEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteOrangeEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteBlueEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteRedEdgeSolution());

	m_solvers.emplace_back(solutionFactory.createLastSolution());

	m_currentSolver = m_solvers.begin();
}

void RealRotationFinder::setNextState()
{
	m_currentSolver++;
	if (m_currentSolver == m_solvers.end())
		m_currentSolver = m_solvers.begin();
}

void RealRotationFinder::setInitialState()
{
	m_currentSolver = m_solvers.begin();
}

void RealRotationFinder::findNextRotationSet()
{
	(*m_currentSolver)->findRotations();
}

RealRotationFinder::~RealRotationFinder()
{
}
