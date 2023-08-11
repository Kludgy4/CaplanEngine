#include <Engine.h>
#include <memory>

class Game : public GameApp
{
public:
	Game()
	{

	}

	~Game()
	{

	}
};

std::unique_ptr<GameApp> CreateGameApp() {
	return std::move(std::make_unique<Game>());
}