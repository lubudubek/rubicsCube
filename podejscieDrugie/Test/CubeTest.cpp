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
#include <glm/gtx/intersect.hpp>
//#include "Finders/BlankRotattionFinder.h"


//#define _USE_MATH_DEFINES

namespace test
{

	CubeTest::CubeTest()
		:	m_proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
			m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
			cubicMvps(m_onlineParams),
			m_rotationFinder(std::make_shared<RealRotationFinder>(m_rotates, m_rotatesHistory, cubicMvps)),
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
		//glm::vec3 v0(1, 4, 1);
		//glm::vec3 v1(-1, 4, 1);
		//glm::vec3 v2(0, 4, -1);
		//glm::vec3 origin(0, 0, 0);
		//glm::vec3 direction(0, 1, 0);


		Renderer render;
		render.Clear();
		{
			m_keyHandler.handleKey();
		   
			m_cubicSupervisor->ping();
			cubicMvps.handleCamera();
			m_shader->Bind();

			
			for (auto& cubic : cubicMvps.getCubics())
			{
				std::vector<Position> temp{ Position::FRONT, Position::LEFT, Position::TOP };
				if (cubic.getInitialPosition() == temp)
				{


					glm::vec4 tr1coord = { -0.5f, -0.5f, 0.5f, 1.0f};
					glm::vec4 tr2coord = { 0.5f, -0.5f, 0.5f, 1.0f };
					glm::vec4 tr3coord = { 0.5f, 0.5f, 0.5f, 1.0f };
					auto transform = cubic.getTransformation();
					tr1coord = tr1coord * transform;
					tr2coord = tr2coord * transform;
					tr3coord = tr3coord * transform;
					m_onlineParams.fTriangle = tr1coord;
					m_onlineParams.sTriangle = tr2coord;
					m_onlineParams.tTriangle = tr3coord;




					cubic.setOpacity(1.0f);
				}
				else
				{
					cubic.setOpacity(0.2f);
				}
			}
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
				cubic.setOpacity(1.0f);
			}

		}
	}
	glm::vec3 CreateRay(float mousePosX, 
						float mousePosY,
						float windowH,
						float windowW,
						float fov,
						float aspect,
						float near,
						float far,
						glm::vec3 cameraDirection,
						glm::vec3 cameraUpVector) {
		// these positions must be in range [-1, 1] (!!!), not [0, width] and [0, height]
		float mouseX = mousePosX / (windowW * 0.5f) - 1.0f;
		float mouseY = mousePosY / (windowH * 0.5f) - 1.0f;

		glm::mat4 proj = glm::perspective(fov, aspect, near, far);
		glm::mat4 view = glm::lookAt(glm::vec3(0.0f), cameraDirection, cameraUpVector);

		glm::mat4 invVP = glm::inverse(proj * view);
		glm::vec4 screenPos = glm::vec4(mouseX, -mouseY, 1.0f, 1.0f);
		glm::vec4 worldPos = invVP * screenPos;

		glm::vec3 dir = glm::normalize(glm::vec3(worldPos));

		return dir;
	}
	void CubeTest::OnImGuiRenderer()
	{
			ImGui::SliderFloat("Fovy", &m_onlineParams.fovy, -3.14f, 3.14f);// 6.0f, 9.0f
			ImGui::SliderFloat("Fovy 1", &m_onlineParams.near, -50.0f, 50.0f);// 1.5f, 2.5f
			ImGui::SliderFloat("Fovy 2", &m_onlineParams.far, -50.0f, 50.0f);

			ImGui::SliderFloat("Translate Z", &m_onlineParams.transformZ, -40.0f, 40.0f);
			ImGui::SliderFloat("Rotation X", &m_onlineParams.rotateX, -0.6f, 0.6f);
			ImGui::SliderFloat("Rotation Y", &m_onlineParams.rotateY, -2.0f, 2.0f);
			ImGui::SliderFloat("Aspect", &m_onlineParams.aspect, -2.0f, 2.0f);

			auto vecMouse = ImGui::GetMouseDragDelta(0, 1.0);
			
			if (ImGui::IsKeyPressed(68))
			{
				m_onlineParams.fovy = (m_onlineParams.fovy == 0.4f) ? 1.2 : 0.4;
				m_onlineParams.transformZ = (m_onlineParams.transformZ == -16) ? -5 : -16;
				m_onlineParams.aspect *= -1;
				m_onlineParams.rotateX *= -1;
				std::swap(m_onlineParams.near, m_onlineParams.far);
				//m_onlineParams.transformZ = 5;
			}
			if (ImGui::IsAnyMouseDown())
			{
				m_onlineParams.rotateY = (vecMouse.x / 100) + m_onlineParams.rotateYstatic;
				m_onlineParams.rotateX = (vecMouse.y / 100) + m_onlineParams.rotateXstatic;
				std::cout << std::endl << "Mouse Position: x(" << ImGui::GetMousePos().x << "), y(" << ImGui::GetMousePos().y << ")" <<std::endl;

				glm::vec2 BaryPosition(0.0f, 0.0f);
				float Distance = 0;
				auto cameraDirection = glm::vec3(0.0f, 0.0f, 1.0f);
				auto cameraUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
				auto orig = glm::vec3(0.0f, 0.0f, 0.0f);
				auto dir = CreateRay(
					m_onlineParams.rotateX,
					m_onlineParams.rotateY,
					480.0f,
					840.0f,
					m_onlineParams.fovy,
					m_onlineParams.aspect,
					m_onlineParams.near,
					m_onlineParams.far,
					cameraDirection,
					cameraUpVector);

				bool const Result = glm::intersectRayTriangle(orig, dir, m_onlineParams.fTriangle, m_onlineParams.sTriangle, m_onlineParams.tTriangle, BaryPosition, Distance);
				std::cout << "Result:" << Result << std::endl;
				std::cout << "Verts: (" << m_onlineParams.fTriangle.x << ", " << m_onlineParams.fTriangle.y << ", " << m_onlineParams.fTriangle.z<< ") " <<
					 " (" << m_onlineParams.sTriangle.x << ", " << m_onlineParams.sTriangle.y << ", " << m_onlineParams.sTriangle.z << ")" << 
			         " (" << m_onlineParams.tTriangle.x << ", " << m_onlineParams.tTriangle.y << ", " << m_onlineParams.tTriangle.z << ")" << std::endl;

			}
			if (ImGui::IsMouseReleased(0)) {
				m_onlineParams.rotateYstatic = m_onlineParams.rotateY;
				m_onlineParams.rotateXstatic = m_onlineParams.rotateX;
			}



			//	m_onlineParams.fTriangle,
			//	m_onlineParams.sTriangle
			//	m_onlineParams.tTriangle
			//	vec<3, T, Q> const& orig, vec<3, T, Q> const& dir,
			//	vec<3, T, Q> const& v0, vec<3, T, Q> const& v1, vec<3, T, Q> const& v2,
			//	vec<2, T, Q> & baryPosition, T & distance);



			//	auto pos = ImGui::GetMousePos();

			//	std::cout << std::endl << "MOUSE CLICKED pos: x(" << pos.x << ") y(" << pos.y << ")";
			//	//std::cout << std::endl << "MOUSE DRAGGED: x(" << vecMouse5.x << ") y(" << vecMouse5.y << ")";
			//}
			//auto vecMouse = ImGui::GetMouseDragDelta(0, 1.0);
			//m_onlineParams.rotateX = vecMouse.x / 100;

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}