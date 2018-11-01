#include "MyTexturePtrs.hpp"
#include "renderer.hpp"
#include "GL/glew.h"
#include "imgui/imgui.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

namespace test
{

	MyTexturePtrs::MyTexturePtrs()
		:	m_translationA(200.0f, 200.0f, 0.0f),
			m_translationB(400.0f, 200.0f, 0.0f),
			m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
	{
		setPoints();
		setIndecies();

		m_va = std::make_shared<VertexArray>();
		m_vb = std::make_shared<VertexBuffer>(m_points, 4 * 4 * sizeof(float));
		m_ib = std::make_shared<IndexBuffer>(m_indecies, 6);

		m_shader = std::make_shared<Shader>("res/shaders/Basic.shader");
		m_texture = std::make_shared<Texture>("logo1.png");

		m_layout = std::make_shared<VertexBufferLayout>();

		m_layout->Push<float>(2);
		m_layout->Push<float>(2);
		m_va->AddBuffer(*m_vb, *m_layout);

		m_shader->Bind();
		m_shader->SetUniform1i("u_Texture", 0);

		m_texture->Bind();
	}

	MyTexturePtrs::~MyTexturePtrs()
	{


	}

	void MyTexturePtrs::OnUpdate(float deltaTime)
	{

	}

	void MyTexturePtrs::OnRenderer()
	{
		Renderer render;
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);
			glm::mat4 mvp = m_proj * m_view * model;
			m_shader->Bind();

			m_shader->SetUniformMat4f("u_MVP", mvp);
			render.Draw(*m_va, *m_ib, *m_shader);
		}
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);
			glm::mat4 mvp = m_proj * m_view * model;
			m_shader->Bind();

			m_shader->SetUniformMat4f("u_MVP", mvp);
			render.Draw(*m_va, *m_ib, *m_shader);
		}
	}

	void MyTexturePtrs::OnImGuiRenderer()
	{
			ImGui::SliderFloat3("float A", &m_translationA.x, 0.0f, 960.0f);
			ImGui::SliderFloat3("float B", &m_translationB.x, 0.0f, 960.0f);
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

	void MyTexturePtrs::setPoints()
	{
		int i = 16;
		m_points = new float[i]{
			-50.0f, -50.0f, 0.2f, 0.2f,
			 50.0f, -50.0f, 0.8f, 0.2f,
			 50.0f,  50.0f, 0.8f, 0.8f,
			-50.0f,  50.0f, 0.2f, 0.8f
		};
	}

	void MyTexturePtrs::setIndecies()
	{
		int i = 6;
		unsigned int* indecies = new unsigned int[i]{
				0, 1, 2,
				2, 3, 0
		};
		m_indecies = indecies;
	}
}