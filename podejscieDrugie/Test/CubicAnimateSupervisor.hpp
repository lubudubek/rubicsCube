#pragma once
#include "CubicTransformations.hpp"
#include <queue>
#include <memory>

class CubicAnimateSupervisor
{
public:
	void ping();
	CubicAnimateSupervisor(CubicTransformations& p_cubicMvps,
						   std::queue<std::shared_ptr<IRotation>>& m_rotates);

private:
	int stepCounter;
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	std::shared_ptr<IRotation> m_emptyRotation;
	CubicTransformations& m_cubicMvps;
};