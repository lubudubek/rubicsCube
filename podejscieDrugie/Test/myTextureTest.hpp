#pragma once
#include "Test/Test.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "shader.hpp"
#include "Texture.hpp"
#include <memory>

namespace test
{
	class MyTextureTest : public Test
	{
	public:
		MyTextureTest();
		~MyTextureTest();

		virtual void OnUpdate(float deltaTime);
		virtual void OnRenderer();
		virtual void OnImGuiRenderer();
	private:
		float m_points[16];
		unsigned int m_indecies[6];
		glm::vec3 m_translationA;
		glm::vec3 m_translationB;
		glm::mat4 m_proj;
		glm::mat4 m_view;
		VertexArray m_va;
		VertexBuffer m_vb;
		IndexBuffer m_ib;
		VertexBufferLayout m_layout;
		Shader m_shader;
		Texture m_texture;

	};
}