#pragma once
#include "Rotator.hpp"

class EmptyRotator : public Rotator
{
public:
	EmptyRotator();
	~EmptyRotator();

	virtual bool move(std::vector<Cubic>& cubic) override;
};