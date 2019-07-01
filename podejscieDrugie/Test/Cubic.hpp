#pragma once
#include <vector>
#include "glm/glm.hpp"
#include "PositionSwitch.hpp"
#include "Rotators/Rotation.hpp"
#include "ICubicToDraw.h"
#include <optional>

class Cubic : public ICubicToDraw
{
private:
	std::vector<Position> m_positions;
	std::vector<Position> m_initialPositions;
	glm::mat4 m_transformation;
	glm::mat4 m_initTransformation;
	std::shared_ptr<IRotation> m_rotator;
	float m_opacity{ 1.0f };
public:
	Cubic(std::vector<Position>, glm::mat4);
	glm::mat4 getTransformation() const;
	void initiateTransformation(glm::mat4 addedTransformation);
	std::vector<Position>& getPosition();
	std::vector<Position>& getInitialPosition();
	//void setRotation(std::shared_ptr<Rotator>);
	void applyRotator(std::shared_ptr<IRotation>);
	void rotate();

	float getOpacity();
	void setOpacity(float);

	PositionSwitch m_positionSwitch;

	glm::mat4 commonTransformation;

	void rotateOnAxis(float angle, glm::vec3 axis);
	double m_animationAngle;

	//void rotatePosition(std::vector<Position> rotation, int direction);
	void rotatePosition();
	std::optional<Position> getPositionOfInitial(Position initialPosition);
	std::optional<Position> getInitialPositionOf(Position);
	std::optional<Position> getPositionOtherThan(Position);
	std::optional<Position> getInitPositionOtherThan(Position);
};