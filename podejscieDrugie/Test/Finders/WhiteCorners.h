#pragma once
#include "ISolver.h"
#include <queue>
#include <memory>
#include "../Rotators/IRotation.hpp"
#include "../CubicTransformations.hpp"
#include "IFinder.h"
#include "../PositionTypes.hpp"
#include <map>

class WhiteCornersSolver : public ISolver
{
public:
	WhiteCornersSolver(std::queue<std::shared_ptr<IRotation>>& p_rotates,
	   					 CubicTransformations& p_cubicMvps,
						 IFinder& solverContainer,
				 		 std::vector<Position> positions,
				 		 std::map<std::vector<Position>, std::vector<Rotation1>> rotationsMap);
	virtual ~WhiteCornersSolver();
	void findRotations() override;
private:
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	CubicTransformations& m_cubicMvps;
	IFinder& m_solverContainer;
	std::map<Rotation1, std::shared_ptr<IRotation>> allRotations;
	void moveByPosition(Cubic& cubic);
	bool doesCubicMatch(Cubic& cube);

	std::vector<Position> m_positions;
	std::map<std::vector<Position>, std::vector<Rotation1>> m_rotationsMap;
};

