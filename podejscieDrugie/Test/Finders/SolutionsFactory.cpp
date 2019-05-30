#include "SolutionsFactory.h"
#include "WhiteGreenEdgeSolver.h"
#include "SolvingMaps.h"
#include "EmptySolver.h"
#include "LastSolver.h"

SolutionsFactory::SolutionsFactory(std::queue<std::shared_ptr<IRotation>>& p_rotates,
								   CubicTransformations& p_cubicMvps,
								   IFinder& p_solverContainer)
	: m_rotates(p_rotates),
	  m_cubicMvps(p_cubicMvps),
	  m_solverContainer(p_solverContainer)
{
}

std::unique_ptr<ISolver> SolutionsFactory::createEmptySolution()
{
	return std::make_unique<EmptySolver>();
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteYellowWallSolution()
{
	std::vector<Position> l_whiteInitPosition = { Position::BOTTOM };
	return std::make_unique<WhiteGreenEdgeSolver>(m_rotates,
												  m_cubicMvps,
												  m_solverContainer,
												  l_whiteInitPosition,
												  Solution::WhiteYellowWallSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createGrboWallsSolution()
{
	std::vector<Position> l_greenInitPosition = { Position::FRONT };
	return std::make_unique<WhiteGreenEdgeSolver>(m_rotates,
												  m_cubicMvps,
												  m_solverContainer,
												  l_greenInitPosition,
												  Solution::GreenWallSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteGreenEdgeSolution()
{
	std::vector<Position> l_whiteGreenInitPosition = { Position::BOTTOM, Position::FRONT };
	return std::make_unique<WhiteGreenEdgeSolver>(m_rotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteGreenInitPosition,
		Solution::WhiteGreenEdgeSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteOrangeEdgeSolution()
{
	std::vector<Position> l_whiteOrangeInitPosition = { Position::BOTTOM, Position::RIGHT };
	return std::make_unique<WhiteGreenEdgeSolver>(
		m_rotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteOrangeInitPosition,
		Solution::WhiteOrangeEdgeSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteBlueEdgeSolution()
{
	std::vector<Position> l_whiteGreenInitPosition = { Position::BOTTOM, Position::BACK };
	return std::make_unique<WhiteGreenEdgeSolver>(
		m_rotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteGreenInitPosition,
		Solution::WhiteBlueEdgeSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteRedEdgeSolution()
{
	std::vector<Position> l_whiteGreenInitPosition = { Position::BOTTOM, Position::LEFT };
	return std::make_unique<WhiteGreenEdgeSolver>(
		m_rotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteGreenInitPosition,
		Solution::WhiteRedEdgeSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createLastSolution()
{
	return std::make_unique<LastSolver>(m_solverContainer);
}

