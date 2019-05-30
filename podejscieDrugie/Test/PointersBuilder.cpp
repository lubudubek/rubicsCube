#include "PointersBuilder.hpp"
#include <iostream>

namespace
{
	constexpr int floatsInVertex = 7;
	constexpr int pointsInSquare = 4;
	constexpr int surfacesInCube = 6;

	constexpr int floatsInCube = floatsInVertex * pointsInSquare * surfacesInCube;
}

PointersBuilder::PointersBuilder()
	: m_points()
{
	m_points.resize(3 * floatsInCube);
	setInitialCubePoints();
	addCubeBoarders();
	addInsideCubeBoarders();
	convertOutsideCubeBoarders();
}
PointersBuilder::~PointersBuilder()
{
}

float* PointersBuilder::getPoints()
{
	return &m_points[0];
}

void PointersBuilder::setInitialCubePoints()
{
	m_points = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,  // back
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,

		-0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,  // front
		 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
											   
		-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,  // left
		-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
											   
		 0.5f, -0.5f, -0.5f, 1.0f, 0.23f, 0.0f, 1.0f,  // right
		 0.5f,  0.5f, -0.5f, 1.0f, 0.23f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.23f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.23f, 0.0f, 1.0f,
											   
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,  // bottom
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
											   
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f,  // top
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f
	};
}

void PointersBuilder::addCubeBoarders()
{
	std::cout << std::endl << std::endl;
	for (int i = floatsInCube; i < floatsInCube + 7 * 8; i++)
	{
		if (i % 7 < 2)
		{
			m_points[i] = m_points[i - floatsInCube] * 0.8f;
		}
		else if (i % 7 == 6)
		{
			m_points[i] = 1.0f;
		}
		else
		{
			m_points[i] = m_points[i - floatsInCube];
		}
	}

	for (int i = floatsInCube + 7 * 8; i < floatsInCube + 7 * 16; i++)
	{
		if (i % 7 == 1 || i % 7 == 2)
		{
			m_points[i] = m_points[i - floatsInCube] * 0.8f;
		}
		else if (i % 7 == 6)
		{
			m_points[i] = 1.0f;
		}
		else
		{
			m_points[i] = m_points[i - floatsInCube];
		}
	}

	for (int i = floatsInCube + 7 * 16; i < floatsInCube + 7 * 24; i++)
	{
		if (i % 7 == 0 || i % 7 == 2)
		{
			m_points[i] = m_points[i - floatsInCube] * 0.8f;
		}
		else if (i % 7 == 6)
		{
			m_points[i] = 1.0f;
		}
		else
		{
			m_points[i] = m_points[i - floatsInCube];
		}
	}
}

void PointersBuilder::addInsideCubeBoarders()
{
	std::cout << std::endl << std::endl;
	for (int i = floatsInCube * 2; i < floatsInCube * 3; i++)
	{
		if (i % 7 < 3)
		{
			m_points[i] = m_points[i - (floatsInCube)];
		}
		else if (i % 7 == 6)
		{
			m_points[i] = 1.0f;
		}
		else
		{
			m_points[i] = 0.0f;
		}
	}
}

void PointersBuilder::convertOutsideCubeBoarders()
{
	std::cout << std::endl << std::endl;
	for (int i = 0; i < floatsInCube; i++)
	{
		if (i % 7 < 3)
		{
		}
		else if (i % 7 == 6)
		{
			m_points[i] = 1.0f;
		}
		else
		{
			m_points[i] = 0.0f;;
		}
	}
}