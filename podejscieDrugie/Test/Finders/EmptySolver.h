#pragma once
#include "ISolver.h"
#include <vector>
//#include "../PositionTypes.hpp"
//#include <map>

class EmptySolver :
	public ISolver
{
public:
	EmptySolver();
	void findRotations() override;
	virtual ~EmptySolver();
};

