#include "RealRotationFinder.h"
#include "EmptySolver.h"
#include "WhiteGreenEdgeSolver.h"
#include <iostream>
#include "SolutionsFactory.h"
#include <stack>

RealRotationFinder::RealRotationFinder(std::queue<std::shared_ptr<IRotation>>& p_rotates,
									   std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
									   CubicTransformations& p_cubicMvps)
{
	SolutionsFactory solutionFactory(p_rotates, p_historyRotates, p_cubicMvps, *this);
	std::vector<Position> l_temp = { Position::BOTTOM, Position::FRONT };
	m_solvers.reserve(10);
	m_solvers.emplace_back(solutionFactory.createEmptySolution());
	m_solvers.emplace_back(solutionFactory.createWhiteYellowWallSolution());
	m_solvers.emplace_back(solutionFactory.createGrboWallsSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteGreenEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteOrangeEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteBlueEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteRedEdgeSolution());

	m_solvers.emplace_back(solutionFactory.createWhiteGreenOrangeCornerSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteGreenRedCornerSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteBlueOrangeCornerSolution());
	m_solvers.emplace_back(solutionFactory.createWhiteBlueRedCornerSolution());

	m_solvers.emplace_back(solutionFactory.createSecondLayerEdgeSolution());
	m_solvers.emplace_back(solutionFactory.createSecondLayerEdgeFinalSolution());
	m_solvers.emplace_back(solutionFactory.createYellowCrossSolution());
	m_solvers.emplace_back(solutionFactory.createYellowCrossPermutationSolution());
	m_solvers.emplace_back(solutionFactory.createYellowCrossPermutationSolution()); //todo remove it
	m_solvers.emplace_back(solutionFactory.createYellowCornersSetSolution());
	m_solvers.emplace_back(solutionFactory.createYellowCornersPermutationSolution());
	m_solvers.emplace_back(solutionFactory.createFinalPermutationSolution());


	m_solvers.emplace_back(solutionFactory.createLastSolution());

	m_currentSolver = m_solvers.begin();
}

void RealRotationFinder::setNextState()
{
	m_currentSolver++;
	if (m_currentSolver == m_solvers.end())
		m_currentSolver = m_solvers.begin();
}

void RealRotationFinder::setPreviousState()
{
	if (m_currentSolver != m_solvers.begin())
		m_currentSolver--;
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
