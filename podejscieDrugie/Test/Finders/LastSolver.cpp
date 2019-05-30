#include "LastSolver.h"
#include <iostream>
#include "../PositionTypes.hpp"
#include <map>


LastSolver::LastSolver(IFinder& p_solverContainer)
	: m_solverContainer(p_solverContainer)
{
}

void LastSolver::findRotations()
{
	m_solverContainer.setInitialState();
}

LastSolver::~LastSolver()
{
}
