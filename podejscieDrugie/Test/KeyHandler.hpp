#pragma once
#include "CubicTransformations.hpp"
#include "Rotators/CenterXUpRotator.hpp"
#include "Rotators/BackLeftRotator.hpp"
#include "Rotators/BackRightRotator.hpp"
#include "Rotators/BottomLeftRotator.hpp"
#include "Rotators/BottomRightRotator.hpp"
#include "Rotators/CenterXDownRotator.hpp"
#include "Rotators/CenterYLeftRotator.hpp"
#include "Rotators/CenterYRightRotator.hpp"
#include "Rotators/CenterZLeftRotator.hpp"
#include "Rotators/CenterZRightRotator.hpp"
#include "Rotators/FrontLeftRotator.hpp"
#include "Rotators/FrontRightRotator.hpp"
#include "Rotators/LeftDownRotator.hpp"
#include "Rotators/LeftUpRotator.hpp"
#include "Rotators/RightDownRotator.hpp"
#include "Rotators/RightUpRotator.hpp"
#include "Rotators/TopLeftRotator.hpp"
#include "Rotators/TopRightRotator.hpp"
#include "Rotators/EmptyRotator.hpp"
#include <queue>

class KeyHandler
{

public:
	KeyHandler(CubicTransformations& cubicMvps);
	void handleKey(std::queue<std::shared_ptr<Rotator>>& rotators);
private:
	std::shared_ptr<BackLeftRotator> m_backLeftRotator;
	std::shared_ptr<CenterXUpRotator> m_centerXUpRotator;
	std::shared_ptr<BackRightRotator> m_backRightRotator;
	std::shared_ptr<BottomLeftRotator> m_bottomLeftRotator;
	std::shared_ptr<BottomRightRotator> m_bottomRightRotator;
	std::shared_ptr<CenterXDownRotator> m_centerXDownRotator;
	std::shared_ptr<CenterYLeftRotator> m_centerYLeftRotator;
	std::shared_ptr<CenterYRightRotator> m_centerYRightRotator;
	std::shared_ptr<CenterZLeftRotator> m_centerZLeftRotator;
	std::shared_ptr<CenterZRightRotator> m_centerZRightRotator;
	std::shared_ptr<FrontLeftRotator> m_frontLeftRotator;
	std::shared_ptr<FrontRightRotator> m_frontRightRotator;
	std::shared_ptr<LeftDownRotator> m_leftDownRotator;
	std::shared_ptr<LeftUpRotator> m_leftUpRotator;
	std::shared_ptr<RightDownRotator> m_rightDownRotator;
	std::shared_ptr<RightUpRotator> m_rightUpRotator;
	std::shared_ptr<TopLeftRotator> m_topLeftRotator;
	std::shared_ptr<TopRightRotator> m_topRightRotator;
	std::shared_ptr<EmptyRotator> m_emptyRotator;
	CubicTransformations& m_cubicMvps;
};