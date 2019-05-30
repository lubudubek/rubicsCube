#pragma once
#include <memory>
#include <queue>
#include "../PositionTypes.hpp"
#include "../CubicTransformations.hpp"
#include "IFinder.h"

#include "ISolver.h"

class SolutionsFactory
{
public:
	SolutionsFactory(std::queue<std::shared_ptr<IRotation>>& p_rotates,
					 CubicTransformations& p_cubicMvps,
					 IFinder& p_solverContaine);

	std::unique_ptr<ISolver> createEmptySolution();
	std::unique_ptr<ISolver> createWhiteYellowWallSolution();
	std::unique_ptr<ISolver> createGrboWallsSolution();
	std::unique_ptr<ISolver> createWhiteGreenEdgeSolution();

	std::unique_ptr<ISolver> createWhiteRedEdgeSolution();
	std::unique_ptr<ISolver> createWhiteBlueEdgeSolution();
	std::unique_ptr<ISolver> createWhiteOrangeEdgeSolution();

	std::unique_ptr<ISolver> createLastSolution();
private:
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	CubicTransformations& m_cubicMvps;
	IFinder& m_solverContainer;
};