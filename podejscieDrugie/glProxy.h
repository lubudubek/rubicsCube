#pragma once

struct GLFWwindow;

class GlProxy
{
public:
	GlProxy();
	~GlProxy();
	GLFWwindow* initialize();
	void updateWindow();
	bool isWindowOpen();
private:
	GLFWwindow* m_window = nullptr;
};

