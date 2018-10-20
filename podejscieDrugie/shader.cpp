#include "shader.hpp"
#include "GL/glew.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "renderer.hpp"

Shader::Shader(const std::string& filePath)
	: m_rendererId(0), m_pathFile(filePath)
{
	ShadersCode shaders = ParceShaderFile(filePath);//"res/shaders/Basic.shader"
	m_rendererId = CreateShader(shaders.vertexShader, shaders.fragmentShader);
}

Shader::~Shader()
{
	glDeleteProgram(m_rendererId);
}

unsigned int Shader::CompileShader(unsigned int type, const std::string shaderCode)
{
	unsigned int id = glCreateShader(type);
	const char* source = shaderCode.c_str();
	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	int results;
	glGetShaderiv(id, GL_COMPILE_STATUS, &results);
	if (results == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char *)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile shader: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
		std::cout << message;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string vertexShader, const std::string fragmentShader)
{
	unsigned int pr = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	glAttachShader(pr, vs);
	glAttachShader(pr, fs);
	glLinkProgram(pr);
	glValidateProgram(pr);

	glDeleteProgram(vs);
	glDeleteProgram(fs);

	return pr;
}

ShadersCode Shader::ParceShaderFile(const std::string& filePath)
{
	std::ifstream stream(filePath);

	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}
	return { ss[0].str(), ss[1].str() };
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
		return m_uniformLocationCache[name];

	GLCall(int location = glGetUniformLocation(m_rendererId, name.c_str()));
	if (location == -1)
	{
		std::cout << "warning: glGetUniformLocation failed. Uniform " << name << " does not exist" << std::endl;
	}

	m_uniformLocationCache[name] = location;
	return location;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_rendererId));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniformMat4f(const std::string & name, const glm::mat4 & matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}
