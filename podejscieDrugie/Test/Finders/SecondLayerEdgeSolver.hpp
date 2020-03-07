#pragma once
#include "ISolver.h"
#include <queue>
#include <memory>
#include "../Rotators/IRotation.hpp"
#include <stack>
#include "../CubicTransformations.hpp"
#include "IFinder.h"
#include <optional>

class SecondLayerEdgeSolver : public ISolver
{
public:
	SecondLayerEdgeSolver(std::queue<std::shared_ptr<IRotation>>& p_rotates,
		std::stack<std::shared_ptr<IRotation>>& p_historyRrotates,
		CubicTransformations& p_cubicMvps,
		IFinder& solverContainer,
		std::map<std::vector<Position>, std::vector<Rotation1>> rotationsMap);
	void findRotations() override;

	~SecondLayerEdgeSolver();
private:
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	std::stack<std::shared_ptr<IRotation>>& m_historyRrotates;
	CubicTransformations& m_cubicMvps;
	std::map<Rotation1, std::shared_ptr<IRotation>> allRotations;
	bool comeBackToDefaultCubePosition();

	IFinder& m_solverContainer;
	std::map<std::vector<Position>, std::vector<Rotation1>> m_rotationsMap;
};

