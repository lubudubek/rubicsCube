#define GLEW_STATIC

#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "glProxy.h"
#include <iostream>



namespace
{
	void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		std::cout << "key: " << key << ", scancode: " << scancode << ", action: " << action << ", mods: " << mods;
	}
}

GlProxy::GlProxy()
{
	if (!glfwInit())
	{
		std::cout << "ERROR: could not start GLFW3" << std::endl;
		return;
	}

	m_window = glfwCreateWindow(840, 480, "Hello Triangle", NULL, NULL);
	if (!m_window)
	{
		std::cout << "ERROR: could not open window with GLFW3" << std::endl;
		glfwTerminate();
	}
}

GLFWwindow* GlProxy::initialize()
{
	glfwSetKeyCallback(m_window, keyCallBack);
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);
	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	std::cout << "Renderer: " << *renderer;
	std::cout << "OpenGL version supported" << *version;

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // works fine, except cracks
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glClearColor(0.3f, 0.2f, 0.8f, 0.1f);

	return m_window;
}

void GlProxy::updateWindow()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

bool GlProxy::isWindowOpen()
{
	return !glfwWindowShouldClose(m_window);
}

GlProxy::~GlProxy()
{
	glfwTerminate();
}
