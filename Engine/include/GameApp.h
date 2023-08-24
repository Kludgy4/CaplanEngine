#pragma once
#include <memory>
#include <vector>
#include "Layer.h"
#include "Window.h"

class GameApp {
public:
	GameApp();
	virtual ~GameApp();

	void PushLayer(Layer layer);

	void run();
private:
	bool running = true;
	std::vector<Layer> layerVec;
	std::unique_ptr<Window> window;
};