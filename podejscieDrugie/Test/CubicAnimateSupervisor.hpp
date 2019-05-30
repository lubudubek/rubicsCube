#pragma once
#include "CubicTransformations.hpp"
#include <queue>
#include <memory>
#include "Finders/IFinder.h"
#include <stack>

class CubicAnimateSupervisor
{
public:
	void ping();
	CubicAnimateSupervisor(CubicTransformations& p_cubicMvps,
						   std::queue<std::shared_ptr<IRotation>>& p_rotates,
						   std::stack<std::shared_ptr<IRotation>>& p_rotatesHistory,
						   std::shared_ptr<IFinder>& p_finder);

private:
	int stepCounter;
	std::queue<std::shared_ptr<IRotation>>& m_rotates;
	std::stack<std::shared_ptr<IRotation>>& m_rotatesHistory;
	std::shared_ptr<IRotation> m_emptyRotation;
	CubicTransformations& m_cubicMvps;
	std::shared_ptr<IFinder>& m_finder;
};