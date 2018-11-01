#pragma once

#include "Test.hpp"

namespace test
{

	class TestClearColor : public Test
	{
	public:
		TestClearColor();
		~TestClearColor();

		virtual void OnUpdate(float deltaTime);
		virtual void OnRenderer();
		virtual void OnImGuiRenderer();
	private:
		float m_clearColor[4];
	};

}