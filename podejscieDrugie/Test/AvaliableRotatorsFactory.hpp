#pragma once
#include <map>
#include <memory>

enum class Rotation1;
class IRotation;

class AvaliableRotatorsFactory
{
public:
	std::map<Rotation1, std::shared_ptr<IRotation>> createAvaliableRotators();
};