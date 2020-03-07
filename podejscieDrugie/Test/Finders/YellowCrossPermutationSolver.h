#pragma once
#include "ISolver.h"
#include <queue>
#include <memory>
#include "../Rotators/IRotation.hpp"
#include "../CubicTransformations.hpp"
#include "IFinder.h"
#include "../PositionTypes.hpp"
#include <map>
#include <stack>

class YellowCrossPermutationSolver :
	public ISolver
{
public:
	YellowCrossPermutationSolver(std::queue<std::shared_ptr<IRotation>>& p_rotates,
		std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
		CubicTransformations& p_cubicMvps,
		IFinder& solverContainer);
	void findRotations();
	~YellowCrossPermutationSolver();
private:
	std::vector<Position> findYellowEdgePositions();

	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	std::stack<std::shared_ptr<IRotation>>& m_historyRrotates;
	CubicTransformations& m_cubicMvps;
	IFinder& m_solverContainer;
	std::map<Rotation1, std::shared_ptr<IRotation>> allRotations;
	std::map<std::vector<Position>, std::vector<Rotation1>> m_rotationsMap;
	bool comeBackToDefaultCubePosition();
};

