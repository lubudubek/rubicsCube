#include "YellowCornerPermutationSolver.h"
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
	std::vector<Rotation1 > standardSequenceCornerRotateRight = { Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT,
			Rotation1::RIGHT_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT,
			Rotation1::TOP_ROTATE_RIGHT, Rotation1::RIGHT_ROTATE_DOWN };
	std::vector<Rotation1 > standardSequenceCornerRotateLeft = { Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN,
			Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::RIGHT_ROTATE_DOWN,
			Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT };

	std::map<std::vector<Position>, std::vector<Rotation1>> setYellowCornersMap =
	{
		{ {Position::BACK, Position::LEFT, Position::TOP  }, 
			{Rotation1::Y_ROTATE_RIGHT} },
		{ {Position::BACK, Position::RIGHT, Position::TOP  },
			{} },
		{ {Position::FRONT, Position::LEFT, Position::TOP  },
			{Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::RIGHT, Position::TOP  },
			{Rotation1::Y_ROTATE_LEFT} }
	};

	std::map<std::vector<Position>, std::vector<Rotation1>> initialSetterMap =
	{
		{ {Position::BACK, Position::BACK  },
			{} },
		{ {Position::FRONT, Position::FRONT },
			{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::RIGHT },
			{Rotation1::Y_ROTATE_LEFT} },
		{ {Position::LEFT, Position::LEFT  },
			{Rotation1::Y_ROTATE_RIGHT} },

		{ {Position::FRONT, Position::BACK  },
			{} },
		{ {Position::BACK, Position::FRONT },
			{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
		{ {Position::RIGHT, Position::LEFT },
			{Rotation1::Y_ROTATE_LEFT} },
		{ {Position::LEFT, Position::RIGHT  },
			{Rotation1::Y_ROTATE_RIGHT} },

		{ {Position::BACK, Position::LEFT  },
			{} },
		{ {Position::FRONT, Position::RIGHT },
			{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
		{ {Position::BACK, Position::RIGHT },
			{Rotation1::Y_ROTATE_LEFT} },
		{ {Position::FRONT, Position::LEFT  },
			{Rotation1::Y_ROTATE_RIGHT} },

		{ {Position::FRONT, Position::FRONT, Position::BACK, Position::BACK  },
			{} },
		{ {Position::RIGHT, Position::RIGHT, Position::LEFT, Position::LEFT },
			{Rotation1::Y_ROTATE_LEFT} },

		{ {Position::FRONT, Position::FRONT, Position::RIGHT, Position::LEFT  },
			{} },
		{ {Position::BACK, Position::BACK, Position::RIGHT, Position::LEFT  },
			{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
		{ {Position::FRONT, Position::BACK, Position::RIGHT, Position::RIGHT  },
			{Rotation1::Y_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::BACK, Position::LEFT, Position::LEFT  },
			{Rotation1::Y_ROTATE_LEFT} }
	};
}

YellowCornerPermutationSolver::YellowCornerPermutationSolver(
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

std::vector<Position> YellowCornerPermutationSolver::getPositionOfCubicInRightPlace()
{
	std::vector<Position> result;
	std::vector<Cubic> cornerInRightPlace;

	auto cubics = m_cubicMvps.getCubics();
	auto cubic = std::find_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return cubic.getPosition().size() == 3 and
		std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			cubic.getInitialPositionOf(Position::TOP) == Position::TOP;
	});
	cubic->setOpacity(0.7);
	result = cubic->getPosition();
	std::cout << std::endl << "Initials:";
	std::for_each(cubic->getInitialPosition().begin(), cubic->getInitialPosition().end(), [](auto pos) {std::cout << pos << " "; });
	std::cout << std::endl << "current:";

	std::for_each(result.begin(), result.end(), [](auto pos) {std::cout << pos << " "; });

	std::sort(result.begin(), result.end());
	std::cout << std::endl;

	std::for_each(result.begin(), result.end(), [](auto pos) {std::cout << pos << " "; });


	return result;
}

void YellowCornerPermutationSolver::setToRightBackCorner()
{
	std::cout << std::endl << "set to yellow to back right corner";
	auto setCubic = getPositionOfCubicInRightPlace();
	std::for_each(setCubic.begin(), setCubic.end(), [](auto pos) {std::cout << pos << " "; });

	for (auto& rotation : m_rotationsMap.at(setCubic))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
}

bool  YellowCornerPermutationSolver::isYellowOnRightBackCorner()
{
	auto cubics = m_cubicMvps.getCubics();
	auto yellowOnTop = std::find_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return
			cubic.getPosition().size() == 3 and
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
				cubic.getInitialPositionOf(Position::TOP) == Position::TOP;
	});
	std::vector<Position> initials = yellowOnTop->getInitialPosition();
	std::sort(initials.begin(), initials.end());
	std::cout << std::endl << "Yellow correct set corner: ";
	std::for_each(initials.begin(), initials.end(), [](auto pos) {std::cout << pos << " "; });
	std::vector<Position> targetPosition = {Position::BACK, Position::RIGHT, Position::TOP};
	std::cout << ((initials == targetPosition) ? "TRUE" : "FALSE");

	return initials == targetPosition;
}

int YellowCornerPermutationSolver::countYellowWallCornerOnTop()
{
	std::vector<Position> result;

	auto cubics = m_cubicMvps.getCubics();
	return std::count_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return cubic.getPosition().size() == 3 and
			std::any_of(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			cubic.getInitialPositionOf(Position::TOP) == Position::TOP;
	});
}

bool YellowCornerPermutationSolver::isLeftAlgorithmNeeded()
{
	auto cubics = m_cubicMvps.getCubics();
	auto yellowOnTop = std::find_if(cubics.begin(), cubics.end(), [](auto cubic)
	{
		return
			cubic.getPosition().size() == 3 and
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::RIGHT; }) and
			std::any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::FRONT; });
	});
	return yellowOnTop->getInitialPositionOf(Position::RIGHT) == Position::TOP;
}

std::vector<Position> YellowCornerPermutationSolver::findYellowPositionsNotOnTop()
{
	std::vector<Position> result;
	std::vector<Cubic> cornerYellowNotOnTop;

	auto cubics = m_cubicMvps.getCubics();
	std::copy_if(cubics.begin(), cubics.end(), std::back_inserter(cornerYellowNotOnTop), [](auto cubic)
	{
		return cubic.getPosition().size() == 3 and
			std::any_of(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
			cubic.getInitialPositionOf(Position::TOP) != Position::TOP;
	});
	std::transform(cornerYellowNotOnTop.begin(), cornerYellowNotOnTop.end(), std::back_inserter(result), [](auto cubic) {
		return *cubic.getPositionOfInitial(Position::TOP);
	});
	std::sort(result.begin(), result.end());
	return result;
}

void YellowCornerPermutationSolver::executeSequenceToSetOneYellowOnTop()
{
	auto yellowPositions = findYellowPositionsNotOnTop();
	for (auto& rotation : initialSetterMap.at(yellowPositions))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
	for (auto& rotation : standardSequenceCornerRotateRight)
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}

}

void YellowCornerPermutationSolver::executeSequence()
{
	if (isLeftAlgorithmNeeded())
	{
		for (auto& rotation : standardSequenceCornerRotateLeft)
		{
			m_rotates.push(allRotations.at(rotation));
			m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
		}
	}
	else
	{
		for (auto& rotation : standardSequenceCornerRotateRight)
		{
			m_rotates.push(allRotations.at(rotation));
			m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
		}
	}
}

void YellowCornerPermutationSolver::findRotations()
{
	if (countYellowWallCornerOnTop() == 4)
	{
		std::cout << std::endl << "CORNERS PERMUTED";
		m_solverContainer.setNextState();
		return;
	}
	//if (comeBackToDefaultCubePosition())
	//	return;
	if (countYellowWallCornerOnTop() == 1)
	{
		if (not isYellowOnRightBackCorner())
		{
			setToRightBackCorner();
			return;
		}
		executeSequence();
		m_solverContainer.setNextState();
		return;
	}
	executeSequenceToSetOneYellowOnTop();
	//m_solverContainer.setNextState();
	//else

}
namespace {
	std::map<Position, std::vector<Rotation1>> backFrontToDefault =
	{
		{ {Position::FRONT }, // ok 
			{} },
		{ {Position::LEFT }, // ok
			{Rotation1::Y_ROTATE_RIGHT} },
		{ {Position::BACK }, // ok
			{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
		{ {Position::RIGHT }, // ok
			{Rotation1::Y_ROTATE_LEFT} }
	};
}
bool YellowCornerPermutationSolver::comeBackToDefaultCubePosition()
{
	auto cubics = m_cubicMvps.getCubics();
	auto cubicInFront = std::find_if(cubics.begin(), cubics.end(), [&](auto cube)
	{
		return cube.getPosition() == std::vector{ Position::FRONT };
	});

	if (cubicInFront->getInitialPositionOf(Position::FRONT) == Position::FRONT)
		return false;
	//std::cout << "initial position in front: " << *cubicInFront->getInitialPositionOf(Position::FRONT) << ", from map: (size: " << backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT)).size() << ") ";
	//for (int i = 0; i < backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT)).size(); i++)
	//	std::cout << backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT))[0] << std::endl;
	for (auto& rotation : backFrontToDefault.at(*cubicInFront->getInitialPositionOf(Position::FRONT)))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
	return true;
}

YellowCornerPermutationSolver::~YellowCornerPermutationSolver()
{
}
