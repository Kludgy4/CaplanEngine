#pragma once

#include "Window.h"
#include <GLFW\glfw3.h>

class WindowGLFW : public Window {
public:
	WindowGLFW(std::string&& title, uint32_t width, uint32_t height);
	~WindowGLFW();

	void onUpdate();

	void setEventCallback(std::function<void(Event&)>&);
private:
	GLFWwindow* windowHandle;
};
