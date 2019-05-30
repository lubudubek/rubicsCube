#pragma once
#include "IFinder.h"
#include "ISolver.h"
#include <vector>
#include <memory>
#include <queue>
#include "../Rotators/IRotation.hpp"
class CubicTransformations;

class RealRotationFinder : public IFinder
{
public:
	RealRotationFinder(std::queue<std::shared_ptr<IRotation>>& p_rotates,
						CubicTransformations& p_cubicMvps);
	void findNextRotationSet() override;
	void setNextState() override;
	void setInitialState() override;
	virtual ~RealRotationFinder();

private:
	std::vector<std::unique_ptr<ISolver>>::iterator m_currentSolver; //iterator
	std::vector<std::unique_ptr<ISolver>> m_solvers;

	//WhiteBlueEdgeSolver
	//WhiteGreenEdgeSolver
	//WhiteRedEdgeSolver
	//WhiteOrangeEdgeSolver

	//WhiteBlueReqCornerSlover
	//WhiteReqGreenCornerSlover
	//WhiteGreenOrangeCornerSlover
	//WhiteOrangeBlueCornerSlover


};

