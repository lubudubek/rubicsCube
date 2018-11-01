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

	class TestMenu : public Test
	{
	public:
		TestMenu(Test*& currentTestPointer);

		void OnImGuiRenderer() override;

		template<typename T>
		void RegisterTest(const std::string& name)
		{
			std::cout << "Registered test" << name;
			m_tests.push_back(std::make_pair(name, []() { return new T(); }));
		}
	private:
		Test*& m_currentTest;
		std::vector<std::pair<std::string, std::function<Test*()>>> m_tests;
	};

}