#include "CubicAnimateSupervisor.hpp"
#include "Rotators/NoRotation.hpp"
#include <iostream>

CubicAnimateSupervisor::CubicAnimateSupervisor(CubicTransformations& p_cubicMvps,
											   std::queue<std::shared_ptr<IRotation>>& p_rotates)
	: stepCounter{ 0 },
	  m_rotates(p_rotates),
	  m_emptyRotation(std::make_shared<NoRotation>()),
	  m_cubicMvps(p_cubicMvps)
{
	m_cubicMvps.setRotators(m_emptyRotation);
}

void CubicAnimateSupervisor::ping()
{
	if (m_rotates.empty() and stepCounter == 0)
	{
		return;
	}
	if (stepCounter == 0)
	{
		m_cubicMvps.setRotators(m_rotates.front());
		m_rotates.pop();
	}
	m_cubicMvps.stepMove();
	if (stepCounter == 9)
	{
		m_cubicMvps.moveLast();
		m_cubicMvps.setRotators(m_emptyRotation);
		stepCounter = 0;
		return;
	}
	stepCounter++;
}