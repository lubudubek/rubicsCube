#include "CubeTest.hpp"
#include "renderer.hpp"
#include "GL/glew.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"
#include <corecrt_math_defines.h>
#include "KeyHandler.hpp"
//#define _USE_MATH_DEFINES

namespace test
{

	CubeTest::CubeTest()
		:	m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
			cubicMvps(m_onlineParams)
	{
		setCubePoints();
		setIndecies();

		m_va = std::make_shared<VertexArray>();
		m_vb = std::make_shared<VertexBuffer>(m_points, 7 * 24 * sizeof(float));
		m_ib = std::make_shared<IndexBuffer>(m_indecies, 3*12);
		
		delete m_points;
		delete m_indecies;

		m_shader = std::make_shared<Shader>("res/shaders/Cube.shader");

		m_layout = std::make_shared<VertexBufferLayout>();

		m_layout->Push<float>(3);
		m_layout->Push<float>(4);
		m_va->AddBuffer(*m_vb, *m_layout);

		m_shader->Bind();
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
		{
			cubicMvps.update();
			
			m_shader->Bind();

			KeyHandler().handleKey(cubicMvps);

			for(auto& trans : cubicMvps.getTransformations())
			{
				m_shader->SetUniformMat4f("u_MVP", trans);
				render.Draw(*m_va, *m_ib, *m_shader);
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

	void CubeTest::setCubePoints()
	{
		int i = 7 * 4 * 6;
		m_points = new float[i] {
			-0.5f, -0.5f, -0.5f, 1.0f, 0.65f, 0.0f, 1.0f,  // back
			 0.5f, -0.5f, -0.5f, 1.0f, 0.65f, 0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f, 1.0f, 0.65f, 0.0f, 1.0f,
			-0.5f,  0.5f, -0.5f, 1.0f, 0.65f, 0.0f, 1.0f,

			-0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,  // front
			 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,  // right
			-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f,

			 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,  // left
			 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f,

			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,  // bottom
			 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f,

			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f,  // top
			 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 1.0f
		};
	}

	void CubeTest::setIndecies()
	{
		int i = 3*12;
		unsigned int* indecies = new unsigned int[i]{

			0,  1,  2,
			2,  3,  0,
			4,  5,  6,
			6,  7,  4,
			8,  9,  10,
			10, 11, 8,
			12, 13, 14,
			14, 15, 12,
			16, 17, 18,
			18, 19, 16,
		    20, 21, 22,
			22, 23, 20

		};
		m_indecies = indecies;
	}

}