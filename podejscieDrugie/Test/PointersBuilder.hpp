#pragma once
#include <memory>
#include <vector>

class PointersBuilder
{
public:
	PointersBuilder();
	~PointersBuilder();

	float* getPoints();
private:
	std::vector<float> m_points;

	void setInitialCubePoints();
	void addCubeBoarders();
	void convertOutsideCubeBoarders();
	void addInsideCubeBoarders();
};