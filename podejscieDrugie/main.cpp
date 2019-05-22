#include "Test/CubeTest.hpp"
#include "glProxy.h"
#include "imGuiProxy.h"

int main() {
	GlProxy glProxy;
	ImGuiProxy imGuiProxy(glProxy.initialize());
	test::Test* currentTest = new test::CubeTest;

	while (glProxy.isWindowOpen()) {
		
		if (currentTest)
		{
			currentTest->OnUpdate(0.0f);
			currentTest->OnRenderer();

			auto resetCurrentTest = [&currentTest]()
				{
					delete currentTest;
					currentTest = new test::CubeTest;
				};

			imGuiProxy.drawGui(currentTest,
							   resetCurrentTest);
		}
		glProxy.updateWindow();
	}
	return 1;
}