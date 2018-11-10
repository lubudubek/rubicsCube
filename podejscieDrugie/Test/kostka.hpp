#pragma once
#include "Test/Test.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "shader.hpp"
#include "Texture.hpp"
#include <memory>
#include "CubicTransformations.hpp"


namespace test
{
	class Cube : public Test
	{
	public:
		Cube();
		~Cube();

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

		float m_fovy;
		float m_fovy1;
		float m_fovy2;

		float m_rotation_x;
		float m_rotation_y;
		float m_rotateY;
		float m_rotateX;
		int direction;
		bool isAnimationOngoing;
		float tempAngle;
		CubicTransformations cubicMvps;


		void setIndecies();
		void setPoints();
		void setCubePoints();
		void checkKeys();
		void Animate(CubicTransformations& cubiMvp);
	};
}