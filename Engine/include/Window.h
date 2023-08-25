#pragma once

#include "Event.h"
#include <functional>
#include <string>

class Window {
public:
	Window(std::string title, uint32_t width, uint32_t height)
		: title(title), width(width), height(height) { }
	virtual ~Window() = 0;

	virtual void onUpdate() = 0;

	const std::string& getTitle() const { return title; }
	const uint32_t& getWidth() const { return width; }
	const uint32_t& getHeight() const { return height; }

	virtual void setEventCallback(std::function<void(Event&)>&) = 0;

	static std::unique_ptr<Window> CreateEngWindow(std::string title, uint32_t width, uint32_t height);
private:
	std::string title;
	uint32_t width;
	uint32_t height;
};