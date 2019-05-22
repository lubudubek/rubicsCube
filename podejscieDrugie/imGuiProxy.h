#pragma once
#include <functional>

struct GLFWwindow;
namespace test
{
	class Test;
}

class ImGuiProxy
{
public:
	ImGuiProxy(GLFWwindow* window);
	void drawGui(test::Test* currentTest, std::function<void(void)> resetTest);
	~ImGuiProxy();
};

