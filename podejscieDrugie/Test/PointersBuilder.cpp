#include "PointersBuilder.hpp"
#include <iostream>

namespace
{
	const int floatsInVertex = 7;
	const int pointsInSquare = 4;
	const int surfacesInCube = 6;

	const int floatsInCube = floatsInVertex * pointsInSquare * surfacesInCube;
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
		-0.5f, -0.5f, -0.5f, 1.0f, 0.23f, 0.0f, 1.0f,  // back
		 0.5f, -0.5f, -0.5f, 1.0f, 0.23f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 0.23f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.23f, 0.0f, 1.0f,

		-0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.1f,  // front
		 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.1f,
		 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.1f,
		-0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.1f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.1f,  // right
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.1f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.1f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.1f,

		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.1f,  // left
		 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.1f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.1f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.1f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.1f,  // bottom
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.1f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.1f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.1f,

		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.1f,  // top
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.1f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.1f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.1f
	};
}

void PointersBuilder::addCubeBoarders()
{
	std::cout << std::endl << std::endl;
	for (int i = floatsInCube; i < floatsInCube + 7 * 8; i++)
	{
		if (i % 7 < 2)
		{
			//std::cout << i << ", " << i % 7 << "previous point: " << m_points[i] << ", and point from old:" << m_points[i - floatsInCube];
			m_points[i] = m_points[i - floatsInCube] * 0.8f;
			//std::cout << ", new point:" << m_points[i] << std::endl;
		}
		else if (i % 7 == 6)
		{
			//std::cout << "don't touch: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
		else
		{
			//std::cout << "else: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
	}

	for (int i = floatsInCube + 7 * 8; i < floatsInCube + 7 * 16; i++)
	{
		if (i % 7 == 1 || i % 7 == 2)
		{
			//std::cout << i << ", " << i % 7 << "previous point: " << m_points[i] << ", and point from old:" << m_points[i - floatsInCube];
			m_points[i] = m_points[i - floatsInCube] * 0.8f;
			//std::cout << ", new point:" << m_points[i] << std::endl;
		}
		else if (i % 7 == 6)
		{
			//std::cout << "don't touch: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
		else
		{
			//std::cout << "else: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
	}

	for (int i = floatsInCube + 7 * 16; i < floatsInCube + 7 * 24; i++)
	{
		if (i % 7 == 0 || i % 7 == 2)
		{
			//std::cout << i << ", " << i % 7 << "previous point: " << m_points[i] << ", and point from old:" << m_points[i - floatsInCube];
			m_points[i] = m_points[i - floatsInCube] * 0.8f;
			//std::cout << ", new point:" << m_points[i] << std::endl;
		}
		else if (i % 7 == 6)
		{
			//std::cout << "don't touch: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
		else
		{
			//std::cout << "else: " << i << ", " << i % 7 << std::endl;
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
			//std::cout << i << ", " << i % 7 << "previous point: " << m_points[i] << ", and point from old:" << m_points[i - (floatsInCube * 2)];
			m_points[i] = m_points[i - (floatsInCube)];
			//std::cout << ", new point:" << m_points[i] << std::endl;
		}
		else if (i % 7 == 6)
		{
			//std::cout << "don't touch: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
		else
		{
			//std::cout << "else: " << i << ", " << i % 7 << std::endl;
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
			//std::cout << i << ", " << i % 7 << "previous point: " << m_points[i] << ", and point from old:" << m_points[i - floatsInCube];
			m_points[i] = m_points[i];
			//std::cout << ", new point:" << m_points[i] << std::endl;
		}
		else if (i % 7 == 6)
		{
			//std::cout << "don't touch: " << i << ", " << i % 7 << std::endl;
			m_points[i] = m_points[i - floatsInCube];
		}
		else
		{
			//std::cout << "else: " << i << ", " << i % 7 << std::endl;
			m_points[i] = 0.0f;;
		}
	}
}