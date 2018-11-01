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
	class MyTexturePtrs : public Test
	{
	public:
		MyTexturePtrs();
		~MyTexturePtrs();

		virtual void OnUpdate(float deltaTime);
		virtual void OnRenderer();
		virtual void OnImGuiRenderer();
	private:
		float* m_points;
		unsigned int* m_indecies;
		glm::vec3 m_translationA;
		glm::vec3 m_translationB;
		glm::mat4 m_proj;
		glm::mat4 m_view;
		std::shared_ptr<VertexArray> m_va;
		std::shared_ptr<VertexBuffer> m_vb;
		std::shared_ptr<IndexBuffer> m_ib;
		std::shared_ptr<VertexBufferLayout> m_layout;
		std::shared_ptr<Shader> m_shader;
		std::shared_ptr<Texture> m_texture;

		void setIndecies();
		void setPoints();
	};
}