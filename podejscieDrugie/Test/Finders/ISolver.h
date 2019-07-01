#pragma once

class ISolver
{
public:
	virtual void findRotations() = 0;
	virtual ~ISolver() {};
};