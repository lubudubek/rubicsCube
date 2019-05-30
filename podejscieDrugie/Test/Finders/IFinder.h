#pragma once

class IFinder
{
public:
	virtual void findNextRotationSet() = 0;
	virtual void setNextState() = 0;
	virtual void setInitialState() = 0;
};