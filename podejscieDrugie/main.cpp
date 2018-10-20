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
	//glEnable(GL_DEPTH_TEST); // enable depth-testing
	//glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

	float points[] = {
	100.0f, 100.0f, 0.2f, 0.2f,
	200.0f, 100.0f, 0.8f, 0.2f,
	200.0f, 200.0f, 0.8f, 0.8f,
	100.0f, 200.0f, 0.2f, 0.8f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	VertexArray va;
	VertexBuffer vb(points, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6);

	glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200.0f, 200.0f, 0.0f));

	Shader shader("res/shaders/Basic.shader");

	glm::mat4 mvp = proj * view * model;

	shader.Bind();
	shader.SetUniform1i("u_Texture", 2);
	shader.SetUniformMat4f("u_MVP", mvp);
	
	Texture texture("logo1.png");
	texture.Bind(2);
	//shader.SetUniform1i("u_Texture", 2);

	float r = 0.0f;
	Renderer render;
	float increment = 0.05f;
	while (!glfwWindowShouldClose(window)) {
		render.Clear();
		// wipe the drawing surface clear
		shader.Bind();
		
		//shader.SetUniform4f("p_color", r, 0.4f, 0.2f, 1.0f);
		
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