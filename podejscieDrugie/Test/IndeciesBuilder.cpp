#include "IndeciesBuilder.hpp"
#include <iostream>

IndeciesBuilder::IndeciesBuilder()
	: m_indecies()
{
	m_indecies.resize(3 * 12 + 6 * 24);
	setInitialCubeIndecies();
	setAdditionalCubeIndecies();
	addBoardersIndecies();
}
IndeciesBuilder::~IndeciesBuilder()
{
}

unsigned int* IndeciesBuilder::getIndecies()
{
	return &m_indecies[0];
}

void IndeciesBuilder::setInitialCubeIndecies()
{
	m_indecies = {
			0,  1,  2,
			0,  3,  2,
			4,  5,  6,
			4,  7,  6,
			8,  9,  10,
			8, 11, 10,
			12, 13, 14,
			12, 15, 14,
			16, 17, 18,
			16, 19, 18,
			20, 21, 22,
			20, 23, 22,

			0,   1, 48,
			48, 49,  1,
			2,   3, 50,
			50, 51,  3,
			0,   3, 48,
			48, 51,  3,
			1,   2, 49,
			49, 50,  2
	};
}

void IndeciesBuilder::setAdditionalCubeIndecies()
{
	int j = 3 * 12 + 24;
	for (int i = 1; i < 6; i++)
	{
		//std::cout << "j old: " << j;
		for (int p = 0; p < 24; p++)
		{
			//std::cout << ", old: " << m_indecies[j + p - 24];
			m_indecies[j + p] = m_indecies[j + p - 24] + 4;
			//std::cout << ", new:" << m_indecies[j + p] << std::endl;
		}
		j = j + 24;
		//std::cout << ", j new: " << j << std::endl;
		//std::cout << std::endl;
	}
}

void IndeciesBuilder::addBoardersIndecies()
{
	for (int i = 0; i < 3 * 12; i++)
	{
		m_indecies[i] = m_indecies[i] + 24;
	}
}