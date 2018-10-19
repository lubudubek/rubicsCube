#pragma once
#include <string>

#include "renderer.hpp"

class Texture
{
private:
	unsigned int m_rendererId;
	std::string m_filePath;
	int m_width, m_height, m_BPP;
	unsigned char* m_localBuffer;

public:
	Texture(const std::string& filePath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_width; };
	inline int GetHeight() const { return m_height; };

};