#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include "renderer.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexArray.hpp"
#include "shader.hpp"
#include "VertexBufferLayout.hpp"
#include "Texture.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "Test/TestClearColor.hpp"
#include "Test/MyTexturePtrs.hpp"
#include "Test/MyTextureTest.hpp"
#include "Test/CubeTest.hpp"
#include "Test/Test.hpp"
#include "Test/CubicTransformations.hpp"

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
	if (!glfwInit()) {
		std::cout << "ERROR: could not start GLFW3" << std::endl;
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(840, 480, "Hello Triangle", NULL, NULL);
	if (!window) {
		std::cout << "ERROR: could not open window with GLFW3" << std::endl;
		glfwTerminate();
		return 1;
	}
	
	glfwSetKeyCallback(window, keyCallBack);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	GLCall(glEnable(GL_DEPTH_TEST));
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	//glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	float r = 0.0f;
	Renderer render;

	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();

	test::Test* currentTest = nullptr;
	test::TestMenu* testMenu = new test::TestMenu(currentTest);
	currentTest = testMenu;
	testMenu->RegisterTest<test::TestClearColor>("Clear Color");
	testMenu->RegisterTest<test::MyTextureTest>("my texture test");
	testMenu->RegisterTest<test::MyTexturePtrs>("my texture ptrs");
	testMenu->RegisterTest<test::CubeTest>("kostka");

	while (!glfwWindowShouldClose(window)) {
		render.Clear();

		ImGui_ImplGlfwGL3_NewFrame();
		if (currentTest)
		{
			currentTest->OnUpdate(0.0f);
			currentTest->OnRenderer();
			ImGui::Begin("Test");
			if (currentTest != testMenu && ImGui::Button("<-"))
			{
				delete currentTest;
				currentTest = testMenu;
			}
			
			currentTest->OnImGuiRenderer();
			ImGui::End();
		}

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 1;
}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << "key: " << key << ", scancode: " << scancode << ", action: " << action << ", mods: " << mods;
}
