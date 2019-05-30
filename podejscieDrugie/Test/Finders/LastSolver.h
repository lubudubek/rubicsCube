#pragma once
#include "ISolver.h"
#include <vector>
#include "../PositionTypes.hpp"
#include <map>
#include "IFinder.h"

class LastSolver :
	public ISolver
{
public:
	LastSolver(IFinder& p_solverContainer);
	void findRotations() override;
	virtual ~LastSolver();
private:
	IFinder& m_solverContainer;
};

