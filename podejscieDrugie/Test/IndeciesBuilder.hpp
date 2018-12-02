#pragma once
#include <memory>
#include <vector>

class IndeciesBuilder
{
public:
	IndeciesBuilder();
	~IndeciesBuilder();

	unsigned int* getIndecies();
private:
	std::vector<unsigned int> m_indecies;

	void setInitialCubeIndecies();
	void setAdditionalCubeIndecies();
	void addBoardersIndecies();
};