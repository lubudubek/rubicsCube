#pragma once
#include "Test/Test.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "shader.hpp"
#include "Texture.hpp"
#include <memory>
#include "CubicTransformations.hpp"
#include "OnlineParams.hpp"
#include "KeyHandler.hpp"
#include <queue>
#include "RotationFinder.hpp"
#include "CubicAnimateSupervisor.hpp"
#include "Rotators/Rotation.hpp"
#include "Finders/IFinder.h"

namespace test
{
	class CubeTest : public Test
	{
	public:
		CubeTest();
		~CubeTest();

		virtual void OnUpdate(float deltaTime);
		virtual void OnRenderer();
		virtual void OnImGuiRenderer();
	private:
		glm::mat4 m_proj;
		glm::mat4 m_view;
		std::shared_ptr<VertexArray> m_va;
		std::shared_ptr<VertexBuffer> m_vb;
		std::shared_ptr<IndexBuffer> m_ib;
		std::shared_ptr<VertexBufferLayout> m_layout;
		std::shared_ptr<Shader> m_shader;

		CubicTransformations cubicMvps;
		std::shared_ptr<IFinder> m_rotationFinder;
		KeyHandler m_keyHandler;
		std::queue<std::shared_ptr<IRotation>> m_rotates;
		std::stack<std::shared_ptr<IRotation>> m_rotatesHistory;

		//RotationFinder m_rotationFinder;

		std::unique_ptr<CubicAnimateSupervisor> m_cubicSupervisor;
		
		OnlineParams m_onlineParams{};
	};
}