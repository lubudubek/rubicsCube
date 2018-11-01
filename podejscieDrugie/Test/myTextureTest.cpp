#include "MyTextureTest.hpp"
#include "renderer.hpp"
#include "GL/glew.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

namespace test
{

	MyTextureTest::MyTextureTest()
		: m_points{
			-50.0f, -50.0f, 0.2f, 0.2f,
			50.0f, -50.0f, 0.8f, 0.2f,
			50.0f, 50.0f, 0.8f, 0.8f,
			-50.0f, 50.0f, 0.2f, 0.8f
			},
			m_indecies {
				0, 1, 2,
				2, 3, 0
			},
			m_translationA(200.0f, 200.0f, 0.0f),
			m_translationB(400.0f, 200.0f, 0.0f),
			m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
		    m_va(),
			m_vb(m_points, 4 * 4 * sizeof(float)),
		    m_ib(m_indecies, 6),
			m_layout(),
			m_shader("res/shaders/Basic.shader"),
			m_texture("logo1.png")
	{
		m_layout.Push<float>(2);
		m_layout.Push<float>(2);
		m_va.AddBuffer(m_vb, m_layout);

		m_shader.Bind();
		m_shader.SetUniform1i("u_Texture", 0);

		m_texture.Bind();
	}

	MyTextureTest::~MyTextureTest()
	{


	}

	void MyTextureTest::OnUpdate(float deltaTime)
	{

	}

	void MyTextureTest::OnRenderer()
	{
		Renderer render;
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
			glm::mat4 mvp = m_proj * m_view * model;
			m_shader.Bind();

			
			m_shader.SetUniformMat4f("u_MVP", mvp);
			render.Draw(m_va, m_ib, m_shader);
		// update other events like input handling 
		}
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);
			glm::mat4 mvp = m_proj * m_view * model;
			m_shader.Bind();

			m_shader.SetUniformMat4f("u_MVP", mvp);
			render.Draw(m_va, m_ib, m_shader);
		}
	}

	void MyTextureTest::OnImGuiRenderer()
	{
			ImGui::SliderFloat3("float A", &m_translationA.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
			ImGui::SliderFloat3("float B", &m_translationB.x, 0.0f, 960.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

	//float* 
	//::setPoints()
	//{
	//	float points[] = {
	//		-50.0f, -50.0f, 0.2f, 0.2f,
	//		 50.0f, -50.0f, 0.8f, 0.2f,
	//		 50.0f,  50.0f, 0.8f, 0.8f,
	//		-50.0f,  50.0f, 0.2f, 0.8f
	//		};
	//	return points;
	//}

	//unsigned int* MyTextureTest::setIndecies()
	//{
	//	unsigned int indecies[] = {
	//			0, 1, 2,
	//			2, 3, 0
	//	};
	//	return indecies;
	//}
}