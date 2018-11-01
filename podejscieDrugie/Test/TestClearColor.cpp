#include "TestClearColor.hpp"
#include "renderer.hpp"
#include "GL/glew.h"
#include "imgui/imgui.h"

namespace test
{

	TestClearColor::TestClearColor()
		: m_clearColor{ 0.3f, 0.2f, 0.8f, 0.1f }
	{

	}

	TestClearColor::~TestClearColor()
	{

	}

	void TestClearColor::OnUpdate(float deltaTime)
	{

	}

	void TestClearColor::OnRenderer()
	{
		GLCall(glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnImGuiRenderer()
	{
		ImGui::ColorEdit4("Background color", m_clearColor);
	}

}