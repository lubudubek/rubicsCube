#include "SolutionsFactory.h"
#include "WhiteGreenEdgeSolver.h"
#include "SecondLayerEdgeSolver.hpp"
#include "SecondLayerEdgeFinalSolver.hpp"
#include "SolvingMaps.h"
#include "CornersSolvingMaps.h"
#include "EmptySolver.h"
#include "YellowCrossSolver.h"
#include "YellowCrossPermutationSolver.h"
#include "YellowCornerSetSolver.h"
#include "YellowCornerPermutationSolver.h"
#include "FinalPermutationSolver.h"

#include "LastSolver.h"

SolutionsFactory::SolutionsFactory(std::queue<std::shared_ptr<IRotation>>& p_rotates,
								   std::stack<std::shared_ptr<IRotation>>& p_historyRrotates,
								   CubicTransformations& p_cubicMvps,
								   IFinder& p_solverContainer)
	: m_rotates(p_rotates),
	  m_historyRotates(p_historyRrotates),
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
												  m_historyRotates,
												  m_cubicMvps,
												  m_solverContainer,
												  l_whiteInitPosition,
												  Solution::WhiteYellowWallSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createGrboWallsSolution()
{
	std::vector<Position> l_greenInitPosition = { Position::FRONT };
	return std::make_unique<WhiteGreenEdgeSolver>(m_rotates,
												  m_historyRotates,
												  m_cubicMvps,
												  m_solverContainer,
												  l_greenInitPosition,
												  Solution::GreenWallSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteGreenEdgeSolution()
{
	std::vector<Position> l_whiteGreenInitPosition = { Position::BOTTOM, Position::FRONT };
	return std::make_unique<WhiteGreenEdgeSolver>(m_rotates,
		m_historyRotates,
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
		m_historyRotates,
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
		m_historyRotates,
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
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteGreenInitPosition,
		Solution::WhiteRedEdgeSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteGreenOrangeCornerSolution()
{
	std::vector<Position> l_whiteGreenOrangeInitPosition = { Position::BOTTOM, Position::FRONT, Position::RIGHT };
	return std::make_unique<WhiteGreenEdgeSolver>(m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteGreenOrangeInitPosition,
		Solution::WhiteGreenOrangeCornerSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteGreenRedCornerSolution()
{
	std::vector<Position> l_whiteGreenRedInitPosition = { Position::BOTTOM, Position::FRONT, Position::LEFT };
	return std::make_unique<WhiteGreenEdgeSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteGreenRedInitPosition,
		Solution::WhiteGreenRedCornerSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteBlueOrangeCornerSolution()
{
	std::vector<Position> l_whiteBlueOrangeInitPosition = { Position::BOTTOM, Position::BACK, Position::RIGHT };
	return std::make_unique<WhiteGreenEdgeSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteBlueOrangeInitPosition,
		Solution::WhiteBlueOrangeCornerSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createWhiteBlueRedCornerSolution()
{
	std::vector<Position> l_whiteBlueRedInitPosition = { Position::BOTTOM, Position::LEFT, Position::BACK };
	return std::make_unique<WhiteGreenEdgeSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		l_whiteBlueRedInitPosition,
		Solution::WhiteBlueRedCornerSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createSecondLayerEdgeSolution()
{
	return std::make_unique<SecondLayerEdgeSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		Solution::WhiteBlueRedCornerSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createSecondLayerEdgeFinalSolution()
{
	return std::make_unique<SecondLayerEdgeFinalSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer,
		Solution::WhiteBlueRedCornerSolvMap);
}

std::unique_ptr<ISolver> SolutionsFactory::createYellowCrossSolution()
{
	return std::make_unique<YellowCrossSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer);
}

std::unique_ptr<ISolver> SolutionsFactory::createYellowCrossPermutationSolution()
{
	return std::make_unique<YellowCrossPermutationSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer);
}

std::unique_ptr<ISolver> SolutionsFactory::createFinalPermutationSolution()
{
	return std::make_unique<FinalPermutationSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer);
}

std::unique_ptr<ISolver> SolutionsFactory::createYellowCornersSetSolution()
{
	return std::make_unique<YellowCornerSetSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer);
}

std::unique_ptr<ISolver> SolutionsFactory::createYellowCornersPermutationSolution()
{
	return std::make_unique<YellowCornerPermutationSolver>(
		m_rotates,
		m_historyRotates,
		m_cubicMvps,
		m_solverContainer);
}

std::unique_ptr<ISolver> SolutionsFactory::createLastSolution()
{
	return std::make_unique<LastSolver>(m_solverContainer);
}

