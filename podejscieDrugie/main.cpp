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


int main() {
	// start GL context and O/S window using the GLFW helper library
	if (!glfwInit()) {
		std::cout << "ERROR: could not start GLFW3" << std::endl;
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
	if (!window) {
		std::cout << "ERROR: could not open window with GLFW3" << std::endl;
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(2);
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

	float points[] = {
	 0.5f,  0.5f,
	 0.5f, -0.5f,
	-0.5f, -0.5f,
	-0.5f,  0.5f
	};

	unsigned int indices[] = {
		0, 1, 2,
		0, 3, 2
	};

	VertexArray va;
	VertexBuffer vb(points, 4 * 2 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);
	Shader shader("res/shaders/Basic.shader");

	shader.Bind();
	float r = 0.0f;
	
	Renderer render;
	float increment = 0.05f;
	while (!glfwWindowShouldClose(window)) {
		render.Clear();
		// wipe the drawing surface clear 
		shader.SetUniform4f("u_Color", r, 0.4f, 0.2f, 1.0f);

		render.Draw(va, ib, shader);
		// update other events like input handling 
		glfwPollEvents();

		if (r > 1.0f)
			increment = -0.05f;
		else if (r < 0.0f)
			increment = 0.05f;
		r += increment;
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);
	}

	// close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}