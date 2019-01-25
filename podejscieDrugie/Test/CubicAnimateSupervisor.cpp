#include "CubicAnimateSupervisor.hpp"
#include "Rotators/EmptyRotator.hpp"
#include "Rotators/NoRotation.hpp"
#include <iostream>

CubicAnimateSupervisor::CubicAnimateSupervisor(CubicTransformations& p_cubicMvps,
											   std::queue<std::shared_ptr<Rotator>>& p_rotators,
											   std::queue<std::shared_ptr<IRotation>>& p_rotates)
	: stepCounter{ 0 },
	  m_rotators(p_rotators),
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
		//std::cout << "empty rotator; break" << std::endl;
		return;
	}
	if (stepCounter == 0)
	{
		//std::cout << "set rotator" << std::endl;
		//m_cubicMvps.setRotator(m_rotators.front());
		m_cubicMvps.setRotators(m_rotates.front());
		m_rotates.pop();
		//m_rotators.pop();
	}
	//std::cout << "make move" << std::endl;
	m_cubicMvps.stepMove();
	if (stepCounter == 9)
	{
		//std::cout << "last move" << std::endl;
		m_cubicMvps.moveLast();
		m_cubicMvps.setRotators(m_emptyRotation);
		stepCounter = 0;
		return;
	}
	stepCounter++;
}