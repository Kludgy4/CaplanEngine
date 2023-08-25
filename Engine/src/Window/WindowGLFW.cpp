#include "engpch.h"
#include "Log.h"
#include "WindowGLFW.h"

WindowGLFW::WindowGLFW(std::string title = "GLFW Window", uint32_t width = 1024, uint32_t height = 768)
	: Window(title, width, height)
{
	int glfwInitSuccess = glfwInit();

	if (!glfwInitSuccess) {
		// TODO: ERROR HANDLING???
	}

	glfwSetErrorCallback([](int error, const char* description){
		LOG_ENGINE_CRITICAL("Error {0}: {1}", error, description);
	});

	windowHandle = glfwCreateWindow(width, height, getTitle().c_str(), nullptr, nullptr);
}

WindowGLFW::~WindowGLFW()
{
	glfwDestroyWindow(windowHandle);
	glfwTerminate();
}
