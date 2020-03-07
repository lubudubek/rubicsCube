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
#include "MouseRotationMap.h"
#include <array>

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
		Renderer render;
		render.Clear();
		{
			/*m_keyHandler.handleKey();*/
			if (true)//enablePing)
			{
				m_cubicSupervisor->ping();
				enablePing = false;
			}
			cubicMvps.handleCamera();
			m_shader->Bind();

			for (auto& cubic : cubicMvps.getCubics())
			{
				if(cubic.getOpacity() > 0.9f)
				{		
					glm::mat4 proj = glm::perspective(m_onlineParams.fovy, m_onlineParams.aspect, m_onlineParams.near, m_onlineParams.far);
					glm::mat4 transX = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.0f, 0.0f));

					m_shader->SetUniformMat4f("u_MVP", proj * cubic.getTransformation());
					m_shader->SetUniform1f("opacity", cubic.getOpacity());
					render.Draw(*m_va, *m_ib, *m_shader);
				}
			}
			for (auto& cubic : cubicMvps.getCubics())
			{
				if (cubic.getOpacity() < 0.9f)
				{
					glm::mat4 proj = glm::perspective(m_onlineParams.fovy, m_onlineParams.aspect, m_onlineParams.near, m_onlineParams.far);
					glm::mat4 transX = glm::translate(glm::mat4(1.0f), glm::vec3(-0.3f, 0.0f, 0.0f));

					m_shader->SetUniformMat4f("u_MVP", proj * cubic.getTransformation());
					m_shader->SetUniform1f("opacity", cubic.getOpacity());
					render.Draw(*m_va, *m_ib, *m_shader);
				}
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
		float mouseY = 1.0f - mousePosY / (windowH * 0.5f);

		glm::mat4 proj = glm::perspective(fov, aspect, near, far);
		glm::mat4 view = glm::lookAt(glm::vec3(0.0f), cameraDirection, cameraUpVector);

		glm::mat4 invVP = glm::inverse(proj * view);
		glm::vec4 screenPos = glm::vec4(mouseX, -mouseY, 1.0f, 1.0f);
		glm::vec4 worldPos = invVP * screenPos;

		glm::vec3 dir = glm::normalize(glm::vec3(worldPos));

		return dir;
	}
	std::array<glm::vec3, 4> convertToVerts(Position surface)
	{
		switch(surface){
		case Position::FRONT:
			return{
				glm::vec3{ -0.5f, -0.5f, 0.5f },
				glm::vec3{  0.5f, -0.5f, 0.5f },
				glm::vec3{  0.5f,  0.5f, 0.5f },
				glm::vec3{ -0.5f,  0.5f, 0.5f } };
		case Position::BACK:
			return{
				glm::vec3{ -0.5f, -0.5f, -0.5f },
				glm::vec3{  0.5f, -0.5f, -0.5f },
				glm::vec3{  0.5f,  0.5f, -0.5f },
				glm::vec3{ -0.5f,  0.5f, -0.5f } };
		case Position::LEFT:
			return{
				glm::vec3{ -0.5f, -0.5f, -0.5f },
				glm::vec3{ -0.5f,  0.5f, -0.5f },
				glm::vec3{ -0.5f,  0.5f,  0.5f },
				glm::vec3{ -0.5f, -0.5f,  0.5f } };
		case Position::RIGHT:
			return{
				glm::vec3{ 0.5f, -0.5f, -0.5f },
				glm::vec3{ 0.5f,  0.5f, -0.5f },
				glm::vec3{ 0.5f,  0.5f,  0.5f },
				glm::vec3{ 0.5f, -0.5f,  0.5f } };
		case Position::BOTTOM:
			return{
				glm::vec3{ -0.5f, -0.5f, -0.5f },
				glm::vec3{  0.5f, -0.5f, -0.5f },
				glm::vec3{  0.5f, -0.5f,  0.5f },
				glm::vec3{ -0.5f, -0.5f,  0.5f } };
		case Position::TOP:
			return{
				glm::vec3{ -0.5f, 0.5f, -0.5f },
				glm::vec3{  0.5f, 0.5f, -0.5f },
				glm::vec3{  0.5f, 0.5f,  0.5f },
				glm::vec3{ -0.5f, 0.5f,  0.5f } };
		default:
			return{
				glm::vec3{ -0.00001f, -0.00001f, 0.00001f },
				glm::vec3{  0.00001f, -0.00001f, 0.00001f },
				glm::vec3{  0.00001f,  0.00001f, 0.00001f },
				glm::vec3{ -0.00001f,  0.00001f, 0.00001f } };
		}

		//return result;
	}



	

	//std::vector<Position> positions;
	//MouseRotationKey mousRotKey{ { Position::FRONT, Position::LEFT,  Position::TOP    }, Position::FRONT, Direction2d::UP };


	bool isDragStrongEnough(Diff diff)
	{
		return (abs(diff.x * diff.y) > 40);
	}

	void CubeTest::OnImGuiRenderer()
	{
		m_keyHandler.handleKey();
		if (ImGui::IsKeyPressed(80)) //p
			enablePing = true;


			ImGui::SliderFloat("Fovy", &m_onlineParams.fovy, -3.14f, 3.14f);
			ImGui::SliderFloat("Fovy 1", &m_onlineParams.near, -50.0f, 50.0f);
			ImGui::SliderFloat("Fovy 2", &m_onlineParams.far, -50.0f, 50.0f);

			ImGui::SliderFloat("Translate Z", &m_onlineParams.transformZ, -40.0f, 40.0f);
			ImGui::SliderFloat("Rotation X", &m_onlineParams.rotateX, -0.6f, 0.6f);
			ImGui::SliderFloat("Rotation Y", &m_onlineParams.rotateY, -2.0f, 2.0f);
			ImGui::SliderFloat("Aspect", &m_onlineParams.aspect, -2.0f, 2.0f);

			auto vecMouse = ImGui::GetMouseDragDelta(0, 1.0);
			diff.x = diff.x + vecMouse.x;
			diff.y = diff.y + vecMouse.y;

			auto posMouse = ImGui::GetMousePos();
			
			if (ImGui::IsKeyPressed(68))
			{
				m_onlineParams.fovy = (m_onlineParams.fovy == 0.4f) ? 1.2 : 0.4;
				m_onlineParams.transformZ = (m_onlineParams.transformZ == -16) ? -5 : -16;
				m_onlineParams.aspect *= -1;
				m_onlineParams.rotateX *= -1;
				std::swap(m_onlineParams.near, m_onlineParams.far);
			}
			if (ImGui::IsMouseDown(0) and ImGui::IsMouseDown(1))
			{
				m_onlineParams.rotateY = (vecMouse.x / 100) + m_onlineParams.rotateYstatic;
				m_onlineParams.rotateX = (vecMouse.y / 100) + m_onlineParams.rotateXstatic;
				//std::cout << std::endl << "Mouse Position: x(" << ImGui::GetMousePos().x << "), y(" << ImGui::GetMousePos().y << ")" << std::endl;
			}
			else if (ImGui::IsMouseDown(0) and not ImGui::IsMouseDown(1) and not isClicked)
			{
				isClicked = true;
				ctrlClicked = ImGui::GetIO().KeyCtrl;
				glm::vec2 BaryPosition(0.0f, 0.0f);
				float distance = -40;
				float minDistance = -40;
				auto cameraDirection = glm::vec3(0.0f, 0.0f, 1.0f);
				auto cameraUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
				auto orig = glm::vec3(0.0f, 0.0f, 0.0f);
				auto dir = CreateRay(
					posMouse.x,
					posMouse.y,
					480.0f,
					840.0f,
					m_onlineParams.fovy,
					m_onlineParams.aspect,
					m_onlineParams.near,
					m_onlineParams.far,
					cameraDirection,
					cameraUpVector);

				
				
				for (auto& cubic : cubicMvps.getCubics())
				{
					bool temp = cubic.getInitialPosition() == std::vector{ Position::FRONT, Position::TOP } ||
						cubic.getInitialPosition() == std::vector{ Position::TOP, Position::FRONT };
					auto transformation = cubic.getTransformation();
					for (auto& surface : cubic.getInitialPosition())
					{
						std::array<glm::vec3, 4> verts = convertToVerts(surface);
						std::transform(verts.begin(), verts.end(), verts.begin(),
							[&transformation](auto & vert) { return transformation * glm::vec4{ vert, 1.0f }; });
						if (temp && surface == Position::FRONT)
						{
							for (auto& v : verts)
							{
								std::cout << "TEMP: " << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
							}
						}

						bool const Result = glm::intersectRayTriangle(orig, dir, verts[0], verts[1], verts[2], BaryPosition, distance)
							|| glm::intersectRayTriangle(orig, dir, verts[0], verts[2], verts[3], BaryPosition, distance);

						if (Result == true and distance > minDistance)
						{
							minDistance = distance;
							chosenSurface = *cubic.getPositionOfInitial(surface);
							chosenOne = &cubic;
						}
					}
					cubic.setOpacity(0.3f);
				}

				if (not chosenOne)
				{
					std::cout << "not found cube" << std::endl;
				}
				else
				{
					std::cout << "chosen surface: " << chosenSurface << std::endl;
					chosenOne->setOpacity(1.0f);
				}
			}
			if (ImGui::IsMouseReleased(0)) {
				Direction2d chosenDirection;
				if (chosenOne && isDragStrongEnough(diff)) {
					if (abs(diff.x) > abs(diff.y))
					{
						chosenDirection = (diff.x > 0) ? Direction2d::RIGHT : Direction2d::LEFT;
						std::cout << "Move " << chosenSurface << ((diff.x > 0) ? ", RIGHT" : " LEFT") << " by " << abs(diff.x) << std::endl;
					}
					else
					{
						chosenDirection = (diff.y) > 0 ? Direction2d::DOWN : Direction2d::UP;
						std::cout << "Move " << chosenSurface << ((diff.y > 0) ? ", DOWN" : " UP") << " by " << abs(diff.y) << std::endl;
					}
				
					MouseRotationKey selected{ chosenOne->getPosition(), chosenSurface,  chosenDirection};
					std::cout << "Selected item: ";
					for (int i = 0; i < selected.positions.size(); ++i)
					{
						std::cout << selected.positions[i] << ", ";
					}
					std::cout << "chosen surface: " << selected.surface << ", "<< selected.direction << ", ctrl: " << ctrlClicked << std::endl;

					m_keyHandler.pushToEmptyQueue(ctrlClicked ? mouseCtrlRotationsMap.at(selected) : mouseRotationsMap.at(selected));

				
				}
				m_onlineParams.rotateYstatic = m_onlineParams.rotateY;
				m_onlineParams.rotateXstatic = m_onlineParams.rotateX;
				chosenOne = nullptr;
				diff.x = 0;
				diff.y = 0;

				//std::cout << "CHOSEN DIRECTION " << chosenOne->getPosition() << ", " << chosenSurface << ", " << bool(diff.x > 0) << std::endl;


				isClicked = false;
				ctrlClicked = false;
			}

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}