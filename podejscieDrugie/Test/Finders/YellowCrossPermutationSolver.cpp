#include "YellowCrossPermutationSolver.h"
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
	std::vector<Rotation1 > standardSequenceBackSolvedLeftToRight = { Rotation1::CENTER_X_ROTATE_UP, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::CENTER_X_ROTATE_DOWN };
	std::vector<Rotation1 > standardSequenceBackSolvedLeftToFront = { Rotation1::CENTER_X_ROTATE_UP, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::CENTER_X_ROTATE_UP, Rotation1::TOP_ROTATE_LEFT, Rotation1::CENTER_X_ROTATE_DOWN, Rotation1::CENTER_X_ROTATE_DOWN };

	std::map<std::vector<Position>, std::vector<Rotation1>> permuteYellowCrossMap =
	{
		{ {Position::LEFT, Position::RIGHT, Position::FRONT, Position::BACK  }, 
			{Rotation1::TOP_ROTATE_LEFT} },
		{ {Position::LEFT, Position::RIGHT, Position::BACK, Position::FRONT  },
			addSequences(standardSequenceBackSolvedLeftToRight,
						 addSequences({Rotation1::Y_ROTATE_RIGHT},
									  standardSequenceBackSolvedLeftToRight))},
		{ {Position::LEFT, Position::FRONT, Position::RIGHT, Position::BACK  }, //!
			addSequences({Rotation1::Y_ROTATE_LEFT}, standardSequenceBackSolvedLeftToRight) },
		{ {Position::LEFT, Position::BACK, Position::RIGHT, Position::FRONT  },
			addSequences({Rotation1::TOP_ROTATE_LEFT, Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT},
						 standardSequenceBackSolvedLeftToRight)},
		{ {Position::LEFT, Position::BACK, Position::FRONT, Position::RIGHT  }, 
			{standardSequenceBackSolvedLeftToRight} },
		{ {Position::LEFT, Position::FRONT, Position::BACK, Position::RIGHT  },
			addSequences({Rotation1::TOP_ROTATE_LEFT}, standardSequenceBackSolvedLeftToFront)},

		{ {Position::RIGHT, Position::LEFT , Position::FRONT, Position::BACK  },
			addSequences(standardSequenceBackSolvedLeftToRight,
						 addSequences({Rotation1::Y_ROTATE_LEFT},
									  standardSequenceBackSolvedLeftToRight))},
		{ {Position::RIGHT, Position::LEFT , Position::BACK, Position::FRONT  },
			{Rotation1::TOP_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::LEFT , Position::RIGHT, Position::BACK  },
			addSequences({Rotation1::TOP_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToRight)},
		{ {Position::BACK, Position::LEFT , Position::RIGHT, Position::FRONT  },
			addSequences({Rotation1::Y_ROTATE_LEFT}, standardSequenceBackSolvedLeftToFront)},
		{ {Position::BACK, Position::LEFT , Position::FRONT, Position::RIGHT  },
			addSequences({Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToFront)},
		{ {Position::FRONT, Position::LEFT , Position::BACK, Position::RIGHT  },
			addSequences({Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToFront)},

		{ {Position::RIGHT, Position::FRONT, Position::LEFT , Position::BACK  },
			addSequences({Rotation1::TOP_ROTATE_RIGHT,Rotation1::Y_ROTATE_RIGHT,Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToFront)},
		{ {Position::RIGHT, Position::BACK, Position::LEFT , Position::FRONT  },
			{standardSequenceBackSolvedLeftToFront} },
		{ {Position::FRONT, Position::RIGHT, Position::LEFT , Position::BACK  },
			addSequences({Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToRight)},
		{ {Position::BACK, Position::RIGHT, Position::LEFT , Position::FRONT  },
			addSequences({Rotation1::TOP_ROTATE_LEFT},
						 standardSequenceBackSolvedLeftToRight)},
		{ {Position::BACK, Position::FRONT, Position::LEFT , Position::RIGHT  },
			{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT} },
		{ {Position::FRONT, Position::BACK, Position::LEFT , Position::RIGHT  },
			addSequences(standardSequenceBackSolvedLeftToFront,
						 addSequences({Rotation1::TOP_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT},
									  standardSequenceBackSolvedLeftToFront))},

		{ {Position::RIGHT, Position::FRONT, Position::BACK, Position::LEFT },
			addSequences({Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToFront)},
		{ {Position::RIGHT, Position::BACK, Position::FRONT, Position::LEFT },
			addSequences({Rotation1::TOP_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToFront)},
		{ {Position::FRONT, Position::RIGHT, Position::BACK, Position::LEFT },
			addSequences({Rotation1::TOP_ROTATE_LEFT}, standardSequenceBackSolvedLeftToFront)},
		{ {Position::BACK, Position::RIGHT, Position::FRONT, Position::LEFT },
			addSequences({Rotation1::Y_ROTATE_RIGHT}, standardSequenceBackSolvedLeftToRight)},
		{ {Position::BACK, Position::FRONT, Position::RIGHT, Position::LEFT },
			addSequences(standardSequenceBackSolvedLeftToFront,
						 addSequences({Rotation1::TOP_ROTATE_RIGHT, Rotation1::Y_ROTATE_RIGHT},
									  standardSequenceBackSolvedLeftToRight))},
		{ {Position::FRONT, Position::BACK, Position::RIGHT, Position::LEFT },
			{} }
	};
}

YellowCrossPermutationSolver::YellowCrossPermutationSolver(
	std::queue<std::shared_ptr<IRotation>>& p_rotates,
	std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
	CubicTransformations& p_cubicMvps,
	IFinder& solverContainer) :
	m_rotates(p_rotates), m_historyRrotates(p_historyRotates), m_cubicMvps(p_cubicMvps),
	allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
	m_solverContainer(solverContainer),
	m_rotationsMap(permuteYellowCrossMap)
{
}

std::vector<Position> YellowCrossPermutationSolver::findYellowEdgePositions()
{
	std::vector<Position> result;
	std::vector<Cubic> withYellowEdges;

	auto cubics = m_cubicMvps.getCubics();
	std::copy_if(cubics.begin(), cubics.end(), std::back_inserter(withYellowEdges), [](auto cubic)
	{
		return cubic.getPosition().size() == 2 and
		cubic.getPositionOfInitial(Position::TOP) == Position::TOP;
	});
	std::cout << std::endl << "INITIALS TOP: ";
	std::sort(withYellowEdges.begin(), withYellowEdges.end(), [](auto& cubic1, auto& cubic2)
	{ return *cubic1.getInitialPositionOf(*cubic1.getPositionOtherThan(Position::TOP)) < *cubic2.getInitialPositionOf(*cubic2.getPositionOtherThan(Position::TOP)); });
	std::transform(withYellowEdges.begin(), withYellowEdges.end(), std::back_inserter(result), [](auto cubic) {
		std::cout << *cubic.getInitialPositionOf(*cubic.getPositionOtherThan(Position::TOP)) << " ";
		return *cubic.getPositionOtherThan(Position::TOP); });
	return result;
}


void YellowCrossPermutationSolver::findRotations()
{
	std::vector<Position> yellowPos = findYellowEdgePositions();
	std::cout << std::endl << "YELLOW POSITIONS: ";
	for_each(yellowPos.begin(), yellowPos.end(), [](auto pos) {std::cout << pos << " "; });

	for (auto& rotation : m_rotationsMap.at(yellowPos))
	{
		m_rotates.push(allRotations.at(rotation));
		m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
	}
	m_solverContainer.setNextState();
}


YellowCrossPermutationSolver::~YellowCrossPermutationSolver()
{
}
