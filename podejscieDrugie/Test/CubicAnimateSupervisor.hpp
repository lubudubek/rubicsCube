#pragma once
#include "Rotators/Rotator.hpp"
#include "CubicTransformations.hpp"
#include <queue>
#include <memory>

class CubicAnimateSupervisor
{
public:
	void ping();
	CubicAnimateSupervisor(CubicTransformations& p_cubicMvps,
						   std::queue<std::shared_ptr<Rotator>>& p_rotators);

private:
	int stepCounter;
	std::queue<std::shared_ptr<Rotator>>& m_rotators;
	CubicTransformations& m_cubicMvps;
};