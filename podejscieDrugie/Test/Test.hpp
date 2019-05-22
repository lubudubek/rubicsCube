#pragma once
#include "imgui/imgui.h"
#include <iostream>
#include <tuple>
#include <functional>
#include <vector>
#include <string>

namespace test
{
	class Test
	{
	public:
		Test() {}
		virtual ~Test() {}

		virtual void OnUpdate(float deltaTime) {}
		virtual void OnRenderer() {}
		virtual void OnImGuiRenderer() {}
	};
}