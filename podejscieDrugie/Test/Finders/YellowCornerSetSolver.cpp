#include "YellowCornerSetSolver.h"
#include "../AvaliableRotatorsFactory.hpp"
#include <iostream>
#include <vector>

namespace
{
	std::vector<Rotation1 > addSequences(std::vector<Rotation1> sequence1, std::vector<Rotation1> sequence2)
	{
		sequence1.insert(sequence1.end(), sequence2.begin(), sequence2.end());
		return sequence1;
	}
	std::vector<Rotation1 > standardSequenceLeftToBack = { Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP,
			Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN };
	std::vector<Rotation1 > standardSequenceRightToBack = { Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP,
			Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_DOWN };
	std::map<std::vector<Position>, std::vector<Rotation1>> setYellowCornersMap =
	{
		{ {Position::BACK, Position::LEFT, Position::TOP  }, 
			{Rotation1::Y_ROTATE_LEFT} },
		{ {Position::BACK, Position::RIGHT, Position::TOP  },
			{Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::LEFT, Position::TOP  },
			{} },
		{ {Position::FRONT, Position::RIGHT, Position::TOP  },
			{Rotation1::Y_ROTATE_RIGHT} },
	};
}

YellowCornerSetSolver::YellowCornerSetSolver(
	std::queue<std::shared_ptr<IRotation>>& p_rotates,
	std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
	CubicTransformations& p_cubicMvps,
	IFinder& solverContainer) :
	m_rotates(p_rotates), m_historyRrotates(p_historyRotates), m_cubicMvps(p_cubicMvps),
	allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
	m_solverContainer(solverContainer),
	m_rotationsMap(setYellowCornersMap)
{
}

std::vector<Position> YellowCornerSetSolver::getPositionOfCubicInRightPlace()
{
	std::vector<Position> result;
	std::vector<Cubic> cornerInRightPlace;

	auto cubics = m_cubicMvps.getCubics();
	auto cubic = std::find_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return cubic.getPosition().size() == 3 and
			std::any_of(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			std::is_permutation(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), cubic.getPosition().begin(), cubic.getPosition().end());
	});
	cubic->setOpacity(0.7);
	result = cubic->getPosition();
	std::sort(result.begin(), result.end());

	return result;
}

bool  YellowCornerSetSolver::rightFrontShouldBeRightBack()
{
	auto cubics = m_cubicMvps.getCubics();
	auto rightFrontTopCubic = std::find_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::FRONT; }) and
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::RIGHT; });
	});
	std::vector<Position> initials = rightFrontTopCubic->getInitialPosition();
	std::sort(initials.begin(), initials.end());
	std::cout << "Found front right corner: ";
	std::for_each(initials.begin(), initials.end(), [](auto pos) {std::cout << pos << " "; });
	std::vector<Position> targetPosition = {Position::BACK, Position::RIGHT, Position::TOP};
	std::cout << ((initials == targetPosition) ? "TRUE" : "FALSE");

	return initials == targetPosition;
}

int YellowCornerSetSolver::countCubeOnRightPosition()
{
	std::vector<Position> result;
	std::vector<Cubic> cornerInRightPlace;

	auto cubics = m_cubicMvps.getCubics();
	return std::count_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return cubic.getPosition().size() == 3 and
			std::any_of(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			std::is_permutation(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), cubic.getPosition().begin(), cubic.getPosition().end());
	});
}


void YellowCornerSetSolver::findRotations()
{
	if (countCubeOnRightPosition() == 4)
	{
		std::cout << std::endl << "CORNERS SET";
		m_solverContainer.setNextState();
		return;
	}
	if (countCubeOnRightPosition() == 0)
	{

		std::cout << std::endl << "Perform sequence and REPEATE THIS PROCEDURE";
		for (auto& rotation : standardSequenceRightToBack)
		{
			m_rotates.push(allRotations.at(rotation));
			m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
		}
	}
	std::vector<Position> corrected = { Position::FRONT, Position::LEFT, Position::TOP };
	if (countCubeOnRightPosition() == 1 and getPositionOfCubicInRightPlace() != corrected)
	{
		std::cout << std::endl << "Perform sequence to set one";
		//m_solverContainer.setNextState();
		std::vector<Position> solved = getPositionOfCubicInRightPlace();
		std::cout << std::endl << "FOUND POS:";
		std::for_each(solved.begin(), solved.end(), [](auto pos) {std::cout << pos << " "; });
		//if (rightToBack)
		//	performA();
		for (auto& rotation : m_rotationsMap.at(solved))
		{
			m_rotates.push(allRotations.at(rotation));
			m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
		}
		return;
		//else
		//	performB();
	}
	if (countCubeOnRightPosition() == 1 and getPositionOfCubicInRightPlace() == corrected)
	{
		std::cout << std::endl << "Perform sequence to four";

		if (rightFrontShouldBeRightBack())
		{
			for (auto& rotation : addSequences({ Rotation1::Y_ROTATE_LEFT }, standardSequenceRightToBack))
			{
				m_rotates.push(allRotations.at(rotation));
				m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
			}
		}
		else
		{
			for (auto& rotation : standardSequenceLeftToBack)
			{
				m_rotates.push(allRotations.at(rotation));
				m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
			}
		}

		m_solverContainer.setNextState();
	}
	//std::vector<Position> yellowPos = findYellowEdgePositions();
	//std::cout << std::endl << "YELLOW POSITIONS: ";
	//for_each(yellowPos.begin(), yellowPos.end(), [](auto pos) {std::cout << pos << " "; });

	//for (auto& rotation : m_rotationsMap.at(yellowPos))
	//{
	//	m_rotates.push(allRotations.at(rotation));
	//	m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	//}
	//m_solverContainer.setNextState();
}


YellowCornerSetSolver::~YellowCornerSetSolver()
{
}