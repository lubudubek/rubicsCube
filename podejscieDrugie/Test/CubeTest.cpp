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
		:	m_translationA(0.0f, 0.0f, -3.0f),
			m_translationB(0.0f, 0.0f, -6.0f),
			m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
			m_translation_x(0.0f),
	        m_translation_y(0.0f),
			m_translation_z(0.0f),
			cubicMvps(m_translation_x, m_translation_y, m_translation_z)
	{
		setCubePoints();
		setIndecies();

		m_va = std::make_shared<VertexArray>();
		m_vb = std::make_shared<VertexBuffer>(m_points, 7 * 24 * sizeof(float));
		m_ib = std::make_shared<IndexBuffer>(m_indecies, 3*12);
		
		delete m_points;
		delete m_indecies;

		m_shader = std::make_shared<Shader>("res/shaders/Cube.shader");
		//m_texture = std::make_shared<Texture>("logo1.png");

		m_layout = std::make_shared<VertexBufferLayout>();

		m_layout->Push<float>(3);
		m_layout->Push<float>(4);
		m_va->AddBuffer(*m_vb, *m_layout);

		m_shader->Bind();

		m_fovy = 20.0f;
		m_fovy1 = 2.0f;
		m_fovy2 = 10.0f;

		m_translation_x = 0.0f;
		m_translation_y = 0.0f;
		m_translation_z = -6.0f;

		
		m_rotateY = 0.0f;
		m_rotateX = 0.0f;
		//m_shader->SetUniform1i("u_Texture", 0);

		//m_texture->Bind();
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
			//glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
			//glm::mat4 rotationx = glm::rotate(glm::mat4(1.0f), m_rotation_x, glm::vec3(1.0f, 0.0f, 0.0f));
			//glm::mat4 rotationy = glm::rotate(glm::mat4(1.0f), m_rotation_y, glm::vec3(0.0f, 0.1f, 0.0f));
			//glm::mat4 model1 = glm::translate(glm::mat4(1.0f), m_translationB);

			//glm::mat4 proj = glm::perspective(m_fovy, float(4 / 3), m_fovy1, m_fovy2);
			//glm::mat4 mvp = m_proj * m_view * model;


			cubicMvps.update();

			//cubicMvps.RotateCenterX(m_rotateX);
			//cubicMvps.RotateCenterY(m_rotateY);

			//cubicMvps.addCommonTrnasformation(proj * model1 * rotationy * rotationx);
			
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
			ImGui::SliderFloat3("Translation A", &m_translationA.x, -10.0f, 10.0f);
			ImGui::SliderFloat3("Translation B", &m_translationB.x, -10.0f, 10.0f);

			ImGui::SliderFloat("Fovy", &m_fovy, 0.0f, 30.0f);
			ImGui::SliderFloat("Fovy 1", &m_fovy1, 0.0f, 30.0f);
			ImGui::SliderFloat("Fovy 2", &m_fovy2, 0.0f, 30.0f);

			ImGui::SliderFloat("Rotation x", &m_translation_x, -8.0f, 8.0f);
			ImGui::SliderFloat("Rotation y", &m_translation_y, -8.0f, 8.0f);
			ImGui::SliderFloat("Rotation z", &m_translation_z, -8.0f, 8.0f);

			ImGui::SliderFloat("Rotate y", &m_rotateY, -8.0f, 8.0f);
			ImGui::SliderFloat("Rotate x", &m_rotateX, -8.0f, 8.0f);

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