#include "engpch.h"
#include "Window.h"
#include "WindowGLFW.h"

std::unique_ptr<Window> Window::CreateEngWindow(std::string title, uint32_t width, uint32_t height) {
#ifdef CP_WINDOWS
	return std::make_unique<WindowGLFW>(title, width, height);
#else
	// TODO:compilation error
#endif
}
