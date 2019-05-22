#include "imGuiProxy.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "Test/Test.hpp"

ImGuiProxy::ImGuiProxy(GLFWwindow* window)
{
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();
}


ImGuiProxy::~ImGuiProxy()
{
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiProxy::drawGui(test::Test* currentTest, std::function<void(void)> resetTest)
{
	ImGui_ImplGlfwGL3_NewFrame();
	ImGui::Begin("Test");
	if (ImGui::Button("RESET"))
	{
		resetTest();
	}

	currentTest->OnImGuiRenderer();
	ImGui::End();
	ImGui::Render();
	ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}
