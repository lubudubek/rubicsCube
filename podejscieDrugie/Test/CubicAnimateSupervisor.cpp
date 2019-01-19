#include "CubicAnimateSupervisor.hpp"
#include "Rotators/EmptyRotator.hpp"

CubicAnimateSupervisor::CubicAnimateSupervisor(CubicTransformations& p_cubicMvps,
											   std::queue<std::shared_ptr<Rotator>>& p_rotators)
	: stepCounter{ 0 },
	  m_rotators(p_rotators),
	  m_cubicMvps(p_cubicMvps)
{

}

void CubicAnimateSupervisor::ping()
{
	if (m_rotators.empty() and stepCounter == 0)
	{
		return;
	}
	if (stepCounter == 0)
	{
		m_cubicMvps.setRotator(m_rotators.front());
		m_cubicMvps.setRotators(m_rotators.front());
		m_rotators.pop();
	}
	m_cubicMvps.stepMove();
	if (stepCounter == 9)
	{
		m_cubicMvps.moveLast();
		stepCounter = 0;
		return;
	}
	stepCounter++;
}