#pragma once
#include <GL/glew.h>
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GlClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GlClearError();
bool GLLogCall(const char * function, const char * file, int line);

class Renderer
{
public:
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ia, const Shader& shader);
};