#include "CubeTest.hpp"
#include "renderer.hpp"
#include "GL/glew.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include <corecrt_math_defines.h>
#include "KeyHandler.hpp"
#include "PointersBuilder.hpp"
#include "IndeciesBuilder.hpp"
//#include "Finders/BlankRotattionFinder.h"

//#define _USE_MATH_DEFINES

namespace test
{

	CubeTest::CubeTest()
		:	m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
			cubicMvps(m_onlineParams),
			m_rotationFinder(std::make_shared<RealRotationFinder>(m_rotates, cubicMvps)),
		    m_keyHandler(m_rotationFinder, m_rotates, m_rotatesHistory)
	{
		PointersBuilder pointerBuilder;
		IndeciesBuilder indeciesBuilder;

		m_va = std::make_shared<VertexArray>();
		m_vb = std::make_shared<VertexBuffer>(pointerBuilder.getPoints(), 3 * 7 * 24 * sizeof(float));
		m_ib = std::make_shared<IndexBuffer>(indeciesBuilder.getIndecies(), 3 * 12 + 6 * 24);

		m_shader = std::make_shared<Shader>("res/shaders/Cube.shader");
		m_layout = std::make_shared<VertexBufferLayout>();

		m_layout->Push<float>(3);
		m_layout->Push<float>(4);
		m_va->AddBuffer(*m_vb, *m_layout);

		m_shader->Bind();
		
		m_cubicSupervisor = std::make_unique<CubicAnimateSupervisor>(
			cubicMvps, m_rotates, m_rotatesHistory, m_rotationFinder);
	}

	CubeTest::~CubeTest()
	{


	}

	void CubeTest::OnUpdate(float deltaTime)
	{

	}

	void CubeTest::OnRenderer()
	{
		Renderer render;
		render.Clear();
		{
			m_keyHandler.handleKey();
		   
			m_cubicSupervisor->ping();
			cubicMvps.handleCamera();
			m_shader->Bind();

			for (auto& cubic : cubicMvps.getCubics())
			{
				if(cubic.getOpacity() > 0.9f)
				{
					m_shader->SetUniformMat4f("u_MVP", cubic.getTransformation());
					m_shader->SetUniform1f("opacity", cubic.getOpacity());
					render.Draw(*m_va, *m_ib, *m_shader);
				}
			}
			for (auto& cubic : cubicMvps.getCubics())
			{
				if (cubic.getOpacity() < 0.9f)
				{
					m_shader->SetUniformMat4f("u_MVP", cubic.getTransformation());
					m_shader->SetUniform1f("opacity", cubic.getOpacity());
					render.Draw(*m_va, *m_ib, *m_shader);
				}
			}

		}
	}

	void CubeTest::OnImGuiRenderer()
	{
			ImGui::SliderFloat("Fovy", &m_onlineParams.fovy, 6.0f, 9.0f);
			ImGui::SliderFloat("Fovy 1", &m_onlineParams.near, 1.5f, 2.5f);
			ImGui::SliderFloat("Fovy 2", &m_onlineParams.far, -100.0f, 100.0f);

			ImGui::SliderFloat("Translate Z", &m_onlineParams.transformZ, -100.0f, 100.0f);
			ImGui::SliderFloat("Rotation X", &m_onlineParams.rotateX, -0.6f, 0.6f);
			ImGui::SliderFloat("Rotation Y", &m_onlineParams.rotateY, -2.0f, 2.0f);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}