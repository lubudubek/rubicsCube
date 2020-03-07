#include "SecondLayerEdgeSolver.hpp"
#include <functional>
#include <iostream>
#include "../AvaliableRotatorsFactory.hpp"

SecondLayerEdgeSolver::SecondLayerEdgeSolver(
	std::queue<std::shared_ptr<IRotation>>& p_rotates,
	std::stack<std::shared_ptr<IRotation>>& p_historyRotates,
	CubicTransformations& p_cubicMvps,
	IFinder& solverContainer,
	std::map<std::vector<Position>, std::vector<Rotation1>> rotationsMap) :
		m_rotates(p_rotates), m_historyRrotates(p_historyRotates), m_cubicMvps(p_cubicMvps),
		allRotations(AvaliableRotatorsFactory().createAvaliableRotators()),
		m_solverContainer(solverContainer),
		m_rotationsMap(rotationsMap)
{
}

namespace
{
std::map<std::vector<Position>, std::vector<Rotation1>> setInFrontMap =
{
	{ {Position::FRONT }, // ok 
		{} },
	{ {Position::LEFT }, // ok
		{Rotation1::TOP_ROTATE_LEFT} },
	{ {Position::BACK }, // ok
		{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT} },
	{ {Position::RIGHT }, // ok
		{Rotation1::TOP_ROTATE_RIGHT} }
};

std::map<std::vector<Position>, std::vector<Rotation1>> seterToStartMiddleLayerEdgeMap =
{
	{ {Position::FRONT }, // ok 
		{} },
	{ {Position::LEFT }, // ok
		{Rotation1::TOP_ROTATE_RIGHT, Rotation1::Y_ROTATE_LEFT} },
	{ {Position::BACK }, // ok
		{Rotation1::TOP_ROTATE_RIGHT, Rotation1::TOP_ROTATE_RIGHT, Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
	{ {Position::RIGHT }, // ok
		{Rotation1::TOP_ROTATE_LEFT, Rotation1::Y_ROTATE_RIGHT} }
};

std::map<std::vector<Position>, std::vector<Rotation1>> putUnsolvedMiddleFrontLeft =
{
	{ {Position::FRONT, Position::LEFT }, // ok 
		{} },
	{ {Position::LEFT, Position::FRONT }, // ok 
		{} },
	{ {Position::LEFT, Position::BACK }, // ok
		{Rotation1::Y_ROTATE_LEFT} },
	{ {Position::BACK, Position::LEFT }, // ok
		{Rotation1::Y_ROTATE_LEFT} },
	{ {Position::RIGHT, Position::FRONT }, // ok
		{Rotation1::Y_ROTATE_RIGHT} },
	{ {Position::FRONT, Position::RIGHT }, // ok
		{Rotation1::Y_ROTATE_LEFT} },
	{ {Position::RIGHT, Position::BACK }, // ok
		{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
	{ {Position::BACK, Position::RIGHT }, // ok
		{Rotation1::Y_ROTATE_LEFT, Rotation1::Y_ROTATE_LEFT} },
};

std::function<bool(Cubic&)> findNotYellowOnTop = [](Cubic& cube) ->bool
{
	auto currentPositions = cube.getPosition();
	if (currentPositions.size() == 2 and
		std::any_of(currentPositions.begin(), currentPositions.end(), [](auto& pos) {return pos == Position::TOP; }))
	{
		auto initialPositions = cube.getInitialPosition();
		if (std::none_of(initialPositions.begin(), initialPositions.end(), [](auto& pos) {return pos == Position::TOP; }))
		{
			return true;
		}
	}
	return false;
};
}

	void SecondLayerEdgeSolver::findRotations()
	{
		if (comeBackToDefaultCubePosition())
			return;

		auto& cubics = m_cubicMvps.getCubics();
		auto topNotYellow //= cubics.begin();
			= std::find_if(cubics.begin(), cubics.end(), [](Cubic& cube) ->bool
		{
			auto currentPositions = cube.getPosition();
			if (currentPositions.size() == 2 and
				std::any_of(currentPositions.begin(), currentPositions.end(), [](auto& pos) {return pos == Position::TOP; }))
			{
				auto initialPositions = cube.getInitialPosition();
				if (std::none_of(initialPositions.begin(), initialPositions.end(), [](auto& pos) {return pos == Position::TOP; }))
				{
					return true;
				}
			}
			return false;
		});
		topNotYellow->setOpacity(0.8f);
		if (topNotYellow == cubics.end())
		{
			std::cout << std::endl << std::endl << "dupa!!!";

			auto edgeNotSolvedOnCenterLayer = std::find_if(cubics.begin(), cubics.end(), [](auto cubic) {
				return cubic.getPosition().size() == 2 and
					not any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::BOTTOM; }) and
					not any_of(cubic.getPosition().begin(), cubic.getPosition().end(), [](auto pos) {return pos == Position::TOP; }) and
					not std::equal(cubic.getInitialPosition().begin(), cubic.getInitialPosition().end(), cubic.getPosition().begin(), cubic.getPosition().end());
			});
				
			if (edgeNotSolvedOnCenterLayer == cubics.end())
			{
				m_solverContainer.setNextState();
				m_solverContainer.setNextState();
				return;
			}

			for (auto& rotation : putUnsolvedMiddleFrontLeft.at({ edgeNotSolvedOnCenterLayer->getPosition() }))
			{
				m_rotates.push(allRotations.at(rotation));
				m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
			}

			auto permutationMiddleToTop = { Rotation1::TOP_ROTATE_LEFT, Rotation1::LEFT_ROTATE_UP, Rotation1::TOP_ROTATE_RIGHT, Rotation1::LEFT_ROTATE_DOWN, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_RIGHT, Rotation1::TOP_ROTATE_LEFT, Rotation1::TOP_ROTATE_LEFT, Rotation1::FRONT_ROTATE_LEFT };
			for(auto rotation : permutationMiddleToTop)
			{
				m_rotates.push(allRotations.at(rotation));
				m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
			}
			comeBackToDefaultCubePosition();

			std::cout << std::endl << std::endl << "dupa middle to top" << std::endl;
			return;
		}
		std::cout << std::endl << std::endl << "dupa!";

		auto foundPos = find_if(topNotYellow->getPosition().begin(), topNotYellow->getPosition().end(), [](auto pos) {return pos != Position::TOP; });//)];
		auto beginPos = topNotYellow->getPosition().begin();
		Position l_foundFrontCurrent = topNotYellow->getPosition()[std::distance(beginPos, foundPos)];
		for (auto& rotation : setInFrontMap.at({ l_foundFrontCurrent }))
		{
			m_rotates.push(allRotations.at(rotation));
			m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
		}

		Position l_foundFrontInitial = topNotYellow->getInitialPosition()[std::distance(beginPos, foundPos)];
		//Position l_foundFrontInitial = *topNotYellow->getInitialPositionOf(Position::FRONT);
		std::cout << std::endl << "FOUND FRONT INITIAL:" << l_foundFrontInitial << std::endl;
		for (auto& rotation : seterToStartMiddleLayerEdgeMap.at({ l_foundFrontInitial }))
		{
			m_rotates.push(allRotations.at(rotation));
			m_historyRrotates.push(allRotations.at(opositeRotationsMap.at(rotation)));
		}

		Position l_foundTopInitial = topNotYellow->getInitialPosition()[abs(std::distance(beginPos, foundPos) - 1)];
		std::cout << std::endl << "top initial:" << l_foundTopInitial << std::endl;
		m_solverContainer.setNextState();
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

	bool SecondLayerEdgeSolver::comeBackToDefaultCubePosition()
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

SecondLayerEdgeSolver::~SecondLayerEdgeSolver()
{
}
