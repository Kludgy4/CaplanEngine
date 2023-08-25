#include <Engine.h>
#include <memory>

class Game : public GameApp
{
public:
	Game()
	{
		Log::InitLoggers();
		LOG_CLIENT_INFO("Initialised engine/client loggers");
	}

	~Game()
	{

	}
};

std::unique_ptr<GameApp> CreateGameApp() {
	return std::move(std::make_unique<Game>());
}