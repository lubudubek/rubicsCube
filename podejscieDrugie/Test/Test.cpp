#include "Test.hpp"
#include "imgui/imgui.h"
#include <iostream>
#include <tuple>
#include <functional>
#include <vector>
#include <string>

namespace test
{

	TestMenu::TestMenu(Test*& currentTestPointer)
		: m_currentTest(currentTestPointer)
	{

	}



	void TestMenu::OnImGuiRenderer()
	{
		for (auto& test : m_tests)
		{
			if(ImGui::Button(test.first.c_str()))
				m_currentTest = test.second();
		}
	}
}