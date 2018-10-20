#pragma once

#include <string>
#include <unordered_map>
#include "glm/glm.hpp"


struct ShadersCode
{
	std::string vertexShader;
	std::string fragmentShader;
};

class Shader
{
private:
	unsigned int m_rendererId;
	std::string m_pathFile;
	std::unordered_map<std::string, int> m_uniformLocationCache;
public:
	Shader(const std::string& filePath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
private:
	unsigned int CompileShader(unsigned int type, const std::string shaderCode);
	unsigned int CreateShader(const std::string vertexShader, const std::string fragmentShader);
	ShadersCode ParceShaderFile(const std::string& filePath);

	int GetUniformLocation(const std::string& name);
};