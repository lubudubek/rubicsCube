#pragma once
#include <memory>
#include <queue>
#include "../PositionTypes.hpp"
#include "../CubicTransformations.hpp"
#include "IFinder.h"

#include "ISolver.h"
#include <stack>

class SolutionsFactory
{
public:
	SolutionsFactory(std::queue<std::shared_ptr<IRotation>>& p_rotates,
					 std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
					 CubicTransformations& p_cubicMvps,
					 IFinder& p_solverContaine);

	std::unique_ptr<ISolver> createEmptySolution();
	std::unique_ptr<ISolver> createWhiteYellowWallSolution();
	std::unique_ptr<ISolver> createGrboWallsSolution();

	std::unique_ptr<ISolver> createWhiteGreenEdgeSolution();
	std::unique_ptr<ISolver> createWhiteRedEdgeSolution();
	std::unique_ptr<ISolver> createWhiteBlueEdgeSolution();
	std::unique_ptr<ISolver> createWhiteOrangeEdgeSolution();

	std::unique_ptr<ISolver> createWhiteGreenOrangeCornerSolution();
	std::unique_ptr<ISolver> createWhiteGreenRedCornerSolution();
	std::unique_ptr<ISolver> createWhiteBlueOrangeCornerSolution();
	std::unique_ptr<ISolver> createWhiteBlueRedCornerSolution();

	std::unique_ptr<ISolver> createSecondLayerEdgeSolution();
	std::unique_ptr<ISolver> createSecondLayerEdgeFinalSolution();
	std::unique_ptr<ISolver> createYellowCrossSolution();
	std::unique_ptr<ISolver> createYellowCrossPermutationSolution();
	std::unique_ptr<ISolver> createYellowCornersSetSolution();
	std::unique_ptr<ISolver> createYellowCornersPermutationSolution();
	std::unique_ptr<ISolver> createFinalPermutationSolution();

	std::unique_ptr<ISolver> createLastSolution();
private:
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	std::stack<std::shared_ptr<IRotation>>& m_historyRotates;
	CubicTransformations& m_cubicMvps;
	IFinder& m_solverContainer;
};