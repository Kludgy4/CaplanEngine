#pragma once
#include "Layer.h"
#include "vector"

class GameApp {
public:
	GameApp();
	virtual ~GameApp();

	void PushLayer(Layer layer);
	void PopLayer(Layer layer);

	void run();
private:
	std::vector<Layer> layerStack;
};